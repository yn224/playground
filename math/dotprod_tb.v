module test;

  reg CLK;
  reg RESET;
  reg [15:0] A;
  reg [15:0] B;
  wire [6:0] C;
  wire DONE;

  VecMul2bit vm(
    .A(A),
    .B(B), 
    .C(C), 
    .CLK(CLK), 
    .RESET(RESET),
    .DONE(DONE)
  );

  always
  begin
    CLK = 1'b0;
    CLK = #500 1'b1;
    #500;
  end 

  initial begin
    A = 16'b0001101000101001;
    // 00 01 10 10 00 10 10 01
    // [0, 1, 2, 2, 0, 2, 2, 1]
    B = 16'b0110110101101001;
    // 01 10 11 01 01 10 10 01
    // [1, 2, 3, 1, 1, 2, 2, 1]

    RESET = 1'b1;
    #50;
    RESET = 1'b0;
    
    $monitor("a: %d, b: %d, c: %d, done: %d", A, B, C, DONE);

    #10000 $stop;
  end   

endmodule