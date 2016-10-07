#pragma once
#include"stdafx.h";
class instruction
{
	string inst;
	vector<string> op;
	
public:
	instruction();
	~instruction();
	void set_inst(string str);
	void set_op(vector<string> vec);
	void insert_op(string str);
	
	string get_inst();
	string get_op_str();
	vector<string> get_op();
};

