// Sorts the array of length R2 whose first element is at RAM[R1] in ascending order in place. Sets R0 to True (-1) when complete.
// (R0, R1, R2 refer to RAM[0], RAM[1], and RAM[2], respectively.)

// Put your code here.

@R1
D=M
@R3
M=D

(OUTER)
    @R3
    D=M
    @R1
    D=D-M
    @R2
    D=M-D
    @DONE
    D;JLE

    // min = i
    @R3
    D=M
    @R5
    M=D

    @R3
    D=M
    @1
    D=D+A
    @R4
    M=D

(INNER)
    @R4
    D=M
    @R1
    D=D-M
    @R2
    D=M-D
    @END_INNER
    D;JGE

    @R4
    A=M
    D=M
    @R6
    M=D
    @R5
    A=M
    D=M
    @SKIP
    D=D-M
    @SKIP
    D;JLE
    @R4
    D=M
    @R5
    M=D
(SKIP)
    @R4
    M=M+1
    @INNER
    0;JMP

(END_INNER)
    @R5
    D=M
    @R3
    D=D-M
    @NOSWAP
    D;JEQ

    @R3
    A=M
    D=M
    @R6
    M=D
    @R5
    A=M
    D=M
    @R3
    A=M
    M=D
    @R6
    D=M
    @R5
    A=M
    M=D
(NOSWAP)
    // i++
    @R3
    M=M+1
    @OUTER
    0;JMP

(DONE)
    @R0
    M=-1
    @DONE
    0;JMP