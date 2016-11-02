#include "stdafx.h"

__int64 str_hex_to_int(string s){
	__int64 num = 0, aux = 0;
	int ponto = 0;
	for (int i = s.length() - 1; i >= 0; i--){
		int j = s.length() - 1 - i - ponto;
		char a = s[i];
		if (s[i] >= 0x30 && s[i] <= 0x39) aux = s[i] - 0x30;
		else if (s[i] >= 0x61 && s[i] <= 0x66) aux = s[i] - 0x61 + 10;
		else if (s[i] >= 0x41 && s[i] <= 0x46) aux = s[i] - 0x41 + 10;
		else if (s[i] == 0x2E){
			num = 0;
			ponto = j + 1;
		}
		else break;
		num += (pow(16, j))*aux;
	}
	return num;
}

__int64 str_dec_to_int(string s){
	__int64 num = 0, aux = 0;
	int ponto = 0;
	for (int i = s.length() - 1; i >= 0; i--){
		int j = s.length() - 1 - i - ponto;
		char a = s[i];
		if (s[i] >= 0x30 && s[i] <= 0x39) aux = s[i] - 0x30;
		else if (s[i] == 0x2E){
			num = 0;
			ponto = j + 1;
		}
		else if (s[i] == 0x2D){
			num *= -1;
			break;
		}
		else break;
		num += (pow(10, j))*aux;
	}
	return num;
}

string int_to_hex(int i)
{
	stringstream stream;
	stream << hex << i;
	string s = stream.str();
	//while (s.length() < 8)
	//	s = "0" + s;
	return s;
}

string int_to_dec(int i)
{
	stringstream stream;
	stream << i;
	string s = stream.str();
	//while (s.length() < 8)
	//	s = "0" + s;
	return s;
}