// BB_Generator.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include "instruction.h"
#include "line.h"
#include "bblock.h"
#include "bb_check.h"
#include "Roll_Call.h"
#include "simulator.h"

fstream fs;
ofstream arq("bb_out.txt");

list<bblock> bb_creator(list<line> vec, list<line> brs){
	list<bblock> temp;
	bblock blk;
	string s1, s2, s3;
	list<line> lst;
	bool flag_branch = false;
	for (line i : vec){
		lst.push_back(i);
		s1 = i.get_add1();
		for (line j : brs){
			s2 = j.get_add1();
			s3 = j.get_inst().get_op().back();
			if (s1 == s2){
				blk.set_instructions(lst);
				temp.push_back(blk);
				lst.clear();
			}
			if (s1 == s3){
				lst.pop_back();
				if (!lst.empty()){
					blk.set_instructions(lst);
					temp.push_back(blk);
					lst.clear();
				}
				lst.push_back(i);
			}
		}
	}
	if (!lst.empty()){
		blk.set_instructions(lst);
		temp.push_back(blk);
	}
	return temp;
}

string fix_line(string str){
	while (str.front() == ' ' || str.front() == '\t' || str.front() == ':' || str.front() == ','){
		if (str.length() > 1)
			str.erase(0, 1);
		else
			break;
	}
	return str;
}

line get_myline(string str){
	int a, i=0;
	line myline;
	string aux;
	vector<string> temp;
	str = fix_line(str);
	while (!str.empty()){
		a = str.find_first_of(": \t,");
		temp.push_back(str.substr(0, a));
		str.erase(0, a);
		if (str.empty()) break;
		str = fix_line(str);
		//if (str.length() == 1 || str.front()=='<')
		if (str.front()=='<')
			str.clear();
		i++;}
	myline.set_line(temp);
	return myline;}

void print_line_list(list<line> vec){
	for (line t:vec){
		t.print_line();
	}
	cout << "Size: "<<vec.size()<< endl;
}

void print_bblist(list<bblock> block_lst){
	string strvec;
	int n = 0;
	for (bblock i: block_lst){
		n++;
		cout << "Bloco " << n << endl;
		print_line_list(i.get_instructions());
		strvec = i.get_call_for();
		if (!strvec.empty()){
			cout << "Call for: " << strvec;
		}
		cout << endl << endl;
		strvec.clear();
	}
}

void export_line_list(list<line> vec){
	for (line t:vec){
		arq << "<" << t.get_ntimes() << " -> " << t.get_add1() << " " << t.get_add2() << " " << t.get_str_inst() << ">" << endl;
	}
//	arq << endl;
}

void export_bblist(list<bblock> block_list){
	string strvec;
	int n = 0;
	for (bblock i:block_list){
		n++;
		arq << "<Bloco " << n << ">" << endl;
		//export_line_list(i.get_instructions());
		arq << "add: " << i.get_fst_addr() << endl;
		arq << "ntimes: " << i.get_instructions().back().get_ntimes() << endl;
		arq << "size " << i.get_instructions().size() << endl;
		strvec = i.get_call_for();
		__int64 aux = str_hex_to_int(i.get_instructions().back().get_add1()) + 4;
		arq << "Call for: " << int_to_hex(aux);
		if (!strvec.empty()){
			arq << ", " << strvec;
		}
		arq <<endl<< "</Bloco " << n << ">" << endl;
		strvec.clear();
	}
	arq.close();
}

list<line> filter_normal_branch(list<line> program){
	list<line> temp;
	string temp_inst;
	for (line i : program){
		temp_inst = i.get_inst().get_inst();
		if (temp_inst == "beq" || temp_inst == "bne" || temp_inst == "bnez" || temp_inst == "beqz" || temp_inst == "j"){
			temp.push_back(i);
		}
	}
	return temp;
}

list<line> filter_linked_branch(list<line> program){
	list<line> temp;
	string temp_inst;
	for (line i : program){
		temp_inst = i.get_inst().get_inst();
		if (temp_inst == "jr" || temp_inst == "jal"){
			temp.push_back(i);
		}
	}
	return temp;
}

int _tmain(int argc, _TCHAR* argv[]){
	string str = "teste", aux;
	list<line> program, branches, linked_branches;
	list<bblock> block_list;
	fs.open("hello.dump");
	if (!fs.is_open())	return 0;
	while (fs.is_open()){
		getline(fs, str);
		if (str.empty()){
			fs.close();
			break;
		}
		program.push_back(get_myline(str));
	}

	//print_line_list(program);
	//system("PAUSE");
	program = simulation(program);
	print_line_list(program);

	branches = filter_normal_branch(program);
//	linked_branches = filter_linked_branch(program);
//	print_program(linked_branches);
	block_list = bb_creator(program, branches);
//	block_list = bblist_check(block_list, program);
//	print_bblist(block_list);
//	
	export_bblist(block_list);
	system("PAUSE");
	return 0;
}