// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vzad2.h for the primary calling header

#include "Vzad2__pch.h"
#include "Vzad2__Syms.h"
#include "Vzad2___024root.h"

void Vzad2___024root___ctor_var_reset(Vzad2___024root* vlSelf);

Vzad2___024root::Vzad2___024root(Vzad2__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vzad2___024root___ctor_var_reset(this);
}

void Vzad2___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vzad2___024root::~Vzad2___024root() {
}
