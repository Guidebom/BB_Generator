#include "stdafx.h"
#include"bb_check.h";

void print_list_of_str(list<string> str){
	for (string i:str){
		cout << i << endl;
	}
	cout << "Size: " << str.size() << endl << endl;
}

list<line> insert_linked_code(line top, list<line> program){
	bool found_flag=0;
	list<line> temp;
	for (line i : program){
		if (top.get_inst().get_op().back() == i.get_add1())
			found_flag = true;
		if (found_flag == true){
			temp.push_back(i);
			if (i.get_inst().get_inst() == "jr"){
				break;
			}
			if (i.get_inst().get_inst() == "jal"){
				list<line> temp_list = insert_linked_code(i, program);
				for (line i : temp_list){
					temp.push_back(i);
				}
				temp_list.clear();
			}
		}
	}
	return temp;
}

list<bblock> bblist_check(list<bblock> lst, list<line> program){
	list<line> my_list, temp_list;
	list<bblock> temp;
	for (bblock b : lst){
		for (line l : b.get_instructions()){
			my_list.push_back(l);
			if (l.get_inst().get_inst() == "jal"){
				temp_list = insert_linked_code(l, program);
				for (line i : temp_list){
					my_list.push_back(i);
				}
				temp_list.clear();
			}
		}
		b.set_instructions(my_list);
		my_list.clear();
		temp.push_back(b);
	}
	return temp;
}
