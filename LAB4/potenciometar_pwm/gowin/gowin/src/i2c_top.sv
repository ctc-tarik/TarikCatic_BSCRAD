module top (
    input  logic clk,         // Tang Nano 9K onboard 27 MHz oscillator -> pin 52
    input  logic areset_n,    // active-low reset button (S1)           -> pin 4

    inout  wire  i2c_scl,     // to ADS1115 SCL (needs an external/onboard pull-up)
    inout  wire  i2c_sda,     // to ADS1115 SDA (needs an external/onboard pull-up)

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
    // Unchanged from the bargraph version -- same wiring (pot + ADS1115
    // both on 3.3V, wiper straight into A0, no divider).
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
    // ADC code -> 8-bit PWM duty cycle (LED brightness)
    // ------------------------------------------------------------------
    // Clamp a stray negative code (noise near 0V) to 0, same reasoning
    // as in the bargraph version.
    logic [15:0] adc_mag;
    assign adc_mag = result_16[15] ? 16'd0 : result_16;

    // Take the top 8 bits of the 15-bit magnitude as an 8-bit brightness
    // value (0..255). Because the ADC saturates at its max code (32767)
    // before the pot reaches its physical maximum (see top.sv notes from
    // the bargraph version), duty reliably hits 255 (~full brightness) at
    // the pot's true maximum, and 0 (fully off) at its minimum.
    logic [7:0] duty;
    assign duty = adc_mag[14:7];

    // Free-running 8-bit counter -> PWM period = 256 clk cycles.
    // At 27 MHz that's a ~105 kHz PWM frequency: far above anything the
    // eye (or the LED) could perceive as flicker, so it just looks like a
    // steady, continuously variable brightness.
    logic [7:0] pwm_cnt;

    always_ff @(negedge areset_n or posedge clk) begin
        if (areset_n == 1'b0) begin
            pwm_cnt <= 8'd0;
        end else begin
            pwm_cnt <= pwm_cnt + 8'd1;
        end
    end

    logic pwm_on;
    assign pwm_on = (pwm_cnt < duty);   // '1' for `duty` out of every 256 cycles

    // Drive all 6 onboard LEDs together so they dim/brighten as one; they
    // are active-low, so "on" (pwm_on=1) means driving the pin low.
    assign led = {6{~pwm_on}};

endmodule