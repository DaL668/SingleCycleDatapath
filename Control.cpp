#include <bitset>
#include <string>
#include<iostream>
#include"Components.h"
using namespace std;


Control::Control()
{
    ctrl_i     = bitset<6> (0);
    regDst_o   = bitset<1> (0);
    regWrite_o = bitset<1> (0); 
    ALUop_o    = bitset<2> (0);
    ALUsrc_o   = bitset<1> (0);
    Branch_o   = bitset<1> (0); 
    MemRead_o  = bitset<1> (0);
    MemtoReg_o = bitset<1> (0);
    MemWrite_o = bitset<1> (0);
}

Control::~Control()
{
}

void Control::input(bitset<6> ctrl_input)
{
    ctrl_i = ctrl_input;
    this->operation();
}
void Control::operation(){
    /* implement your own control method here*/
    // tips: map the opcode to the instruction type (r-type, i-type...etc) and decide the value for output signal.
    // private member XXX_i is for input, XXX_o is for output.
   if (ctrl_i==bitset<6>("000000")) {//R-type (add and sub)
        regDst_o = bitset<1>("1");
        regWrite_o = bitset<1>("1");
        ALUop_o    = bitset<2>("10");
        ALUsrc_o   = bitset<1>("0");
        Branch_o   = bitset<1>("0");
        MemRead_o  = bitset<1>("0");
        MemtoReg_o = bitset<1>("0");
        MemWrite_o = bitset<1>("0");
    }
    else if (ctrl_i==bitset<6>("100011")) {//lw
        regDst_o = bitset<1>("0");
        regWrite_o = bitset<1>("1");
        ALUop_o    = bitset<2>("00");
        ALUsrc_o   = bitset<1>("1");
        Branch_o   = bitset<1>("0");
        MemRead_o  = bitset<1>("1");
        MemtoReg_o = bitset<1>("1");
        MemWrite_o = bitset<1>("0");
        
    }
    else if (ctrl_i==bitset<6>("101011")) {//sw
        regDst_o = bitset<1>("0");
        regWrite_o = bitset<1>("0");
        ALUop_o    = bitset<2>("00");
        ALUsrc_o   = bitset<1>("1");
        Branch_o   = bitset<1>("0");
        MemRead_o  = bitset<1>("0");
        MemtoReg_o = bitset<1>("1");//x
        MemWrite_o = bitset<1>("1");
    }
    else if (ctrl_i==bitset<6>("000100")) {//beq
        regDst_o = bitset<1>("0");//x
        regWrite_o = bitset<1>("0");
        ALUop_o    = bitset<2>("01");
        ALUsrc_o   = bitset<1>("0");
        Branch_o   = bitset<1>("1");
        MemRead_o  = bitset<1>("0");
        MemtoReg_o = bitset<1>("0");//x
        MemWrite_o = bitset<1>("0");
    }
    else if (ctrl_i==bitset<6>("001000")) {//addi
        regDst_o = bitset<1>("0");//x
        regWrite_o = bitset<1>("1");
        ALUop_o    = bitset<2>("00");
        ALUsrc_o   = bitset<1>("1");
        Branch_o   = bitset<1>("0");
        MemRead_o  = bitset<1>("0");
        MemtoReg_o = bitset<1>("0");
        MemWrite_o = bitset<1>("0");
    }
    
   /*else if (ctrl_i==bitset<6>("001001")) {//opcode=001001
        regDst_o = bitset<1>("0");//x
        regWrite_o = bitset<1>("1");
        ALUop_o    = bitset<2>("00");
        ALUsrc_o   = bitset<1>("1");
        Branch_o   = bitset<1>("0");
        MemRead_o  = bitset<1>("0");
        MemtoReg_o = bitset<1>("0");
        MemWrite_o = bitset<1>("1");
    }*/
   


}
bitset<1> Control::get_regdst(){
    return regDst_o;
}
bitset<1> Control::get_regwrite(){
    return regWrite_o;
}
bitset<2> Control::get_aluop(){
    return ALUop_o;
}
bitset<1> Control::get_alusrc(){
    return ALUsrc_o;
}
bitset<1> Control::get_branch(){
    return Branch_o;
}
bitset<1> Control::get_MemRead(){
    return MemRead_o;
}
bitset<1> Control::get_MemtoReg(){
    return MemtoReg_o;
}
bitset<1> Control::get_MemWrite(){
    return MemWrite_o;
}
