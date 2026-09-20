// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_fst_c.h"
#include "Vzad1__Syms.h"


VL_ATTR_COLD void Vzad1___024root__trace_init_sub__TOP__0(Vzad1___024root* vlSelf, VerilatedFst* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vzad1___024root__trace_init_sub__TOP__0\n"); );
    Vzad1__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBit(c+1,0,"A",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+2,0,"B",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+3,0,"C",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+4,0,"Y",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("zad1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+1,0,"A",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+2,0,"B",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+3,0,"C",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+4,0,"Y",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
}

VL_ATTR_COLD void Vzad1___024root__trace_init_top(Vzad1___024root* vlSelf, VerilatedFst* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vzad1___024root__trace_init_top\n"); );
    Vzad1__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vzad1___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vzad1___024root__trace_const_0(void* voidSelf, VerilatedFst::Buffer* bufp);
VL_ATTR_COLD void Vzad1___024root__trace_full_0(void* voidSelf, VerilatedFst::Buffer* bufp);
void Vzad1___024root__trace_chg_0(void* voidSelf, VerilatedFst::Buffer* bufp);
void Vzad1___024root__trace_cleanup(void* voidSelf, VerilatedFst* /*unused*/);

VL_ATTR_COLD void Vzad1___024root__trace_register(Vzad1___024root* vlSelf, VerilatedFst* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vzad1___024root__trace_register\n"); );
    Vzad1__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    tracep->addConstCb(&Vzad1___024root__trace_const_0, 0U, vlSelf);
    tracep->addFullCb(&Vzad1___024root__trace_full_0, 0U, vlSelf);
    tracep->addChgCb(&Vzad1___024root__trace_chg_0, 0U, vlSelf);
    tracep->addCleanupCb(&Vzad1___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vzad1___024root__trace_const_0(void* voidSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vzad1___024root__trace_const_0\n"); );
    // Init
    Vzad1___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vzad1___024root*>(voidSelf);
    Vzad1__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
}

VL_ATTR_COLD void Vzad1___024root__trace_full_0_sub_0(Vzad1___024root* vlSelf, VerilatedFst::Buffer* bufp);

VL_ATTR_COLD void Vzad1___024root__trace_full_0(void* voidSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vzad1___024root__trace_full_0\n"); );
    // Init
    Vzad1___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vzad1___024root*>(voidSelf);
    Vzad1__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vzad1___024root__trace_full_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vzad1___024root__trace_full_0_sub_0(Vzad1___024root* vlSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vzad1___024root__trace_full_0_sub_0\n"); );
    Vzad1__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullBit(oldp+1,(vlSelfRef.A));
    bufp->fullBit(oldp+2,(vlSelfRef.B));
    bufp->fullBit(oldp+3,(vlSelfRef.C));
    bufp->fullBit(oldp+4,(vlSelfRef.Y));
}
