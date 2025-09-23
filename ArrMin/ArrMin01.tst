load ArrMin.asm,
output-file ArrMin02.out,
compare-to ArrMin02.cmp,
output-list RAM[0]%D2.6.2;

set PC 0,
set RAM[1] 50,
set RAM[2] 6,
set RAM[50]  -3,
set RAM[51]  -1,
set RAM[52]  -100,
set RAM[53]  -2,
set RAM[54]  -100,
set RAM[55]  -50;
repeat 400 { ticktock; }
output;