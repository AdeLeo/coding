/*
ID: 13588021
LANG: C
TASK: milk
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define DEBUG_ON

#ifdef DEBUG_ON
	#define DEBUG(fmt, args...) printf("[DEBUG]:"fmt, ##args)
#else
	#define DEBUG(...)
#endif

struct farm{
	int price;
	int mount;
};

int farm_cmp(const void *fa, const void *fb)
{
	struct farm *a = (struct farm *)fa;
	struct farm *b = (struct farm *)fb;

	if(a->price != b->price)
		return a->price > b->price ? 1 : -1; 
	else
		return a->mount > b->mount ? -1 : 1;
}

int main()
{
	FILE *fin, *fout;
	fin = fopen("milk.in", "r");
	fout = fopen("milk.out", "w");
	assert(fin != NULL && fout != NULL);
	
	int total_need = 0;
	int farmer_num = 0;
	int cost_total = 0;
	int need_mount = 0;

	fscanf(fin, "%d %d\n", &total_need, &farmer_num);
	assert(total_need >= 0 && farmer_num >= 0);

	struct farm farm_list[farmer_num];
	int i = 0;
	for(i = 0; i < farmer_num; i++)
	{
		fscanf(fin, "%d %d\n", &farm_list[i].price, &farm_list[i].mount);
	}

	qsort(farm_list, farmer_num, sizeof(farm_list[0]), farm_cmp);

	for(i = 0; i < farmer_num && total_need > 0; i++)
	{
		DEBUG("farm_list[%d]:%d %d\n", i, farm_list[i].price, farm_list[i].mount);
		need_mount = total_need > farm_list[i].mount ? farm_list[i].mount : total_need; 
		cost_total += farm_list[i].price * need_mount;
		total_need -= need_mount;
	}

	fprintf(fout, "%d\n", cost_total);

	return 0;
}