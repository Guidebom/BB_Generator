#pragma once
#include "instruction.h"
class line
{
	string add1, add2;
	instruction inst;
	int ntimes;
	
public:
	line();
	~line();
	void set_line(vector<string> vec);
	void set_add1(string str);
	void set_add2(string str);
	void set_inst(instruction ins);
	void set_ntimes(int n);
	void increment_ntimes();
	int get_ntimes();
	string get_add1();
	string get_add2();
	string get_str_inst();
	instruction get_inst();
	void print_line();
};

