#include <bitset>
#include <string>
#include<iostream>
#include"Components.h"

AluControl::AluControl(/* args */)
{
    func_i = bitset<6> (0);
    aluop_i = bitset<2> (0);
    aluctrl_o = bitset<4> (0);
}

AluControl::~AluControl()
{
}

void AluControl::input(bitset<6> func, bitset<2> aluop){
    func_i = func;
    aluop_i = aluop;
    aluctrl_o = this->map_aluctrl_code();
}

bitset<4> AluControl::get_output(){
    return aluctrl_o;
}

bitset<4> AluControl::map_aluctrl_code()
{
    /* Implement your ALU Control here */
    if (aluop_i==bitset<2> ("00")) {//lw/sw/addi
        aluctrl_o=bitset<4> ("0010");
    }
    else if (aluop_i==bitset<2>("01")) {//beq
        aluctrl_o=bitset<4> ("0110");
    }
    else if (aluop_i==bitset<2>("10")) {//R-type
             if (func_i==bitset<6>("100000")) {
                 aluctrl_o=bitset<4> ("0010");
             }
            else if (func_i==bitset<6>("100010")) {
                aluctrl_o=bitset<4> ("0110");
            }
            else if (func_i==bitset<6>("100100")) {
                aluctrl_o=bitset<4> ("0000");
            }
            else if (func_i==bitset<6>("100101")) {
                aluctrl_o=bitset<4> ("0001");
            }
            else if (func_i==bitset<6>("101010")) {
                aluctrl_o=bitset<4> ("0111");
            }
    }
             return aluctrl_o;
    
    
    
}
