/*
ID: 13588021
LANG: C
TASK: palsquare
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MAX_N 300
#define NOT_EQU 0
#define EQU 1

char *base_to_str(char dst[], int target, int base); // 数字转字符串
int is_palindrom(char s[]); // 判断是否为回文序列
char get_ch(int target);

int main(void)
{
	FILE *fin, *fout;

	fin = fopen("palsquare.in", "r");
	fout = fopen("palsquare.out", "w");
	assert(fin != NULL && fout != NULL);

	int base;
	fscanf(fin, "%d\n", &base); // 读入进制

	int i = 0;
	char dst[100] = "";
	char src[100] = "";

	for(i = 1; i <= MAX_N; i++)
	{
		base_to_str(src, i, base); // 结果中源的表示
		base_to_str(dst, i*i, base); // 结果中目的数的表示

		if(is_palindrom(dst))
		{
			fprintf(fout, "%s %s\n", src, dst); // 输出结果
		}
	}

	return 0;
}

char get_ch(int target) // 辅助数字转字符串函数
{ 
	if(target >=0 && target <= 9) // 若数字为0-9直接输出‘0’-‘9’
		return '0'+target;
	else // 输出大于9的表示
		return 'A'+target-10;
}

char *base_to_str(char dst[], int target, int base)
{
	assert(dst != NULL && target >= 0 && base >= 2);
	bzero(dst, strlen(dst));

	int i = 0;
	int tmp = 0;

	while(target != 0) // 每次取出最低位并按进制右移一位
	{
		tmp = target % base;
		sprintf(&dst[i], "%c", get_ch(tmp));
		target /= base;
		i++;
	}

	int j = strlen(dst)-1; // 进行字符串的翻转
	char t;

	for(i = 0; i < j; i++, j--)
	{
		t = dst[i];
		dst[i] = dst[j];
		dst[j] = t;
	}

	return dst;
}

int is_palindrom(char s[])
{
	assert(s != NULL);

	int i, j;
	i = 0;
	j = strlen(s)-1;

	for(;i < j; i++, j--)
	{
		if(s[i] != s[j])
			return NOT_EQU;
	}

	return EQU;
}
