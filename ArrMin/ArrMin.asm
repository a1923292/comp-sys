// Finds the smallest element in the array of length R2 whose first element is at RAM[R1] and stores the result in R0.
// (R0, R1, R2 refer to RAM[0], RAM[1], and RAM[2], respectively.)

// Put your code here.

@R2
D=M
@DONE
D;JLE     // If length is 0 or less jump to done

// R3 = length (n)
@R2
D=M
@R3
M=D

// R6 = base address
@R1
D=M
@R6
M=D

// R5 = first element (initial minimum)
@R6
A=M
D=M
@R5
M=D

// R4 = loop counter starts at 1
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

// get current array element M[base + i]
@R6
D=M
@R4
A=D+M
D=M

// compare with current minimum 
@R5
D=M
@TMP
M=D
@R6
D=M
@R4
A=D+M
D=M
@CUR
M=D

@TMP
D=M
@CUR
D=M-D
@CONTINUE
D;JGE

// update minimum
@R6
D=M
@R4
A=D+M
D=M
@R5
M=D

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
@DONE
0;JMP

(TMP)   @0
(CUR)   @0