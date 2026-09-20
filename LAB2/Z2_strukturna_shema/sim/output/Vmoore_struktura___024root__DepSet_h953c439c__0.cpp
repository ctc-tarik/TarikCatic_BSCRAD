// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vmoore_struktura.h for the primary calling header

#include "Vmoore_struktura__pch.h"
#include "Vmoore_struktura___024root.h"

void Vmoore_struktura___024root___ico_sequent__TOP__0(Vmoore_struktura___024root* vlSelf);

void Vmoore_struktura___024root___eval_ico(Vmoore_struktura___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmoore_struktura___024root___eval_ico\n"); );
    Vmoore_struktura__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VicoTriggered.word(0U))) {
        Vmoore_struktura___024root___ico_sequent__TOP__0(vlSelf);
    }
}

VL_INLINE_OPT void Vmoore_struktura___024root___ico_sequent__TOP__0(Vmoore_struktura___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmoore_struktura___024root___ico_sequent__TOP__0\n"); );
    Vmoore_struktura__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.moore_struktura__DOT__T1 = (1U & ((((IData)(vlSelfRef.moore_struktura__DOT__Q1) 
                                                  & (~ (IData)(vlSelfRef.U))) 
                                                 | ((~ (IData)(vlSelfRef.moore_struktura__DOT__Q0)) 
                                                    & (~ (IData)(vlSelfRef.U)))) 
                                                | (((IData)(vlSelfRef.moore_struktura__DOT__Q0) 
                                                    & (IData)(vlSelfRef.U)) 
                                                   & (~ (IData)(vlSelfRef.moore_struktura__DOT__Q1)))));
}

void Vmoore_struktura___024root___eval_triggers__ico(Vmoore_struktura___024root* vlSelf);

bool Vmoore_struktura___024root___eval_phase__ico(Vmoore_struktura___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmoore_struktura___024root___eval_phase__ico\n"); );
    Vmoore_struktura__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VicoExecute;
    // Body
    Vmoore_struktura___024root___eval_triggers__ico(vlSelf);
    __VicoExecute = vlSelfRef.__VicoTriggered.any();
    if (__VicoExecute) {
        Vmoore_struktura___024root___eval_ico(vlSelf);
    }
    return (__VicoExecute);
}

void Vmoore_struktura___024root___eval_act(Vmoore_struktura___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmoore_struktura___024root___eval_act\n"); );
    Vmoore_struktura__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

void Vmoore_struktura___024root___nba_sequent__TOP__0(Vmoore_struktura___024root* vlSelf);

void Vmoore_struktura___024root___eval_nba(Vmoore_struktura___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmoore_struktura___024root___eval_nba\n"); );
    Vmoore_struktura__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((3ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vmoore_struktura___024root___nba_sequent__TOP__0(vlSelf);
    }
}

VL_INLINE_OPT void Vmoore_struktura___024root___nba_sequent__TOP__0(Vmoore_struktura___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmoore_struktura___024root___nba_sequent__TOP__0\n"); );
    Vmoore_struktura__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.moore_struktura__DOT__Q0 = ((1U & (~ (IData)(vlSelfRef.reset))) 
                                          && (1U & 
                                              (~ (IData)(vlSelfRef.moore_struktura__DOT__Q0))));
    vlSelfRef.moore_struktura__DOT__Q1 = ((1U & (~ (IData)(vlSelfRef.reset))) 
                                          && ((IData)(vlSelfRef.moore_struktura__DOT__T1) 
                                              ^ (IData)(vlSelfRef.moore_struktura__DOT__Q1)));
    vlSelfRef.Z = ((IData)(vlSelfRef.moore_struktura__DOT__Q1) 
                   ^ (IData)(vlSelfRef.moore_struktura__DOT__Q0));
    vlSelfRef.stanje = (((IData)(vlSelfRef.moore_struktura__DOT__Q1) 
                         << 1U) | (IData)(vlSelfRef.moore_struktura__DOT__Q0));
    vlSelfRef.moore_struktura__DOT__T1 = (1U & ((((IData)(vlSelfRef.moore_struktura__DOT__Q1) 
                                                  & (~ (IData)(vlSelfRef.U))) 
                                                 | ((~ (IData)(vlSelfRef.moore_struktura__DOT__Q0)) 
                                                    & (~ (IData)(vlSelfRef.U)))) 
                                                | (((IData)(vlSelfRef.moore_struktura__DOT__Q0) 
                                                    & (IData)(vlSelfRef.U)) 
                                                   & (~ (IData)(vlSelfRef.moore_struktura__DOT__Q1)))));
}

void Vmoore_struktura___024root___eval_triggers__act(Vmoore_struktura___024root* vlSelf);

bool Vmoore_struktura___024root___eval_phase__act(Vmoore_struktura___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmoore_struktura___024root___eval_phase__act\n"); );
    Vmoore_struktura__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlTriggerVec<2> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vmoore_struktura___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelfRef.__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelfRef.__VactTriggered, vlSelfRef.__VnbaTriggered);
        vlSelfRef.__VnbaTriggered.thisOr(vlSelfRef.__VactTriggered);
        Vmoore_struktura___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vmoore_struktura___024root___eval_phase__nba(Vmoore_struktura___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmoore_struktura___024root___eval_phase__nba\n"); );
    Vmoore_struktura__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelfRef.__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vmoore_struktura___024root___eval_nba(vlSelf);
        vlSelfRef.__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vmoore_struktura___024root___dump_triggers__ico(Vmoore_struktura___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vmoore_struktura___024root___dump_triggers__nba(Vmoore_struktura___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vmoore_struktura___024root___dump_triggers__act(Vmoore_struktura___024root* vlSelf);
#endif  // VL_DEBUG

void Vmoore_struktura___024root___eval(Vmoore_struktura___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmoore_struktura___024root___eval\n"); );
    Vmoore_struktura__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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
            Vmoore_struktura___024root___dump_triggers__ico(vlSelf);
#endif
            VL_FATAL_MT("../../gowin/src\\moore_struktura.sv", 20, "", "Input combinational region did not converge.");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
        __VicoContinue = 0U;
        if (Vmoore_struktura___024root___eval_phase__ico(vlSelf)) {
            __VicoContinue = 1U;
        }
        vlSelfRef.__VicoFirstIteration = 0U;
    }
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY(((0x64U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            Vmoore_struktura___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("../../gowin/src\\moore_struktura.sv", 20, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelfRef.__VactIterCount = 0U;
        vlSelfRef.__VactContinue = 1U;
        while (vlSelfRef.__VactContinue) {
            if (VL_UNLIKELY(((0x64U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vmoore_struktura___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("../../gowin/src\\moore_struktura.sv", 20, "", "Active region did not converge.");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactContinue = 0U;
            if (Vmoore_struktura___024root___eval_phase__act(vlSelf)) {
                vlSelfRef.__VactContinue = 1U;
            }
        }
        if (Vmoore_struktura___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vmoore_struktura___024root___eval_debug_assertions(Vmoore_struktura___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmoore_struktura___024root___eval_debug_assertions\n"); );
    Vmoore_struktura__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY(((vlSelfRef.U & 0xfeU)))) {
        Verilated::overWidthError("U");}
    if (VL_UNLIKELY(((vlSelfRef.Cp & 0xfeU)))) {
        Verilated::overWidthError("Cp");}
    if (VL_UNLIKELY(((vlSelfRef.reset & 0xfeU)))) {
        Verilated::overWidthError("reset");}
}
#endif  // VL_DEBUG
