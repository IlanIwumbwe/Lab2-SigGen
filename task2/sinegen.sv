`include "counter.sv"
`include "rom.sv"

module sinegen #(
    parameter WIDTH = 8
)(
    // interface signals
    input logic [WIDTH-1:0] _phase,
    input logic _rst,
    input logic _en,
    input logic _clk,
    output logic [WIDTH-1:0] _dout1,
    output logic [WIDTH-1:0] _dout2
);

// interconnect wire
logic [WIDTH-1:0] _count;
logic _incr = 3;

counter Counter(
    .incr(_incr),
    .rst(_rst),
    .en(_en),
    .clk(_clk),
    .count(_count)
);

rom Rom(
    .addr1(_count),
    .addr2(_count + _phase),
    .clk(_clk),
    .dout1(_dout1),
    .dout2(_dout2)
);

endmodule
