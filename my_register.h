//Essa classe é usada para simular os registradores da classe my_mips
#pragma once
#include "stdafx.h"
class my_register
{
	string name, value, num;
	int ivalue;
public:
	my_register();
	~my_register();
	void set_name(string n);
	void set_value(string n);
	void set_ivalue(int n);
	void set_num(string n);
	string get_num();
	string get_name();
	string get_value();
	int get_ivalue();
};

