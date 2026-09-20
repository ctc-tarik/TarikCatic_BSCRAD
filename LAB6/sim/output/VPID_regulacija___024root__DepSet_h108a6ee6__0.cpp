// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VPID_regulacija.h for the primary calling header

#include "VPID_regulacija__pch.h"
#include "VPID_regulacija___024root.h"

void VPID_regulacija___024root___ico_sequent__TOP__0(VPID_regulacija___024root* vlSelf);

void VPID_regulacija___024root___eval_ico(VPID_regulacija___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPID_regulacija___024root___eval_ico\n"); );
    VPID_regulacija__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VicoTriggered.word(0U))) {
        VPID_regulacija___024root___ico_sequent__TOP__0(vlSelf);
    }
}

VL_INLINE_OPT void VPID_regulacija___024root___ico_sequent__TOP__0(VPID_regulacija___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPID_regulacija___024root___ico_sequent__TOP__0\n"); );
    VPID_regulacija__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.PID_regulacija__DOT__d_wire = (0xfffffffffULL 
                                             & (((QData)((IData)(vlSelfRef.PID_regulacija__DOT__u_prev)) 
                                                 + 
                                                 (0xaULL 
                                                  * (QData)((IData)(vlSelfRef.e_in)))) 
                                                - (QData)((IData)(vlSelfRef.PID_regulacija__DOT__e_prev1))));
}

void VPID_regulacija___024root___eval_triggers__ico(VPID_regulacija___024root* vlSelf);

bool VPID_regulacija___024root___eval_phase__ico(VPID_regulacija___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPID_regulacija___024root___eval_phase__ico\n"); );
    VPID_regulacija__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VicoExecute;
    // Body
    VPID_regulacija___024root___eval_triggers__ico(vlSelf);
    __VicoExecute = vlSelfRef.__VicoTriggered.any();
    if (__VicoExecute) {
        VPID_regulacija___024root___eval_ico(vlSelf);
    }
    return (__VicoExecute);
}

void VPID_regulacija___024root___eval_act(VPID_regulacija___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPID_regulacija___024root___eval_act\n"); );
    VPID_regulacija__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

void VPID_regulacija___024root___nba_sequent__TOP__0(VPID_regulacija___024root* vlSelf);
void VPID_regulacija___024root___nba_sequent__TOP__1(VPID_regulacija___024root* vlSelf);
void VPID_regulacija___024root___nba_sequent__TOP__2(VPID_regulacija___024root* vlSelf);

void VPID_regulacija___024root___eval_nba(VPID_regulacija___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPID_regulacija___024root___eval_nba\n"); );
    VPID_regulacija__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((2ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VPID_regulacija___024root___nba_sequent__TOP__0(vlSelf);
    }
    if ((3ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VPID_regulacija___024root___nba_sequent__TOP__1(vlSelf);
        vlSelfRef.__Vm_traceActivity[1U] = 1U;
    }
    if ((2ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VPID_regulacija___024root___nba_sequent__TOP__2(vlSelf);
    }
}

VL_INLINE_OPT void VPID_regulacija___024root___nba_sequent__TOP__0(VPID_regulacija___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPID_regulacija___024root___nba_sequent__TOP__0\n"); );
    VPID_regulacija__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.PID_regulacija__DOT__d_reg = vlSelfRef.PID_regulacija__DOT__d_wire;
    if (VL_GTS_III(16, 0U, (IData)(vlSelfRef.e_in))) {
        vlSelfRef.PID_regulacija__DOT__d_reg = 0ULL;
    } else if (VL_LTS_IQQ(36, 0x7fffULL, vlSelfRef.PID_regulacija__DOT__d_wire)) {
        vlSelfRef.PID_regulacija__DOT__d_reg = 0x7fffULL;
    } else if (VL_GTS_IQQ(36, 0ULL, vlSelfRef.PID_regulacija__DOT__d_wire)) {
        vlSelfRef.PID_regulacija__DOT__d_reg = 0ULL;
    }
}

VL_INLINE_OPT void VPID_regulacija___024root___nba_sequent__TOP__1(VPID_regulacija___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPID_regulacija___024root___nba_sequent__TOP__1\n"); );
    VPID_regulacija__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.areset) {
        vlSelfRef.PID_regulacija__DOT__u_prev = (VL_GTS_III(16, 0U, (IData)(vlSelfRef.e_in))
                                                  ? 0U
                                                  : (IData)(vlSelfRef.u_out));
        if (VL_LTES_III(16, 0U, (IData)(vlSelfRef.e_in))) {
            vlSelfRef.PID_regulacija__DOT__e_prev1 
                = vlSelfRef.PID_regulacija__DOT__e_prev;
            vlSelfRef.PID_regulacija__DOT__e_prev = vlSelfRef.e_in;
        }
    } else {
        vlSelfRef.PID_regulacija__DOT__u_prev = 0U;
        vlSelfRef.PID_regulacija__DOT__e_prev1 = 0U;
        vlSelfRef.PID_regulacija__DOT__e_prev = 0U;
    }
    vlSelfRef.PID_regulacija__DOT__d_wire = (0xfffffffffULL 
                                             & (((QData)((IData)(vlSelfRef.PID_regulacija__DOT__u_prev)) 
                                                 + 
                                                 (0xaULL 
                                                  * (QData)((IData)(vlSelfRef.e_in)))) 
                                                - (QData)((IData)(vlSelfRef.PID_regulacija__DOT__e_prev1))));
}

VL_INLINE_OPT void VPID_regulacija___024root___nba_sequent__TOP__2(VPID_regulacija___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPID_regulacija___024root___nba_sequent__TOP__2\n"); );
    VPID_regulacija__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.u_out = (0x7fffU & (IData)(vlSelfRef.PID_regulacija__DOT__d_reg));
}

void VPID_regulacija___024root___eval_triggers__act(VPID_regulacija___024root* vlSelf);

bool VPID_regulacija___024root___eval_phase__act(VPID_regulacija___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPID_regulacija___024root___eval_phase__act\n"); );
    VPID_regulacija__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlTriggerVec<2> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    VPID_regulacija___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelfRef.__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelfRef.__VactTriggered, vlSelfRef.__VnbaTriggered);
        vlSelfRef.__VnbaTriggered.thisOr(vlSelfRef.__VactTriggered);
        VPID_regulacija___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool VPID_regulacija___024root___eval_phase__nba(VPID_regulacija___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPID_regulacija___024root___eval_phase__nba\n"); );
    VPID_regulacija__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelfRef.__VnbaTriggered.any();
    if (__VnbaExecute) {
        VPID_regulacija___024root___eval_nba(vlSelf);
        vlSelfRef.__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VPID_regulacija___024root___dump_triggers__ico(VPID_regulacija___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void VPID_regulacija___024root___dump_triggers__nba(VPID_regulacija___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void VPID_regulacija___024root___dump_triggers__act(VPID_regulacija___024root* vlSelf);
#endif  // VL_DEBUG

void VPID_regulacija___024root___eval(VPID_regulacija___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPID_regulacija___024root___eval\n"); );
    VPID_regulacija__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VicoIterCount;
    CData/*0:0*/ __VicoContinue;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VicoIterCount = 0U;
    vlSelfRef.__VicoFirstIteration = 1U;
    __VicoContinue = 1U;
    while (__VicoContinue) {
        if (VL_UNLIKELY(((0x64U < __VicoIterCount)))) {
#ifdef VL_DEBUG
            VPID_regulacija___024root___dump_triggers__ico(vlSelf);
#endif
            VL_FATAL_MT("../../gowin/src\\PID_regulacija.sv", 1, "", "Input combinational region did not converge.");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
        __VicoContinue = 0U;
        if (VPID_regulacija___024root___eval_phase__ico(vlSelf)) {
            __VicoContinue = 1U;
        }
        vlSelfRef.__VicoFirstIteration = 0U;
    }
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY(((0x64U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            VPID_regulacija___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("../../gowin/src\\PID_regulacija.sv", 1, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelfRef.__VactIterCount = 0U;
        vlSelfRef.__VactContinue = 1U;
        while (vlSelfRef.__VactContinue) {
            if (VL_UNLIKELY(((0x64U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                VPID_regulacija___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("../../gowin/src\\PID_regulacija.sv", 1, "", "Active region did not converge.");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactContinue = 0U;
            if (VPID_regulacija___024root___eval_phase__act(vlSelf)) {
                vlSelfRef.__VactContinue = 1U;
            }
        }
        if (VPID_regulacija___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void VPID_regulacija___024root___eval_debug_assertions(VPID_regulacija___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPID_regulacija___024root___eval_debug_assertions\n"); );
    VPID_regulacija__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY(((vlSelfRef.clk & 0xfeU)))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY(((vlSelfRef.areset & 0xfeU)))) {
        Verilated::overWidthError("areset");}
}
#endif  // VL_DEBUG
