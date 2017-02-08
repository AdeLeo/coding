/*
ID: 13588021
LANG: C
TASK: wormhole
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define IN 1
#define OUT 0

int n = 0, ans = 0;
int b[13];

struct Node{
	int x;
	int y;
}a[13];

int cmp(const void *a1, const void *a2);
void make_pair(int start);
int judge(void);

int main()
{
	FILE *fin = NULL, *fout = NULL;
	fin = fopen("wormhole.in", "r");
	fout = fopen("wormhole.out", "w");
	assert(fin && fout);

	fscanf(fin, "%d\n", &n);
	int i = 0;
	for(i = 1; i <= n; i++)
	{
		fscanf(fin, "%d %d\n", &a[i].x, &a[i].y);
	}

	qsort(a+1, n, sizeof(a[0]), cmp);
	make_pair(1);
	fprintf(fout, "%d\n", ans);

	fclose(fin);
	fclose(fout);

	return 0;
}

int doit(int cnt, int index, int start, int dir) // cnt for count, index for point now, start is start point, dir is direction.(0 means out, 1 means in)
{
	if(cnt != 1 && index == start && dir == OUT)
		return 1;
	if(dir == OUT)
	{
		if(a[index].y == a[index+1].y)
			return doit(cnt+1, index+1, start, IN);
		else
			return 0;
	}
	if(dir == IN)
		return doit(cnt+1, b[index], start, OUT);
}

int judge(void)
{
	int i, j;
	for(i = 1; i < n+1; i++) // walk start with point i
	{
		if(doit(1, i, i, OUT) == 1)
			return 1;
	}
	return 0;
}

void make_pair(int start)
{
	int i;
	if(start == n+1) // make pair finished, start judge
	{
		if(judge() == 1) // judge if loop exist
			ans++;
		return ;
	}
	if(b[start] == 0) // make pair for unpaired point
	{
		for(i = start+1; i < n+1; i++)
		{
			if(b[i] == 0)
			{
				b[i] = start;
				b[start] = i;
				make_pair(start+1);
				b[i] = 0;
				b[start] = 0;
			}
		}
	}
	else
		make_pair(start+1); // make pair for next point
	return ;
}

int cmp(const void *a1, const void *a2)
{
	struct Node *pa = (struct Node *)a1;
	struct Node *pb = (struct Node *)a2;

	if(pa->y < pb->y)
		return 1;
	else if(pa->y == pb->y)
	{
		if(pa->x < pb->x)
			return 1;
	}
	return 0;
}