#include <stdio.h>

#define N 8
#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof(arr[0]))

/*
	char str[128]中每个元素的值都是0或者1，请编程实现将该128个元素保存到char arr[16]中，以节约空间占用，例如：将str[0]放到arr[0]的第0位上，str[8]放到arr[1]的第0位上。

*/

char charProduce(char *arr)
{
	char result = 0;
	int i = 0;

	for(i = 0; i < N; i++)
	{
		result |= (arr[i] << i);
	}

	return result;
}

void compress(char *dest, int destLen, const char *arr, int len)
{
	if(len / destLen != N)
		return ;

	int i = 0;
	for(i = 0; i < len / destLen; i++)
	{ 
		dest[i] = charProduce(arr + i*N);
	}

	return ;
}

int main()
{
	char str[128] = {};
	char arr[16] = {};

	compress(arr, ARRAY_SIZE(arr), str, ARRAY_SIZE(str));

	int i = 0;
	for(i = 0; i < ARRAY_SIZE(arr); i++)
	{
		printf("arr[%d]:%d\n", i; arr[i]);
	}

	return 0;
}
