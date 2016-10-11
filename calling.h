#pragma once
#include"stdafx.h";
class calling
{
	string caller, called;
	
public:
	void set_caller(string s);
	void set_called(string s);
	string get_caller();
	string get_called();

	calling();
	~calling();
};

