//Simula a execução do programa e conta quantas vezes cada linha do código é executada.

//#include"simulator.h"
#include"stdafx.h"
#include"line.h"
#include"my_mips.h"
#include"instruction.h"

my_mips mips;

void exec_line(line l){
	mips.increment_pc();
	instruction inst = l.get_inst();
	string res, op1, op2;
	int ires = 0, iop1 = 0, iop2 = 0, i=0;
	vector<string> operators = inst.get_op();
	for (auto it = operators.begin(); it != operators.end(); it++){
		switch (i){
		case 0:
			res = *it;
			break;
		case 1:
			op1 = *it;
			break;
		case 2:
			op2 = *it;
			break;
		}
		i++;
	}
	for (my_register r : mips.get_regs()){
		if (r.get_value().size() < 5){
			if (r.get_name() == res || r.get_num() == res)
				ires = stoi(r.get_value());
			if (r.get_name() == op1 || r.get_num() == op1)
				iop1 = stoi(r.get_value());
			if (r.get_name() == op2 || r.get_num() == op2)
				iop2 = stoi(r.get_value());
		}
	}
	if (inst.get_inst() == "add"){
		ires = iop1 + iop2;
	}
	else if (inst.get_inst() == "addu"){
		if (iop1 < 0) iop1 *= -1;
		if (iop2 < 0) iop2 *= -1;
		ires = iop1 + iop2;
	}
	else if (inst.get_inst() == "addi") {
		ires = iop1 + stoi(op2);
	}
	else if (inst.get_inst() == "addiu"){
		iop2 = stoi(op2);
		if (iop1 < 0) iop1 *= -1;
		if (iop2 < 0) iop2 *= -1;
		ires = iop1 + stoi(op2);
	}
	else if (inst.get_inst() == "sub") {
		ires = iop1 - iop2;
	}
	else if (inst.get_inst() == "subu"){
		if (iop1 < 0) iop1 *= -1;
		if (iop2 < 0) iop2 *= -1;
		ires = iop1 - iop2;
	}
	else if (inst.get_inst() == "mfc0") {
		ires = iop1;
	}
	else if (inst.get_inst() == "j"){
		mips.set_program_counter(res);
	}
	else if (inst.get_inst() == "jal"){
		my_register my;
		list<my_register> local = mips.get_regs();
		for (auto it = local.begin(); it != local.end(); it++){
			my = *it;
			if (my.get_name() == "ra"){
				my.set_value(mips.get_program_counter());
				*it = my;
				break;
			}
		}
		mips.set_regs(local);
		mips.set_program_counter(res);
	}
	else if (inst.get_inst() == "jr"){
		my_register my;
		list<my_register> local = mips.get_regs();
		for (auto it = local.begin(); it != local.end(); it++){
			my = *it;
			if (my.get_name() == res){
				mips.set_program_counter(my.get_value());
				break;
			}
		}
	}
	my_register my;
	list<my_register> local = mips.get_regs();
	for (auto it = local.begin(); it != local.end(); it++){
		my = *it;
		if (my.get_name() == res){
			my.set_ivalue(ires);
			*it = my;
			break;
		}
	}
	mips.set_regs(local);
}

void print_mips_regs(){
	int i = 0;
	cout << "PC = " << mips.get_program_counter() << endl;
	for (my_register r : mips.get_regs()){
		cout << r.get_name() << "("<<r.get_num()<<") = " << r.get_value();
		if (i % 2 == 0) cout << endl;
		else cout << "				";
	}
}

list<line> simulation(list<line> program){

	mips.set_program_counter(program.front().get_add1());
	while (mips.get_program_counter() != program.back().get_add1()){
		for (auto it = program.begin(); it != program.end();it++){
			line l = *it;
			if (l.get_add1() == mips.get_program_counter()){
				l.increment_ntimes();
				exec_line(l);
				*it = l;
				print_mips_regs();
			//	system("PAUSE");
				break;
			}
		}
	}

	return program;
}