#include <bitset>
#include <string>
#include<iostream>
#include"Components.h"
using namespace std;

Alu::Alu()
{
    src0_i = bitset<32> (0);
    src1_i = bitset<32> (0);
    aluctrl_i = bitset<4> (0);
    result_o = bitset<32> (0);
    zero_o = bitset<1> (0); 
}

Alu::~Alu()
{
}
void Alu::input(bitset<32> src_0, bitset<32> src_1, bitset<4> alu_ctrl){
    src0_i = src_0;
    src1_i = src_1;
    aluctrl_i = alu_ctrl;
    alu_operation(); // determine operation and assign the result to result_o and zero_o
}
void Alu::alu_operation(){

if (aluctrl_i==bitset<4>("0000")) {//and
        result_o=src0_i & src1_i;
    }
    else if (aluctrl_i==bitset<4>("0001")) {//or
        result_o=src0_i | src1_i;
    }
   else if (aluctrl_i==bitset<4>("0010")) {//add
      //int temp0=(int) src0_i.to_ulong();
        result_o=bitset<32>(src0_i.to_ulong()+src1_i.to_ulong());
    }
    else if (aluctrl_i==bitset<4>("0110")) {//sub/beq
         src1_i=(~(src1_i));
         bitset<1> sTemp=bitset<1> ("1");
         src1_i=bitset<32> (src1_i.to_ulong() + sTemp.to_ulong());
        result_o=bitset<32> (src0_i.to_ulong()+src1_i.to_ulong());
        if (result_o==bitset<32>("00000000000000000000000000000000")) {
            zero_o.set(0);
        }
    }
  

}
bitset<32> Alu::get_aluresult()
{ return result_o;}
bitset<1> Alu::get_zero()
{ return zero_o;}
