
module MEM_WB(

	input   wire        clk,
	input   wire        rst,
	input   wire[5:0]   stall,	
	input   wire[4:0]   MemWriteNum,
	input   wire        MemWriteReg,
	input   wire[31:0]	MemWriteData,
	output  reg [4:0]   wbWriteNum,
	output  reg         wbWriteReg,
	output  reg [31:0]	wbWriteData     
	
);

/*
 * This always part controls the signal wbWriteNum.
 */
always @ (posedge clk) begin
    if (rst)
        wbWriteNum <= 5'b0;
    else if (stall[5:4] == 2'b01)
        wbWriteNum <= 5'b0;
    else if (!stall[4])
        wbWriteNum <= MemWriteNum;
end

/*
 * This always part controls the signal wbWriteReg.
 */
always @ (posedge clk) begin
    if (rst)
        wbWriteReg <= 1'b0;
    else if (stall[5:4] == 2'b01)
        wbWriteReg <= 1'b0;
    else if (!stall[4])
        wbWriteReg <= MemWriteReg;
end

/*
 * This always part controls the signal wbWriteData.
 */
always @ (posedge clk) begin
    if (rst)
        wbWriteData <= 32'b0;
    else if (stall[5:4] == 2'b01)
        wbWriteData <= 32'b0;
    else if (!stall[4])
        wbWriteData <= MemWriteData;
end			

endmodule