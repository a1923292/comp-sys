load ArrSort.asm,
output-file ArrSort01.out,
compare-to ArrSort01.cmp,
output-list RAM[0]%D2.6.2 RAM[1]%D2.6.2 RAM[2]%D2.6.2
             RAM[50]%D2.6.2 RAM[51]%D2.6.2 RAM[52]%D2.6.2 RAM[53]%D2.6.2;

set PC 0,
set RAM[1] 50,
set RAM[2] 4,
set RAM[50] 32767,
set RAM[51] -32768,
set RAM[52] 0,
set RAM[53] 5;
repeat 800 { ticktock; }
output;