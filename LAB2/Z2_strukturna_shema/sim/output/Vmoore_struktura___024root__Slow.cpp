// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vmoore_struktura.h for the primary calling header

#include "Vmoore_struktura__pch.h"
#include "Vmoore_struktura__Syms.h"
#include "Vmoore_struktura___024root.h"

void Vmoore_struktura___024root___ctor_var_reset(Vmoore_struktura___024root* vlSelf);

Vmoore_struktura___024root::Vmoore_struktura___024root(Vmoore_struktura__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vmoore_struktura___024root___ctor_var_reset(this);
}

void Vmoore_struktura___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vmoore_struktura___024root::~Vmoore_struktura___024root() {
}
