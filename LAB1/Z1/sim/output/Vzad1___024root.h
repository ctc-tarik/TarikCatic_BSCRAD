// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vzad1.h for the primary calling header

#ifndef VERILATED_VZAD1___024ROOT_H_
#define VERILATED_VZAD1___024ROOT_H_  // guard

#include "verilated.h"


class Vzad1__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vzad1___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(A,0,0);
    VL_IN8(B,0,0);
    VL_IN8(C,0,0);
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
    Vzad1__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vzad1___024root(Vzad1__Syms* symsp, const char* v__name);
    ~Vzad1___024root();
    VL_UNCOPYABLE(Vzad1___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
