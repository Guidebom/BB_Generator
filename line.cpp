#include "stdafx.h"
#include "line.h"


line::line()
{
	ntimes = 0;
}


line::~line()
{
}

void line::set_ntimes(int n){
	ntimes = n;
}

void line::increment_ntimes(){
	ntimes++;
}

int line::get_ntimes(){
	return ntimes;
}

void line::set_line(vector<string> vec){
	for (int i = 0; i < vec.size(); i++){
		switch (i){
		case 0:
			set_add1(vec[i]);
			break;
		case 1:
			set_add2(vec[i]);
			break;
		case 2:
			inst.set_inst(vec[i]);
			break;
		default:
			inst.insert_op(vec[i]);
			break;
		}
	}
}

void line::set_add1(string str){
	add1 = str;
}

void line::set_add2(string str){
	add2 = str;
}

void line::set_inst(instruction ins){
	inst = ins;
}

string line::get_add1(){
	return add1;
}

string line::get_add2(){
	return add2;
}

string line::get_str_inst(){
	return inst.get_op_str();
}

instruction line::get_inst(){
	return inst;
}