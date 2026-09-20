// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_fst_c.h"
#include "Vmoore_struktura__Syms.h"


void Vmoore_struktura___024root__trace_chg_0_sub_0(Vmoore_struktura___024root* vlSelf, VerilatedFst::Buffer* bufp);

void Vmoore_struktura___024root__trace_chg_0(void* voidSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmoore_struktura___024root__trace_chg_0\n"); );
    // Init
    Vmoore_struktura___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vmoore_struktura___024root*>(voidSelf);
    Vmoore_struktura__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vmoore_struktura___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vmoore_struktura___024root__trace_chg_0_sub_0(Vmoore_struktura___024root* vlSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmoore_struktura___024root__trace_chg_0_sub_0\n"); );
    Vmoore_struktura__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    bufp->chgBit(oldp+0,(vlSelfRef.U));
    bufp->chgBit(oldp+1,(vlSelfRef.Cp));
    bufp->chgBit(oldp+2,(vlSelfRef.reset));
    bufp->chgBit(oldp+3,(vlSelfRef.Z));
    bufp->chgCData(oldp+4,(vlSelfRef.stanje),2);
    bufp->chgBit(oldp+5,(vlSelfRef.moore_struktura__DOT__Q1));
    bufp->chgBit(oldp+6,(vlSelfRef.moore_struktura__DOT__Q0));
    bufp->chgBit(oldp+7,((1U & ((((IData)(vlSelfRef.moore_struktura__DOT__Q1) 
                                  & (~ (IData)(vlSelfRef.U))) 
                                 | ((~ (IData)(vlSelfRef.moore_struktura__DOT__Q0)) 
                                    & (~ (IData)(vlSelfRef.U)))) 
                                | (((IData)(vlSelfRef.moore_struktura__DOT__Q0) 
                                    & (IData)(vlSelfRef.U)) 
                                   & (~ (IData)(vlSelfRef.moore_struktura__DOT__Q1)))))));
}

void Vmoore_struktura___024root__trace_cleanup(void* voidSelf, VerilatedFst* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmoore_struktura___024root__trace_cleanup\n"); );
    // Init
    Vmoore_struktura___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vmoore_struktura___024root*>(voidSelf);
    Vmoore_struktura__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VlUnpacked<CData/*0:0*/, 1> __Vm_traceActivity;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        __Vm_traceActivity[__Vi0] = 0;
    }
    // Body
    vlSymsp->__Vm_activity = false;
    __Vm_traceActivity[0U] = 0U;
}
