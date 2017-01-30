/* DP for PROB:beads*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MAX_LEN 400

int max(int a, int b)
{
	return a-b>0?a:b;
}

int min(int a, int b)
{
	return a-b>0?b:a;
}

int main()
{
	FILE *fin, *fout;

	fin = fopen("beads.in", "r");
	fout = fopen("beads.out", "w");
	assert(fin != NULL && fout != NULL);

	int len;
	char s[MAX_LEN*2];
	char tmp[MAX_LEN];
	int left[MAX_LEN*2][2];
	int right[MAX_LEN*2][2];

	fscanf(fin, "%d\n%s\n", &len, tmp);
	assert(strlen(tmp) == len);

	strcpy(s, tmp);
	strcat(s, tmp);
//	printf("[DEBUG]:%s\n", s);

	int i = 0;
	char c;
	left[0][0] = 0;
	left[0][1] = 0;

	for(i = 1; i <= len*2; i++)
	{
		c = s[i-1];

		if(c == 'r')
		{
			left[i][0] = left[i-1][0] + 1;
			left[i][1] = 0;
		}
		else if(c == 'b')
		{
			left[i][1] = left[i-1][1] + 1;
			left[i][0] = 0; 
		}
		else
		{
			left[i][0] = left[i-1][0] + 1;
			left[i][1] = left[i-1][1] + 1;
		}
	}

	right[2*len][0] = 0;
	right[2*len][1] = 0;

	for(i = 2*len-1; i >= 0; i--)
	{
		c = s[i];

		if(c == 'r')
		{
			right[i][0] = right[i+1][0] + 1;
			right[i][1] = 0;
		}

		else if(c == 'b')
		{
			right[i][1] = right[i+1][1] + 1;
			right[i][0] = 0;
		}

		else
		{
			right[i][0] = right[i+1][0] + 1;
			right[i][1] = right[i+1][1] + 1;
		}
	}

	int m = 0;
	for(i = 0; i < len*2; i++)
	{
		m = max(m, max(left[i][0], left[i][1]) + max(right[i][0], right[i][1]));
	}

	m = min(m, len);

	fprintf(fout, "%d\n", m);

	fclose(fin);
	fclose(fout);

	exit(0);
}
