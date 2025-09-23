
// Load base and limit
@R1
D=M
@BASE
M=D

@R2
D=M
@LIMIT
M=D

@0
D=A
@SWAPFLAG
M=D

(OUTER)
    @LIMIT
    D=M
    D=D-1
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

(INNER)
    @J
    D=M
    @LIMIT
    D=D-M
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
    A=D+M
    A=A+1
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
    A=D+M
    A=A+1

    @R6
    D=M
    M=D

    @SWAPFLAG
    M=-1

(NOSWAP)
    @J
    M=M+1
    @INNER
    0;JMP

(ENDINNER)
    @LIMIT
    M=M-1
    @SWAPFLAG
    D=M
    @OUTER
    D;JNE

(DONE)
    @R0
    M=-1
    @END
    0;JMP

(BASE)       @0
(LIMIT)      @0
(J)          @0
(R6)         @0
(R7)         @0
(SWAPFLAG)   @0
(TMP)        @0
(END)        @END
