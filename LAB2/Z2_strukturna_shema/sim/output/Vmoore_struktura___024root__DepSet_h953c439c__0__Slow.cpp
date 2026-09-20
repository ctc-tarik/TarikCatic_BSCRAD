// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vmoore_struktura.h for the primary calling header

#include "Vmoore_struktura__pch.h"
#include "Vmoore_struktura___024root.h"

VL_ATTR_COLD void Vmoore_struktura___024root___eval_static(Vmoore_struktura___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmoore_struktura___024root___eval_static\n"); );
    Vmoore_struktura__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vtrigprevexpr___TOP__Cp__0 = vlSelfRef.Cp;
    vlSelfRef.__Vtrigprevexpr___TOP__reset__0 = vlSelfRef.reset;
}

VL_ATTR_COLD void Vmoore_struktura___024root___eval_initial(Vmoore_struktura___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmoore_struktura___024root___eval_initial\n"); );
    Vmoore_struktura__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vmoore_struktura___024root___eval_final(Vmoore_struktura___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmoore_struktura___024root___eval_final\n"); );
    Vmoore_struktura__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vmoore_struktura___024root___dump_triggers__stl(Vmoore_struktura___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vmoore_struktura___024root___eval_phase__stl(Vmoore_struktura___024root* vlSelf);

VL_ATTR_COLD void Vmoore_struktura___024root___eval_settle(Vmoore_struktura___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmoore_struktura___024root___eval_settle\n"); );
    Vmoore_struktura__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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
            Vmoore_struktura___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("../../gowin/src\\moore_struktura.sv", 20, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vmoore_struktura___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelfRef.__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vmoore_struktura___024root___dump_triggers__stl(Vmoore_struktura___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmoore_struktura___024root___dump_triggers__stl\n"); );
    Vmoore_struktura__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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

VL_ATTR_COLD void Vmoore_struktura___024root___stl_sequent__TOP__0(Vmoore_struktura___024root* vlSelf);

VL_ATTR_COLD void Vmoore_struktura___024root___eval_stl(Vmoore_struktura___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmoore_struktura___024root___eval_stl\n"); );
    Vmoore_struktura__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        Vmoore_struktura___024root___stl_sequent__TOP__0(vlSelf);
    }
}

VL_ATTR_COLD void Vmoore_struktura___024root___stl_sequent__TOP__0(Vmoore_struktura___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmoore_struktura___024root___stl_sequent__TOP__0\n"); );
    Vmoore_struktura__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
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

VL_ATTR_COLD void Vmoore_struktura___024root___eval_triggers__stl(Vmoore_struktura___024root* vlSelf);

VL_ATTR_COLD bool Vmoore_struktura___024root___eval_phase__stl(Vmoore_struktura___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmoore_struktura___024root___eval_phase__stl\n"); );
    Vmoore_struktura__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vmoore_struktura___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelfRef.__VstlTriggered.any();
    if (__VstlExecute) {
        Vmoore_struktura___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vmoore_struktura___024root___dump_triggers__ico(Vmoore_struktura___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmoore_struktura___024root___dump_triggers__ico\n"); );
    Vmoore_struktura__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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
VL_ATTR_COLD void Vmoore_struktura___024root___dump_triggers__act(Vmoore_struktura___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmoore_struktura___024root___dump_triggers__act\n"); );
    Vmoore_struktura__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VactTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge Cp)\n");
    }
    if ((2ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @(posedge reset)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vmoore_struktura___024root___dump_triggers__nba(Vmoore_struktura___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmoore_struktura___024root___dump_triggers__nba\n"); );
    Vmoore_struktura__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VnbaTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge Cp)\n");
    }
    if ((2ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @(posedge reset)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vmoore_struktura___024root___ctor_var_reset(Vmoore_struktura___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmoore_struktura___024root___ctor_var_reset\n"); );
    Vmoore_struktura__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelf->U = VL_RAND_RESET_I(1);
    vlSelf->Cp = VL_RAND_RESET_I(1);
    vlSelf->reset = VL_RAND_RESET_I(1);
    vlSelf->Z = VL_RAND_RESET_I(1);
    vlSelf->stanje = VL_RAND_RESET_I(2);
    vlSelf->moore_struktura__DOT__Q1 = VL_RAND_RESET_I(1);
    vlSelf->moore_struktura__DOT__Q0 = VL_RAND_RESET_I(1);
    vlSelf->moore_struktura__DOT__T1 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__Cp__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__reset__0 = VL_RAND_RESET_I(1);
}
