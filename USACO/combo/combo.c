/*
ID: 13588021
LANG: C
TASK: combo
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// #define DEBUG_ON

#ifdef DEBUG_ON
	#define DEBUG(fmt, args...) printf("[DEBUG]:"fmt, ##args);
#else
	#define DEBUG(...)
#endif

#define PASSWD_LEN 3

int check(int key, int (*passwd)[PASSWD_LEN], int index);
void get_bound(int key, int *low, int *high);
int check_passwd(int *key, int (*passwd)[PASSWD_LEN]);

int max_number = 0;

int main()
{
	FILE *fin, *fout;

	fin = fopen("combo.in", "r");
	fout = fopen("combo.out", "w");

	assert(fin != NULL && fout != NULL);

	fscanf(fin, "%d\n", &max_number);
	assert(max_number >= 0);

	int passwd[2][PASSWD_LEN];
	fscanf(fin, "%d %d %d\n", &passwd[0][0], &passwd[0][1], &passwd[0][2]);
	fscanf(fin, "%d %d %d\n", &passwd[1][0], &passwd[1][1], &passwd[1][2]);

	int tmp[PASSWD_LEN];
	int cnt = 0;

	for(tmp[0] = 1; tmp[0] <= max_number; (tmp[0])++)
	{
		for(tmp[1] = 1; tmp[1] <= max_number; (tmp[1])++)
		{
			for(tmp[2] = 1; tmp[2] <= max_number; (tmp[2])++)
			{
				if(check_passwd(tmp, passwd))
				{
					DEBUG("tmp:%d %d %d\n", tmp[0], tmp[1], tmp[2]);
					++cnt;
				}
			}
		}
	}

	fprintf(fout, "%d\n", cnt);

	fclose(fin);
	fclose(fout);

	return 0;
}

int check_passwd(int *key, int (*passwd)[PASSWD_LEN])
{
	assert(key && passwd);

	int i = 0;
	for(i = 0; i < 2; i++)
	{
		if((check(key[0], passwd+i, 0) && check(key[1], passwd+i, 1) && check(key[2], passwd+i, 2)))
			return 1;
	}
	return 0;
}

int check(int key, int (*passwd)[PASSWD_LEN], int index)
{
	assert(passwd && index >= 0 && index <= PASSWD_LEN);

	int low, high;

	get_bound(passwd[0][index], &low, &high);
	DEBUG("high:%d low:%d\n", high, low);
	// getchar();

	if((high - low == 4))
	{
		if((key >= low && key <= high)){
			DEBUG("111\n");
			return 1;
		}
		else
			return 0;
	}
	else if(!(key > low && key < high))
	{
		DEBUG("222\n");
		return 1;
	}

	return 0;
}

void get_bound(int key, int *low, int *high)
{
	assert(low && high && max_number >= 0);

	if(key - 2 > 0 && key + 2 <=max_number)
	{
		*high = key + 2;
		*low = key - 2;
	}
	else
	{
		*high = (key - 2 + max_number) % (max_number+((key > 0 && key <= 2) ? 1:0));
		*low = (key + 2) % max_number;
	}
}