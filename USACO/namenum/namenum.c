/*
ID: 13588021
LANG: C
TASK: transform
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#define DEBUG_ON
#ifdef DEBUG_ON
	#define DEBUG(fmt, args...) printf("[DEBUG]:"fmt, ##args);
#else
	#define DEBUG(...)
#endif

#define MAX_LEN 15

int num_map[] = {2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,0,7,7,8,8,8,9,9,9,0};

int main()
{
	FILE *fin = NULL;
	FILE *fout = NULL;
	FILE *fdict = NULL;

	fin = fopen("namenum.in", "r");
	fout = fopen("namenum.out", "w");
	fdict = fopen("dict.txt", "r");

	assert(fin != NULL && fout != NULL && fdict != NULL);

	char namenum[MAX_LEN] = "";
	char num_set[MAX_LEN] = "";
	
	fscanf(fin, "%s\n", namenum);
	assert(namenum != NULL);

	int n = strlen(namenum);
	int count = 0;

	while(fscanf(fdict, "%s\n", num_set) != EOF)
	{
		int m = strlen(num_set);
		if(n == m)
		{
			while(namenum[n-m]-'0' == num_map[num_set[n-m]-'A'] && m>=0)
			{
				m--;
				if(m == 0)
				{
					fprintf(fout, "%s\n", num_set);
					count++;
				}
			}
		}
	}

	if(count == 0)
		fprintf(fout, "NONE\n");

	return 0;
}