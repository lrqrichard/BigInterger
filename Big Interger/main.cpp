// main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "biginterger.h"
#include <malloc.h>
#include <string.h>

int _tmain(int argc, _TCHAR* argv[])
{
	char op;
	char *num1, *num2, *num3, *num4;
	int len1, len2, maxlen;
	num1 = (char*)malloc(sizeof(char)*MAXLEN);
	num2 = (char*)malloc(sizeof(char)*MAXLEN);
	printf("Input the operator:\n");
	while (scanf("%c", &op)){
		printf("Input the first number\n");
		scanf("%s", num1);
		len1 = strlen(num1);
		printf("Input the second number\n");
		scanf("%s", num2);
		len2 = strlen(num2);
		maxlen = len1 > len2 ? len1 : len2;
		if (op == '+'){
			num3 = (char*)malloc(sizeof(char)*(maxlen + 2));
			BigAdd(num1, num2, num3);
			printf("The result is :\n%s\n", num3);
			free(num3);
		}
		else if (op == '-'){
			num3 = (char*)malloc(sizeof(char)*(maxlen + 2));
			BigSub(num1, num2, num3);
			printf("The result is :\n%s\n", num3);
			free(num3);
		}
		else if (op == '*'){
			num3 = (char*)malloc(sizeof(char)*(len1 + len2 + 1));
			BigMul(num1, num2, num3);
			printf("The result is :\n%s\n", num3);
			free(num3);
		}
		else if (op == '/'){
			num3 = (char*)malloc(sizeof(char)*(len1 + 2));
			num4 = (char*)malloc(sizeof(char)*(len1 + 2));
			BigDiv(num1, num2, num3, num4);
			printf("The result is :\n%s\n%s\n", num3, num4);
			free(num3);
			free(num4);
		}
		else{
			printf("Invalid operator!Try again!\nInput the operator:\n");
			getchar();
			continue;
		}
		getchar();
		printf("Input the operator\n");
	}
	return 0;
}

