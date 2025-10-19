#include <string>

#include "VMTranslator.h"

using namespace std;

/**
 * VMTranslator constructor
 */
VMTranslator::VMTranslator() {
    // Your code here
}

/**
 * VMTranslator destructor
 */
VMTranslator::~VMTranslator() {
    // Your code here
}

/** Generate Hack Assembly code for a VM push operation */
string VMTranslator::vm_push(string segment, int offset){
    return "";
}

/** Generate Hack Assembly code for a VM pop operation */
string VMTranslator::vm_pop(string segment, int offset){    
    return "";
}

/** Generate Hack Assembly code for a VM add operation */
string VMTranslator::vm_add(){
    return "";
}

/** Generate Hack Assembly code for a VM sub operation */
string VMTranslator::vm_sub(){
    return "";
}

/** Generate Hack Assembly code for a VM neg operation */
string VMTranslator::vm_neg(){
    return "";
}

/** Generate Hack Assembly code for a VM eq operation */
string VMTranslator::vm_eq(){
    return "";
}

/** Generate Hack Assembly code for a VM gt operation */
string VMTranslator::vm_gt(){
    return "";
}

/** Generate Hack Assembly code for a VM lt operation */
string VMTranslator::vm_lt(){
    return "";
}

/** Generate Hack Assembly code for a VM and operation */
string VMTranslator::vm_and(){
    return "";
}

/** Generate Hack Assembly code for a VM or operation */
string VMTranslator::vm_or(){
    return "";
}

/** Generate Hack Assembly code for a VM not operation */
string VMTranslator::vm_not(){
    return "";
}

/** Generate Hack Assembly code for a VM label operation */
string VMTranslator::vm_label(string label) {
    return "(" + label + ")\n";
}

/** Generate Hack Assembly code for a VM goto operation */
string VMTranslator::vm_goto(string label) {
    return "@" + label + "\n0;JMP\n";
}

/** Generate Hack Assembly code for a VM if-goto operation */
string VMTranslator::vm_if(string label) {
    return "@SP\nAM=M-1\nD=M\n@" + label + "\nD;JNE\n";
}

/** Generate Hack Assembly code for a VM function operation */
string VMTranslator::vm_function(string function_name, int n_vars) {
    string asm_code = "(" + function_name + ")\n";
    for (int i = 0; i < n_vars; i++) {
        asm_code += "@0\nD=A\n@SP\nA=M\nM=D\n@SP\nM=M+1\n";
    }
    return asm_code;
}

/** Generate Hack Assembly code for a VM call operation */
int call_counter = 0;

string VMTranslator::vm_call(string function_name, int n_args) {
    string return_label = "RET_LABEL_" + to_string(call_counter++);
    string asm_code;
    asm_code += "@" + return_label + "\nD=A\n@SP\nA=M\nM=D\n@SP\nM=M+1\n";
    string segments[] = {"LCL", "ARG", "THIS", "THAT"};
    for (auto seg : segments) {
        asm_code += "@" + seg + "\nD=M\n@SP\nA=M\nM=D\n@SP\nM=M+1\n";
    }
    asm_code += "@SP\nD=M\n@" + to_string(n_args + 5) + "\nD=D-A\n@ARG\nM=D\n";
    asm_code += "@SP\nD=M\n@LCL\nM=D\n";
    asm_code += "@" + function_name + "\n0;JMP\n";
    asm_code += "(" + return_label + ")\n";
    return asm_code;
}

/** Generate Hack Assembly code for a VM return operation */
string VMTranslator::vm_return() {
    string asm_code;
    asm_code += "@LCL\nD=M\n@R13\nM=D\n";
    asm_code += "@5\nA=D-A\nD=M\n@R14\nM=D\n";
    asm_code += "@SP\nAM=M-1\nD=M\n@ARG\nA=M\nM=D\n";
    asm_code += "@ARG\nD=M+1\n@SP\nM=D\n";
    string segments[] = {"THAT", "THIS", "ARG", "LCL"};
    for (int i = 0; i < 4; i++) {
        asm_code += "@R13\nD=M\n@" + to_string(i+1) + "\nA=D-A\nD=M\n@" + segments[3-i] + "\nM=D\n";
    }
    asm_code += "@R14\nA=M\n0;JMP\n";
    return asm_code;
}