#include "Vsinegen.h"   
#include "verilated.h"
#include "verilated_vcd_c.h"
#include "vbuddy.cpp"

int main(int argc, char** argv, char** env){
    int i;
    int clk;

    // initialise DUT instance 
    Verilated::commandArgs(argc, argv);

    Vsinegen* top = new Vsinegen;

    // init vbuddy
    if (vbdOpen()!=1) return(-1);
    vbdHeader("Lab 2: SineGen");
    vbdSetMode(0);

    top->_clk = 1;
    top->_rst = 0;
    top->_en = 1;

    // run simulation for many clock cycles

    for(int i = 0; i < 10^6; i++){
        top->_phase = vbdValue();

        for(clk=0; clk<2; clk++){
            top->_clk = !top->_clk;   
            top->eval();
        }

        vbdPlot(top->_dout1, 0, 255);
        vbdPlot(top->_dout2, 0, 255);

        vbdCycle(i+1);

        if(Verilated::gotFinish() || vbdGetkey() == 'q') exit(0);
    }

    vbdClose();
    exit(0);
}