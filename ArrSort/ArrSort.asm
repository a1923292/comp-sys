// Sorts the array of length R2 whose first element is at RAM[R1] in ascending order in place. Sets R0 to True (-1) when complete.
// (R0, R1, R2 refer to RAM[0], RAM[1], and RAM[2], respectively.)

// Put your code here.

@R1
D=M
@base_address
M=D

@R2
D=M
@length
M=D

@i
M=0

(OUTER_LOOP)
    @i
    D=M
    @length
    A=M
    D=D-A
    @END
    D;JGE

    @i
    D=M
    @base_address
    A=M+D
    D=A
    @min_index
    M=D

    @i
    D=M
    D=D+1
    @j
    M=D

(INNER_LOOP)
    @j
    D=M
    @length
    A=M
    D=D-A
    @SWAP
    D;JGE

    @base_address
    D=M
    @j
    A=D+M
    D=M
    @min_index
    A=M
    D=D-M
    @UPDATE_MIN_INDEX
    D;JLT

(INCREMENT_J)
    @j
    M=M+1
    @INNER_LOOP
    0;JMP


(UPDATE_MIN_INDEX)
    @base_address
    D=M
    @j
    A=D+M
    D=A
    @min_index
    M=D
    @INCREMENT_J
    0;JMP

(SWAP)
    @base_address
    D=M
    @i
    A=D+M
    D=M
    @temp_val
    M=D

    @min_index
    A=M
    D=M

    @base_address
    A=M
    @i
    A=A+M
    M=D

    @min_index
    A=M
    @temp_val
    D=M
    M=D

    @i
    M=M+1
    @OUTER_LOOP
    0;JMP


(END)
    @R0
    M=-1
    @END
    0;JMP