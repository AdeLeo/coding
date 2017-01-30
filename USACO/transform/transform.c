/*
ID: 13588021
LANG: C
TASK: transform
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define N_MAX 15
#define EQUAL 1
#define UNEQU 0
#define ROTATE_90 1
#define ROTATE_180 2
#define ROTATE_270 3
#define REFLECTION 4
#define COMBINATION 5
#define NO_CHANGE 6
#define INVALID_TRANSFORM 7

// #define DEBUG_ON

#ifdef DEBUG_ON
	#define DEBUG(fmt, args...) printf("[DEBUG]:"fmt, ##args)
#else
	#define DEBUG(...)
#endif

int cmp_arr(char arr1[][N_MAX], char arr2[][N_MAX], int len); //比较函数， 比较两个矩阵是否完全相等
void rotate_90_n(char dest_arr[][N_MAX], char src_arr[][N_MAX], int len, int n); // 旋转(90 * n)°， n可以为1,2,3
void reflect(char dest_arr[][N_MAX], char src_arr[][N_MAX], int len); // 水平翻转，镜面对称

int main()
{
	FILE *fin, *fout;
    int n;

	fin = fopen("transform.in", "r");
	fout = fopen("transform.out", "w");
	assert(fin != NULL && fout != NULL);

	fscanf(fin, "%d\n", &n);
	char before_transform[n][N_MAX];
	char after_transform[n][N_MAX];
	char tmp[n][N_MAX];

	int i = 0, j = 0;
	for(i = 0; i < n; i++)
	{
		fscanf(fin, "%s\n", before_transform[i]);
	}

	for(i = 0; i < n; i++)
	{
		fscanf(fin, "%s\n", after_transform[i]);
	}
	
    int result = INVALID_TRANSFORM; // 先假定输出为非法转换，因为非法转换的优先级数最低

	if(cmp_arr(before_transform, after_transform, n) == EQUAL) // 比较是否相等，若相等可以提到比非法转换优先级较高一级的不转换
		result = NO_CHANGE;

	for(i = 1; i <= 3; i++) // 优先级最高的前三级，若符合条件则输出只会为1,2,3.此时不会进行后续的比较
	{
		rotate_90_n(tmp, before_transform, n, i);
		if(cmp_arr(after_transform, tmp, n) == EQUAL)
		{
			result = ROTATE_90 * i;
			break;
		}
	}

	if(result > COMBINATION) //若前三优先级未符合
	{
		reflect(tmp, before_transform, n); // 此时需要进行是否为水平翻转的判断
		if(cmp_arr(after_transform, tmp, n) == EQUAL)
			result = REFLECTION;

		for(i = 1; result != REFLECTION && i <= 3; i++) // 因优先级水平翻转比复合要高，若水平翻转匹配，则不进行下一步的匹配
		{
			rotate_90_n(before_transform, tmp, n, i); // 在先前水平翻转的基础上进行是否为复合的匹配操作

			if(cmp_arr(after_transform, before_transform, n) == EQUAL) 
			{
				result = COMBINATION;
				break;
			}
		}
	}

	fprintf(fout, "%d\n", result); // 输出结果

	fclose(fin);
	fclose(fout);

	return 0;
}

int cmp_arr(char arr1[][N_MAX], char arr2[][N_MAX], int len) // 比较函数，如完全匹配，则输出EQUAL, 否则输出UNEQU
{
	int i = 0;
	for(i = 0; i < len; i++)
	{
		if(strcmp(arr1[i], arr2[i]) != 0)
			break;
	}

	return i==len?EQUAL:UNEQU;
}

void rotate_90_n(char dest_arr[][N_MAX], char src_arr[][N_MAX], int len, int n) // 旋转操作函数，源操作矩阵放在src_arr中，输出的目的矩阵放在dest_arr中
{
	int i = 0;
	int j = 0;

	bzero(dest_arr, len*N_MAX*sizeof(char)); // 对目的矩阵进行清零操作
	if(n == 1) // 若旋转90°
	{
		for(i = 0; i < len; i++)
			for(j = 0; j < len; j++)
				dest_arr[j][len-1-i] = src_arr[i][j];
	}
	else if(n == 2) // 若旋转180°
	{
		for(i = 0; i < len; i++)
			for(j = 0; j < len; j++)
				dest_arr[len-1-i][len-1-j] = src_arr[i][j];
	}
	else if(n == 3) // 若旋转270°
	{
		for(i = 0; i < len; i++)
			for(j = 0; j < len; j++)
				dest_arr[len-1-j][i] = src_arr[i][j];
	}
}

void reflect(char dest_arr[][N_MAX], char src_arr[][N_MAX], int len) // 水平翻转矩阵操作，源操作矩阵放在src_arr中，输出的目的矩阵放在dest_arr中
{
	int i, j;

	bzero(dest_arr, len*N_MAX*sizeof(char)); // 对目的矩阵清零操作

	for(i = 0; i < len; i++)
		for(j = 0; j < len; j++)
			dest_arr[i][len-1-j] = src_arr[i][j];
}
