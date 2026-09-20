///////////////////////////////////////////////////////////////////////////////
//
// (c) Copyright 2022 -- CHILI CHIPS LLC, All rights reserved.
//
//                      PROPRIETARY INFORMATION
//
// The information contained in this file is the property of CHILI CHIPS LLC.
// Except as specifically authorized in writing by CHILI CHIPS LLC, the holder
// of this file: (1) shall keep all information contained herein confidential;
// and (2) shall protect the same in whole or in part from disclosure and
// dissemination to all third parties; and (3) shall use the same for operation
// and maintenance purposes only.
//-----------------------------------------------------------------------------
// Top level of a future full video game. It instantiates:
//   1) video back-end that generates pixel clock and renders the screen
//   2) video front-end that creates the game 
// Also included is LED activity monitor which mimics game speed / difficulty.
//
// RTL is written in a way that facilitates porting to different FPGA platforms.
// Tested with:
//  1) Xilinx Artix7    (XC7A35T-1CPG236) on Digilent Cmod A7-35T, 24MHz ext.clock
//  2) GoWin  LittleBee (GW1NR-9C)        on Sipeed   TangNano-9K, 27MHz ext.clock
///////////////////////////////////////////////////////////////////////////////

module top 
   import hdmi_pkg::*;
(
   input  logic  clk_ext, // External clock: GoWin=27MHz; Artix7=24MHz

   input  logic  butnL_n, // moveUp   button -\ they return 0
   input  logic  butnR_n, // moveDown button -/  when pressed

 //HDMI output, goes directly to connector
   output logic  hdmi_clk_p,
   output logic  hdmi_clk_n,
   output bus3_t hdmi_dat_p,
   output bus3_t hdmi_dat_n,

// active-low LED monitors
   output logic  led_n,     // treperi ravnomjerno - pokazuje da je igra "ziva"
   output logic  led_hit_n  // pali se iskljucivo pri sudaru sa preprekom
);

   logic   clk_pix, srst_n;
   logic   frame_done;
   logic   mfram_done;

   bus12_t x, y;
   pix_t   pix;

//-----------------------------------------------------------
// Loptica: fiksna horizontalna pozicija (sredina ekrana),
// vertikalna pozicija se mijenja dugmadima.
//-----------------------------------------------------------
   localparam bus12_t BALL_X      = 12'd640;  // fiksni horizontalni centar
   localparam bus12_t BALL_R      = 12'd16;   // poluprecnik (~sqrt(250))
   localparam bus12_t BALL_Y_MIN  = 12'd20;
   localparam bus12_t BALL_Y_MAX  = 12'd700;
   localparam bus12_t BALL_Y_INIT = 12'd360;
   localparam bus12_t BALL_STEP   = 12'd10;

   bus12_t brojac; // trenutna vertikalna pozicija loptice

//-----------------------------------------------------------
// Prepreka: vertikalni zid sirine OBST_WIDTH, sa prorezom
// visine GAP_HEIGHT. Pomjera se udesno-ulijevo brzinom
// OBST_SPEED piksela po prikazanom okviru (60 puta u sekundi).
// Kada izadje van lijeve ivice, ponovo se pojavljuje desno,
// sa novom (unaprijed pripremljenom) pozicijom proreza.
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

     if ((x-BALL_X)*(x-BALL_X)+(y-brojac)*(y-brojac)<=250) begin
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
// Sudar postoji ako se prepreka horizontalno preklapa sa lopticom
// I loptica pritom NIJE u potpunosti unutar proreza.
//-----------------------------------------------------------
   always_comb begin: _collision_check
      hit = (obst_x <= BALL_X + BALL_R)
          & (obst_x + OBST_WIDTH > BALL_X - BALL_R)
          & ~( (brojac >= gap_y + BALL_R) & (brojac + BALL_R <= gap_y + GAP_HEIGHT) );
   end: _collision_check

//-----------------------------------------------------------
// HDMI Backend: 1290x720P@60Hz display renderer
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
// Pomjeranje loptice dugmadima. LED (led_n) treperi ravnomjerno
// jednom u MFRAM_CNT_MAX prikazanih okvira, nezavisno od sudara.
//-----------------------------------------------------------
   always_ff @(negedge srst_n or posedge clk_pix) begin: _led_mon
      if (srst_n == LO) begin
         led_n  <= HI;
         brojac <= BALL_Y_INIT;
      end
      else begin
         if (mfram_done == HI) begin
            led_n <= ~led_n;
         end

         if (frame_done == HI) begin
            if (butnL_n == LO) begin
               if (brojac > BALL_Y_MIN + BALL_STEP)
                  brojac <= brojac - BALL_STEP;
               else
                  brojac <= BALL_Y_MIN;
            end
            else if (butnR_n == LO) begin
               if (brojac < BALL_Y_MAX - BALL_STEP)
                  brojac <= brojac + BALL_STEP;
               else
                  brojac <= BALL_Y_MAX;
            end
         end
      end
   end: _led_mon

//-----------------------------------------------------------
// Posebna LED (led_hit_n) iskljucivo za signalizaciju sudara -
// upaljena tacno onoliko dugo koliko traje preklapanje loptice
// i prepreke, potpuno nezavisno od led_n treperenja.
//-----------------------------------------------------------
   always_ff @(negedge srst_n or posedge clk_pix) begin: _hit_led
      if (srst_n == LO) begin
         led_hit_n <= HI;
      end
      else begin
         led_hit_n <= hit ? LO : HI;
      end
   end: _hit_led
   
endmodule: top

/*
------------------------------------------------------------------------------
Version History:
------------------------------------------------------------------------------
 2022/10/9 JI: initial creation    
 Dodatak: pokretna prepreka sa prorezom + detekcija sudara (LED upozorenje)
*/