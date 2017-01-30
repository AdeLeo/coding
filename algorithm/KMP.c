#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void get_next(char T[], int *next)
{
	int len = T[0];

	int i = 0;
	int j = 0;

	next[1] = 0;

	while(i < len)
	{
		if(j == 0 || T[i] == T[j])
		{
			++i;
			++j;
			next[i] = j;
		}
		else
			j = next[j];
	}
}

int KMP(char S[], char T[], int pos)
{
	int i = pos;
	int j = 1;
	int next[500];
	get_next(T, next);

	while(i <= S[0] && j <= T[0])
	{
		if(j == 0 || S[i] == T[j])
		{
			i++;
			j++;
		}
		else
		{
			j = next[j];
		}
	}

	if(j > T[0])
		return i-T[0];
	else
		return 0;
}