// BB_Generator.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "instruction.h";
#include "line.h";
#include "bblock.h";
#include "bb_check.h";

fstream fs;
ofstream arq("bb_out.txt");

list<bblock> bb_creator(list<line> vec){
	list<bblock> temp;
	bblock blk;
	string temp_inst;
	list<line> lst;
	while (!vec.empty()){
		temp_inst = vec.front().get_inst().get_inst();
		lst.push_back(vec.front());
		if (temp_inst == "beq" || temp_inst == "bne" || temp_inst == "bnez" || temp_inst == "beqz" || temp_inst == "j" || temp_inst == "jr" || temp_inst == "jal"){
			//vec.erase(vec.begin());
			//temp_inst = vec.front().get_inst().get_inst();
			//list.push_back(vec.front());
			blk.set_instructions(lst);
			temp.push_back(blk);
			lst.clear();
		}
		vec.erase(vec.begin());
	}
	if (!lst.empty())
		blk.set_instructions(lst);
	temp.push_back(blk);
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
		if (str.length() == 1 || str.front()=='<')
			str.clear();
		i++;}
	myline.set_line(temp);
	return myline;}

void print_program(list<line> vec){
	for (line t:vec){
		cout << t.get_add1() << " ";
		cout << t.get_add2() << " ";
		cout << t.get_str_inst() << endl;
	}
	cout << endl;
}

void print_bblist(list<bblock> block_lst){
	string strvec;
	int n = 0;
	for (bblock i: block_lst){
		n++;
	//for (int i = 0; i < block_list.size(); i++){
		cout << "Bloco " << n << endl;
		print_program(i.get_instructions());
		strvec = i.get_call_for();
		if (!strvec.empty()){
			cout << "Call for: " << strvec;
		}
		cout << endl << endl;
		strvec.clear();
	}
}
void export_program(list<line> vec){
	for (line t:vec){
		arq << t.get_add1() << " " << t.get_add2() << " " << t.get_str_inst() << endl;
	}
	arq << endl;
}

void export_bblist(list<bblock> block_list){
	string strvec;
	int n = 0;
	for (bblock i:block_list){
		n++;
	//for (int i = 0; i < block_list.size(); i++){
		arq << " Bloco " << n << endl;
		export_program(i.get_instructions());
		strvec = i.get_call_for();
		if (!strvec.empty()){
			arq << "Call for: " << strvec;
		}
		arq << endl << endl;
		strvec.clear();
	}
	arq.close();
}


int _tmain(int argc, _TCHAR* argv[]){
	int a;
	string str = "teste", aux;
	list<line> program;
	list<bblock> block_list;
		
	fs.open("hello.lst");
	if (!fs.is_open())	return 0;
	while (fs.is_open()){
		getline(fs, str);
		if (str.empty()){
			fs.close();
			break;
		}
		program.push_back(get_myline(str));
	}
	print_program(program);
	block_list = bb_creator(program);
	bblist_check(block_list, program);
	print_bblist(block_list);
	export_bblist(block_list);
	system("PAUSE");
	return 0;
}