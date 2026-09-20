// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_fst_c.h"
#include "Vmealy_struktura__Syms.h"


VL_ATTR_COLD void Vmealy_struktura___024root__trace_init_sub__TOP__0(Vmealy_struktura___024root* vlSelf, VerilatedFst* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmealy_struktura___024root__trace_init_sub__TOP__0\n"); );
    Vmealy_struktura__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBit(c+1,0,"U",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+2,0,"Cp",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+3,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+4,0,"Z",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+5,0,"stanje",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->pushPrefix("mealy_struktura", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+1,0,"U",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+2,0,"Cp",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+3,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+4,0,"Z",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
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

VL_ATTR_COLD void Vmealy_struktura___024root__trace_init_top(Vmealy_struktura___024root* vlSelf, VerilatedFst* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmealy_struktura___024root__trace_init_top\n"); );
    Vmealy_struktura__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vmealy_struktura___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vmealy_struktura___024root__trace_const_0(void* voidSelf, VerilatedFst::Buffer* bufp);
VL_ATTR_COLD void Vmealy_struktura___024root__trace_full_0(void* voidSelf, VerilatedFst::Buffer* bufp);
void Vmealy_struktura___024root__trace_chg_0(void* voidSelf, VerilatedFst::Buffer* bufp);
void Vmealy_struktura___024root__trace_cleanup(void* voidSelf, VerilatedFst* /*unused*/);

VL_ATTR_COLD void Vmealy_struktura___024root__trace_register(Vmealy_struktura___024root* vlSelf, VerilatedFst* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmealy_struktura___024root__trace_register\n"); );
    Vmealy_struktura__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    tracep->addConstCb(&Vmealy_struktura___024root__trace_const_0, 0U, vlSelf);
    tracep->addFullCb(&Vmealy_struktura___024root__trace_full_0, 0U, vlSelf);
    tracep->addChgCb(&Vmealy_struktura___024root__trace_chg_0, 0U, vlSelf);
    tracep->addCleanupCb(&Vmealy_struktura___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vmealy_struktura___024root__trace_const_0(void* voidSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmealy_struktura___024root__trace_const_0\n"); );
    // Init
    Vmealy_struktura___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vmealy_struktura___024root*>(voidSelf);
    Vmealy_struktura__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
}

VL_ATTR_COLD void Vmealy_struktura___024root__trace_full_0_sub_0(Vmealy_struktura___024root* vlSelf, VerilatedFst::Buffer* bufp);

VL_ATTR_COLD void Vmealy_struktura___024root__trace_full_0(void* voidSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmealy_struktura___024root__trace_full_0\n"); );
    // Init
    Vmealy_struktura___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vmealy_struktura___024root*>(voidSelf);
    Vmealy_struktura__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vmealy_struktura___024root__trace_full_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vmealy_struktura___024root__trace_full_0_sub_0(Vmealy_struktura___024root* vlSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmealy_struktura___024root__trace_full_0_sub_0\n"); );
    Vmealy_struktura__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullBit(oldp+1,(vlSelfRef.U));
    bufp->fullBit(oldp+2,(vlSelfRef.Cp));
    bufp->fullBit(oldp+3,(vlSelfRef.reset));
    bufp->fullCData(oldp+4,(vlSelfRef.Z),2);
    bufp->fullCData(oldp+5,(vlSelfRef.stanje),2);
    bufp->fullBit(oldp+6,(vlSelfRef.mealy_struktura__DOT__Q1));
    bufp->fullBit(oldp+7,(vlSelfRef.mealy_struktura__DOT__Q0));
    bufp->fullBit(oldp+8,((((IData)(vlSelfRef.mealy_struktura__DOT__Q1) 
                            & (IData)(vlSelfRef.U)) 
                           | ((IData)(vlSelfRef.mealy_struktura__DOT__Q0) 
                              & (~ (IData)(vlSelfRef.U))))));
    bufp->fullBit(oldp+9,((1U & ((IData)(vlSelfRef.mealy_struktura__DOT__Q0) 
                                 | (~ (IData)(vlSelfRef.U))))));
}
