// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vzad1.h for the primary calling header

#include "Vzad1__pch.h"
#include "Vzad1___024root.h"

VL_ATTR_COLD void Vzad1___024root___eval_static(Vzad1___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vzad1___024root___eval_static\n"); );
    Vzad1__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vzad1___024root___eval_initial(Vzad1___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vzad1___024root___eval_initial\n"); );
    Vzad1__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vzad1___024root___eval_final(Vzad1___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vzad1___024root___eval_final\n"); );
    Vzad1__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vzad1___024root___dump_triggers__stl(Vzad1___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vzad1___024root___eval_phase__stl(Vzad1___024root* vlSelf);

VL_ATTR_COLD void Vzad1___024root___eval_settle(Vzad1___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vzad1___024root___eval_settle\n"); );
    Vzad1__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VstlIterCount;
    CData/*0:0*/ __VstlContinue;
    // Body
    __VstlIterCount = 0U;
    vlSelfRef.__VstlFirstIteration = 1U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        if (VL_UNLIKELY(((0x64U < __VstlIterCount)))) {
#ifdef VL_DEBUG
            Vzad1___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("../../gowin/src\\zad1.sv", 1, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vzad1___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelfRef.__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vzad1___024root___dump_triggers__stl(Vzad1___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vzad1___024root___dump_triggers__stl\n"); );
    Vzad1__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VstlTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

void Vzad1___024root___ico_sequent__TOP__0(Vzad1___024root* vlSelf);

VL_ATTR_COLD void Vzad1___024root___eval_stl(Vzad1___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vzad1___024root___eval_stl\n"); );
    Vzad1__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        Vzad1___024root___ico_sequent__TOP__0(vlSelf);
    }
}

VL_ATTR_COLD void Vzad1___024root___eval_triggers__stl(Vzad1___024root* vlSelf);

VL_ATTR_COLD bool Vzad1___024root___eval_phase__stl(Vzad1___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vzad1___024root___eval_phase__stl\n"); );
    Vzad1__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vzad1___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelfRef.__VstlTriggered.any();
    if (__VstlExecute) {
        Vzad1___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vzad1___024root___dump_triggers__ico(Vzad1___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vzad1___024root___dump_triggers__ico\n"); );
    Vzad1__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VicoTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VicoTriggered.word(0U))) {
        VL_DBG_MSGF("         'ico' region trigger index 0 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vzad1___024root___dump_triggers__act(Vzad1___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vzad1___024root___dump_triggers__act\n"); );
    Vzad1__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VactTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vzad1___024root___dump_triggers__nba(Vzad1___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vzad1___024root___dump_triggers__nba\n"); );
    Vzad1__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VnbaTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vzad1___024root___ctor_var_reset(Vzad1___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vzad1___024root___ctor_var_reset\n"); );
    Vzad1__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelf->A = VL_RAND_RESET_I(1);
    vlSelf->B = VL_RAND_RESET_I(1);
    vlSelf->C = VL_RAND_RESET_I(1);
    vlSelf->Y = VL_RAND_RESET_I(1);
}
