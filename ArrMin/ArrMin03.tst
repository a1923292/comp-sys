load ArrMin.asm,
output-file ArrMin04.out,
compare-to ArrMin04.cmp,
output-list RAM[0]%D2.6.2;

set PC 0,
set RAM[1] 300,
set RAM[2] 7,
set RAM[300] 5,
set RAM[301] 5,
set RAM[302] -1,
set RAM[303] 5,
set RAM[304] -1,
set RAM[305] 10,
set RAM[306] 0;
repeat 400 { ticktock; }
output;
