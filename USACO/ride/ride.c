/*
ID: 13588021
LANG: C
TASK: ride
*/

#include <stdio.h>
#include <stdlib.h>

#define GATE 47

unsigned name_count(char *name);

int main(void)
{
	FILE *fin = fopen("ride.in", "r");
	FILE *fout = fopen("ride.out", "w");

	char comet_name[8] = "";
	char group_name[8] = "";

	fscanf(fin, "%s\n%s\n", comet_name, group_name);
    printf("[DEBUG]:%s\n%s\n", comet_name, group_name);
	if((name_count(comet_name)%GATE) == (name_count(group_name)%GATE))
	{
		fprintf(fout, "%s\n", "GO");
	}
	else
	{
		fprintf(fout, "%s\n", "STAY");
	}

	exit(0);
}

unsigned name_count(char *name)
{
	if(!name)
		return 0;

	char *p = name;
	unsigned int result = 1;
	while(*p != '\0' && *p != '\n')
	{
		result *= (*p - 'A' + 1);
		++p;
	}
	return result;
}
