#include "stdafx.h";
#include "Roll_Call.h";

void print_call_list(list<calling> l){
	for (calling i : l){
		cout << "caller:  " << i.get_caller() << " | called:  " << i.get_called() << endl;
	}
	cout << "Size: " << l.size() << endl << endl;
}

list<calling> create_call_list(list<line> l){
	list<calling> temp;
	calling t;
	for (line i : l){
		t.set_caller(i.get_add1());
		t.set_called(i.get_inst().get_op().back());
		temp.push_back(t);
	}
	print_call_list(temp);
	return temp;
}