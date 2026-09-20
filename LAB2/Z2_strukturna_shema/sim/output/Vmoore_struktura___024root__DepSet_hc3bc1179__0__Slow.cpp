// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vmoore_struktura.h for the primary calling header

#include "Vmoore_struktura__pch.h"
#include "Vmoore_struktura__Syms.h"
#include "Vmoore_struktura___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vmoore_struktura___024root___dump_triggers__stl(Vmoore_struktura___024root* vlSelf);
#endif  // VL_DEBUG

VL_ATTR_COLD void Vmoore_struktura___024root___eval_triggers__stl(Vmoore_struktura___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmoore_struktura___024root___eval_triggers__stl\n"); );
    Vmoore_struktura__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VstlTriggered.setBit(0U, (IData)(vlSelfRef.__VstlFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vmoore_struktura___024root___dump_triggers__stl(vlSelf);
    }
#endif
}
