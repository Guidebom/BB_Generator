//Simula a execução do programa e conta quantas vezes cada linha do código é executada.

//#include"simulator.h"
#include"stdafx.h"
#include"line.h"
#include"my_mips.h"
#include"instruction.h"
#include"n_to_hex.h"

my_mips mips;

void exec_line(line l){
	bool branch_flag = false;
	mips.increment_pc();
	instruction inst = l.get_inst();
	string res, op1, op2;
	__int64 ires = 0, iop1 = 0, iop2 = 0;
	int i = 0;
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
		if (r.get_name() == res || r.get_num() == res)
			ires = str_dec_to_int(r.get_value());
		if (r.get_name() == op1 || r.get_num() == op1)
			iop1 = str_dec_to_int(r.get_value());
		if (r.get_name() == op2 || r.get_num() == op2)
			iop2 = str_dec_to_int(r.get_value());
	}
	//MIPS INSTRUCTIONS SET ARCHITECTURE
	if (inst.get_inst() == "abs"){
		ires = iop1;
	}
	else if (inst.get_inst() == "add" || inst.get_inst() == "addu" || inst.get_inst() == "addi" || inst.get_inst() == "addiu"){
		if (inst.get_inst() == "addi" || inst.get_inst() == "addiu") {
			iop2 = str_dec_to_int(op2);
		}
		ires = iop1 + iop2;
	}
	else if (inst.get_inst() == "and" || inst.get_inst() == "andi"){
		if (inst.get_inst() == "andi")
			iop2 = str_dec_to_int(op2);
		ires = iop1 & iop2;
	}
	else if (inst.get_inst() == "div" || inst.get_inst() == "divu"){
		if (inst.get_inst() == "divu"){
			if (iop1 < 0) iop1 *= -1;
			if (iop2 < 0) iop2 *= -1;
		}
		ires = (iop1%iop2)*0xFFFF + (iop1 / iop2);
	}
	else if (inst.get_inst() == "neg" || inst.get_inst() == "negu"){
		if (inst.get_inst() == "negu"){ if (iop1 < 0) { iop1 *= -1; } }
		ires = (-1)*iop1;
	}
	else if (inst.get_inst() == "not"){
		ires = ~iop1;
	}
	else if (inst.get_inst() == "nor"){
		ires = ~(iop1 | iop2);
	}
	else if (inst.get_inst() == "or" || inst.get_inst() == "ori"){
		if (inst.get_inst() == "ori")
			iop2 = str_dec_to_int(op2);
		ires = iop1 || iop2;
	}
	else if (inst.get_inst() == "sllv" || inst.get_inst() == "sll"){
		if (inst.get_inst() == "sll")
			iop2 = str_dec_to_int(op2);
		ires = iop1 << iop2;
	}
	else if (inst.get_inst() == "sra" || inst.get_inst() == "srav" || inst.get_inst() == "srl" || inst.get_inst() == "srlv"){
		if (inst.get_inst() == "sra" || inst.get_inst() == "srl")
			iop2 = str_dec_to_int(op2);
		ires = iop1 >> iop2;
	}
	else if (inst.get_inst() == "sub" || inst.get_inst() == "subu") {
		if (inst.get_inst() == "subu"){
			if (iop1 < 0) iop1 *= -1;
			if (iop2 < 0) iop2 *= -1;
		}
		ires = iop1 - iop2;
	}
	else if (inst.get_inst() == "xor" || inst.get_inst() == "xori"){
		if (inst.get_inst() == "xori")
			iop2 = str_dec_to_int(op2);
		ires = iop1 ^ iop2;
	}
	else if (inst.get_inst() == "mfc0") {
		ires = iop1;
	}
	else if (inst.get_inst() == "move") {
		ires = iop1;
	}
	else if (inst.get_inst() == "j"){
		mips.set_program_counter(res);
	}
	else if (inst.get_inst() == "jal"){
		/*my_register my;
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
		mips.set_program_counter(res);*/
	}
	else if (inst.get_inst() == "jr"){
		//my_register my;
		//list<my_register> local = mips.get_regs();
		//for (auto it = local.begin(); it != local.end(); it++){
		//	my = *it;
		//	if (my.get_name() == res){
		//		if (my.get_value().size() == 8){
		//			mips.set_program_counter(my.get_value());
		//			break;
		//		}
		//		else{
		//			//if (my.get_ivalue() < 0xFFFF){
		//			//	mips.set_low_pc(my.get_ivalue());
		//			//}
		//			//else {
		//			//	mips.set_hig_pc(my.get_ivalue()/0xFFFF);
		//			//	mips.set_low_pc(my.get_ivalue() - (my.get_ivalue() / 0xFFFF));
		//			//}
		//			mips.set_iprogram_counter(my.get_ivalue());
		//			break;
		//		}
		//	}
		//}
	}
	else if (inst.get_inst() == "slt" || inst.get_inst() == "sltu"){
		if (inst.get_inst() == "sltu"){
			if (iop1 < 0) iop1 *= -1;
			if (iop2 < 0) iop2 *= -1;
		}
		if (iop1 < iop2) ires = 1;
		else ires = 0;
	}
	else if (inst.get_inst() == "slti" || inst.get_inst() == "sltiu"){
		iop2 = str_dec_to_int(op2);
		if (inst.get_inst() == "sltiu"){
			if (iop1 < 0) iop1 *= -1;
			if (iop2 < 0) iop2 *= -1;
		}
		if (iop1 < iop2) ires = 1;
		else ires = 0;
	}
	else if (inst.get_inst() == "bnez"){
		branch_flag = true;
		if (ires != 0) mips.set_program_counter(op1);
	}
	else if (inst.get_inst() == "bne"){
		branch_flag = true;
		if (ires != iop1) mips.set_program_counter(op2);
	}
	else if (inst.get_inst() == "beqz"){
		branch_flag = true;
		if (ires == 0) mips.set_program_counter(op1);
	}
	else if (inst.get_inst() == "beq"){
		branch_flag = true;
		if (ires == iop1) {
			mips.set_program_counter(op2);
		}
	}
	else if (inst.get_inst() == "li" || inst.get_inst() == "lui"){
		iop1 = str_dec_to_int(op1);
		if (inst.get_inst() == "lui"){
			iop1 &= 0xFF;
			iop1 *= 0xFFFF;
		}
		ires = iop1;
	}
	else {
		cout << "Invalid instructions at: " << mips.get_program_counter()<<endl;
		//system("PAUSE");
	}
	if (branch_flag == false){
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
	else {
		branch_flag = false;
	}
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
				/*l.print_line();
				print_mips_regs();*/
				l.increment_ntimes();
				exec_line(l);
				//system("PAUSE");
				*it = l;
				break;
			}
		}
	}

	return program;
}