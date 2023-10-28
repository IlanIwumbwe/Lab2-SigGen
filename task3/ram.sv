module ram #(
    parameter DATA_WIDTH = 8,
    parameter ADDRESS_WIDTH = 9
)(
    input logic [ADDRESS_WIDTH-1:0] wraddr,
    input logic [ADDRESS_WIDTH-1:0] raddr,
    input logic [DATA_WIDTH-1:0] din,
    input logic clk,
    input logic wren,
    input logic ren,
    output logic [DATA_WIDTH-1:0] dout
);

// ram
logic [DATA_WIDTH-1:0] ram_array [2**ADDRESS_WIDTH-1:0];

always_ff @(posedge clk) begin
    if (wren == 1'b1) begin 
        ram_array[wraddr] <= din;
    end 

    if (ren == 1'b1) begin
        dout <= ram_array[raddr];
    end
    
end

endmodule

