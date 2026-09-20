module top (
    input  logic clk,         // Tang Nano 9K onboard 27 MHz oscillator -> pin 52
    input  logic areset_n,    // active-low reset button (S1)           -> pin 4

    inout  wire  i2c_scl,     // to ADS1115 SCL (needs an external/onboard pull-up, ADS1115 VDD = 3.3V!)
    inout  wire  i2c_sda,     // to ADS1115 SDA (needs an external/onboard pull-up, ADS1115 VDD = 3.3V!)

    output logic [5:0] led    // onboard LEDs, active-low -> pins 10,11,13,14,15,16
);

    // ------------------------------------------------------------------
    // ~400 kHz strobe that paces the I2C bit-banging FSM (unchanged)
    // ------------------------------------------------------------------
    logic [26:0] brojac;
    logic strobe_400kHz;

    always_ff @(negedge areset_n or posedge clk) begin
        if (areset_n == 1'b0) begin
            brojac        <= 27'd0;
            strobe_400kHz <= 1'b0;
        end else begin
            brojac <= brojac + 27'd1;
            if (brojac == 27'd68) begin
                strobe_400kHz <= 1'b1;
                brojac        <= 27'd0;
            end else begin
                strobe_400kHz <= 1'b0;
            end
        end
    end

    // ------------------------------------------------------------------
    // ADS1115 read: single-ended AIN0 vs GND, PGA = +-2.048V, single-shot.
    // start_transaction is tied high so it re-triggers continuously,
    // i.e. it just keeps polling the potentiometer forever.
    // ------------------------------------------------------------------
    logic transaction_done;
    logic [15:0] result_16;

    logic scl_oe, scl_di, sda_oe, sda_di;

    i2c_ctrl u_i2c_ads1115 (
        .clk              (clk),
        .strobe_400kHz    (strobe_400kHz),
        .areset_n         (areset_n),
        .start_transaction(1'b1),
        .pause_duration   (16'hFFFF),
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

    // ------------------------------------------------------------------
    // ADC code -> 6-LED bargraph
    //
    // result_16 is the ADS1115's signed 16-bit conversion code. A single-
    // ended reading vs GND should always be >= 0, but noise near 0V can
    // occasionally produce a small negative code; treated as unsigned
    // that would wrap to a huge value and wrongly light every LED at the
    // minimum voltage. So negative codes are clamped to 0 first.
    // ------------------------------------------------------------------
    logic [15:0] adc_mag;
    assign adc_mag = result_16[15] ? 16'd0 : result_16;

    // The potentiometer AND the ADS1115 are both powered from the FPGA
    // board's 3V3 pin (not 5V!), so the wiper can never exceed ~3.3V --
    // safely below the ADS1115's absolute-max analog input (~VDD+0.3V)
    // and safe to wire straight into AIN0, no divider needed.
    // u_i2c_ads1115's PGA is set to +-2.048V, so the ADC still saturates
    // at its max code (32767) well before the pot reaches its physical
    // maximum. Net effect: 0V on the pot -> code 0 -> all LEDs off, and
    // the pot's maximum (3.3V) -> full scale -> all LEDs on.
    localparam logic [15:0] TH1 = 16'd5461;   // 1/6 of full scale
    localparam logic [15:0] TH2 = 16'd10922;  // 2/6
    localparam logic [15:0] TH3 = 16'd16384;  // 3/6
    localparam logic [15:0] TH4 = 16'd21845;  // 4/6
    localparam logic [15:0] TH5 = 16'd27306;  // 5/6
    localparam logic [15:0] TH6 = 16'd32767;  // 6/6 (full scale)

    logic [5:0] led_on;

    assign led_on[0] = (adc_mag >= TH1);
    assign led_on[1] = (adc_mag >= TH2);
    assign led_on[2] = (adc_mag >= TH3);
    assign led_on[3] = (adc_mag >= TH4);
    assign led_on[4] = (adc_mag >= TH5);
    assign led_on[5] = (adc_mag >= TH6);

    assign led = ~led_on;   // onboard LEDs are active-low (0 = lit)

endmodule