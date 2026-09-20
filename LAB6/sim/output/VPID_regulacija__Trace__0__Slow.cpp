// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_fst_c.h"
#include "VPID_regulacija__Syms.h"


VL_ATTR_COLD void VPID_regulacija___024root__trace_init_sub__TOP__0(VPID_regulacija___024root* vlSelf, VerilatedFst* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPID_regulacija___024root__trace_init_sub__TOP__0\n"); );
    VPID_regulacija__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBus(c+4,0,"u_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 14,0);
    tracep->declBus(c+5,0,"e_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+6,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+7,0,"areset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("PID_regulacija", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+4,0,"u_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 14,0);
    tracep->declBus(c+5,0,"e_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+6,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+7,0,"areset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+12,0,"k1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 9,0);
    tracep->declBus(c+13,0,"k2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 9,0);
    tracep->declBus(c+1,0,"u_prev",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+2,0,"e_prev",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+3,0,"e_prev1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declQuad(c+8,0,"d_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 35,0);
    tracep->declQuad(c+10,0,"d_wire",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 35,0);
    tracep->popPrefix();
}

VL_ATTR_COLD void VPID_regulacija___024root__trace_init_top(VPID_regulacija___024root* vlSelf, VerilatedFst* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPID_regulacija___024root__trace_init_top\n"); );
    VPID_regulacija__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    VPID_regulacija___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void VPID_regulacija___024root__trace_const_0(void* voidSelf, VerilatedFst::Buffer* bufp);
VL_ATTR_COLD void VPID_regulacija___024root__trace_full_0(void* voidSelf, VerilatedFst::Buffer* bufp);
void VPID_regulacija___024root__trace_chg_0(void* voidSelf, VerilatedFst::Buffer* bufp);
void VPID_regulacija___024root__trace_cleanup(void* voidSelf, VerilatedFst* /*unused*/);

VL_ATTR_COLD void VPID_regulacija___024root__trace_register(VPID_regulacija___024root* vlSelf, VerilatedFst* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPID_regulacija___024root__trace_register\n"); );
    VPID_regulacija__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    tracep->addConstCb(&VPID_regulacija___024root__trace_const_0, 0U, vlSelf);
    tracep->addFullCb(&VPID_regulacija___024root__trace_full_0, 0U, vlSelf);
    tracep->addChgCb(&VPID_regulacija___024root__trace_chg_0, 0U, vlSelf);
    tracep->addCleanupCb(&VPID_regulacija___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void VPID_regulacija___024root__trace_const_0_sub_0(VPID_regulacija___024root* vlSelf, VerilatedFst::Buffer* bufp);

VL_ATTR_COLD void VPID_regulacija___024root__trace_const_0(void* voidSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPID_regulacija___024root__trace_const_0\n"); );
    // Init
    VPID_regulacija___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VPID_regulacija___024root*>(voidSelf);
    VPID_regulacija__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    VPID_regulacija___024root__trace_const_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void VPID_regulacija___024root__trace_const_0_sub_0(VPID_regulacija___024root* vlSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPID_regulacija___024root__trace_const_0_sub_0\n"); );
    VPID_regulacija__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullSData(oldp+12,(0xaU),10);
    bufp->fullSData(oldp+13,(1U),10);
}

VL_ATTR_COLD void VPID_regulacija___024root__trace_full_0_sub_0(VPID_regulacija___024root* vlSelf, VerilatedFst::Buffer* bufp);

VL_ATTR_COLD void VPID_regulacija___024root__trace_full_0(void* voidSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPID_regulacija___024root__trace_full_0\n"); );
    // Init
    VPID_regulacija___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VPID_regulacija___024root*>(voidSelf);
    VPID_regulacija__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    VPID_regulacija___024root__trace_full_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void VPID_regulacija___024root__trace_full_0_sub_0(VPID_regulacija___024root* vlSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPID_regulacija___024root__trace_full_0_sub_0\n"); );
    VPID_regulacija__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullSData(oldp+1,(vlSelfRef.PID_regulacija__DOT__u_prev),16);
    bufp->fullSData(oldp+2,(vlSelfRef.PID_regulacija__DOT__e_prev),16);
    bufp->fullSData(oldp+3,(vlSelfRef.PID_regulacija__DOT__e_prev1),16);
    bufp->fullSData(oldp+4,(vlSelfRef.u_out),15);
    bufp->fullSData(oldp+5,(vlSelfRef.e_in),16);
    bufp->fullBit(oldp+6,(vlSelfRef.clk));
    bufp->fullBit(oldp+7,(vlSelfRef.areset));
    bufp->fullQData(oldp+8,(vlSelfRef.PID_regulacija__DOT__d_reg),36);
    bufp->fullQData(oldp+10,(vlSelfRef.PID_regulacija__DOT__d_wire),36);
}
