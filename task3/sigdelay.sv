`include "counter.sv"
`include "ram.sv"

module sigdelay#(
    parameter DATA_WIDTH = 8,
    parameter ADDRESS_WIDTH = 9
)(  
    input logic [DATA_WIDTH-1:0] mic_signal,
    input logic clk,
    input logic wr,
    input logic rd,
    input logic rst,
    input logic offset,
    output logic [DATA_WIDTH-1:0] delayed_signal
);
    ram Ram(
        




    );






endmodule
