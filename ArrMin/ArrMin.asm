
@R2
D=M
@DONE
D;JLE

@R2
D=M
@R3
M=D

@R1
D=M
@BASE
M=D

@BASE
A=M
D=M
@R5
M=D

@1
D=A
@R4
M=D

(LOOP)
    @R4
    D=M
    @R3
    D=D-M
    @DONE
    D;JGE

    @BASE
    D=M
    @R4
    A=D+M
    D=M
    @CUR
    M=D

    
    @CUR
    D=M
    @CUR_NONNEG
    D;JGE

    @R5
    D=M
    @DO_UPDATE
    D;JGE

    @CUR
    D=M
    @R5
    D=D-M
    @CONTINUE
    D;JGE
    
    @DO_UPDATE
    0;JMP

(CUR_NONNEG)
    @R5
    D=M
    @CONTINUE
    D;JLT

    @CUR
    D=M
    @R5
    D=D-M
    @CONTINUE
    D;JGE
    
    @DO_UPDATE
    0;JMP

(DO_UPDATE)
    @CUR
    D=M
    @R5
    M=D
    @CONTINUE
    0;JMP

(CONTINUE)
    @R4
    M=M+1
    @LOOP
    0;JMP

(DONE)
    @R5
    D=M
    @R0
    M=D
    @END
    0;JMP

(END)
    @END
    0;JMP