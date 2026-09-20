// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VPID_REGULACIJA__SYMS_H_
#define VERILATED_VPID_REGULACIJA__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "VPID_regulacija.h"

// INCLUDE MODULE CLASSES
#include "VPID_regulacija___024root.h"

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES)VPID_regulacija__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    VPID_regulacija* const __Vm_modelp;
    bool __Vm_activity = false;  ///< Used by trace routines to determine change occurred
    uint32_t __Vm_baseCode = 0;  ///< Used by trace routines when tracing multiple models
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    VPID_regulacija___024root      TOP;

    // CONSTRUCTORS
    VPID_regulacija__Syms(VerilatedContext* contextp, const char* namep, VPID_regulacija* modelp);
    ~VPID_regulacija__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
};

#endif  // guard
