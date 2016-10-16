#include "stdafx.h"
#include "my_register.h"


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
	if (n.size()<5)
	ivalue = stoi(n);
}

void my_register::set_ivalue(int n){
	value = to_string(n);
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