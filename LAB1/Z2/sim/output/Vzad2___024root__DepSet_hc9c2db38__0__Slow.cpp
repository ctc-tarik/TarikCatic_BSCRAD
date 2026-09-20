// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vzad2.h for the primary calling header

#include "Vzad2__pch.h"
#include "Vzad2__Syms.h"
#include "Vzad2___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vzad2___024root___dump_triggers__stl(Vzad2___024root* vlSelf);
#endif  // VL_DEBUG

VL_ATTR_COLD void Vzad2___024root___eval_triggers__stl(Vzad2___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vzad2___024root___eval_triggers__stl\n"); );
    Vzad2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VstlTriggered.setBit(0U, (IData)(vlSelfRef.__VstlFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vzad2___024root___dump_triggers__stl(vlSelf);
    }
#endif
}
