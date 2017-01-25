#include <stdio.h>

#define SHIFT 5
#define N 10000000
#define BITSPERWORD 32
#define MASK 0X1F

int arr[1 + N/BITSPERWORD] = {0};

void set(int i)
{
	arr[i >> SHIFT] |= (1 << (i & MASK));
}

void clr(int i)
{
	arr[i >> SHIFT] &= ~(1 << (i & MASK));
}

int test(int i)
{
	return arr[i >> SHIFT] & (1 << (i & MASK));
}

