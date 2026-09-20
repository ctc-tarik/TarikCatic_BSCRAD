// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vmealy_struktura.h for the primary calling header

#include "Vmealy_struktura__pch.h"
#include "Vmealy_struktura__Syms.h"
#include "Vmealy_struktura___024root.h"

void Vmealy_struktura___024root___ctor_var_reset(Vmealy_struktura___024root* vlSelf);

Vmealy_struktura___024root::Vmealy_struktura___024root(Vmealy_struktura__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vmealy_struktura___024root___ctor_var_reset(this);
}

void Vmealy_struktura___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vmealy_struktura___024root::~Vmealy_struktura___024root() {
}
