module VecMul2bit (A, B, C, CLK, RESET, DONE);
    // Adopted from https://stackoverflow.com/questions/42573947/verilog-vector-inner-product

    // Two vector inner product, each has 8 elements
    // Each element is 2 bits (unsigned)
    // So the Output should be at least 2^4*2^3 = 2^7 in order to
    // prevent overflow 
    // Output is 7 bits

    input CLK;
    input RESET;
    input [15:0] A;
    input [15:0] B;
    output [6:0] C;
    output DONE;

    reg c_done;
    reg [3:0] k;
    reg [6:0] c_reg;
    reg [3:0] prod;

    wire CLK, RESET;

    reg [1:0] a_cp [0:7];
    reg [1:0] b_cp [0:7];

    always @ (A) begin
        a_cp[0] = A[15:14];
        a_cp[1] = A[13:12];
        a_cp[2] = A[11:10];
        a_cp[3] = A[9:8];
        a_cp[4] = A[7:6];
        a_cp[5] = A[5:4];
        a_cp[6] = A[3:2];
        a_cp[7] = A[1:0];
    end
    always @ (B) begin
        b_cp[0] = B[15:14];
        b_cp[1] = B[13:12];
        b_cp[2] = B[11:10];
        b_cp[3] = B[9:8];
        b_cp[4] = B[7:6];
        b_cp[5] = B[5:4];
        b_cp[6] = B[3:2];
        b_cp[7] = B[1:0];
    end

    always @ (posedge CLK or posedge RESET)
    begin
        if (RESET) begin
            prod <= 0;
            c_reg <= 0;
            k <= 0;
            c_done <= 0;

        end else begin
            prod <= a_cp[k] * b_cp[k];
            c_reg   <= c_done ? c_reg : (c_reg + prod);
            k       <= c_done ? k : (k + 1);
            c_done  <= c_done ? 1 : (k == 8);
        end
    end

    assign C = c_reg;
    assign DONE = c_done;

endmodule