load ArrMin.asm,
output-file ArrMin03.out,
compare-to ArrMin03.cmp,
output-list RAM[0]%D2.6.2;

set PC 0,
set RAM[1] 200,
set RAM[2] 0;    // length 0
repeat 10 { ticktock; }
output;