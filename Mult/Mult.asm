// This file is based on part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: Mult.asm

// Multiplies R1 and R2 and stores the result in R0.
// (R0, R1, R2 refer to RAM[0], RAM[1], and RAM[2], respectively.)

// Put your code here.

@R0
M=0
@R3
M=0 // used for sign flag (0+,1-)

// check if either R1 or R2 is zero
@R1
D=M
@END
D;JEQ

@R2
D=M
@END
D;JEQ

@R1
D=M
@NEGR1
D;JLT 

(CHECK_R2)
    @R2
    D=M
    @NEG_R2
    D;JLT         // if R2 < 0, negate and flip sign
    @MULTIPLY
    0;JMP

(NEG_R1)
    @R1
    M=-M        
    @R3
    M=M + 1     
    @CHECK_R2
    0;JMP

(NEG_R2)
    @R2
    M=-M
    @R3
    M=M + 1     
    @MULTIPLY
    0;JMP

(MULTIPLY)
    @R1
    D=M
    @LOOP_END
    D;JEQ
    @R2
    D=M
    @R0
    M=M+D
    @R1
    M=M-1
    D=M
    @MULTIPLY
    D;JGT

(LOOP_END)
    @R3
    D=M
    @END
    D;JEQ         // if sign == 0, done
    @R0
    M=-M 

(END)
    @END // jump forever
    0;JMP