// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vmoore_struktura.h for the primary calling header

#include "Vmoore_struktura__pch.h"
#include "Vmoore_struktura__Syms.h"
#include "Vmoore_struktura___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vmoore_struktura___024root___dump_triggers__ico(Vmoore_struktura___024root* vlSelf);
#endif  // VL_DEBUG

void Vmoore_struktura___024root___eval_triggers__ico(Vmoore_struktura___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmoore_struktura___024root___eval_triggers__ico\n"); );
    Vmoore_struktura__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VicoTriggered.setBit(0U, (IData)(vlSelfRef.__VicoFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vmoore_struktura___024root___dump_triggers__ico(vlSelf);
    }
#endif
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vmoore_struktura___024root___dump_triggers__act(Vmoore_struktura___024root* vlSelf);
#endif  // VL_DEBUG

void Vmoore_struktura___024root___eval_triggers__act(Vmoore_struktura___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmoore_struktura___024root___eval_triggers__act\n"); );
    Vmoore_struktura__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered.setBit(0U, ((IData)(vlSelfRef.Cp) 
                                          & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__Cp__0))));
    vlSelfRef.__VactTriggered.setBit(1U, ((IData)(vlSelfRef.reset) 
                                          & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__reset__0))));
    vlSelfRef.__Vtrigprevexpr___TOP__Cp__0 = vlSelfRef.Cp;
    vlSelfRef.__Vtrigprevexpr___TOP__reset__0 = vlSelfRef.reset;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vmoore_struktura___024root___dump_triggers__act(vlSelf);
    }
#endif
}
