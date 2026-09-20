// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vmoore_struktura__pch.h"
#include "verilated_fst_c.h"

//============================================================
// Constructors

Vmoore_struktura::Vmoore_struktura(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vmoore_struktura__Syms(contextp(), _vcname__, this)}
    , Cp{vlSymsp->TOP.Cp}
    , reset{vlSymsp->TOP.reset}
    , U{vlSymsp->TOP.U}
    , Z{vlSymsp->TOP.Z}
    , stanje{vlSymsp->TOP.stanje}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
    contextp()->traceBaseModelCbAdd(
        [this](VerilatedTraceBaseC* tfp, int levels, int options) { traceBaseModel(tfp, levels, options); });
}

Vmoore_struktura::Vmoore_struktura(const char* _vcname__)
    : Vmoore_struktura(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vmoore_struktura::~Vmoore_struktura() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vmoore_struktura___024root___eval_debug_assertions(Vmoore_struktura___024root* vlSelf);
#endif  // VL_DEBUG
void Vmoore_struktura___024root___eval_static(Vmoore_struktura___024root* vlSelf);
void Vmoore_struktura___024root___eval_initial(Vmoore_struktura___024root* vlSelf);
void Vmoore_struktura___024root___eval_settle(Vmoore_struktura___024root* vlSelf);
void Vmoore_struktura___024root___eval(Vmoore_struktura___024root* vlSelf);

void Vmoore_struktura::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vmoore_struktura::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vmoore_struktura___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vmoore_struktura___024root___eval_static(&(vlSymsp->TOP));
        Vmoore_struktura___024root___eval_initial(&(vlSymsp->TOP));
        Vmoore_struktura___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vmoore_struktura___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vmoore_struktura::eventsPending() { return false; }

uint64_t Vmoore_struktura::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vmoore_struktura::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vmoore_struktura___024root___eval_final(Vmoore_struktura___024root* vlSelf);

VL_ATTR_COLD void Vmoore_struktura::final() {
    Vmoore_struktura___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vmoore_struktura::hierName() const { return vlSymsp->name(); }
const char* Vmoore_struktura::modelName() const { return "Vmoore_struktura"; }
unsigned Vmoore_struktura::threads() const { return 1; }
void Vmoore_struktura::prepareClone() const { contextp()->prepareClone(); }
void Vmoore_struktura::atClone() const {
    contextp()->threadPoolpOnClone();
}
std::unique_ptr<VerilatedTraceConfig> Vmoore_struktura::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void Vmoore_struktura___024root__trace_decl_types(VerilatedFst* tracep);

void Vmoore_struktura___024root__trace_init_top(Vmoore_struktura___024root* vlSelf, VerilatedFst* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedFst* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vmoore_struktura___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vmoore_struktura___024root*>(voidSelf);
    Vmoore_struktura__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->pushPrefix(std::string{vlSymsp->name()}, VerilatedTracePrefixType::SCOPE_MODULE);
    Vmoore_struktura___024root__trace_decl_types(tracep);
    Vmoore_struktura___024root__trace_init_top(vlSelf, tracep);
    tracep->popPrefix();
}

VL_ATTR_COLD void Vmoore_struktura___024root__trace_register(Vmoore_struktura___024root* vlSelf, VerilatedFst* tracep);

VL_ATTR_COLD void Vmoore_struktura::traceBaseModel(VerilatedTraceBaseC* tfp, int levels, int options) {
    (void)levels; (void)options;
    VerilatedFstC* const stfp = dynamic_cast<VerilatedFstC*>(tfp);
    if (VL_UNLIKELY(!stfp)) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'Vmoore_struktura::trace()' called on non-VerilatedFstC object;"
            " use --trace-fst with VerilatedFst object, and --trace-vcd with VerilatedVcd object");
    }
    stfp->spTrace()->addModel(this);
    stfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    Vmoore_struktura___024root__trace_register(&(vlSymsp->TOP), stfp->spTrace());
}
