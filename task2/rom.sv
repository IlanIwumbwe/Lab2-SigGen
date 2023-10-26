module rom #(
    parameter ADDRESS_WIDTH = 8,
    parameter DATA_WIDTH = 8
)(
    // interface signals
    input logic [ADDRESS_WIDTH-1:0] addr1,
    input logic [ADDRESS_WIDTH-1:0] addr2,
    input logic clk,
    output logic [DATA_WIDTH-1:0] dout1,
    output logic [DATA_WIDTH-1:0] dout2
);

logic [DATA_WIDTH-1:0] rom_array [2**ADDRESS_WIDTH-1:0];

// load memory
initial begin
    $display("Loading memory");
    $readmemh("sinerom.mem", rom_array);
end

always_ff @(posedge clk) begin
    dout1 <= rom_array[addr1];
    dout2 <= rom_array[addr2];
end

endmodule
