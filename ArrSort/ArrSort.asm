@R2
D=M
@DONE
D;JLE
@R2
D=M
@SKIP_SORT
D;JEQ

@R1
D=M
@BASE
M=D

@R2
D=M
@LEN
M=D

@LEN
D=M
@ONE
D=D-A
@LIMIT
M=D

@0
D=A
@I
M=D

(OUTER_LOOP)
    @LIMIT
    D=M
    @I
    D=D-M
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
    @LIMIT
    D=M
    @I
    D=D-M
    @J
    D=D-M
    @NO_INNER
    D;JLE

    @BASE
    D=M
    @J
    D=D+M
    @ADDR
    M=D

    @ADDR
    A=M
    D=M
    @R6
    M=D

    @ADDR
    D=M+1
    @ADDR1
    M=D

    @ADDR1
    A=M
    D=M
    @R7
    M=D

    @R6
    D=M
    @R7
    D=D-M
    @NO_SWAP
    D;JLE

(SWAP)
    @R6
    D=M
    @ADDR1
    A=M
    M=D

    @R7
    D=M
    @ADDR
    A=M
    M=D

    @1
    D=A
    @SWAPFLAG
    M=D

(NO_SWAP)
    @J
    M=M+1
    @INNER_LOOP
    0;JMP

(NO_INNER)
    @SWAPFLAG
    D=M
    @DONE
    D;JEQ

    @I
    M=M+1
    @OUTER_LOOP
    0;JMP

(SKIP_SORT)
(DONE)
    @R0
    M=-1

    @END
    0;JMP

(BASE)  
@0
(LEN)   
@0
(I)     
@0
(J)     
@0
(ADDR)  
@0
(ADDR1) 
@0
(R6)    
@0
(R7)    
@0
(ONE)   
@1
(LIMIT) 
@0
(SWAPFLAG)
@0
(END)   
@END
