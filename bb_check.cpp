#include "stdafx.h"
#include"bb_check.h";

list<string> called, found, new_bb_headers, all_addr;

void remove_found_from_called(){
	//remove endereços encontrados da lista de endereços chamados
	bool found_flag = false;
	int j, i;
	string aux;
	for (string i:found){
		for (string j: called){
 			if (i == j){
				found_flag = true;
				aux = j;
			}
		}
		if (found_flag == true){
			called.remove(aux);
			found_flag = false;
		}
	}
}

void print_list_of_str(list<string> str){
	for (string i:str){
		cout << i << endl;
	}
	cout << "Size: " << str.size() << endl << endl;
}

void load_all_addr(list<line> lst){
	for (line i:lst){
		all_addr.push_back(i.get_add1());
	}
}
void filter_called(){
	list<string> str;
	if (!all_addr.empty()){
		for (string i : called){
			for (string j : all_addr){
				if (j == i)
					str.push_back(i);
			}
		}
		called.clear();
		called = str;
	}
}

void bblist_check(list<bblock> lst, list<line> program){
	//Confere blocos criados para criar novos blocos se necessário
	vector<line> temp;
	string str1, str2;
	for (bblock i:lst){
		called.push_back(i.get_call_for());
	}
	load_all_addr(program);
	filter_called();
	for (string j:called){
		str1 = j;
		for (bblock i : lst){
			str2 = i.get_fst_addr();
			if (str1 == str2){
				found.push_back(str1);
			}
		}
	}
	print_list_of_str(called);
	remove_found_from_called();
	print_list_of_str(called);
}
