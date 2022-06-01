#include <iostream>
#include <string>
#include <bitset>
#include<vector>
#include "Components.h"

using namespace std;

DataMemory::DataMemory()
{
    Address_i   = bitset<32> (0);
    Writedata_i = bitset<32> (0);

    Readdata_o  = bitset<32> (0);

    //control signal
    MemRead_i   = bitset<1> (0);
    MemWrite_i  = bitset<1> (0);

    // memory is byte address, every location store 8bits.
    memory_space = vector<string> (128,"0"); // 128 bytes data memory
    
    memory_space[15] = "00000000";
    memory_space[16] = "00000000";
    memory_space[17] = "00000000";
    memory_space[18] = "00100101";
    memory_space[64] = "00000000";
    memory_space[65] = "00000000";
    memory_space[66] = "00100110";
    memory_space[67] = "10101010";


}   

DataMemory::~DataMemory()
{
}

void DataMemory::input(bitset<32> Address, bitset<32> Writedata, 
                        bitset<1> MemRead, bitset<1> MemWrite){
    Address_i   = Address;
    Writedata_i = Writedata;
    MemRead_i   = MemRead;
    MemWrite_i  = MemWrite;
    operation();

}
void DataMemory::operation(){
      
    if (MemWrite_i == 1)    store_writedata_to_location();
    if (MemRead_i == 1)     load_readdata_from_location();
}

int DataMemory::bitaddress_to_intlocation(){
    return (int)Address_i.to_ulong();
}
void DataMemory::store_writedata_to_location(){
    /* 
    (1) you are storing 32bits data, memory is byte address (8bits) per unit
    (2) let Writedata_i (bitet<32>) to string (you can find in c++ library)
    (3) truncat the string and store into consecutive 4 locations (4 * 8bit = 32bit) in memory_space
    */
   string stringData=Writedata_i.to_string();
   int intAddress=bitaddress_to_intlocation();
   memory_space[intAddress]=stringData.substr(0,8);
   memory_space[intAddress+1]=stringData.substr(8,8);
   memory_space[intAddress+2]=stringData.substr(16,8);
   memory_space[intAddress+3]=stringData.substr(24,8);


}

void DataMemory::load_readdata_from_location(){
    /* 
    (1) you are reading 32bits data, memory is byte address (8bits) per unit
    (2) read string from consecutive 4 memory_space location (4*8bit = 32)
    (3) create bitset<32> from string and assign to Readdata_o
    */
   int intAddress=bitaddress_to_intlocation();
   string s1=memory_space[intAddress+3];//lsb
   string s2=memory_space[intAddress+2];
   string s3=memory_space[intAddress+1];
   string s4=memory_space[intAddress];//msb
   string stringSum=s4+s3+s2+s1;
   bitset<32> dataRead(stringSum);
   Readdata_o=dataRead;


}

bitset<32> DataMemory::get_Readdata(){
    return Readdata_o;
}

vector<string> DataMemory::get_memory_space(){
    return memory_space;
}
