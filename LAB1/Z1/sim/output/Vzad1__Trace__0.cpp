// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_fst_c.h"
#include "Vzad1__Syms.h"


void Vzad1___024root__trace_chg_0_sub_0(Vzad1___024root* vlSelf, VerilatedFst::Buffer* bufp);

void Vzad1___024root__trace_chg_0(void* voidSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vzad1___024root__trace_chg_0\n"); );
    // Init
    Vzad1___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vzad1___024root*>(voidSelf);
    Vzad1__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vzad1___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vzad1___024root__trace_chg_0_sub_0(Vzad1___024root* vlSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vzad1___024root__trace_chg_0_sub_0\n"); );
    Vzad1__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    bufp->chgBit(oldp+0,(vlSelfRef.A));
    bufp->chgBit(oldp+1,(vlSelfRef.B));
    bufp->chgBit(oldp+2,(vlSelfRef.C));
    bufp->chgBit(oldp+3,(vlSelfRef.Y));
}

void Vzad1___024root__trace_cleanup(void* voidSelf, VerilatedFst* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vzad1___024root__trace_cleanup\n"); );
    // Init
    Vzad1___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vzad1___024root*>(voidSelf);
    Vzad1__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VlUnpacked<CData/*0:0*/, 1> __Vm_traceActivity;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        __Vm_traceActivity[__Vi0] = 0;
    }
    // Body
    vlSymsp->__Vm_activity = false;
    __Vm_traceActivity[0U] = 0U;
}
