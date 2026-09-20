// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vmealy_struktura__pch.h"
#include "verilated_fst_c.h"

//============================================================
// Constructors

Vmealy_struktura::Vmealy_struktura(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vmealy_struktura__Syms(contextp(), _vcname__, this)}
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

Vmealy_struktura::Vmealy_struktura(const char* _vcname__)
    : Vmealy_struktura(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vmealy_struktura::~Vmealy_struktura() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vmealy_struktura___024root___eval_debug_assertions(Vmealy_struktura___024root* vlSelf);
#endif  // VL_DEBUG
void Vmealy_struktura___024root___eval_static(Vmealy_struktura___024root* vlSelf);
void Vmealy_struktura___024root___eval_initial(Vmealy_struktura___024root* vlSelf);
void Vmealy_struktura___024root___eval_settle(Vmealy_struktura___024root* vlSelf);
void Vmealy_struktura___024root___eval(Vmealy_struktura___024root* vlSelf);

void Vmealy_struktura::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vmealy_struktura::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vmealy_struktura___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vmealy_struktura___024root___eval_static(&(vlSymsp->TOP));
        Vmealy_struktura___024root___eval_initial(&(vlSymsp->TOP));
        Vmealy_struktura___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vmealy_struktura___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vmealy_struktura::eventsPending() { return false; }

uint64_t Vmealy_struktura::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vmealy_struktura::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vmealy_struktura___024root___eval_final(Vmealy_struktura___024root* vlSelf);

VL_ATTR_COLD void Vmealy_struktura::final() {
    Vmealy_struktura___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vmealy_struktura::hierName() const { return vlSymsp->name(); }
const char* Vmealy_struktura::modelName() const { return "Vmealy_struktura"; }
unsigned Vmealy_struktura::threads() const { return 1; }
void Vmealy_struktura::prepareClone() const { contextp()->prepareClone(); }
void Vmealy_struktura::atClone() const {
    contextp()->threadPoolpOnClone();
}
std::unique_ptr<VerilatedTraceConfig> Vmealy_struktura::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void Vmealy_struktura___024root__trace_decl_types(VerilatedFst* tracep);

void Vmealy_struktura___024root__trace_init_top(Vmealy_struktura___024root* vlSelf, VerilatedFst* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedFst* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vmealy_struktura___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vmealy_struktura___024root*>(voidSelf);
    Vmealy_struktura__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->pushPrefix(std::string{vlSymsp->name()}, VerilatedTracePrefixType::SCOPE_MODULE);
    Vmealy_struktura___024root__trace_decl_types(tracep);
    Vmealy_struktura___024root__trace_init_top(vlSelf, tracep);
    tracep->popPrefix();
}

VL_ATTR_COLD void Vmealy_struktura___024root__trace_register(Vmealy_struktura___024root* vlSelf, VerilatedFst* tracep);

VL_ATTR_COLD void Vmealy_struktura::traceBaseModel(VerilatedTraceBaseC* tfp, int levels, int options) {
    (void)levels; (void)options;
    VerilatedFstC* const stfp = dynamic_cast<VerilatedFstC*>(tfp);
    if (VL_UNLIKELY(!stfp)) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'Vmealy_struktura::trace()' called on non-VerilatedFstC object;"
            " use --trace-fst with VerilatedFst object, and --trace-vcd with VerilatedVcd object");
    }
    stfp->spTrace()->addModel(this);
    stfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    Vmealy_struktura___024root__trace_register(&(vlSymsp->TOP), stfp->spTrace());
}
