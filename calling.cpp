#include "stdafx.h"
#include "calling.h"


calling::calling()
{
}


calling::~calling()
{
}

void calling::set_caller(string s){
	caller = s;
}
void calling::set_called(string s){
	called = s;
}
string calling::get_caller(){
	return caller;
}
string calling::get_called(){
	return called;
}
