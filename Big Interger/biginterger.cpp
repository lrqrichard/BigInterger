#include "stdafx.h"
#include <stdio.h>
#include <string.h>
#include <malloc.h>
void BigAdd(char* a, char* b, char* answer)
{
	char *na, *nb,*ta;
	int bit1, bit2, bit3, carry = 0, len1, len2, i, j = 0;
	while (*a == '0' && *(a+1)!=0)a++;
	while (*b == '0' && *(b+1)!=0)b++;
	len1 = strlen(a);
	len2 = strlen(b);
	na = (char*)malloc(sizeof(char)*(len1));
	nb = (char*)malloc(sizeof(char)*(len2));
	for (i = 0; i < len1; i++)
			na[i] = a[len1 - i - 1];
	for (i = 0; i < len2; i++)
			nb[i] = b[len2 - i - 1];
	if (len1 > len2){
		char * tempc;
		int templen;
		tempc = na;
		na = nb;
		nb = tempc;
		templen = len1;
		len1 = len2;
		len2 = templen;
	}
	ta = (char*)malloc(sizeof(char)*(len2 + 1));
	for (i = 0; i <= len2; i++){
		if (i < len1)
			bit1 = na[i] - '0';
		else
			bit1 = 0;
		if (i < len2)
			bit2 = nb[i] - '0';
		else
			bit2 = 0;
		bit3 = (bit1 + bit2 + carry) % 10;
		carry = (bit1 + bit2 + carry) / 10;
		ta[i] = bit3 + '0';
	}
	i = len2;
	while (i > 0 && ta[i] == '0')i--;
	while (i >= 0)
		answer[j++] = ta[i--];
	answer[j] = '\0';
	free(na);
	free(nb);
	free(ta);
	return;
}

void BigSub(char* a, char* b, char* answer)
{
	char answersign = '+';
	char *na, *nb, *ta;
	int bit1, bit2, bit3, borrow = 0, len1, len2, i, j;
	while (*a == '0'  && *(a + 1) != 0)a++;
	while (*b == '0'  && *(b + 1) != 0)b++;
	len1 = strlen(a);
	len2 = strlen(b);
	na = (char*)malloc(sizeof(char)*(len1));
	nb = (char*)malloc(sizeof(char)*(len2));
	for (i = 0; i < len1; i++)
		na[i] = a[len1 - i - 1];
	for (i = 0; i < len2; i++)
		nb[i] = b[len2 - i - 1];
	if (len2 > len1){
		char * tempc;
		int templen;
		tempc = na;
		na = nb;
		nb = tempc;
		templen = len1;
		len1 = len2;
		len2 = templen;
		answersign = '-';
	}
	if (len1 == len2){
		i = 0;
		while (i < len1){
			if (a[i] < b[i]){
				char * tempc;
				int templen;
				tempc = na;
				na = nb;
				nb = tempc;
				templen = len1;
				len1 = len2;
				len2 = templen;
				answersign = '-';
				break;
			}
			i++;
		}
	}
	ta = (char*)malloc(sizeof(char)*(len1));
	for (i = 0; i < len1; i++){
		bit1 = na[i] - '0';
		if (i < len2)
			bit2 = nb[i] - '0';
		else
			bit2 = 0;
		bit3 = (bit1 - bit2 - borrow + 10) % 10;
		borrow = (bit1 - bit2 - borrow < 0) ? 1 : 0;
		ta[i] = bit3 + '0';
	}
	i = len1-1;
	j = 0;
	while (i > 0 && ta[i] == '0')i--;
	if (answersign == '-')
		answer[j++] = '-';
	while (i >= 0)
		answer[j++] = ta[i--];
	answer[j] = '\0';
	free(na);
	free(nb);
	free(ta);
	return;
}

void BigMul(char* a, char* b, char* answer)
{
	char *na, *nb, *ta;
	int bit1, bit2, bit3, carry, len1, len2, i, j;
	while (*a == '0'  && *(a + 1) != 0)a++;
	while (*b == '0'  && *(b + 1) != 0)b++;
	len1 = strlen(a);
	len2 = strlen(b);
	na = (char*)malloc(sizeof(char)*(len1));
	nb = (char*)malloc(sizeof(char)*(len2));
	ta = (char*)malloc(sizeof(char)*(len1+len2));
	for (i = 0; i < len1 + len2; i++)
		ta[i] = '0';
	for (i = 0; i < len1; i++)
		na[i] = a[len1 - i - 1];
	for (i = 0; i < len2; i++)
		nb[i] = b[len2 - i - 1];
	if (len2 > len1){
		char * tempc;
		int templen;
		tempc = na;
		na = nb;
		nb = tempc;
		templen = len1;
		len1 = len2;
		len2 = templen;
	}
	for (j = 0; j < len2; j++){
		carry = 0;
		bit2 = nb[j] - '0';
		for (i = 0; i < len1; i++){
			bit1 = na[i] - '0';
			bit3 = (bit1*bit2 + carry + ta[i + j] - '0') % 10;
			carry = (bit1*bit2 + carry + ta[i + j] - '0') / 10;
			ta[i + j] = bit3 + '0';
		}
	}
	ta[len1 + len2 - 1] = carry + '0';
	i = len1 + len2 - 1;
	j = 0;
	while (i > 0 && ta[i] == '0')i--;
	while (i >= 0)
		answer[j++] = ta[i--];
	answer[j] = '\0';
	free(na);
	free(nb);
	free(ta);
	return;
}
bool lessthan(char* a, char* b)
{
	int len1, len2;
	len1 = strlen(a);
	len2 = strlen(b);
	if (len1 < len2)
		return true;
	else if (len1 == len2){
		int i;
		for (i = 0; i < len1; i++){
			if (a[i] < b[i])
				return true;
		}
		return false;
	}
	else
		return false;
}
void BigDiv(char* a, char* b, char* answer1, char* answer2)
{
	char *ta, one[2] = {'1',0};
	int bit1, bit2, bit3, len1, len2, i, j, maxlen;
	while (*a == '0'  && *(a + 1) != 0)a++;
	while (*b == '0'  && *(b + 1) != 0)b++;
	if (*b == '0'){
		printf("The second number cannot be 0!\n");
		return;
	}
	len1 = strlen(a);
	len2 = strlen(b);
	ta = (char*)malloc(sizeof(char)*(len1+1));
	for (i = 0; i < len1; i++)
		answer1[i] = '0';
	answer1[len1] = 0;
	strcpy(ta, a);
	while (1){
		if (lessthan(ta,b)){
			strcpy(answer2, ta);
			break;
		}
		else{
			BigSub(ta, b, ta);
			BigAdd(answer1, one, answer1);
		}
	}
	free(ta);
	return;
}