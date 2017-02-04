/*
ID: 13588021
LANG: C
TASK: barn1
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// #define DEBUG_ON

#ifdef DEBUG_ON
	#define DEBUG(fmt, args...) printf("[DEBUG]:"fmt, ##args)
#else
	#define DEBUG(...) 
#endif

struct gaps{
	int start;
	int end;
};

int order_cmp(const void *pa, const void *pb)
{
	return *(int *)pa - *(int *)pb;
}

int gaps_cmp(const void *ga, const void *gb)
{
	struct gaps *a = (struct gaps *)ga;
	struct gaps *b = (struct gaps *)gb;

	int gapa = a->end - a->start;
	int gapb = b->end - b->start;

	return gapa > gapb ? -1 : 1;
}

int main()
{
	FILE *fin = NULL, *fout = NULL;

	fin = fopen("barn1.in", "r");
	fout = fopen("barn1.out", "w");
	assert(fin != NULL && fout != NULL);

	int max_board_number = 0;
	int stall_numbers = 0;
	int occupied_numbers = 0;
	
	fscanf(fin, "%d %d %d\n", &max_board_number, &stall_numbers, &occupied_numbers);

	int i = 0;
	struct gaps stall_list[occupied_numbers-1];
	int input_list[occupied_numbers];

	for(i = 0; i < occupied_numbers; i++)
		fscanf(fin, "%d\n", &input_list[i]);

	qsort(input_list, occupied_numbers, sizeof(input_list[0]), order_cmp);

	stall_list[0].start = input_list[0];
	stall_list[0].end = input_list[1];

	for(i = 1; i < occupied_numbers - 1; i++)
	{
		stall_list[i].start = stall_list[i-1].end;
		stall_list[i].end = input_list[i+1];
	}
	
	stall_numbers -= stall_numbers - stall_list[occupied_numbers-2].end;
	stall_numbers = stall_numbers - stall_list[0].start + 1;

	DEBUG("stall_numbers:%d\n", stall_numbers);

	qsort(stall_list, occupied_numbers-1, sizeof(stall_list[0]), gaps_cmp);

	for(i = 0; i < occupied_numbers-1; i++)
	{
		DEBUG("stall_list[%d]:%d\n", i, stall_list[i].end-stall_list[i].start);
	}

	int gap = 0;

	for(i = max_board_number-1; i > 0 && max_board_number-1-i < occupied_numbers-1; i--)
	{
		gap = stall_list[max_board_number-1-i].end - stall_list[max_board_number-1-i].start - 1;
		stall_numbers -= gap;
		DEBUG("stall_numbers:%d gap:%d\n", stall_numbers, gap);
	}

	DEBUG("stall_numbers:%d\n", stall_numbers);
	fprintf(fout, "%d\n", stall_numbers);

	fclose(fin);
	fclose(fout);

	return 0;
}