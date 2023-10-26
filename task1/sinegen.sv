`include "counter.sv"
`include "rom.sv"


module sinegen #(
    parameter WIDTH = 8
)(
    // interface signals
    input logic [WIDTH-1:0] _incr,
    input logic _rst,
    input logic _en,
    input logic _clk,
    output logic [WIDTH-1:0] _dout 
);

// interconnect wirte
logic [WIDTH-1:0] _count;

counter Counter(
    .incr(_incr),
    .rst(_rst),
    .en(_en),
    .clk(_clk),
    .count(_count)
);

rom Rom(
    .addr(_count),
    .clk(_clk),
    .dout(_dout)
);

endmodule
