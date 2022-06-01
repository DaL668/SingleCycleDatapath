#include <iostream>
#include <bitset>
#include <string>

#include "Components.h"

SignExtend::SignExtend()
{
    data_i = bitset<16> (0);
    data_o = bitset<32> (0);
}

SignExtend::~SignExtend()
{
}

void SignExtend::input(bitset<16> input){
    data_i = input;
    data_o = this->extend(data_i);
}
bitset<32> SignExtend::get_output(){
    return data_o;
}

bitset<32> SignExtend::extend(bitset<16> input){
bitset<32>se = bitset<32> (input.to_ulong());

if (input.test(15)==1) {
   for (int i=0;i<16;i++) {
   se.set(i+16);
}
return se;
}

else {
return se;
}

    
}
