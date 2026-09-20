// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_fst_c.h"
#include "Vmealy_struktura__Syms.h"


void Vmealy_struktura___024root__trace_chg_0_sub_0(Vmealy_struktura___024root* vlSelf, VerilatedFst::Buffer* bufp);

void Vmealy_struktura___024root__trace_chg_0(void* voidSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmealy_struktura___024root__trace_chg_0\n"); );
    // Init
    Vmealy_struktura___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vmealy_struktura___024root*>(voidSelf);
    Vmealy_struktura__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vmealy_struktura___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vmealy_struktura___024root__trace_chg_0_sub_0(Vmealy_struktura___024root* vlSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmealy_struktura___024root__trace_chg_0_sub_0\n"); );
    Vmealy_struktura__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    bufp->chgBit(oldp+0,(vlSelfRef.U));
    bufp->chgBit(oldp+1,(vlSelfRef.Cp));
    bufp->chgBit(oldp+2,(vlSelfRef.reset));
    bufp->chgCData(oldp+3,(vlSelfRef.Z),2);
    bufp->chgCData(oldp+4,(vlSelfRef.stanje),2);
    bufp->chgBit(oldp+5,(vlSelfRef.mealy_struktura__DOT__Q1));
    bufp->chgBit(oldp+6,(vlSelfRef.mealy_struktura__DOT__Q0));
    bufp->chgBit(oldp+7,((((IData)(vlSelfRef.mealy_struktura__DOT__Q1) 
                           & (IData)(vlSelfRef.U)) 
                          | ((IData)(vlSelfRef.mealy_struktura__DOT__Q0) 
                             & (~ (IData)(vlSelfRef.U))))));
    bufp->chgBit(oldp+8,((1U & ((IData)(vlSelfRef.mealy_struktura__DOT__Q0) 
                                | (~ (IData)(vlSelfRef.U))))));
}

void Vmealy_struktura___024root__trace_cleanup(void* voidSelf, VerilatedFst* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmealy_struktura___024root__trace_cleanup\n"); );
    // Init
    Vmealy_struktura___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vmealy_struktura___024root*>(voidSelf);
    Vmealy_struktura__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VlUnpacked<CData/*0:0*/, 1> __Vm_traceActivity;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        __Vm_traceActivity[__Vi0] = 0;
    }
    // Body
    vlSymsp->__Vm_activity = false;
    __Vm_traceActivity[0U] = 0U;
}
