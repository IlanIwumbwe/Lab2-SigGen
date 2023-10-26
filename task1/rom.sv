module rom #(
	parameter ADDRESS_WIDTH = 8,
	parameter DATA_WIDTH = 8
)(
// interface signals
	input logic [ADDRESS_WIDTH-1:0] addr,
	input logic clk,
	output logic [DATA_WIDTH-1:0] dout
);

logic [DATA_WIDTH-1:0] rom_array [2**ADDRESS_WIDTH-1:0];
// load memory
initial begin
	$display("Loading memory");
	$readmemh("sinerom.mem", rom_array);
end

always_ff @(posedge clk) begin
	dout <= rom_array[addr];
end
endmodule