// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vmealy_automat.h for the primary calling header

#ifndef VERILATED_VMEALY_AUTOMAT___024ROOT_H_
#define VERILATED_VMEALY_AUTOMAT___024ROOT_H_  // guard

#include "verilated.h"


class Vmealy_automat__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vmealy_automat___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(Cp,0,0);
    VL_IN8(reset,0,0);
    VL_IN8(U,0,0);
    VL_OUT8(Z,1,0);
    VL_OUT8(stanje,1,0);
    CData/*1:0*/ mealy_automat__DOT__sljed_stanje;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __VicoFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__Cp__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__reset__0;
    CData/*0:0*/ __VactContinue;
    IData/*31:0*/ __VactIterCount;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<2> __VactTriggered;
    VlTriggerVec<2> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vmealy_automat__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vmealy_automat___024root(Vmealy_automat__Syms* symsp, const char* v__name);
    ~Vmealy_automat___024root();
    VL_UNCOPYABLE(Vmealy_automat___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
