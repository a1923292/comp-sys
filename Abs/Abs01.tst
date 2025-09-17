load Abs.asm,
output-file Abs01.out,
compare-to Abs00.cmp,
output-list RAM[0]%D RAM[1]%D;

set PC 0,
set RAM[0] 8,  // Set R0
set RAM[1] 4;  // Set R1
repeat 100 {
  ticktock;    // Run for 100 clock cycles
}
set RAM[1] 4,  // Restore arguments in case program used them
output;        // Output to file

// expected: 4
