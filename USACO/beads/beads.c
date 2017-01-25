/*
ID: 13588021
LANG: C
TASK: beads
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

#define MAX_N 400 //定义接受字符串输入的最长长度
#define GET_PRE_ONE(i, numbers) ((i-1+numbers)%numbers) //在字符串有效长度内取前一个有效索引
#define GET_NEXT_ONE(i, numbers) ((i+1)%numbers) //在字符串有效长度内取后一个有效索引

int main(void)
{
	FILE *fin, *fout;
	int beads_number; //珠子数目
	char beads_order[MAX_N] = ""; //珠子的排布
	int max_collect_beads = 0; //最大能收集的珠子的数量
	int beads_cnt = 0; //每次能收集的珠子的数量
	int i = 0; 
	int j = 0;
	int new_i = 0;
	int next_i = 0;
	int bound = 0; //定义边界，用于处理能收集全部珠子的特殊情况

	fin = fopen("beads.in", "r");
	fout = fopen("beads.out", "w");

	fscanf(fin, "%d\n%s\n", &beads_number, beads_order); //读取珠子的数目和排布情况

	for(i = 0; i < beads_number; )
	{
		beads_cnt = 0; //每次将能收取的珠子数目清零
		while(i < beads_number && beads_order[i] == 'w') //定位第一个非w字符，注意：考虑字符全为w的情况下，需要考虑边界条件
			i++; 

		if(i >= beads_number) //字符全为w的情况，直接将全部珠子收集并退出
		{
			max_collect_beads = beads_number;
			break;
		}

		j = i;	//从当前开始往后收集珠子
		next_i = i; //下一个非'w'的字符作为新的起点
		bound = i; //边界为当前位置
		while(beads_order[j] == beads_order[i] || beads_order[j] == 'w') //开始收集珠子
		{
			beads_cnt++;
			next_i++;
			j = GET_NEXT_ONE(j, beads_number);

			if(j == bound) //若到达边界，则说明能收集所有珠子，此时得到最大能收集数目并退出
			{
				max_collect_beads = beads_cnt; 
				break;
			}
			DEBUG("i:%d j:%d\n", i, j);
			//sleep(1);
		}

		DEBUG("i:%d j:%d beads_cnt:%d\n", i, j, beads_cnt);
		if(j == bound) //达到边界直接退出循环
			break;

		bound = GET_PRE_ONE(j, beads_number); //边界为j的前一个字符

		new_i = GET_PRE_ONE(i, beads_number); //从后往前开始收集珠子
		i = next_i; //更新下一次循环时所用到的i

		while(new_i != bound && beads_order[new_i] == 'w') //收集遇到第一个非'w'珠子前遇到的所有w珠子
		{
			beads_cnt++;
			new_i = GET_PRE_ONE(new_i, beads_number);
		}

		if(new_i == bound) //收集到达边界
		{
			max_collect_beads = beads_cnt;
			break;
		}

		j = new_i;
		while(j != bound && beads_order[j] == beads_order[new_i] || beads_order[j] == 'w') //从后往前收集珠子
		{
			beads_cnt++;
			j = GET_PRE_ONE(j, beads_number);
		}

		if(j == bound)
		{
			max_collect_beads = beads_cnt;
			break;
		}

		if(beads_cnt > max_collect_beads) //若此时收集珠子的个数大于最大收集珠子数目，则更新最大收集珠子数目
			max_collect_beads = beads_cnt;

		DEBUG("max:%d", max_collect_beads);
		//putchar(getchar());
	}

	fprintf(fout, "%d\n", max_collect_beads);

	fclose(fin);
	fclose(fout);

	exit(0);
}