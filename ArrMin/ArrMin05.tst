load ArrMin.asm,
output-file ArrMin01.out,
compare-to ArrMin01.cmp,
output-list RAM[0]%D2.6.2;

set PC 0,
set RAM[1] 100,
set RAM[2] 5,
set RAM[100]  32767,
set RAM[101]  -32768,
set RAM[102]  0,
set RAM[103]  123,
set RAM[104]  -5;
repeat 400 { ticktock; }
output;