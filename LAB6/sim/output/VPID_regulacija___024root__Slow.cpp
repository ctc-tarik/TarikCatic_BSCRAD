// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VPID_regulacija.h for the primary calling header

#include "VPID_regulacija__pch.h"
#include "VPID_regulacija__Syms.h"
#include "VPID_regulacija___024root.h"

void VPID_regulacija___024root___ctor_var_reset(VPID_regulacija___024root* vlSelf);

VPID_regulacija___024root::VPID_regulacija___024root(VPID_regulacija__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    VPID_regulacija___024root___ctor_var_reset(this);
}

void VPID_regulacija___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

VPID_regulacija___024root::~VPID_regulacija___024root() {
}
