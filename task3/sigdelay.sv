`include "counter.sv"
`include "ram.sv"

module sigdelay#(
    parameter DATA_WIDTH = 8,
    parameter ADDRESS_WIDTH = 9
)(  
    input logic [DATA_WIDTH-1:0] mic_signal,
    input logic _clk,
    input logic wr,
    input logic rd,
    input logic _rst,
    input logic [ADDRESS_WIDTH-1:0] offset,
    output logic [DATA_WIDTH-1:0] delayed_signal
);

    logic [ADDRESS_WIDTH-1:0] _count;  // interconnecting wire

    counter address(
        .clk(_clk),
        .rst(_rst),
        .count(_count)
    );

    ram memory(
        .wren(wr),
        .ren(rd),
        .clk(_clk),
        .din(mic_signal),
        .wraddr(_count),
        .raddr(_count - offset),
        .dout(delayed_signal)
    );

endmodule
