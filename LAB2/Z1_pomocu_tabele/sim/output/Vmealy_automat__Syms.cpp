// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vmealy_automat__pch.h"
#include "Vmealy_automat.h"
#include "Vmealy_automat___024root.h"

// FUNCTIONS
Vmealy_automat__Syms::~Vmealy_automat__Syms()
{
}

Vmealy_automat__Syms::Vmealy_automat__Syms(VerilatedContext* contextp, const char* namep, Vmealy_automat* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    // Setup module instances
    , TOP{this, namep}
{
        // Check resources
        Verilated::stackCheck(31);
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-9);
    _vm_contextp__->timeprecision(-9);
    // Setup each module's pointers to their submodules
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
}
