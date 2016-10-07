#include "stdafx.h"
#include "instruction.h"


instruction::instruction()
{
}


instruction::~instruction()
{
}

void instruction::set_inst(string str){
	inst = str;
}

string instruction::get_op_str(){
	string str = inst;
	for (int i = 0; i < op.size(); i++){
		str = str + ' ' + op[i];
	}
	return str;
}

void instruction::set_op(vector<string> vec){
	string str;
	for (int i = 0; i < vec.size(); i++){
		switch (i){
		case 0:
			inst = vec[i];
			break;
		default:
			str = vec[i];
			if (str[0] == '0' && str[1] == 'x'){
				vec[i].erase(vec[i].begin(), vec[i].begin() + 2);
			}
			op.push_back(vec[i]);
			break;
		}
	}
}


void instruction::insert_op(string str){
	if (str[0] == '0' && str[1] == 'x'){
		str.erase(str.begin(), str.begin() + 2);
	}
	op.push_back(str);
}

string instruction::get_inst(){
	return inst;
}
vector<string> instruction::get_op(){
	return op;
}