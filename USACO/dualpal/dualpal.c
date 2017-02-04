/*
ID: 13588021
LANG: C
TASK: dualpal
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define NOT_EQU 0
#define EQU 1
#define TRUE 1
#define FALSE 0

#define DEBUG_ON

#ifdef DEBUG_ON
	#define DEBUG(fmt, args...) printf("[DEBUG]:"fmt, ##args)
#else
	#define DEBUG(...)
#endif

int is_palindromic(char s[]);
int is_dual_palindromes(int target);
char *int_to_str(char dst[], int target, int base);

int main()
{
	FILE *fin, *fout;

	fin = fopen("dualpal.in", "r");
	fout = fopen("dualpal.out", "w");
	assert(fin != NULL && fout != NULL);

	int n;
	int start;
	fscanf(fin, "%d %d\n", &n, &start);
	assert(n >= 1 && n <= 15 && start > 0 && start < 10000);
	DEBUG("n:%d start:%d\n", n, start);

	for(++start; n > 0; start++)
	{
		if(is_dual_palindromes(start))
		{
			DEBUG("start:%d n:%d\n", start, n);
			fprintf(fout, "%d\n", start);
			n--;
		}
	}

	return 0;
}



int is_dual_palindromes(int target)
{
	int base = 2;
	int cnt = 0;
	char tmp[100] = "";

	for(; cnt < 2 && base <= 10; base++)
	{
		if(is_palindromic(int_to_str(tmp, target, base)))
		{
			// DEBUG("cnt:%d target:%d base:%d %s\n", cnt, target, base, tmp);
			cnt++;
		}
	}

	if(cnt == 2)
		return TRUE;
	else
		return FALSE;
}

int is_palindromic(char s[])
{
	assert(s != NULL);

	int len = strlen(s);
	int i = 0;
	int j = len-1;

	for(; i < j; i++, j--)
	{
		if(s[i] != s[j])
			return NOT_EQU;
	}

	return EQU;
}

char *int_to_str(char dst[], int target, int base)
{
	assert(dst != NULL && base >= 2);

	int i, j;
	int tmp;

	bzero(dst, strlen(dst));

	for(i = 0; target != 0; i++, target /= base)
	{
		tmp = target % base;
		sprintf(&dst[i], "%c", '0'+tmp);
	}

	for(i = 0, j = strlen(dst)-1; i < j; i++, j--)
	{
		tmp = dst[i];
		dst[i] = dst[j];
		dst[j] = tmp;
	}

	return dst;
}