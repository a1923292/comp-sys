
@R2
D=M
@DONE
D;JLE

@R1
D=M
@BASE
M=D

@R2
D=M
@LEN
M=D

@0
D=A
@SWAPFLAG
M=D

@0
D=A
@I
M=D

(OUTER_LOOP)
    @LEN
    D=M
    @I
    D=D-M
    D=D+1
    @DONE
    D;JLE

    @0
    D=A
    @J
    M=D

    @0
    D=A
    @SWAPFLAG
    M=D

(INNER_LOOP)
    @LEN
    D=M
    @I
    D=D-M
    @J
    D=D-M
    @ONE
    D=D-1
    @ENDINNER
    D;JLE

    @BASE
    D=M
    @J
    A=D+M
    D=M
    @R6
    M=D

    @BASE
    D=M
    @J
    A=D+M+1
    D=M
    @R7
    M=D

    @R6
    D=M
    @R7
    D=D-M
    @NOSWAP
    D;JLE

(SWAP)

    @BASE
    D=M
    @J
    A=D+M
    @R7
    D=M
    M=D

    @BASE
    D=M
    @J
    A=D+M+1
    @R6
    D=M
    M=D

    @1
    D=A
    @SWAPFLAG
    M=D

(NOSWAP)
    @J
    M=M+1
    @INNER_LOOP
    0;JMP

(ENDINNER)
    @SWAPFLAG
    D=M
    @DONE
    D;JEQ

    @I
    M=M+1
    @OUTER_LOOP
    0;JMP

(DONE)
    @R0
    M=-1
    @END
    0;JMP

(BASE)      @0
(LEN)       @0
(I)         @0
(J)         @0
(R6)        @0
(R7)        @0
(ONE)       @1
(SWAPFLAG)  @0
(END)       @END
