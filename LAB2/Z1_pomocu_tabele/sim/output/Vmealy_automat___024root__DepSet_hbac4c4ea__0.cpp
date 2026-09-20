// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vmealy_automat.h for the primary calling header

#include "Vmealy_automat__pch.h"
#include "Vmealy_automat___024root.h"

void Vmealy_automat___024root___ico_sequent__TOP__0(Vmealy_automat___024root* vlSelf);

void Vmealy_automat___024root___eval_ico(Vmealy_automat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmealy_automat___024root___eval_ico\n"); );
    Vmealy_automat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VicoTriggered.word(0U))) {
        Vmealy_automat___024root___ico_sequent__TOP__0(vlSelf);
    }
}

extern const VlUnpacked<CData/*1:0*/, 8> Vmealy_automat__ConstPool__TABLE_h5f278a51_0;
extern const VlUnpacked<CData/*1:0*/, 8> Vmealy_automat__ConstPool__TABLE_h49ce7a55_0;

VL_INLINE_OPT void Vmealy_automat___024root___ico_sequent__TOP__0(Vmealy_automat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmealy_automat___024root___ico_sequent__TOP__0\n"); );
    Vmealy_automat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*2:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    // Body
    __Vtableidx1 = (((IData)(vlSelfRef.U) << 2U) | (IData)(vlSelfRef.stanje));
    vlSelfRef.Z = Vmealy_automat__ConstPool__TABLE_h5f278a51_0
        [__Vtableidx1];
    vlSelfRef.mealy_automat__DOT__sljed_stanje = Vmealy_automat__ConstPool__TABLE_h49ce7a55_0
        [__Vtableidx1];
}

void Vmealy_automat___024root___eval_triggers__ico(Vmealy_automat___024root* vlSelf);

bool Vmealy_automat___024root___eval_phase__ico(Vmealy_automat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmealy_automat___024root___eval_phase__ico\n"); );
    Vmealy_automat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VicoExecute;
    // Body
    Vmealy_automat___024root___eval_triggers__ico(vlSelf);
    __VicoExecute = vlSelfRef.__VicoTriggered.any();
    if (__VicoExecute) {
        Vmealy_automat___024root___eval_ico(vlSelf);
    }
    return (__VicoExecute);
}

void Vmealy_automat___024root___eval_act(Vmealy_automat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmealy_automat___024root___eval_act\n"); );
    Vmealy_automat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

void Vmealy_automat___024root___nba_sequent__TOP__0(Vmealy_automat___024root* vlSelf);

void Vmealy_automat___024root___eval_nba(Vmealy_automat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmealy_automat___024root___eval_nba\n"); );
    Vmealy_automat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((3ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vmealy_automat___024root___nba_sequent__TOP__0(vlSelf);
    }
}

VL_INLINE_OPT void Vmealy_automat___024root___nba_sequent__TOP__0(Vmealy_automat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmealy_automat___024root___nba_sequent__TOP__0\n"); );
    Vmealy_automat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*2:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    // Body
    vlSelfRef.stanje = ((IData)(vlSelfRef.reset) ? 0U
                         : (IData)(vlSelfRef.mealy_automat__DOT__sljed_stanje));
    __Vtableidx1 = (((IData)(vlSelfRef.U) << 2U) | (IData)(vlSelfRef.stanje));
    vlSelfRef.Z = Vmealy_automat__ConstPool__TABLE_h5f278a51_0
        [__Vtableidx1];
    vlSelfRef.mealy_automat__DOT__sljed_stanje = Vmealy_automat__ConstPool__TABLE_h49ce7a55_0
        [__Vtableidx1];
}

void Vmealy_automat___024root___eval_triggers__act(Vmealy_automat___024root* vlSelf);

bool Vmealy_automat___024root___eval_phase__act(Vmealy_automat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmealy_automat___024root___eval_phase__act\n"); );
    Vmealy_automat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlTriggerVec<2> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vmealy_automat___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelfRef.__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelfRef.__VactTriggered, vlSelfRef.__VnbaTriggered);
        vlSelfRef.__VnbaTriggered.thisOr(vlSelfRef.__VactTriggered);
        Vmealy_automat___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vmealy_automat___024root___eval_phase__nba(Vmealy_automat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmealy_automat___024root___eval_phase__nba\n"); );
    Vmealy_automat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelfRef.__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vmealy_automat___024root___eval_nba(vlSelf);
        vlSelfRef.__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vmealy_automat___024root___dump_triggers__ico(Vmealy_automat___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vmealy_automat___024root___dump_triggers__nba(Vmealy_automat___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vmealy_automat___024root___dump_triggers__act(Vmealy_automat___024root* vlSelf);
#endif  // VL_DEBUG

void Vmealy_automat___024root___eval(Vmealy_automat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmealy_automat___024root___eval\n"); );
    Vmealy_automat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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
            Vmealy_automat___024root___dump_triggers__ico(vlSelf);
#endif
            VL_FATAL_MT("../../gowin/src\\mealy_automat.sv", 1, "", "Input combinational region did not converge.");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
        __VicoContinue = 0U;
        if (Vmealy_automat___024root___eval_phase__ico(vlSelf)) {
            __VicoContinue = 1U;
        }
        vlSelfRef.__VicoFirstIteration = 0U;
    }
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY(((0x64U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            Vmealy_automat___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("../../gowin/src\\mealy_automat.sv", 1, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelfRef.__VactIterCount = 0U;
        vlSelfRef.__VactContinue = 1U;
        while (vlSelfRef.__VactContinue) {
            if (VL_UNLIKELY(((0x64U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vmealy_automat___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("../../gowin/src\\mealy_automat.sv", 1, "", "Active region did not converge.");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactContinue = 0U;
            if (Vmealy_automat___024root___eval_phase__act(vlSelf)) {
                vlSelfRef.__VactContinue = 1U;
            }
        }
        if (Vmealy_automat___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vmealy_automat___024root___eval_debug_assertions(Vmealy_automat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmealy_automat___024root___eval_debug_assertions\n"); );
    Vmealy_automat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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
