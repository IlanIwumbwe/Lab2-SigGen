#!/bin/sh

# cleanup
rm -rf obj_dir
rm -f sigdelay.vcd

# run Verilator to translate Verlig into C++, including C++ testbench
verilator -Wall --cc --trace sigdelay.sv --exe sigdelay_tb.cpp

# build C++ project via make file automatically generated by Verilator
make -j -C obj_dir/ -f Vsigdelay.mk Vsigdelay

# run the executable simulation file
obj_dir/Vsigdelay