/*
ID: 13588021
LANG: C
TASK: beads
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

int main()
{
	FILE *fin, *fout;

	fin = fopen("beads.in", "r");
	fout = fopen("beads.out", "w");

	int len;
	char tmp[400] = "";
	char s[800] = "";

	fscanf(fin, "%d\n%s\n", &len, tmp);
	assert(strlen(tmp) == len);

	strcpy(s, tmp);
	strcat(s, tmp);

	int i = 0;
	int j = 0;
	int state = 0;
	char c;
	int current = 0;
	int max = 0;

	for(i = 0; i < len; i++)
	{
		c = s[i];
		if(c == 'w')
			state = 0;
		else
			state = 1;

		j = i;
		current = 0;
		while(state <= 2)
		{
			while(j < len+i && (s[j] == c || s[j] == 'w'))
			{
				current++;
				j++;
			}
			state++;
			c = s[j];
		}
		if(current > max)
			max = current;
	}

	fprintf(fout, "%d\n", max);
	fclose(fin);
	fclose(fout);
	exit(0);
}
