// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vzad1__pch.h"
#include "verilated_fst_c.h"

//============================================================
// Constructors

Vzad1::Vzad1(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vzad1__Syms(contextp(), _vcname__, this)}
    , A{vlSymsp->TOP.A}
    , B{vlSymsp->TOP.B}
    , C{vlSymsp->TOP.C}
    , Y{vlSymsp->TOP.Y}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
    contextp()->traceBaseModelCbAdd(
        [this](VerilatedTraceBaseC* tfp, int levels, int options) { traceBaseModel(tfp, levels, options); });
}

Vzad1::Vzad1(const char* _vcname__)
    : Vzad1(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vzad1::~Vzad1() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vzad1___024root___eval_debug_assertions(Vzad1___024root* vlSelf);
#endif  // VL_DEBUG
void Vzad1___024root___eval_static(Vzad1___024root* vlSelf);
void Vzad1___024root___eval_initial(Vzad1___024root* vlSelf);
void Vzad1___024root___eval_settle(Vzad1___024root* vlSelf);
void Vzad1___024root___eval(Vzad1___024root* vlSelf);

void Vzad1::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vzad1::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vzad1___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vzad1___024root___eval_static(&(vlSymsp->TOP));
        Vzad1___024root___eval_initial(&(vlSymsp->TOP));
        Vzad1___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vzad1___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vzad1::eventsPending() { return false; }

uint64_t Vzad1::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vzad1::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vzad1___024root___eval_final(Vzad1___024root* vlSelf);

VL_ATTR_COLD void Vzad1::final() {
    Vzad1___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vzad1::hierName() const { return vlSymsp->name(); }
const char* Vzad1::modelName() const { return "Vzad1"; }
unsigned Vzad1::threads() const { return 1; }
void Vzad1::prepareClone() const { contextp()->prepareClone(); }
void Vzad1::atClone() const {
    contextp()->threadPoolpOnClone();
}
std::unique_ptr<VerilatedTraceConfig> Vzad1::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void Vzad1___024root__trace_decl_types(VerilatedFst* tracep);

void Vzad1___024root__trace_init_top(Vzad1___024root* vlSelf, VerilatedFst* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedFst* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vzad1___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vzad1___024root*>(voidSelf);
    Vzad1__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->pushPrefix(std::string{vlSymsp->name()}, VerilatedTracePrefixType::SCOPE_MODULE);
    Vzad1___024root__trace_decl_types(tracep);
    Vzad1___024root__trace_init_top(vlSelf, tracep);
    tracep->popPrefix();
}

VL_ATTR_COLD void Vzad1___024root__trace_register(Vzad1___024root* vlSelf, VerilatedFst* tracep);

VL_ATTR_COLD void Vzad1::traceBaseModel(VerilatedTraceBaseC* tfp, int levels, int options) {
    (void)levels; (void)options;
    VerilatedFstC* const stfp = dynamic_cast<VerilatedFstC*>(tfp);
    if (VL_UNLIKELY(!stfp)) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'Vzad1::trace()' called on non-VerilatedFstC object;"
            " use --trace-fst with VerilatedFst object, and --trace-vcd with VerilatedVcd object");
    }
    stfp->spTrace()->addModel(this);
    stfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    Vzad1___024root__trace_register(&(vlSymsp->TOP), stfp->spTrace());
}
