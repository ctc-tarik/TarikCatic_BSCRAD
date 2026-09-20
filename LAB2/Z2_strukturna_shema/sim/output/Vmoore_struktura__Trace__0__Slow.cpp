// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_fst_c.h"
#include "Vmoore_struktura__Syms.h"


VL_ATTR_COLD void Vmoore_struktura___024root__trace_init_sub__TOP__0(Vmoore_struktura___024root* vlSelf, VerilatedFst* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmoore_struktura___024root__trace_init_sub__TOP__0\n"); );
    Vmoore_struktura__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBit(c+1,0,"U",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+2,0,"Cp",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+3,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+4,0,"Z",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+5,0,"stanje",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->pushPrefix("moore_struktura", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+1,0,"U",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+2,0,"Cp",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+3,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+4,0,"Z",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+5,0,"stanje",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+6,0,"Q1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+7,0,"Q0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+8,0,"T1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+9,0,"T2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("flipflop1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+8,0,"T",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+2,0,"Cp",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+3,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+6,0,"Q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("flipflop2", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+9,0,"T",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+2,0,"Cp",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+3,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+7,0,"Q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
}

VL_ATTR_COLD void Vmoore_struktura___024root__trace_init_top(Vmoore_struktura___024root* vlSelf, VerilatedFst* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmoore_struktura___024root__trace_init_top\n"); );
    Vmoore_struktura__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vmoore_struktura___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vmoore_struktura___024root__trace_const_0(void* voidSelf, VerilatedFst::Buffer* bufp);
VL_ATTR_COLD void Vmoore_struktura___024root__trace_full_0(void* voidSelf, VerilatedFst::Buffer* bufp);
void Vmoore_struktura___024root__trace_chg_0(void* voidSelf, VerilatedFst::Buffer* bufp);
void Vmoore_struktura___024root__trace_cleanup(void* voidSelf, VerilatedFst* /*unused*/);

VL_ATTR_COLD void Vmoore_struktura___024root__trace_register(Vmoore_struktura___024root* vlSelf, VerilatedFst* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmoore_struktura___024root__trace_register\n"); );
    Vmoore_struktura__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    tracep->addConstCb(&Vmoore_struktura___024root__trace_const_0, 0U, vlSelf);
    tracep->addFullCb(&Vmoore_struktura___024root__trace_full_0, 0U, vlSelf);
    tracep->addChgCb(&Vmoore_struktura___024root__trace_chg_0, 0U, vlSelf);
    tracep->addCleanupCb(&Vmoore_struktura___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vmoore_struktura___024root__trace_const_0_sub_0(Vmoore_struktura___024root* vlSelf, VerilatedFst::Buffer* bufp);

VL_ATTR_COLD void Vmoore_struktura___024root__trace_const_0(void* voidSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmoore_struktura___024root__trace_const_0\n"); );
    // Init
    Vmoore_struktura___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vmoore_struktura___024root*>(voidSelf);
    Vmoore_struktura__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vmoore_struktura___024root__trace_const_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vmoore_struktura___024root__trace_const_0_sub_0(Vmoore_struktura___024root* vlSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmoore_struktura___024root__trace_const_0_sub_0\n"); );
    Vmoore_struktura__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullBit(oldp+9,(1U));
}

VL_ATTR_COLD void Vmoore_struktura___024root__trace_full_0_sub_0(Vmoore_struktura___024root* vlSelf, VerilatedFst::Buffer* bufp);

VL_ATTR_COLD void Vmoore_struktura___024root__trace_full_0(void* voidSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmoore_struktura___024root__trace_full_0\n"); );
    // Init
    Vmoore_struktura___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vmoore_struktura___024root*>(voidSelf);
    Vmoore_struktura__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vmoore_struktura___024root__trace_full_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vmoore_struktura___024root__trace_full_0_sub_0(Vmoore_struktura___024root* vlSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmoore_struktura___024root__trace_full_0_sub_0\n"); );
    Vmoore_struktura__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullBit(oldp+1,(vlSelfRef.U));
    bufp->fullBit(oldp+2,(vlSelfRef.Cp));
    bufp->fullBit(oldp+3,(vlSelfRef.reset));
    bufp->fullBit(oldp+4,(vlSelfRef.Z));
    bufp->fullCData(oldp+5,(vlSelfRef.stanje),2);
    bufp->fullBit(oldp+6,(vlSelfRef.moore_struktura__DOT__Q1));
    bufp->fullBit(oldp+7,(vlSelfRef.moore_struktura__DOT__Q0));
    bufp->fullBit(oldp+8,((1U & ((((IData)(vlSelfRef.moore_struktura__DOT__Q1) 
                                   & (~ (IData)(vlSelfRef.U))) 
                                  | ((~ (IData)(vlSelfRef.moore_struktura__DOT__Q0)) 
                                     & (~ (IData)(vlSelfRef.U)))) 
                                 | (((IData)(vlSelfRef.moore_struktura__DOT__Q0) 
                                     & (IData)(vlSelfRef.U)) 
                                    & (~ (IData)(vlSelfRef.moore_struktura__DOT__Q1)))))));
}
