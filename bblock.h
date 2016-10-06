#pragma once
#include"stdafx.h";
#include"line.h";
class bblock
{
	list<line> instructions;
	list<string> called_by;
	string fst_addr, lst_addr, call_for;
	int time;

public:
	bblock();
	~bblock();
	void set_instructions(list<line> inst);
	void set_call_for(string vec);
	void set_called_by(list<string> vec);
	void set_fst_addr(string str);
	void set_lst_addr(string str);
	void set_time(int t);
	list<line> get_instructions();
	string get_call_for();
	string get_fst_addr();
	string get_lst_addr();
};

