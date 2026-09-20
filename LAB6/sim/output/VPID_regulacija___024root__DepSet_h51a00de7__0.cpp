// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VPID_regulacija.h for the primary calling header

#include "VPID_regulacija__pch.h"
#include "VPID_regulacija__Syms.h"
#include "VPID_regulacija___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void VPID_regulacija___024root___dump_triggers__ico(VPID_regulacija___024root* vlSelf);
#endif  // VL_DEBUG

void VPID_regulacija___024root___eval_triggers__ico(VPID_regulacija___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPID_regulacija___024root___eval_triggers__ico\n"); );
    VPID_regulacija__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VicoTriggered.setBit(0U, (IData)(vlSelfRef.__VicoFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        VPID_regulacija___024root___dump_triggers__ico(vlSelf);
    }
#endif
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VPID_regulacija___024root___dump_triggers__act(VPID_regulacija___024root* vlSelf);
#endif  // VL_DEBUG

void VPID_regulacija___024root___eval_triggers__act(VPID_regulacija___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPID_regulacija___024root___eval_triggers__act\n"); );
    VPID_regulacija__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered.setBit(0U, ((~ (IData)(vlSelfRef.areset)) 
                                          & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__areset__0)));
    vlSelfRef.__VactTriggered.setBit(1U, ((IData)(vlSelfRef.clk) 
                                          & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__clk__0))));
    vlSelfRef.__Vtrigprevexpr___TOP__areset__0 = vlSelfRef.areset;
    vlSelfRef.__Vtrigprevexpr___TOP__clk__0 = vlSelfRef.clk;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        VPID_regulacija___024root___dump_triggers__act(vlSelf);
    }
#endif
}
