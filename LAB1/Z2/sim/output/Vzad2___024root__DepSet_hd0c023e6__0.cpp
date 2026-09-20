// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vzad2.h for the primary calling header

#include "Vzad2__pch.h"
#include "Vzad2___024root.h"

void Vzad2___024root___ico_sequent__TOP__0(Vzad2___024root* vlSelf);

void Vzad2___024root___eval_ico(Vzad2___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vzad2___024root___eval_ico\n"); );
    Vzad2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VicoTriggered.word(0U))) {
        Vzad2___024root___ico_sequent__TOP__0(vlSelf);
    }
}

VL_INLINE_OPT void Vzad2___024root___ico_sequent__TOP__0(Vzad2___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vzad2___024root___ico_sequent__TOP__0\n"); );
    Vzad2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.Y = (1U & (((~ (IData)(vlSelfRef.A)) 
                          & ((IData)(vlSelfRef.B) & 
                             ((IData)(vlSelfRef.C) 
                              & (IData)(vlSelfRef.D)))) 
                         | ((~ ((~ (IData)(vlSelfRef.E)) 
                                | (IData)(vlSelfRef.A))) 
                            | ((~ (IData)(vlSelfRef.C)) 
                               & ((IData)(vlSelfRef.B) 
                                  & ((~ (IData)(vlSelfRef.E)) 
                                     & (IData)(vlSelfRef.D)))))));
}

void Vzad2___024root___eval_triggers__ico(Vzad2___024root* vlSelf);

bool Vzad2___024root___eval_phase__ico(Vzad2___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vzad2___024root___eval_phase__ico\n"); );
    Vzad2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VicoExecute;
    // Body
    Vzad2___024root___eval_triggers__ico(vlSelf);
    __VicoExecute = vlSelfRef.__VicoTriggered.any();
    if (__VicoExecute) {
        Vzad2___024root___eval_ico(vlSelf);
    }
    return (__VicoExecute);
}

void Vzad2___024root___eval_act(Vzad2___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vzad2___024root___eval_act\n"); );
    Vzad2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

void Vzad2___024root___eval_nba(Vzad2___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vzad2___024root___eval_nba\n"); );
    Vzad2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

void Vzad2___024root___eval_triggers__act(Vzad2___024root* vlSelf);

bool Vzad2___024root___eval_phase__act(Vzad2___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vzad2___024root___eval_phase__act\n"); );
    Vzad2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlTriggerVec<0> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vzad2___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelfRef.__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelfRef.__VactTriggered, vlSelfRef.__VnbaTriggered);
        vlSelfRef.__VnbaTriggered.thisOr(vlSelfRef.__VactTriggered);
        Vzad2___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vzad2___024root___eval_phase__nba(Vzad2___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vzad2___024root___eval_phase__nba\n"); );
    Vzad2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelfRef.__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vzad2___024root___eval_nba(vlSelf);
        vlSelfRef.__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vzad2___024root___dump_triggers__ico(Vzad2___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vzad2___024root___dump_triggers__nba(Vzad2___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vzad2___024root___dump_triggers__act(Vzad2___024root* vlSelf);
#endif  // VL_DEBUG

void Vzad2___024root___eval(Vzad2___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vzad2___024root___eval\n"); );
    Vzad2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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
            Vzad2___024root___dump_triggers__ico(vlSelf);
#endif
            VL_FATAL_MT("../../gowin/src\\zad2.sv", 1, "", "Input combinational region did not converge.");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
        __VicoContinue = 0U;
        if (Vzad2___024root___eval_phase__ico(vlSelf)) {
            __VicoContinue = 1U;
        }
        vlSelfRef.__VicoFirstIteration = 0U;
    }
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY(((0x64U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            Vzad2___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("../../gowin/src\\zad2.sv", 1, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelfRef.__VactIterCount = 0U;
        vlSelfRef.__VactContinue = 1U;
        while (vlSelfRef.__VactContinue) {
            if (VL_UNLIKELY(((0x64U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vzad2___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("../../gowin/src\\zad2.sv", 1, "", "Active region did not converge.");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactContinue = 0U;
            if (Vzad2___024root___eval_phase__act(vlSelf)) {
                vlSelfRef.__VactContinue = 1U;
            }
        }
        if (Vzad2___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vzad2___024root___eval_debug_assertions(Vzad2___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vzad2___024root___eval_debug_assertions\n"); );
    Vzad2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY(((vlSelfRef.A & 0xfeU)))) {
        Verilated::overWidthError("A");}
    if (VL_UNLIKELY(((vlSelfRef.B & 0xfeU)))) {
        Verilated::overWidthError("B");}
    if (VL_UNLIKELY(((vlSelfRef.C & 0xfeU)))) {
        Verilated::overWidthError("C");}
    if (VL_UNLIKELY(((vlSelfRef.D & 0xfeU)))) {
        Verilated::overWidthError("D");}
    if (VL_UNLIKELY(((vlSelfRef.E & 0xfeU)))) {
        Verilated::overWidthError("E");}
}
#endif  // VL_DEBUG
