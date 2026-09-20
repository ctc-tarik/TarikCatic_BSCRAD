// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vzad2.h for the primary calling header

#ifndef VERILATED_VZAD2___024ROOT_H_
#define VERILATED_VZAD2___024ROOT_H_  // guard

#include "verilated.h"


class Vzad2__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vzad2___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(A,0,0);
    VL_IN8(B,0,0);
    VL_IN8(C,0,0);
    VL_IN8(D,0,0);
    VL_IN8(E,0,0);
    VL_OUT8(Y,0,0);
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __VicoFirstIteration;
    CData/*0:0*/ __VactContinue;
    IData/*31:0*/ __VactIterCount;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<0> __VactTriggered;
    VlTriggerVec<0> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vzad2__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vzad2___024root(Vzad2__Syms* symsp, const char* v__name);
    ~Vzad2___024root();
    VL_UNCOPYABLE(Vzad2___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
