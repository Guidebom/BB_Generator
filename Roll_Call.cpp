#include "stdafx.h"
#include "Roll_Call.h"

ofstream arq2("edges_out.txt");

void print_call_list(list<calling> l){
	for (calling i : l){
		cout << "caller:  " << i.get_caller() << " | called:  " << i.get_called() << endl;
	}
	cout << "Size: " << l.size() << endl << endl;
}

void export_call_list(list<calling> l){
	for (calling i : l){
		arq2 << "caller:  " << i.get_caller() << " | called:  " << i.get_called() << endl;
	}
	arq2 << "Size: " << l.size() << endl << endl;
	arq2.close();
}

list<calling> create_call_list(list<line> l){
	list<calling> temp;
	calling t;
	for (line i : l){
		t.set_caller(i.get_add1());
		t.set_called(i.get_inst().get_op().back());
		temp.push_back(t);
	}
//	print_call_list(temp);
	return temp;
}