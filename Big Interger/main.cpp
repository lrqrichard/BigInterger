// main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "biginterger.h"
#include <iostream>
#include <malloc.h>
#include <string>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	char op;
	char *num1, *num2, *num3, *num4;
	string str1, str2;
	int len1, len2, maxlen;
	while (cin>>op){
		cin >> str1;
		len1 = str1.size();
		num1 = (char*)malloc(sizeof(char)*(len1 + 1));
		strcpy(num1, str1.c_str());
		cin >> str2;
		len2 = str2.size();
		num2 = (char*)malloc(sizeof(char)*(len2 + 1));
		strcpy(num2, str2.c_str());
		maxlen = len1 > len2 ? len1 : len2;
		if (op == '+'){
			num3 = (char*)malloc(sizeof(char)*(maxlen + 2));
			BigAdd(num1, num2, num3);
			cout<<num3<<endl;
			free(num3);
		}
		else if (op == '-'){
			num3 = (char*)malloc(sizeof(char)*(maxlen + 2));
			BigSub(num1, num2, num3);
			cout<<num3<<endl;
			free(num3);
		}
		else if (op == '*'){
			num3 = (char*)malloc(sizeof(char)*(len1 + len2 + 1));
			BigMul(num1, num2, num3);
			cout<<num3<<endl;
			free(num3);
		}
		else if (op == '/'){
			num3 = (char*)malloc(sizeof(char)*(len1 + 2));
			num4 = (char*)malloc(sizeof(char)*(len1 + 2));
			BigDiv(num1, num2, num3, num4);
			cout<<num3<<endl<<num4<<endl;
			free(num3);
			free(num4);
		}	
	}
	return 0;
}