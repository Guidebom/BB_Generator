//Essa classe é utilzada para simular o processador Mips
#pragma once
#include "stdafx.h"
#include "my_register.h"
class my_mips
{
	list<my_register> regs;
	string program_counter;
	int hig_pc, low_pc;
public:
	my_mips();
	~my_mips();
	void set_regs(list<my_register> l);
	void set_program_counter(string s);
	void set_hig_pc(int l);
	void set_low_pc(int l);
	void increment_pc();
	string get_program_counter();
	int get_hig_pc();
	int get_low_pc();
	list<my_register> get_regs();
};

