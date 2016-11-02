#include "stdafx.h"
#include "my_mips.h"
#include "n_to_hex.h"

template< typename T >
string int_to_hex(T i)
{
	stringstream stream;
	stream << hex << i;
	string s = stream.str();
	//while (s.length() < 8)
	//	s = "0" + s;
	return s;
}

my_mips::my_mips()
{
	program_counter = int_to_hex<int>(0);
	my_register r;
	for (int i = 0; i <=31; i++)
	{
		r.set_value("0");
		switch (i){
		case 0:
			r.set_name("zero");
			break;
		case 1:
			r.set_name("at");
			break;
		case 2:
			r.set_name("v0");
			break;
		case 3:
			r.set_name("v1");
			break;
		case 4:
			r.set_name("a0");
			break;
		case 5:
			r.set_name("a1");
			break;
		case 6:
			r.set_name("a2");
			break;
		case 7:
			r.set_name("a3");
			break;
		case 8:
			r.set_name("t0");
			break;
		case 9:
			r.set_name("t1");
			break;
		case 10:
			r.set_name("t2");
			break;
		case 11:
			r.set_name("t3");
			break;
		case 12:
			r.set_name("t4");
			break;
		case 13:
			r.set_name("t5");
			break;
		case 14:
			r.set_name("t6");
			break;
		case 15:
			r.set_name("t7");
			break;
		case 16:
			r.set_name("s0");
			break;
		case 17:
			r.set_name("s1");
			break;
		case 18:
			r.set_name("s2");
			break;
		case 19:
			r.set_name("s3");
			break;
		case 20:
			r.set_name("s4");
			break;
		case 21:
			r.set_name("s5");
			break;
		case 22:
			r.set_name("s6");
			break;
		case 23:
			r.set_name("s7");
			break;
		case 24:
			r.set_name("t8");
			break;
		case 25:
			r.set_name("t9");
			break;
		case 26:
			r.set_name("k0");
			break;
		case 27:
			r.set_name("k1");
			break;
		case 28:
			r.set_name("gp");
			r.set_value("268468224");
			break;
		case 29:
			r.set_name("sp");
			break;
		case 30:
			r.set_name("fp");
			break;
		case 31:
			r.set_name("ra");
			break;
		}
		r.set_num("$" + to_string(i));
		regs.push_back(r);
	}	
}

my_mips::~my_mips()
{
}

void my_mips::set_regs(list<my_register> l){
	regs = l;
}
list<my_register> my_mips::get_regs(){
	return regs;
}

void my_mips::set_program_counter(string s){
	program_counter = s;
	iprogram_counter = str_hex_to_int(s);
}

void my_mips::set_iprogram_counter(__int64 d){
	iprogram_counter = d;
	string s = int_to_hex<__int64>(d);
	program_counter = s;
}

__int64 my_mips::get_iprogram_counter(){
	return iprogram_counter;
}

void my_mips::increment_pc(){
	iprogram_counter += 4;
	program_counter = int_to_hex<__int64>(iprogram_counter);
}
string my_mips::get_program_counter(){
	return program_counter;
}