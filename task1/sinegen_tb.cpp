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
top->_incr = 1;
top->_en = 1;

// run simulation for many clock cycles
for(int i = 0; i < 10^6; i++){
	vbdPlot(top->_dout, 0, 255);
	vbdCycle(i+1);
	top->_en = vbdFlag();
	top->_incr = vbdValue() / 20;
	
	if(Verilated::gotFinish() || vbdGetkey() == 'q') exit(0);  
	
	for(clk=0; clk<2; clk++){
		top->_clk = !top->_clk;
		top->eval();
	}

}

vbdClose();
exit(0);

}