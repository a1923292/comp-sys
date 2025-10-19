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
string VMTranslator::vm_push(string segment, int offset) {
    string out;

    if (segment == "constant") {
        out += "@" + to_string(offset) + "\n";
        out += "D=A\n";
    } else if (segment == "local") {
        out += "@" + to_string(offset) + "\n";
        out += "D=A\n";
        out += "@LCL\n";
        out += "A=M+D\n";
        out += "D=M\n";
    } else if (segment == "argument") {
        out += "@" + to_string(offset) + "\n";
        out += "D=A\n";
        out += "@ARG\n";
        out += "A=M+D\n";
        out += "D=M\n";
    } else if (segment == "this") {
        out += "@" + to_string(offset) + "\n";
        out += "D=A\n";
        out += "@THIS\n";
        out += "A=M+D\n";
        out += "D=M\n";
    } else if (segment == "that") {
        out += "@" + to_string(offset) + "\n";
        out += "D=A\n";
        out += "@THAT\n";
        out += "A=M+D\n";
        out += "D=M\n";
    } else if (segment == "temp") {
        out += "@" + to_string(5 + offset) + "\n";
        out += "D=M\n";
    } else if (segment == "pointer") {
        string base = (offset == 0) ? "THIS" : "THAT";
        out += "@" + base + "\n";
        out += "D=M\n";

    } else if (segment == "static") {
        int address = 16 + offset;
        out += "@" + to_string(address) + "\n";
        out += "D=M\n";
    }

    out += "@SP\n";
    out += "A=M\n";
    out += "M=D\n";
    out += "@SP\n";
    out += "M=M+1\n";

    return out;
}


/** Generate Hack Assembly code for a VM pop operation */
string VMTranslator::vm_pop(string segment, int offset) {
    string out;

    if (segment == "local" || segment == "argument" || segment == "this" || segment == "that") {
        // Map to base pointers
        string base;
        if (segment == "local") base = "LCL";
        else if (segment == "argument") base = "ARG";
        else if (segment == "this") base = "THIS";
        else if (segment == "that") base = "THAT";

        out += "@" + to_string(offset) + "\n";
        out += "D=A\n";
        out += "@" + base + "\n";
        out += "D=M+D\n";
        out += "@R13\n";
        out += "M=D\n";

        // Pop value → *R13
        out += "@SP\n";
        out += "AM=M-1\n";
        out += "D=M\n";
        out += "@R13\n";
        out += "A=M\n";
        out += "M=D\n";
    }
    else if (segment == "temp") {
        // temp segment starts at RAM[5]
        int address = 5 + offset;
        out += "@SP\n";
        out += "AM=M-1\n";
        out += "D=M\n";
        out += "@" + to_string(address) + "\n";
        out += "M=D\n";
    }
    else if (segment == "pointer") {
        string pointerBase = (offset == 0) ? "THIS" : "THAT";
        out += "@SP\n";
        out += "AM=M-1\n";
        out += "D=M\n";
        out += "@" + pointerBase + "\n";
        out += "M=D\n";
    }
    else if (segment == "static") {
        int address = 16 + offset;  // static variables start at RAM[16]
        out += "@SP\n";
        out += "AM=M-1\n";
        out += "D=M\n";
        out += "@" + to_string(address) + "\n";
        out += "M=D\n";
    }

    return out;
}



/** Generate Hack Assembly code for a VM add operation */
string VMTranslator::vm_add(){
    string out;
    out+="@SP\n";
    out+="AM=M-1\n";
    out+="D=M\n";
    out+="A=A-1\n";
    out+="M=D+M";
    return out;
}

/** Generate Hack Assembly code for a VM sub operation */
string VMTranslator::vm_sub(){
    string out;
    out+="@SP\n";
    out+="AM=M-1\n";
    out+="D=M\n";
    out+="A=A-1\n";
    out+="M=M-D";
    return out;
}

/** Generate Hack Assembly code for a VM neg operation */
string VMTranslator::vm_neg(){
    string out;
    out+="@SP\n";
    out+="A=M-1\n";
    out+="M=-M\n";
    return out;
}

/** Generate Hack Assembly code for a VM eq operation */
string VMTranslator::vm_eq() {
    static int labelIndex = 0; 
    string trueLabel = "EQ_TRUE_" + to_string(labelIndex);
    string endLabel = "EQ_END_" + to_string(labelIndex);
    labelIndex++;

    string out;
    out += "@SP\n";        // SP--
    out += "AM=M-1\n";     // A = SP - 1, SP = SP - 1
    out += "D=M\n";        // D = y (top value)
    out += "A=A-1\n";      // A = SP - 2
    out += "D=M-D\n";      // D = x - y
    out += "@" + trueLabel + "\n";
    out += "D;JEQ\n";      // if x == y, jump to trueLabel
    out += "@SP\n";
    out += "A=M-1\n";
    out += "M=0\n";        // set false (0)
    out += "@" + endLabel + "\n";
    out += "0;JMP\n";      // jump to end

    out += "(" + trueLabel + ")\n";
    out += "@SP\n";
    out += "A=M-1\n";
    out += "M=-1\n";       // set true (-1)

    out += "(" + endLabel + ")\n";

    return out;
}

/** Generate Hack Assembly code for a VM gt operation */
string VMTranslator::vm_gt(){
    static int labelIndex = 0; 
    string trueLabel = "GT_TRUE_" + to_string(labelIndex);
    string endLabel = "GT_END_" + to_string(labelIndex);
    labelIndex++;

    string out;
    out += "@SP\n";        // SP--
    out += "AM=M-1\n";     // A = SP - 1, SP = SP - 1
    out += "D=M\n";        // D = y (top value)
    out += "A=A-1\n";      // A = SP - 2
    out += "D=M-D\n";      // D = x - y
    out += "@" + trueLabel + "\n";
    out += "D;JGT\n";      // if x == y, jump to trueLabel
    out += "@SP\n";
    out += "A=M-1\n";
    out += "M=0\n";        // set false (0)
    out += "@" + endLabel + "\n";
    out += "0;JMP\n";      // jump to end

    out += "(" + trueLabel + ")\n";
    out += "@SP\n";
    out += "A=M-1\n";
    out += "M=-1\n";       // set true (-1)

    out += "(" + endLabel + ")\n";

    return out;
}

/** Generate Hack Assembly code for a VM lt operation */
string VMTranslator::vm_lt(){
    static int labelIndex = 0; 
    string trueLabel = "GT_TRUE_" + to_string(labelIndex);
    string endLabel = "GT_END_" + to_string(labelIndex);
    labelIndex++;

    string out;
    out += "@SP\n";        // SP--
    out += "AM=M-1\n";     // A = SP - 1, SP = SP - 1
    out += "D=M\n";        // D = y (top value)
    out += "A=A-1\n";      // A = SP - 2
    out += "D=M-D\n";      // D = x - y
    out += "@" + trueLabel + "\n";
    out += "D;JLT\n";      // if x == y, jump to trueLabel
    out += "@SP\n";
    out += "A=M-1\n";
    out += "M=0\n";        // set false (0)
    out += "@" + endLabel + "\n";
    out += "0;JMP\n";      // jump to end

    out += "(" + trueLabel + ")\n";
    out += "@SP\n";
    out += "A=M-1\n";
    out += "M=-1\n";       // set true (-1)

    out += "(" + endLabel + ")\n";

    return out;
}

/** Generate Hack Assembly code for a VM and operation */
string VMTranslator::vm_and(){
    string out;
    out+="@SP\n";
    out+="AM=M-1\n";
    out+="D=M\n";
    out+="A=A-1\n";
    out+="M=D&M\n";

    return out;
}

/** Generate Hack Assembly code for a VM or operation */
string VMTranslator::vm_or(){
    string out;
    out+="@SP\n";
    out+="AM=M-1\n";
    out+="D=M\n";
    out+="A=A-1\n";
    out+="M=M|D\n";
    return out;
}

/** Generate Hack Assembly code for a VM not operation */
string VMTranslator::vm_not(){
    string out;
    out+="@SP\n";
    out+="A=M-1\n";
    out+="M=!M\n";
    
    return out;
}

/** Generate Hack Assembly code for a VM label operation */
string VMTranslator::vm_label(string label){
    string out;
    out+="(" + label + ")";
    return out;
}

/** Generate Hack Assembly code for a VM goto operation */
string VMTranslator::vm_goto(string label){
    string out;
    out+="@" + label + "\n";
    out+="0;JMP\n";
    return out;
}

/** Generate Hack Assembly code for a VM if-goto operation */
string VMTranslator::vm_if(string label){
    string out;
    out+="@SP\n";
    out+="AM=M-1\n";
    out+="D=M\n";
    out+="@" + label + "\n";
    out+= "D;JNE";
    return out;
}

/** Generate Hack Assembly code for a VM function operation */
string VMTranslator::vm_function(string function_name, int n_vars) {
    string out;

    // Declare the function label
    out += "(" + function_name + ")\n";

    // Initialize n_vars local variables to 0 on the stack
    for (int i = 0; i < n_vars; i++) {
        out += "@0\n";        // D = 0
        out += "D=A\n";
        out += "@SP\n";
        out += "A=M\n";
        out += "M=D\n";       // *SP = 0
        out += "@SP\n";
        out += "M=M+1\n";     
    }

    return out;
}


/** Generate Hack Assembly code for a VM call operation */
string VMTranslator::vm_call(string function_name, int n_args) {
    string out;

    string return_label = "RET_" + function_name;
    
    out += "@" + return_label + "\n";
    out += "D=A\n";
    out += "@SP\n";
    out += "A=M\n";
    out += "M=D\n";
    out += "@SP\n";
    out += "M=M+1\n";

    // Push LCL
    out += "@LCL\nD=M\n@SP\nA=M\nM=D\n@SP\nM=M+1\n";

    // Push ARG
    out += "@ARG\nD=M\n@SP\nA=M\nM=D\n@SP\nM=M+1\n";

    // Push THIS
    out += "@THIS\nD=M\n@SP\nA=M\nM=D\n@SP\nM=M+1\n";

    // Push THAT
    out += "@THAT\nD=M\n@SP\nA=M\nM=D\n@SP\nM=M+1\n";

    // ARG = SP - n_args - 5
    out += "@SP\nD=M\n";
    out += "@" + to_string(n_args + 5) + "\n";
    out += "D=D-A\n@ARG\nM=D\n";

    // LCL = SP
    out += "@SP\nD=M\n@LCL\nM=D\n";

    // goto function
    out += "@" + function_name + "\n0;JMP\n";

    // Declare return label
    out += "(" + return_label + ")\n";

    return out;
}

/** Generate Hack Assembly code for a VM return operation */
string VMTranslator::vm_return() {
    return
        "@LCL\nD=M\n@R13\nM=D\n" // Save LCL in temp
        "@5\nA=D-A\nD=M\n@R14\nM=D\n" // Store return address
        "@SP\nAM=M-1\nD=M\n@ARG\nA=M\nM=D\n" // Pop value in ARG
        "@ARG\nD=M+1\n@SP\nM=D\n" // Restore SP
        "@R13\nAM=M-1\nD=M\n@THAT\nM=D\n" // get THAT
        "@R13\nAM=M-1\nD=M\n@THIS\nM=D\n" // get THIS
        "@R13\nAM=M-1\nD=M\n@ARG\nM=D\n" // get ARG
        "@R13\nAM=M-1\nD=M\n@LCL\nM=D\n" // get LCL
        "@R14\nA=M\n0;JMP\n"; // Jump to te address
}