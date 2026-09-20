// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vmealy_automat__pch.h"
#include "verilated_fst_c.h"

//============================================================
// Constructors

Vmealy_automat::Vmealy_automat(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vmealy_automat__Syms(contextp(), _vcname__, this)}
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

Vmealy_automat::Vmealy_automat(const char* _vcname__)
    : Vmealy_automat(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vmealy_automat::~Vmealy_automat() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vmealy_automat___024root___eval_debug_assertions(Vmealy_automat___024root* vlSelf);
#endif  // VL_DEBUG
void Vmealy_automat___024root___eval_static(Vmealy_automat___024root* vlSelf);
void Vmealy_automat___024root___eval_initial(Vmealy_automat___024root* vlSelf);
void Vmealy_automat___024root___eval_settle(Vmealy_automat___024root* vlSelf);
void Vmealy_automat___024root___eval(Vmealy_automat___024root* vlSelf);

void Vmealy_automat::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vmealy_automat::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vmealy_automat___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vmealy_automat___024root___eval_static(&(vlSymsp->TOP));
        Vmealy_automat___024root___eval_initial(&(vlSymsp->TOP));
        Vmealy_automat___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vmealy_automat___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vmealy_automat::eventsPending() { return false; }

uint64_t Vmealy_automat::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vmealy_automat::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vmealy_automat___024root___eval_final(Vmealy_automat___024root* vlSelf);

VL_ATTR_COLD void Vmealy_automat::final() {
    Vmealy_automat___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vmealy_automat::hierName() const { return vlSymsp->name(); }
const char* Vmealy_automat::modelName() const { return "Vmealy_automat"; }
unsigned Vmealy_automat::threads() const { return 1; }
void Vmealy_automat::prepareClone() const { contextp()->prepareClone(); }
void Vmealy_automat::atClone() const {
    contextp()->threadPoolpOnClone();
}
std::unique_ptr<VerilatedTraceConfig> Vmealy_automat::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void Vmealy_automat___024root__trace_decl_types(VerilatedFst* tracep);

void Vmealy_automat___024root__trace_init_top(Vmealy_automat___024root* vlSelf, VerilatedFst* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedFst* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vmealy_automat___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vmealy_automat___024root*>(voidSelf);
    Vmealy_automat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->pushPrefix(std::string{vlSymsp->name()}, VerilatedTracePrefixType::SCOPE_MODULE);
    Vmealy_automat___024root__trace_decl_types(tracep);
    Vmealy_automat___024root__trace_init_top(vlSelf, tracep);
    tracep->popPrefix();
}

VL_ATTR_COLD void Vmealy_automat___024root__trace_register(Vmealy_automat___024root* vlSelf, VerilatedFst* tracep);

VL_ATTR_COLD void Vmealy_automat::traceBaseModel(VerilatedTraceBaseC* tfp, int levels, int options) {
    (void)levels; (void)options;
    VerilatedFstC* const stfp = dynamic_cast<VerilatedFstC*>(tfp);
    if (VL_UNLIKELY(!stfp)) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'Vmealy_automat::trace()' called on non-VerilatedFstC object;"
            " use --trace-fst with VerilatedFst object, and --trace-vcd with VerilatedVcd object");
    }
    stfp->spTrace()->addModel(this);
    stfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    Vmealy_automat___024root__trace_register(&(vlSymsp->TOP), stfp->spTrace());
}
