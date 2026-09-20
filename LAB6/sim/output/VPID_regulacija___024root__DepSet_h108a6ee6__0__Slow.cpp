// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VPID_regulacija.h for the primary calling header

#include "VPID_regulacija__pch.h"
#include "VPID_regulacija___024root.h"

VL_ATTR_COLD void VPID_regulacija___024root___eval_static(VPID_regulacija___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPID_regulacija___024root___eval_static\n"); );
    VPID_regulacija__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vtrigprevexpr___TOP__areset__0 = vlSelfRef.areset;
    vlSelfRef.__Vtrigprevexpr___TOP__clk__0 = vlSelfRef.clk;
}

VL_ATTR_COLD void VPID_regulacija___024root___eval_initial(VPID_regulacija___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPID_regulacija___024root___eval_initial\n"); );
    VPID_regulacija__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void VPID_regulacija___024root___eval_final(VPID_regulacija___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPID_regulacija___024root___eval_final\n"); );
    VPID_regulacija__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VPID_regulacija___024root___dump_triggers__stl(VPID_regulacija___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool VPID_regulacija___024root___eval_phase__stl(VPID_regulacija___024root* vlSelf);

VL_ATTR_COLD void VPID_regulacija___024root___eval_settle(VPID_regulacija___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPID_regulacija___024root___eval_settle\n"); );
    VPID_regulacija__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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
            VPID_regulacija___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("../../gowin/src\\PID_regulacija.sv", 1, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (VPID_regulacija___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelfRef.__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VPID_regulacija___024root___dump_triggers__stl(VPID_regulacija___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPID_regulacija___024root___dump_triggers__stl\n"); );
    VPID_regulacija__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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

VL_ATTR_COLD void VPID_regulacija___024root___stl_sequent__TOP__0(VPID_regulacija___024root* vlSelf);

VL_ATTR_COLD void VPID_regulacija___024root___eval_stl(VPID_regulacija___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPID_regulacija___024root___eval_stl\n"); );
    VPID_regulacija__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        VPID_regulacija___024root___stl_sequent__TOP__0(vlSelf);
    }
}

VL_ATTR_COLD void VPID_regulacija___024root___stl_sequent__TOP__0(VPID_regulacija___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPID_regulacija___024root___stl_sequent__TOP__0\n"); );
    VPID_regulacija__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.u_out = (0x7fffU & (IData)(vlSelfRef.PID_regulacija__DOT__d_reg));
    vlSelfRef.PID_regulacija__DOT__d_wire = (0xfffffffffULL 
                                             & (((QData)((IData)(vlSelfRef.PID_regulacija__DOT__u_prev)) 
                                                 + 
                                                 (0xaULL 
                                                  * (QData)((IData)(vlSelfRef.e_in)))) 
                                                - (QData)((IData)(vlSelfRef.PID_regulacija__DOT__e_prev1))));
}

VL_ATTR_COLD void VPID_regulacija___024root___eval_triggers__stl(VPID_regulacija___024root* vlSelf);

VL_ATTR_COLD bool VPID_regulacija___024root___eval_phase__stl(VPID_regulacija___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPID_regulacija___024root___eval_phase__stl\n"); );
    VPID_regulacija__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    VPID_regulacija___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelfRef.__VstlTriggered.any();
    if (__VstlExecute) {
        VPID_regulacija___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VPID_regulacija___024root___dump_triggers__ico(VPID_regulacija___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPID_regulacija___024root___dump_triggers__ico\n"); );
    VPID_regulacija__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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
VL_ATTR_COLD void VPID_regulacija___024root___dump_triggers__act(VPID_regulacija___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPID_regulacija___024root___dump_triggers__act\n"); );
    VPID_regulacija__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VactTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(negedge areset)\n");
    }
    if ((2ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @(posedge clk)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void VPID_regulacija___024root___dump_triggers__nba(VPID_regulacija___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPID_regulacija___024root___dump_triggers__nba\n"); );
    VPID_regulacija__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VnbaTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(negedge areset)\n");
    }
    if ((2ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @(posedge clk)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void VPID_regulacija___024root___ctor_var_reset(VPID_regulacija___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPID_regulacija___024root___ctor_var_reset\n"); );
    VPID_regulacija__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelf->u_out = VL_RAND_RESET_I(15);
    vlSelf->e_in = VL_RAND_RESET_I(16);
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->areset = VL_RAND_RESET_I(1);
    vlSelf->PID_regulacija__DOT__u_prev = VL_RAND_RESET_I(16);
    vlSelf->PID_regulacija__DOT__e_prev = VL_RAND_RESET_I(16);
    vlSelf->PID_regulacija__DOT__e_prev1 = VL_RAND_RESET_I(16);
    vlSelf->PID_regulacija__DOT__d_reg = VL_RAND_RESET_Q(36);
    vlSelf->PID_regulacija__DOT__d_wire = VL_RAND_RESET_Q(36);
    vlSelf->__Vtrigprevexpr___TOP__areset__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
