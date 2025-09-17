load ArrSort.asm,
output-file ArrSort05.out,
compare-to ArrSort05.cmp,
output-list RAM[0]%D2.6.2 RAM[10]%D2.6.2;

set PC 0,
set RAM[1] 10,
set RAM[2] 1,
set RAM[10] 42;
repeat 200 { ticktock; }
output;
