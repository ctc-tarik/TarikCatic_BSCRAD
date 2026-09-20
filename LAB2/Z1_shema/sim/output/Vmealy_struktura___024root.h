// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vmealy_struktura.h for the primary calling header

#ifndef VERILATED_VMEALY_STRUKTURA___024ROOT_H_
#define VERILATED_VMEALY_STRUKTURA___024ROOT_H_  // guard

#include "verilated.h"


class Vmealy_struktura__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vmealy_struktura___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(Cp,0,0);
    VL_IN8(reset,0,0);
    VL_IN8(U,0,0);
    VL_OUT8(Z,1,0);
    VL_OUT8(stanje,1,0);
    CData/*0:0*/ mealy_struktura__DOT__Q1;
    CData/*0:0*/ mealy_struktura__DOT__Q0;
    CData/*0:0*/ mealy_struktura__DOT__T1;
    CData/*0:0*/ mealy_struktura__DOT__T2;
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
    Vmealy_struktura__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vmealy_struktura___024root(Vmealy_struktura__Syms* symsp, const char* v__name);
    ~Vmealy_struktura___024root();
    VL_UNCOPYABLE(Vmealy_struktura___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
