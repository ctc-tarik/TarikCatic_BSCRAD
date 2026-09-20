// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vmoore_automat__pch.h"
#include "verilated_fst_c.h"

//============================================================
// Constructors

Vmoore_automat::Vmoore_automat(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vmoore_automat__Syms(contextp(), _vcname__, this)}
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

Vmoore_automat::Vmoore_automat(const char* _vcname__)
    : Vmoore_automat(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vmoore_automat::~Vmoore_automat() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vmoore_automat___024root___eval_debug_assertions(Vmoore_automat___024root* vlSelf);
#endif  // VL_DEBUG
void Vmoore_automat___024root___eval_static(Vmoore_automat___024root* vlSelf);
void Vmoore_automat___024root___eval_initial(Vmoore_automat___024root* vlSelf);
void Vmoore_automat___024root___eval_settle(Vmoore_automat___024root* vlSelf);
void Vmoore_automat___024root___eval(Vmoore_automat___024root* vlSelf);

void Vmoore_automat::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vmoore_automat::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vmoore_automat___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vmoore_automat___024root___eval_static(&(vlSymsp->TOP));
        Vmoore_automat___024root___eval_initial(&(vlSymsp->TOP));
        Vmoore_automat___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vmoore_automat___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vmoore_automat::eventsPending() { return false; }

uint64_t Vmoore_automat::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vmoore_automat::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vmoore_automat___024root___eval_final(Vmoore_automat___024root* vlSelf);

VL_ATTR_COLD void Vmoore_automat::final() {
    Vmoore_automat___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vmoore_automat::hierName() const { return vlSymsp->name(); }
const char* Vmoore_automat::modelName() const { return "Vmoore_automat"; }
unsigned Vmoore_automat::threads() const { return 1; }
void Vmoore_automat::prepareClone() const { contextp()->prepareClone(); }
void Vmoore_automat::atClone() const {
    contextp()->threadPoolpOnClone();
}
std::unique_ptr<VerilatedTraceConfig> Vmoore_automat::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void Vmoore_automat___024root__trace_decl_types(VerilatedFst* tracep);

void Vmoore_automat___024root__trace_init_top(Vmoore_automat___024root* vlSelf, VerilatedFst* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedFst* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vmoore_automat___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vmoore_automat___024root*>(voidSelf);
    Vmoore_automat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->pushPrefix(std::string{vlSymsp->name()}, VerilatedTracePrefixType::SCOPE_MODULE);
    Vmoore_automat___024root__trace_decl_types(tracep);
    Vmoore_automat___024root__trace_init_top(vlSelf, tracep);
    tracep->popPrefix();
}

VL_ATTR_COLD void Vmoore_automat___024root__trace_register(Vmoore_automat___024root* vlSelf, VerilatedFst* tracep);

VL_ATTR_COLD void Vmoore_automat::traceBaseModel(VerilatedTraceBaseC* tfp, int levels, int options) {
    (void)levels; (void)options;
    VerilatedFstC* const stfp = dynamic_cast<VerilatedFstC*>(tfp);
    if (VL_UNLIKELY(!stfp)) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'Vmoore_automat::trace()' called on non-VerilatedFstC object;"
            " use --trace-fst with VerilatedFst object, and --trace-vcd with VerilatedVcd object");
    }
    stfp->spTrace()->addModel(this);
    stfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    Vmoore_automat___024root__trace_register(&(vlSymsp->TOP), stfp->spTrace());
}
