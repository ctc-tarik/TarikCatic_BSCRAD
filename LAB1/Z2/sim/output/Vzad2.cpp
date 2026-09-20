// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vzad2__pch.h"
#include "verilated_fst_c.h"

//============================================================
// Constructors

Vzad2::Vzad2(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vzad2__Syms(contextp(), _vcname__, this)}
    , A{vlSymsp->TOP.A}
    , B{vlSymsp->TOP.B}
    , C{vlSymsp->TOP.C}
    , D{vlSymsp->TOP.D}
    , E{vlSymsp->TOP.E}
    , Y{vlSymsp->TOP.Y}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
    contextp()->traceBaseModelCbAdd(
        [this](VerilatedTraceBaseC* tfp, int levels, int options) { traceBaseModel(tfp, levels, options); });
}

Vzad2::Vzad2(const char* _vcname__)
    : Vzad2(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vzad2::~Vzad2() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vzad2___024root___eval_debug_assertions(Vzad2___024root* vlSelf);
#endif  // VL_DEBUG
void Vzad2___024root___eval_static(Vzad2___024root* vlSelf);
void Vzad2___024root___eval_initial(Vzad2___024root* vlSelf);
void Vzad2___024root___eval_settle(Vzad2___024root* vlSelf);
void Vzad2___024root___eval(Vzad2___024root* vlSelf);

void Vzad2::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vzad2::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vzad2___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vzad2___024root___eval_static(&(vlSymsp->TOP));
        Vzad2___024root___eval_initial(&(vlSymsp->TOP));
        Vzad2___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vzad2___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vzad2::eventsPending() { return false; }

uint64_t Vzad2::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vzad2::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vzad2___024root___eval_final(Vzad2___024root* vlSelf);

VL_ATTR_COLD void Vzad2::final() {
    Vzad2___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vzad2::hierName() const { return vlSymsp->name(); }
const char* Vzad2::modelName() const { return "Vzad2"; }
unsigned Vzad2::threads() const { return 1; }
void Vzad2::prepareClone() const { contextp()->prepareClone(); }
void Vzad2::atClone() const {
    contextp()->threadPoolpOnClone();
}
std::unique_ptr<VerilatedTraceConfig> Vzad2::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void Vzad2___024root__trace_decl_types(VerilatedFst* tracep);

void Vzad2___024root__trace_init_top(Vzad2___024root* vlSelf, VerilatedFst* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedFst* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vzad2___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vzad2___024root*>(voidSelf);
    Vzad2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->pushPrefix(std::string{vlSymsp->name()}, VerilatedTracePrefixType::SCOPE_MODULE);
    Vzad2___024root__trace_decl_types(tracep);
    Vzad2___024root__trace_init_top(vlSelf, tracep);
    tracep->popPrefix();
}

VL_ATTR_COLD void Vzad2___024root__trace_register(Vzad2___024root* vlSelf, VerilatedFst* tracep);

VL_ATTR_COLD void Vzad2::traceBaseModel(VerilatedTraceBaseC* tfp, int levels, int options) {
    (void)levels; (void)options;
    VerilatedFstC* const stfp = dynamic_cast<VerilatedFstC*>(tfp);
    if (VL_UNLIKELY(!stfp)) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'Vzad2::trace()' called on non-VerilatedFstC object;"
            " use --trace-fst with VerilatedFst object, and --trace-vcd with VerilatedVcd object");
    }
    stfp->spTrace()->addModel(this);
    stfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    Vzad2___024root__trace_register(&(vlSymsp->TOP), stfp->spTrace());
}
