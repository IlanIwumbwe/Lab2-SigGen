// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vsinegen__Syms.h"


void Vsinegen___024root__trace_chg_sub_0(Vsinegen___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vsinegen___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsinegen___024root__trace_chg_top_0\n"); );
    // Init
    Vsinegen___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vsinegen___024root*>(voidSelf);
    Vsinegen__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vsinegen___024root__trace_chg_sub_0((&vlSymsp->TOP), bufp);
}

void Vsinegen___024root__trace_chg_sub_0(Vsinegen___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vsinegen__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsinegen___024root__trace_chg_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    bufp->chgBit(oldp+0,(vlSelf->_clk));
    bufp->chgBit(oldp+1,(vlSelf->_rst));
    bufp->chgBit(oldp+2,(vlSelf->_en));
    bufp->chgCData(oldp+3,(vlSelf->_incr),8);
    bufp->chgCData(oldp+4,(vlSelf->sinegen__DOT___count),8);
    bufp->chgCData(oldp+5,(vlSelf->_dout),8);
}

void Vsinegen___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsinegen___024root__trace_cleanup\n"); );
    // Init
    Vsinegen___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vsinegen___024root*>(voidSelf);
    Vsinegen__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VlUnpacked<CData/*0:0*/, 1> __Vm_traceActivity;
    // Body
    vlSymsp->__Vm_activity = false;
    __Vm_traceActivity[0U] = 0U;
}
