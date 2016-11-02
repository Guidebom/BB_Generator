//Essa classe é utilzada para simular o processador Mips
#pragma once
#include "stdafx.h"
#include "my_register.h"
#include "n_to_hex.h"
class my_mips
{
	list<my_register> regs;
	string program_counter;
	__int64 iprogram_counter;
	//hig_pc, low_pc;
public:
	my_mips();
	~my_mips();
	void set_regs(list<my_register> l);
	void set_program_counter(string s);
	void set_iprogram_counter(__int64 d);
	void increment_pc();
	__int64 get_iprogram_counter();
	string get_program_counter();
	list<my_register> get_regs();
};

