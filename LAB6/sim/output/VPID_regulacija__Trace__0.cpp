// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_fst_c.h"
#include "VPID_regulacija__Syms.h"


void VPID_regulacija___024root__trace_chg_0_sub_0(VPID_regulacija___024root* vlSelf, VerilatedFst::Buffer* bufp);

void VPID_regulacija___024root__trace_chg_0(void* voidSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPID_regulacija___024root__trace_chg_0\n"); );
    // Init
    VPID_regulacija___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VPID_regulacija___024root*>(voidSelf);
    VPID_regulacija__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    VPID_regulacija___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void VPID_regulacija___024root__trace_chg_0_sub_0(VPID_regulacija___024root* vlSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPID_regulacija___024root__trace_chg_0_sub_0\n"); );
    VPID_regulacija__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[1U]))) {
        bufp->chgSData(oldp+0,(vlSelfRef.PID_regulacija__DOT__u_prev),16);
        bufp->chgSData(oldp+1,(vlSelfRef.PID_regulacija__DOT__e_prev),16);
        bufp->chgSData(oldp+2,(vlSelfRef.PID_regulacija__DOT__e_prev1),16);
    }
    bufp->chgSData(oldp+3,(vlSelfRef.u_out),15);
    bufp->chgSData(oldp+4,(vlSelfRef.e_in),16);
    bufp->chgBit(oldp+5,(vlSelfRef.clk));
    bufp->chgBit(oldp+6,(vlSelfRef.areset));
    bufp->chgQData(oldp+7,(vlSelfRef.PID_regulacija__DOT__d_reg),36);
    bufp->chgQData(oldp+9,(vlSelfRef.PID_regulacija__DOT__d_wire),36);
}

void VPID_regulacija___024root__trace_cleanup(void* voidSelf, VerilatedFst* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPID_regulacija___024root__trace_cleanup\n"); );
    // Init
    VPID_regulacija___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VPID_regulacija___024root*>(voidSelf);
    VPID_regulacija__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
}
