// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vmealy_struktura.h for the primary calling header

#include "Vmealy_struktura__pch.h"
#include "Vmealy_struktura___024root.h"

VL_ATTR_COLD void Vmealy_struktura___024root___eval_static(Vmealy_struktura___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmealy_struktura___024root___eval_static\n"); );
    Vmealy_struktura__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vtrigprevexpr___TOP__Cp__0 = vlSelfRef.Cp;
    vlSelfRef.__Vtrigprevexpr___TOP__reset__0 = vlSelfRef.reset;
}

VL_ATTR_COLD void Vmealy_struktura___024root___eval_initial(Vmealy_struktura___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmealy_struktura___024root___eval_initial\n"); );
    Vmealy_struktura__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vmealy_struktura___024root___eval_final(Vmealy_struktura___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmealy_struktura___024root___eval_final\n"); );
    Vmealy_struktura__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vmealy_struktura___024root___dump_triggers__stl(Vmealy_struktura___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vmealy_struktura___024root___eval_phase__stl(Vmealy_struktura___024root* vlSelf);

VL_ATTR_COLD void Vmealy_struktura___024root___eval_settle(Vmealy_struktura___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmealy_struktura___024root___eval_settle\n"); );
    Vmealy_struktura__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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
            Vmealy_struktura___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("../../gowin/src\\mealy_struktura.sv", 20, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vmealy_struktura___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelfRef.__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vmealy_struktura___024root___dump_triggers__stl(Vmealy_struktura___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmealy_struktura___024root___dump_triggers__stl\n"); );
    Vmealy_struktura__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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

VL_ATTR_COLD void Vmealy_struktura___024root___stl_sequent__TOP__0(Vmealy_struktura___024root* vlSelf);

VL_ATTR_COLD void Vmealy_struktura___024root___eval_stl(Vmealy_struktura___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmealy_struktura___024root___eval_stl\n"); );
    Vmealy_struktura__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        Vmealy_struktura___024root___stl_sequent__TOP__0(vlSelf);
    }
}

VL_ATTR_COLD void Vmealy_struktura___024root___stl_sequent__TOP__0(Vmealy_struktura___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmealy_struktura___024root___stl_sequent__TOP__0\n"); );
    Vmealy_struktura__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.mealy_struktura__DOT__T2 = (1U & ((IData)(vlSelfRef.mealy_struktura__DOT__Q0) 
                                                | (~ (IData)(vlSelfRef.U))));
    vlSelfRef.stanje = (((IData)(vlSelfRef.mealy_struktura__DOT__Q1) 
                         << 1U) | (IData)(vlSelfRef.mealy_struktura__DOT__Q0));
    vlSelfRef.mealy_struktura__DOT__T1 = (((IData)(vlSelfRef.mealy_struktura__DOT__Q1) 
                                           & (IData)(vlSelfRef.U)) 
                                          | ((IData)(vlSelfRef.mealy_struktura__DOT__Q0) 
                                             & (~ (IData)(vlSelfRef.U))));
    vlSelfRef.Z = ((1U & (IData)(vlSelfRef.Z)) | (((IData)(vlSelfRef.U) 
                                                   | ((IData)(vlSelfRef.mealy_struktura__DOT__Q1) 
                                                      ^ (IData)(vlSelfRef.mealy_struktura__DOT__Q0))) 
                                                  << 1U));
    vlSelfRef.Z = ((2U & (IData)(vlSelfRef.Z)) | (1U 
                                                  & (((((IData)(vlSelfRef.mealy_struktura__DOT__Q1) 
                                                        & (IData)(vlSelfRef.mealy_struktura__DOT__Q0)) 
                                                       & (~ (IData)(vlSelfRef.U))) 
                                                      | (((IData)(vlSelfRef.mealy_struktura__DOT__Q1) 
                                                          & (IData)(vlSelfRef.U)) 
                                                         & (~ (IData)(vlSelfRef.mealy_struktura__DOT__Q0)))) 
                                                     | (((~ (IData)(vlSelfRef.mealy_struktura__DOT__Q1)) 
                                                         & (~ (IData)(vlSelfRef.mealy_struktura__DOT__Q0))) 
                                                        & (~ (IData)(vlSelfRef.U))))));
}

VL_ATTR_COLD void Vmealy_struktura___024root___eval_triggers__stl(Vmealy_struktura___024root* vlSelf);

VL_ATTR_COLD bool Vmealy_struktura___024root___eval_phase__stl(Vmealy_struktura___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmealy_struktura___024root___eval_phase__stl\n"); );
    Vmealy_struktura__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vmealy_struktura___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelfRef.__VstlTriggered.any();
    if (__VstlExecute) {
        Vmealy_struktura___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vmealy_struktura___024root___dump_triggers__ico(Vmealy_struktura___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmealy_struktura___024root___dump_triggers__ico\n"); );
    Vmealy_struktura__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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
VL_ATTR_COLD void Vmealy_struktura___024root___dump_triggers__act(Vmealy_struktura___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmealy_struktura___024root___dump_triggers__act\n"); );
    Vmealy_struktura__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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
VL_ATTR_COLD void Vmealy_struktura___024root___dump_triggers__nba(Vmealy_struktura___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmealy_struktura___024root___dump_triggers__nba\n"); );
    Vmealy_struktura__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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

VL_ATTR_COLD void Vmealy_struktura___024root___ctor_var_reset(Vmealy_struktura___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmealy_struktura___024root___ctor_var_reset\n"); );
    Vmealy_struktura__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelf->U = VL_RAND_RESET_I(1);
    vlSelf->Cp = VL_RAND_RESET_I(1);
    vlSelf->reset = VL_RAND_RESET_I(1);
    vlSelf->Z = VL_RAND_RESET_I(2);
    vlSelf->stanje = VL_RAND_RESET_I(2);
    vlSelf->mealy_struktura__DOT__Q1 = VL_RAND_RESET_I(1);
    vlSelf->mealy_struktura__DOT__Q0 = VL_RAND_RESET_I(1);
    vlSelf->mealy_struktura__DOT__T1 = VL_RAND_RESET_I(1);
    vlSelf->mealy_struktura__DOT__T2 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__Cp__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__reset__0 = VL_RAND_RESET_I(1);
}
