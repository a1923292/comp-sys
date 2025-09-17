load ArrSort.asm,
output-file ArrSort01.out,
compare-to ArrSort01.cmp,
output-list RAM[0]%D2.6.2 RAM[10]%D2.6.2 RAM[11]%D2.6.2 RAM[12]%D2.6.2 RAM[13]%D2.6.2;

set PC 0,
set RAM[1] 10,
set RAM[2] 4,
set RAM[10] 1,
set RAM[11] 3,
set RAM[12] 5,
set RAM[13] 7;
repeat 400 { ticktock; }
output;
