// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vzad1.h for the primary calling header

#include "Vzad1__pch.h"
#include "Vzad1__Syms.h"
#include "Vzad1___024root.h"

void Vzad1___024root___ctor_var_reset(Vzad1___024root* vlSelf);

Vzad1___024root::Vzad1___024root(Vzad1__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vzad1___024root___ctor_var_reset(this);
}

void Vzad1___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vzad1___024root::~Vzad1___024root() {
}
