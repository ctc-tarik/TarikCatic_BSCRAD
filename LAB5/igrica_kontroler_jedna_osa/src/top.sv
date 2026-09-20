///////////////////////////////////////////////////////////////////////////////
// Top level: HDMI igrica ("trcanje kroz otvore") + upravljanje crvenom
// lopticom GORE/DOLE putem JEDNE ose analognog dzojstika, ocitane preko
// ADS1115 I2C ADC-a. Zamjenjuje prethodnu verziju upravljanu sa dva tastera
// (butnL_n/butnR_n).
//
// POJEDNOSTAVLJENO u odnosu na prethodnu (dvo-kanalnu X+Y) verziju:
// -----------------------------------------------------------------------
// Prethodna verzija (naizmjenicno citanje dva ADS1115 kanala za X i Y,
// sopstveni power-on-reset brojac za i2c domen, PGA=+-4.096V) NIKAD nije
// proradila na stvarnom hardveru -- ni u kombinovanom projektu, ni u
// potpuno izolovanom test-projektu bez ijednog reda HDMI koda -- iako je
// RTL logika dva puta strogo verifikovana simulacijom (idealizovani stub
// i pravi bihevioralni ADS1115 I2C slave model), a sinteza/PnR izvjestaji
// ne pokazuju nijedan problem (ispravan top modul, ispravni pinovi,
// ispravno INIT stanje registara).
//
// Jedina konfiguracija koja je STVARNO dokazana da radi na ovoj ploci je
// ona iz LV4 (jedan ADS1115 kanal -- AIN0, PGA=+-2.048V, i2c_ctrl.sv BEZ
// config_msb/cycle_done prosirenja, areset_n vezan na fizicko dugme S1
// koje se NIKAD ne pritiska -- FSM se pri ukljucenju napaja direktno iz
// svojih deklarisanih pocetnih vrijednosti). Zato je ovdje ta ISTA
// konfiguracija preuzeta BEZ IKAKVE IZMJENE:
//   - i2c_ctrl.sv = originalni LV4 fajl (fiksni CONFIG_MSB=8'hC5, AIN0).
//   - areset_n je, kao i u LV4, pravi fizicki ulaz (dugme S1, pin 4),
//     a ne izveden/generisan signal.
// Dzojstik sada ima samo JEDNU aktivnu osu: njen analogni izlaz ide na
// AIN0 (isti fizicki ulaz ADS1115-a kao potenciometar u LV4-u) i pomjera
// lopticu gore/dole. X pozicija loptice je fiksna (kao u originalnoj
// igrici prije dodavanja dzojstika).
///////////////////////////////////////////////////////////////////////////////

module top
   import hdmi_pkg::*;
(
   input  logic  clk_ext,     // Vanjski oscilator: 27MHz (Tang Nano 9K)
   input  logic  areset_n,    // Fizicko dugme S1 (aktivno nisko) -> pin 4.
                               // NE MORA se pritiskati -- vidjeti komentar
                               // gore. Resetuje SAMO i2c/dzojstik dio;
                               // HDMI dio i dalje koristi svoj srst_n.

   inout  wire   i2c_scl,     // ka ADS1115 SCL (koristi onboard pull-up modula)
   inout  wire   i2c_sda,     // ka ADS1115 SDA (koristi onboard pull-up modula)

 //HDMI izlaz, direktno na konektor
   output logic  hdmi_clk_p,
   output logic  hdmi_clk_n,
   output bus3_t hdmi_dat_p,
   output bus3_t hdmi_dat_n,

// aktivno-niski LED indikatori
   output logic  led_n,       // treperi ravnomjerno - pokazuje da je igra "ziva"
   output logic  led_hit_n,   // pali se iskljucivo pri sudaru sa preprekom

// DIJAGNOSTICKI bar-graf (3 diode, privremeno -- za brzu provjeru da
// ADS1115 uopste vraca vrijednosti; kad se potvrdi da sve radi, mogu se
// slobodno ukloniti, zajedno sa .cst unosima).
//   led_dbg_n[0], led_dbg_n[1] -> prag sirove magnitude ocitanja (kao ranije)
//   led_dbg_n[2] -> "otkucaj srca" I2C FSM-a: mijenja stanje SVAKI PUT kada
//                   se zavrsi transakcija (transaction_done). Ako OVA dioda
//                   uopste ne treperi, I2C protokol se nikad ne zavrsi (npr.
//                   ACK od ADS1115-a nikad ne stigne -- fizicki I2C problem).
//                   Ako TREPERI, ali led_dbg_n[0]/[1] i dalje nikad ne
//                   svijetle, I2C RADI ali dzojstik/AIN0 vraca vrijednost
//                   blizu 0 -- vjerovatno fizicko/naponsko pitanje na Y osi.
   output logic [2:0] led_dbg_n
);

   logic   clk_pix, srst_n;
   logic   frame_done;
   logic   mfram_done;

   bus12_t x, y;
   pix_t   pix;

//-----------------------------------------------------------
// Loptica: X pozicija FIKSNA (kao u originalnoj igrici), Y pozicija se
// pomjera dzojstikom (ranije: tasterima butnL_n/butnR_n).
//-----------------------------------------------------------
   localparam bus12_t BALL_R      = 12'd16;   // poluprecnik (~sqrt(250))

   localparam bus12_t BALL_X_INIT = 12'd640;  // fiksna X pozicija (sredina ekrana)

   localparam bus12_t BALL_Y_MIN  = 12'd20;
   localparam bus12_t BALL_Y_MAX  = 12'd700;
   localparam bus12_t BALL_Y_INIT = 12'd360;

   bus12_t ball_y; // trenutna (jedina promjenljiva) pozicija loptice
   localparam bus12_t ball_x = BALL_X_INIT; // fiksno, radi kompatibilnosti sa nizim kodom

//-----------------------------------------------------------
// Prepreka: vertikalni zid sirine OBST_WIDTH, sa prorezom
// visine GAP_HEIGHT. Pomjera se udesno-ulijevo brzinom
// OBST_SPEED piksela po prikazanom okviru (60 puta u sekundi).
// Kada izadje van lijeve ivice, ponovo se pojavljuje desno,
// sa novom (unaprijed pripremljenom) pozicijom proreza.
// (Nepromijenjeno u odnosu na originalnu igricu.)
//-----------------------------------------------------------
   localparam bus12_t OBST_WIDTH  = 12'd40;
   localparam bus12_t OBST_SPEED  = 12'd6;
   localparam bus12_t GAP_HEIGHT  = 12'd200;

   bus12_t     obst_x;   // trenutna X pozicija lijeve ivice prepreke
   bus12_t     gap_y;    // trenutna Y pozicija vrha proreza
   logic [1:0] gap_sel;  // redni broj trenutne pozicije proreza (0-3)

   function automatic bus12_t gap_preset(input logic [1:0] sel);
      case (sel)
         2'd0:    gap_preset = 12'd60;
         2'd1:    gap_preset = 12'd220;
         2'd2:    gap_preset = 12'd380;
         default: gap_preset = 12'd500;
      endcase
   endfunction

   logic obst_here; // da li se prepreka nalazi na trenutnoj X poziciji piksela
   logic in_gap;     // da li se trenutni piksel nalazi unutar proreza
   logic hit;        // da li se loptica trenutno sudara sa preprekom

//-----------------------------------------------------------
// Color generation: loptica ima prioritet iscrtavanja, zatim
// prepreka (zeleni zid), a u ostatku je pozadina jednobojna plava.
//-----------------------------------------------------------
  always_comb begin: _my_game
     obst_here = (x >= obst_x) && (x < obst_x + OBST_WIDTH);
     in_gap    = (y >= gap_y)  && (y < gap_y + GAP_HEIGHT);

     if ((x-ball_x)*(x-ball_x)+(y-ball_y)*(y-ball_y)<=250) begin
        pix.R = '1;  // loptica - crvena
        pix.G = '0;
        pix.B = '0;
     end
     else if (obst_here && !in_gap) begin
        pix.R = '0;  // prepreka - zelena
        pix.G = '1;
        pix.B = '0;
     end
     else begin
        pix.R = '0;  // pozadina - plava
        pix.G = '0;
        pix.B = '1;
     end
  end: _my_game

//-----------------------------------------------------------
// Detekcija sudara: jednostavna provjera na nivou pravougaonika/
// intervala (ne piksel-po-piksel), dovoljno precizna za igru.
//-----------------------------------------------------------
   always_comb begin: _collision_check
      hit = (obst_x <= ball_x + BALL_R)
          & (obst_x + OBST_WIDTH > ball_x - BALL_R)
          & ~( (ball_y >= gap_y + BALL_R) & (ball_y + BALL_R <= gap_y + GAP_HEIGHT) );
   end: _collision_check

//-----------------------------------------------------------
// HDMI Backend: 1280x720P@60Hz display renderer (nepromijenjeno)
//-----------------------------------------------------------
   hdmi_backend u_hdmi_backend (
      .clk_ext    (clk_ext),    //i
      .clk_pix    (clk_pix),    //o
      .srst_n     (srst_n),     //o

    // Current X and Y position of the pixel
      .hcount     (x),          //o[11:0]
      .vcount     (y),          //o[11:0]
      .pix        (pix),        //i[7:0].R/G/B

    //Pulse1 when done rendering:
      .frame_done (frame_done), //o
      .mfram_done (mfram_done), //o

      .hdmi_clk_p (hdmi_clk_p), //o
      .hdmi_clk_n (hdmi_clk_n), //o
      .hdmi_dat_p (hdmi_dat_p), //o[2:0]
      .hdmi_dat_n (hdmi_dat_n)  //o[2:0]
   );

//-----------------------------------------------------------
// Pomjeranje prepreke - jednom po svakom prikazanom okviru (60Hz)
// (Nepromijenjeno u odnosu na originalnu igricu.)
//-----------------------------------------------------------
   always_ff @(negedge srst_n or posedge clk_pix) begin: _obstacle_mov
      if (srst_n == LO) begin
         obst_x  <= 12'(HSCREEN) + OBST_WIDTH; // pocinje van desne ivice ekrana
         gap_y   <= gap_preset(2'd0);
         gap_sel <= 2'd0;
      end
      else if (frame_done == HI) begin
         if (obst_x <= OBST_SPEED) begin
            gap_sel <= gap_sel + 2'd1;
            gap_y   <= gap_preset(gap_sel + 2'd1);
            obst_x  <= 12'(HSCREEN) + OBST_WIDTH;
         end
         else begin
            obst_x <= obst_x - OBST_SPEED;
         end
      end
   end: _obstacle_mov

//-----------------------------------------------------------
// LED (led_n) treperi ravnomjerno jednom u MFRAM_CNT_MAX prikazanih
// okvira, nezavisno od sudara i od dzojstika. (Nepromijenjeno.)
//-----------------------------------------------------------
   always_ff @(negedge srst_n or posedge clk_pix) begin: _led_mon
      if (srst_n == LO) begin
         led_n <= HI;
      end
      else if (mfram_done == HI) begin
         led_n <= ~led_n;
      end
   end: _led_mon

//-----------------------------------------------------------
// Posebna LED (led_hit_n) iskljucivo za signalizaciju sudara.
// (Nepromijenjeno.)
//-----------------------------------------------------------
   always_ff @(negedge srst_n or posedge clk_pix) begin: _hit_led
      if (srst_n == LO) begin
         led_hit_n <= HI;
      end
      else begin
         led_hit_n <= hit ? LO : HI;
      end
   end: _hit_led

//=============================================================
// I2C / ADS1115 / dzojstik dio -- IDENTICNO LV4-u (jedan kanal, AIN0,
// PGA=+-2.048V), radi u domenu takta clk_ext (27MHz). Jedina razlika u
// odnosu na LV4: rezultat se, umjesto na LED bargraf, preslikava u
// brzinu/pravac pomjeranja loptice po Y osi, i prenosi se u clk_pix
// domen preko dvostrukog flip-flop sinhronizatora (_cdc_sync_pix nize).
//=============================================================
   logic [26:0] brojac_i2c;
   logic strobe_400kHz;

   always_ff @(negedge areset_n or posedge clk_ext) begin
      if (areset_n == 1'b0) begin
         brojac_i2c    <= 27'd0;
         strobe_400kHz <= 1'b0;
      end else begin
         brojac_i2c <= brojac_i2c + 27'd1;
         if (brojac_i2c == 27'd68) begin
            strobe_400kHz <= 1'b1;
            brojac_i2c    <= 27'd0;
         end else begin
            strobe_400kHz <= 1'b0;
         end
      end
   end

   logic transaction_done;
   logic [15:0] result_16;
   logic scl_oe, scl_di, sda_oe, sda_di;

   i2c_ctrl u_i2c_ads1115 (
       .clk              (clk_ext),
       .strobe_400kHz    (strobe_400kHz),
       .areset_n         (areset_n),
       .start_transaction(1'b1),
       .pause_duration   (16'hFFFF),   // isto kao LV4 (~167ms/citanje)
       .transaction_done (transaction_done),
       .scl_oe           (scl_oe),
       .scl_di           (scl_di),
       .sda_oe           (sda_oe),
       .sda_di           (sda_di),
       .result_16        (result_16)
   );

   assign i2c_scl = scl_oe ? 1'b0 : 1'bz;
   assign scl_di  = i2c_scl;

   assign i2c_sda = sda_oe ? 1'b0 : 1'bz;
   assign sda_di  = i2c_sda;

//-----------------------------------------------------------
// Isto kao u LV4: negativni kodovi (sum blizu 0V) se odsijecaju na 0,
// da se ne bi pogresno protumacili kao veliki pozitivni broj.
//-----------------------------------------------------------
   logic [15:0] adc_mag;
   assign adc_mag = result_16[15] ? 16'd0 : result_16;

//-----------------------------------------------------------
// DIJAGNOSTICKI bar-graf (2 diode): direktno pokazuje sirovu magnitudu
// ocitanja, potpuno nezavisno od igrice i od dalje logike (deadzone,
// pragovi brzine, CDC...). Ako ove diode uopste ne reaguju na pomjeranje
// dzojstika, problem je u samoj I2C komunikaciji.
//-----------------------------------------------------------
   logic [2:0] led_dbg;
   assign led_dbg[0] = (adc_mag >= 16'd10000);
   assign led_dbg[1] = (adc_mag >= 16'd22000);

   // "Otkucaj srca" I2C FSM-a -- mijenja stanje pri svakom transaction_done
   // pulsu (ima ih dva po punom ciklusu citanja: jedan nakon upisa
   // konfiguracije, jedan na kraju citanja). Ako I2C protokol stvarno radi,
   // ova dioda vidljivo treperi (perioda ~167ms x 2 = otprilike 3 treptaja
   // u sekundi); ako je I2C zaglavljen (npr. ACK nikad ne stigne), ostaje
   // trajno u jednom stanju.
   logic i2c_heartbeat;
   always_ff @(negedge areset_n or posedge clk_ext) begin
      if (areset_n == 1'b0) begin
         i2c_heartbeat <= 1'b0;
      end else if (transaction_done) begin
         i2c_heartbeat <= ~i2c_heartbeat;
      end
   end
   assign led_dbg[2] = i2c_heartbeat;

   assign led_dbg_n  = ~led_dbg; // onboard diode su aktivno-niske

//-----------------------------------------------------------
// Preslikavanje ADC koda u brzinu/pravac pomjeranja loptice: mrtva zona
// (deadzone) oko sredisnjeg polozaja dzojstika sprijecava da sitan sum
// pomjera lopticu kad dzojstik miruje; van mrtve zone, dvije brzine
// (spora/brza) biraju se prema otklonu od centra.
//
// JOY_CENTER je teorijska sredina za PGA=+-2.048V i napajanje dzojstika
// sa 3.3V (V_sredina=1.65V): kod = 1.65V * (32768/2.048V) = 26400.
// PAZNJA: za PGA=+-2.048V, ADC se zasicuje (na kodu 32767) vec na
// V=2.048V -- dzojstik pomjeren "gore" preko toga i dalje ispravno
// pokazuje maksimalan pozitivan otklon (samo bez dodatne granularnosti
// iznad te tacke), sto je za dvo-brzinsko upravljanje (spora/brza)
// sasvim dovoljno i ne pravi razliku u ponasanju igre.
//-----------------------------------------------------------
   localparam logic signed [16:0] JOY_CENTER  = 17'sd26400;
   localparam logic        [15:0] DEADZONE    = 16'd800;
   localparam logic        [15:0] FAST_THRESH = 16'd4000;
   localparam logic signed [ 4:0] STEP_SLOW   = 5'sd3;
   localparam logic signed [ 4:0] STEP_FAST   = 5'sd9;

   logic signed [16:0] diff_y;
   assign diff_y = $signed({1'b0, adc_mag}) - JOY_CENTER;

   logic [15:0] adiff_y; // apsolutna udaljenost od centra

   assign adiff_y = diff_y[16] ? 16'(-diff_y) : 16'(diff_y);

   logic signed [4:0] step_y_comb;

   always_comb begin
      if (adiff_y < DEADZONE) begin
         step_y_comb = 5'sd0;
      end else if (adiff_y < FAST_THRESH) begin
         step_y_comb = diff_y[16] ? -STEP_SLOW : STEP_SLOW;
      end else begin
         step_y_comb = diff_y[16] ? -STEP_FAST : STEP_FAST;
      end
   end

   // Registruje se u clk_ext domenu prije prelaska u clk_pix domen,
   // sto je standardna CDC praksa (izbjegava se sinhronizacija
   // "sirove" kombinacione logike).
   logic signed [4:0] step_y_ext;

   always_ff @(negedge areset_n or posedge clk_ext) begin
      if (areset_n == 1'b0) begin
         step_y_ext <= 5'sd0;
      end else begin
         step_y_ext <= step_y_comb;
      end
   end

//-----------------------------------------------------------
// CDC: dvostruki flip-flop sinhronizator iz clk_ext u clk_pix domen.
//-----------------------------------------------------------
   logic signed [4:0] step_y_sync0, step_y_sync;

   always_ff @(negedge srst_n or posedge clk_pix) begin: _cdc_sync_pix
      if (srst_n == LO) begin
         step_y_sync0 <= 5'sd0;
         step_y_sync  <= 5'sd0;
      end else begin
         step_y_sync0 <= step_y_ext;
         step_y_sync  <= step_y_sync0;
      end
   end: _cdc_sync_pix

//-----------------------------------------------------------
// Pomjeranje loptice dzojstikom (samo Y osa) - jednom po svakom
// prikazanom okviru (60Hz), sa zasicenjem na granicama igraceg polja.
//-----------------------------------------------------------
   always_ff @(negedge srst_n or posedge clk_pix) begin: _ball_mov
      if (srst_n == LO) begin
         ball_y <= BALL_Y_INIT;
      end
      else if (frame_done == HI) begin
         if (step_y_sync > 5'sd0) begin
            if (ball_y < BALL_Y_MAX - 12'(step_y_sync))
               ball_y <= ball_y + 12'(step_y_sync);
            else
               ball_y <= BALL_Y_MAX;
         end
         else if (step_y_sync < 5'sd0) begin
            if (ball_y > BALL_Y_MIN + 12'(-step_y_sync))
               ball_y <= ball_y - 12'(-step_y_sync);
            else
               ball_y <= BALL_Y_MIN;
         end
      end
   end: _ball_mov

endmodule: top

/*
------------------------------------------------------------------------------
Version History:
------------------------------------------------------------------------------
 2022/10/9 JI: initial creation
 Dodatak: pokretna prepreka sa prorezom + detekcija sudara (LED upozorenje)
 Dodatak: upravljanje lopticom (X i Y) putem analognog dzojstika preko
          ADS1115 I2C ADC-a -- NIKAD nije proradilo na hardveru.
 Pojednostavljenje: samo JEDNA osa dzojstika (Y), ista I2C konfiguracija
          kao dokazano ispravna LV4 verzija (AIN0, PGA=+-2.048V,
          areset_n = fizicko dugme S1, i2c_ctrl.sv bez izmjena).
*/
