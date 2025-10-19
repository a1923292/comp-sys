#include <string>
#include <sstream>

#include "VMTranslator.h"

using namespace std;

static int label_counter = 0;

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
string VMTranslator::vm_label(string label){
    stringstream ss;
    ss << "(" << label << ")\n";
    return ss.str();
}

/** Generate Hack Assembly code for a VM goto operation */
string VMTranslator::vm_goto(string label){
    stringstream ss;
    ss << "@" << label << "\n";
    ss << "0;JMP\n";
    return ss.str();
}

/** Generate Hack Assembly code for a VM if-goto operation */
string VMTranslator::vm_if(string label){
    stringstream ss;
    ss << "@SP\n";
    ss << "M=M-1\n";
    ss << "A=M\n";
    ss << "D=M\n";
    ss << "@" << label << "\n";
    ss << "D;JNE\n";
    return ss.str();
}

/** Generate Hack Assembly code for a VM function operation */
string VMTranslator::vm_function(string function_name, int n_vars){
    stringstream ss;
    ss << "(" << function_name << ")\n";
    
    for(int i = 0; i < n_vars; i++){
        ss << "@SP\n";
        ss << "A=M\n";
        ss << "M=0\n";
        ss << "@SP\n";
        ss << "M=M+1\n";
    }
    
    return ss.str();
}

/** Generate Hack Assembly code for a VM call operation */
string VMTranslator::vm_call(string function_name, int n_args){
    stringstream ss;
    
    string safe_function_name = function_name;
    for(size_t i = 0; i < safe_function_name.length(); i++){
        if(safe_function_name[i] == '.') safe_function_name[i] = '_';
    }
    string return_label = "RETURN_" + safe_function_name + "_" + to_string(label_counter++);

    ss << "@" << return_label << "\n";
    ss << "D=A\n";
    ss << "@SP\n";
    ss << "A=M\n";
    ss << "M=D\n";
    ss << "@SP\n";
    ss << "M=M+1\n";
    
    ss << "@LCL\n";
    ss << "D=M\n";
    ss << "@SP\n";
    ss << "A=M\n";
    ss << "M=D\n";
    ss << "@SP\n";
    ss << "M=M+1\n";
    
    ss << "@ARG\n";
    ss << "D=M\n";
    ss << "@SP\n";
    ss << "A=M\n";
    ss << "M=D\n";
    ss << "@SP\n";
    ss << "M=M+1\n";
    
    ss << "@THIS\n";
    ss << "D=M\n";
    ss << "@SP\n";
    ss << "A=M\n";
    ss << "M=D\n";
    ss << "@SP\n";
    ss << "M=M+1\n";
    
    ss << "@THAT\n";
    ss << "D=M\n";
    ss << "@SP\n";
    ss << "A=M\n";
    ss << "M=D\n";
    ss << "@SP\n";
    ss << "M=M+1\n";
    
    ss << "@SP\n";
    ss << "D=M\n";
    ss << "@" << n_args << "\n";
    ss << "D=D-A\n";
    ss << "@5\n";
    ss << "D=D-A\n";
    ss << "@ARG\n";
    ss << "M=D\n";
    
    ss << "@SP\n";
    ss << "D=M\n";
    ss << "@LCL\n";
    ss << "M=D\n";
    
    ss << "@" << function_name << "\n";
    ss << "0;JMP\n";
    
    ss << "(" << return_label << ")\n";
    
    return ss.str();
}

/** Generate Hack Assembly code for a VM return operation */
string VMTranslator::vm_return(){
    stringstream ss;
    
    ss << "@LCL\n";
    ss << "D=M\n";
    ss << "@R13\n";
    ss << "M=D\n";
    
    ss << "@5\n";
    ss << "A=D-A\n";
    ss << "D=M\n";
    ss << "@R14\n";
    ss << "M=D\n";
    
    ss << "@SP\n";
    ss << "M=M-1\n";
    ss << "A=M\n";
    ss << "D=M\n";
    ss << "@ARG\n";
    ss << "A=M\n";
    ss << "M=D\n";
    
    ss << "@ARG\n";
    ss << "D=M+1\n";
    ss << "@SP\n";
    ss << "M=D\n";
    
    ss << "@R13\n";
    ss << "D=M\n";
    ss << "@1\n";
    ss << "A=D-A\n";
    ss << "D=M\n";
    ss << "@THAT\n";
    ss << "M=D\n";
    
    ss << "@R13\n";
    ss << "D=M\n";
    ss << "@2\n";
    ss << "A=D-A\n";
    ss << "D=M\n";
    ss << "@THIS\n";
    ss << "M=D\n";
    
    ss << "@R13\n";
    ss << "D=M\n";
    ss << "@3\n";
    ss << "A=D-A\n";
    ss << "D=M\n";
    ss << "@ARG\n";
    ss << "M=D\n";
    
    ss << "@R13\n";
    ss << "D=M\n";
    ss << "@4\n";
    ss << "A=D-A\n";
    ss << "D=M\n";
    ss << "@LCL\n";
    ss << "M=D\n";
    
    ss << "@R14\n";
    ss << "A=M\n";
    ss << "0;JMP\n";
    
    return ss.str();
}