// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vmealy_automat.h for the primary calling header

#include "Vmealy_automat__pch.h"
#include "Vmealy_automat__Syms.h"
#include "Vmealy_automat___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vmealy_automat___024root___dump_triggers__stl(Vmealy_automat___024root* vlSelf);
#endif  // VL_DEBUG

VL_ATTR_COLD void Vmealy_automat___024root___eval_triggers__stl(Vmealy_automat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmealy_automat___024root___eval_triggers__stl\n"); );
    Vmealy_automat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VstlTriggered.setBit(0U, (IData)(vlSelfRef.__VstlFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vmealy_automat___024root___dump_triggers__stl(vlSelf);
    }
#endif
}
