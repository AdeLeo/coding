/*
ID: 13588021
LANG: C
TASK: milk2
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define MAX(a, b) ((a)>(b)?(a):(b))
#define MAX3(a, b, c) (MAX(a, MAX(b, c)))
#define MIN(a, b) ((a)<(b)?(a):(b))
#define MIN3(a, b, c) (MIN(a, MIN(b, c)))

int cmp(const void *a, const void *b)
{
	int *pa = *(int (*)[2])a;
	int *pb = *(int (*)[2])b;

	if(pa[0] > pb[0])
		return 1;
	else if(pa[0] < pb[0])
		return -1;
	else if(pa[1] > pb[1])
		return 1;
	else if(pa[1] < pb[1])
		return -1;
	else
		return 0;
}

int main()
{
	FILE *fin, *fout;

	fin = fopen("milk2.in", "r");
	fout = fopen("milk2.out", "w");

	assert(fin != NULL && fout != NULL);

	int n;
	int i = 0;

	int start_time1, end_time1;
	int start_time2, end_time2;
	int start, end;
	int start_no_milk, end_no_milk;
	int longest_time_milked = 0;
	int longest_time_no_milked = 0;

	fscanf(fin, "%d\n", &n);

	int event[n][2];

	for(i = 0; i < n; i++)
		fscanf(fin, "%d %d\n", &event[i][0], &event[i][1]);

	qsort((void *)event, n, sizeof(event[0]), cmp);

	start_time1 = event[0][0];
	end_time1 = event[0][1];
	start = start_time1;
	end = end_time1;

	for(i = 1; i < n; i++)
	{
		start_time2 = event[i][0];
		end_time2 = event[i][1];

		start_no_milk = end_time1;
		end_no_milk = start_time2;

		if(start_time2 <= end_time1)
		{
			start = MIN3(start, start_time1, start_time2);
			end = MAX3(end, end_time1, end_time2);
			longest_time_milked = MAX(longest_time_milked, end-start);
		}

		else
		{
			longest_time_milked = MAX3(longest_time_milked, end_time1-start_time1, end_time2-start_time2);
			longest_time_no_milked = MAX(longest_time_no_milked, end_no_milk-start_no_milk);
			start = start_time2;
			end = end_time2;
		}

		start_time1 = start;
		end_time1 = end;
	}

	longest_time_milked = MAX(longest_time_milked, end-start);
	fprintf(fout, "%d %d\n", longest_time_milked, longest_time_no_milked);

	fclose(fin);
	fclose(fout);

	return 0;
}
