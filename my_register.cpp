#include "stdafx.h"
#include "my_register.h"
#include "n_to_hex.h"


my_register::my_register()
{
}


my_register::~my_register()
{
}

void my_register::set_name(string n){
	name = n;
}
void my_register::set_value(string n){
	value = n;
	ivalue = str_dec_to_int(n);
}

void my_register::set_ivalue(double n){
	value = int_to_dec(n);
	ivalue = n;
}

void my_register::set_num(string n){
	num = n;
}
string my_register::get_num(){
	return num;
}

string my_register::get_name(){
	return name;
}

string my_register::get_value(){
	return value;
}

__int64 my_register::get_ivalue(){
	return ivalue;
}