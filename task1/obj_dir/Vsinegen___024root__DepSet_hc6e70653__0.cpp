// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsinegen.h for the primary calling header

#include "verilated.h"

#include "Vsinegen___024root.h"

VL_INLINE_OPT void Vsinegen___024root___sequent__TOP__0(Vsinegen___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsinegen__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsinegen___024root___sequent__TOP__0\n"); );
    // Body
    vlSelf->_dout = vlSelf->sinegen__DOT__Rom__DOT__rom_array
        [vlSelf->sinegen__DOT___count];
}

VL_INLINE_OPT void Vsinegen___024root___sequent__TOP__1(Vsinegen___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsinegen__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsinegen___024root___sequent__TOP__1\n"); );
    // Body
    vlSelf->sinegen__DOT___count = ((IData)(vlSelf->_rst)
                                     ? 0U : (0xffU 
                                             & ((IData)(vlSelf->sinegen__DOT___count) 
                                                + ((IData)(vlSelf->_en)
                                                    ? (IData)(vlSelf->_incr)
                                                    : 0U))));
}

void Vsinegen___024root___eval(Vsinegen___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsinegen__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsinegen___024root___eval\n"); );
    // Body
    if (((IData)(vlSelf->_clk) & (~ (IData)(vlSelf->__Vclklast__TOP___clk)))) {
        Vsinegen___024root___sequent__TOP__0(vlSelf);
    }
    if ((((IData)(vlSelf->_clk) & (~ (IData)(vlSelf->__Vclklast__TOP___clk))) 
         | ((~ (IData)(vlSelf->_rst)) & (IData)(vlSelf->__Vclklast__TOP___rst)))) {
        Vsinegen___024root___sequent__TOP__1(vlSelf);
    }
    // Final
    vlSelf->__Vclklast__TOP___clk = vlSelf->_clk;
    vlSelf->__Vclklast__TOP___rst = vlSelf->_rst;
}

#ifdef VL_DEBUG
void Vsinegen___024root___eval_debug_assertions(Vsinegen___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsinegen__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsinegen___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->_rst & 0xfeU))) {
        Verilated::overWidthError("_rst");}
    if (VL_UNLIKELY((vlSelf->_en & 0xfeU))) {
        Verilated::overWidthError("_en");}
    if (VL_UNLIKELY((vlSelf->_clk & 0xfeU))) {
        Verilated::overWidthError("_clk");}
}
#endif  // VL_DEBUG
