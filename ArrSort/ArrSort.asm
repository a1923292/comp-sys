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
@R8
M=D

@R2
D=M
@R3
M=D

(OUTER_LOOP)
    @R3
    M=M-1
    D=M
    @1
    D=D-A
    @DONE
    D;JLE

    // Set swap flag to false
    @0
    D=A
    @R7
    M=D

    @0
    D=A
    @R4
    M=D

    (INNER_LOOP)
        @R4
        D=M
        @R3
        D=D-M
        @1
        D=D-A
        @END_INNER
        D;JGE

        @R8
        D=M
        @R4
        A=D+M
        D=M
        @R5
        M=D

        @R8
        D=M
        @R4
        A=D+M
        A=A+1
        D=M
        @R6
        M=D

        @R5
        D=M
        @R6
        D=D-M
        @NOSWAP
        D;JLE

        @R6
        D=M
        @R8
        A=M
        @R4
        A=A+M
        M=D

        @R5
        D=M
        @R8
        A=M
        @R4
        A=A+M
        A=A+1
        M=D

        @R7
        M=1

(NOSWAP)
    @R4
    M=M+1
    @INNER_LOOP
    0;JMP

(END_INNER)
    @R7
    D=M
    @DONE
    D;JEQ

    @OUTER_LOOP
    0;JMP

(DONE)
    @R0
    M=-1
    @DONE
    0;JMP
    // this does not work at all brother , just furkcffffccccfcfcfuckcccc