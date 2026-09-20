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

// active-low LED monitor
   output logic  led_n 
);

   logic   clk_pix, srst_n;
   logic   frame_done;
   logic   mfram_done;

   bus12_t x, y;
   pix_t   pix;

// Vertikalna pozicija centra loptice. Opseg je ogranicen na [BALL_Y_MIN, BALL_Y_MAX]
// kako bi loptica ostala potpuno vidljiva i kako ne bi doslo do neocekivanog
// "skoka" usljed prekoracenja (wraparound) 12-bitnog registra.
   localparam bus12_t BALL_Y_MIN  = 12'd20;   // gornja granica kretanja
   localparam bus12_t BALL_Y_MAX  = 12'd700;  // donja granica kretanja
   localparam bus12_t BALL_Y_INIT = 12'd360;  // pocetna pozicija - sredina ekrana (VSCREEN/2)
   localparam bus12_t BALL_STEP   = 12'd10;   // korak pomjeranja po jednom updateu

   bus12_t brojac;

//-----------------------------------------------------------
// Color generation algorithm: Based on the X,Y screen coordinates,
// set colors as you wish, or your imagination whispers to your ear
//    24'h00_00_00 is pitch-black 
//    24'hFF_FF_FF is bright-white
//
//   [2]=Red, [1]=Green, [0]=Blue
//
// Resolution is 1280x720Px60Hz, thus:
//    max visible X=1279 [10:0]
//    max visible Y= 719 [9:0]
//-----------------------------------------------------------
  always_comb begin: _my_game
     // Crvena loptica poluprecnika ~sqrt(250)=15.8px, centrirana u (640, brojac).
     // Van kruga, pozadina je jednobojna plava.
     if ((x-640)*(x-640)+(y-brojac)*(y-brojac)<=250) begin
        pix.R = '1;
        pix.G = '0;
        pix.B = '0;
     end
     else begin
        pix.R = '0;
        pix.G = '0;
        pix.B = '1;
     end
  end: _my_game
   

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
// LED monitor of game update speed is also provided
// For the light to be seen, convert from narrow Pulse1 to 50% duty cycle
//-----------------------------------------------------------
   always_ff @(negedge srst_n or posedge clk_pix) begin: _led_mon
      if (srst_n == LO) begin
         led_n  <= HI;
         brojac <= BALL_Y_INIT;
      end
      else begin
         if (mfram_done == HI) begin
            led_n <= ~led_n;

         // Pomjeranje gore/dole, uz zaustavljanje na granicama umjesto
         // nekontrolisanog prekoracenja (wraparound) registra.
            if (butnL_n == LO) begin
               if (brojac > BALL_Y_MIN + BALL_STEP)
                  brojac <= brojac - BALL_STEP;   // gore
               else
                  brojac <= BALL_Y_MIN;
            end
            else if (butnR_n == LO) begin
               if (brojac < BALL_Y_MAX - BALL_STEP)
                  brojac <= brojac + BALL_STEP;   // dole
               else
                  brojac <= BALL_Y_MAX;
            end
         end
      end
   end: _led_mon
   
endmodule: top

/*
------------------------------------------------------------------------------
Version History:
------------------------------------------------------------------------------
 2022/10/9 JI: initial creation    
 Ispravka: pocetna pozicija loptice i granice kretanja (izbjegava wraparound)
*/