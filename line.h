#pragma once
#include "instruction.h";
class line
{
	string add1, add2;
	instruction inst;
	
public:
	line();
	~line();
	void set_line(vector<string> vec);
	void set_add1(string str);
	void set_add2(string str);
	void set_inst(instruction ins);
	string get_add1();
	string get_add2();
	string get_str_inst();
	instruction get_inst();
};

