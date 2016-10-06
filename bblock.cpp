#include "stdafx.h"
#include "bblock.h"

bblock::bblock()
{
	time = 0;
}

bblock::~bblock()
{
}

void bblock::set_instructions(list<line> inst){
	instructions = inst;
	string temp_inst = inst.back().get_inst().get_inst();
	if (temp_inst == "beq" || temp_inst == "bne" || temp_inst == "bnez" || temp_inst == "beqz" || temp_inst == "j" || temp_inst == "jr" || temp_inst == "jal"){
		set_call_for(instructions.back().get_inst().get_op().back());
	}
	else{
		call_for.clear();
	}
	fst_addr = inst.front().get_add1();
	lst_addr = inst.back().get_add1();
}
list<line> bblock::get_instructions(){
	return instructions;
}
void bblock::set_call_for(string vec){
	if (vec[0] == '0' && vec[1] == 'x'){
		vec.erase(vec.begin(), vec.begin() + 2);
	}
	call_for = vec;
}

string bblock::get_call_for(){
	return call_for;
}
void bblock::set_called_by(list<string> vec){
	called_by = vec;
}
void bblock::set_fst_addr(string str){
	fst_addr = str;
}
void bblock::set_lst_addr(string str){
	lst_addr = str;
}
void bblock::set_time(int t){
	time = t;
}
string bblock::get_fst_addr(){
	return fst_addr;
}
string bblock::get_lst_addr(){
	return lst_addr;
}