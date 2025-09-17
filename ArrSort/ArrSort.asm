// Sorts the array of length R2 whose first element is at RAM[R1] in ascending order in place. Sets R0 to True (-1) when complete.
// (R0, R1, R2 refer to RAM[0], RAM[1], and RAM[2], respectively.)

// Put your code here.

@R2
D=M
@1
D=D-A
@DONE
D;JLE

@R1
D=M
@R6
M=D

@R2
D=M
@R5
M=D

@0
D=A
@R3
M=D

(OUTER_LOOP)
    @R3
    D=M
    @R5
    D=D-M
    @1
    D=D+A
    @DONE
    D;JGE

    @0
    D=A
    @R4
    M=D

    (INNER_LOOP)
        @R4
        D=M
        @R5
        D=M-D
        @R3
        D=D-M
        @1
        D=D-A
        @END_INNER
        D;JLE

        @R6
        D=M
        @R4
        A=D+M
        D=M
        @R7
        M=D

        @R6
        D=M
        @R4
        A=D+M
        A=A+1
        D=M
        @R8
        M=D

        @R7
        D=M
        @R8
        D=D-M
        @NOSWAP
        D;JLE

        @R8
        D=M
        @R6
        A=M
        @R4
        A=A+M
        M=D

        @R7
        D=M
        @R6
        A=M
        @R4
        A=A+M
        A=A+1
        M=D

(NOSWAP)
    @R4
    M=M+1
    @INNER_LOOP
    0;JMP

(END_INNER)
    @R3
    M=M+1
    @OUTER_LOOP
    0;JMP

(DONE)
    @R0
    M=-1
    @DONE
    0;JMP