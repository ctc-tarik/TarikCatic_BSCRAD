// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vmoore_struktura.h for the primary calling header

#ifndef VERILATED_VMOORE_STRUKTURA___024ROOT_H_
#define VERILATED_VMOORE_STRUKTURA___024ROOT_H_  // guard

#include "verilated.h"


class Vmoore_struktura__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vmoore_struktura___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(Cp,0,0);
    VL_IN8(reset,0,0);
    VL_IN8(U,0,0);
    VL_OUT8(Z,0,0);
    VL_OUT8(stanje,1,0);
    CData/*0:0*/ moore_struktura__DOT__Q1;
    CData/*0:0*/ moore_struktura__DOT__Q0;
    CData/*0:0*/ moore_struktura__DOT__T1;
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
    Vmoore_struktura__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vmoore_struktura___024root(Vmoore_struktura__Syms* symsp, const char* v__name);
    ~Vmoore_struktura___024root();
    VL_UNCOPYABLE(Vmoore_struktura___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
