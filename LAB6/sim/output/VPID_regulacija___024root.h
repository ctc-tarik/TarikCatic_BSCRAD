// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VPID_regulacija.h for the primary calling header

#ifndef VERILATED_VPID_REGULACIJA___024ROOT_H_
#define VERILATED_VPID_REGULACIJA___024ROOT_H_  // guard

#include "verilated.h"


class VPID_regulacija__Syms;

class alignas(VL_CACHE_LINE_BYTES) VPID_regulacija___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(areset,0,0);
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __VicoFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__areset__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
    CData/*0:0*/ __VactContinue;
    VL_OUT16(u_out,14,0);
    VL_IN16(e_in,15,0);
    SData/*15:0*/ PID_regulacija__DOT__u_prev;
    SData/*15:0*/ PID_regulacija__DOT__e_prev;
    SData/*15:0*/ PID_regulacija__DOT__e_prev1;
    IData/*31:0*/ __VactIterCount;
    QData/*35:0*/ PID_regulacija__DOT__d_reg;
    QData/*35:0*/ PID_regulacija__DOT__d_wire;
    VlUnpacked<CData/*0:0*/, 2> __Vm_traceActivity;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<2> __VactTriggered;
    VlTriggerVec<2> __VnbaTriggered;

    // INTERNAL VARIABLES
    VPID_regulacija__Syms* const vlSymsp;

    // CONSTRUCTORS
    VPID_regulacija___024root(VPID_regulacija__Syms* symsp, const char* v__name);
    ~VPID_regulacija___024root();
    VL_UNCOPYABLE(VPID_regulacija___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
