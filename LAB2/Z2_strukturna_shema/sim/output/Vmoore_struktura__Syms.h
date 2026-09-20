// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VMOORE_STRUKTURA__SYMS_H_
#define VERILATED_VMOORE_STRUKTURA__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vmoore_struktura.h"

// INCLUDE MODULE CLASSES
#include "Vmoore_struktura___024root.h"

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES)Vmoore_struktura__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vmoore_struktura* const __Vm_modelp;
    bool __Vm_activity = false;  ///< Used by trace routines to determine change occurred
    uint32_t __Vm_baseCode = 0;  ///< Used by trace routines when tracing multiple models
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vmoore_struktura___024root     TOP;

    // CONSTRUCTORS
    Vmoore_struktura__Syms(VerilatedContext* contextp, const char* namep, Vmoore_struktura* modelp);
    ~Vmoore_struktura__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
};

#endif  // guard
