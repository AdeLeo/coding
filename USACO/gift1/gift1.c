/*
ID: 13588021
LANG: C
TASK: gift1
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MAX_NAME_LEN 15
#define SUB 1
#define ADD 0

typedef struct person_info{
	char name[MAX_NAME_LEN];
	int money;
}person_info_t;

typedef struct total{
	int total_number;
	person_info_t *person;
}total_t;

total_t g_table;

/*初始化全局表格*/
void create_g_table(FILE *fin);
/*修改表格操作*/
void modify_table(FILE *fin);
/*修改对应的金额*/
/*
target_name:被修改者的名字
flag:标志(可为ADD或SUB)(ADD:增加金额，SUB:减少金额)
money:修改金额数目
*/
void modify_money(char *target_name, int flag, int money);
/*销毁表格*/
void destroy_g_table(void);
/*存储结果*/
void save_result(FILE *fout);

int main(void)
{
	FILE *fin = fopen("gift1.in", "r");
	FILE *fout = fopen("gift1.out", "w");

	create_g_table(fin);
	int i = 0;

	for(i = 0; i < g_table.total_number; i++)
		modify_table(fin);
	
	save_result(fout);
	destroy_g_table();

	fclose(fin);
	fclose(fout);

	exit(0);
}

void create_g_table(FILE *fin)
{
	int i = 0;

	fscanf(fin, "%d\n", &g_table.total_number);
	g_table.person = (person_info_t *)malloc(sizeof(person_info_t)*g_table.total_number);
	
	assert(g_table.person)
	
	bzero(g_table.person, sizeof(person_info_t)*g_table.total_number);
	
	for(i = 0; i < g_table.total_number; i++)
	{
		fscanf(fin, "%s\n", g_table.person[i].name);
		(g_table.person)[i].money = 0;
	}
}

void modify_money(char *target_name, int flag, int money)
{
	int i = 0;
	person_info_t *p = NULL;

	for(i = 0,  p = g_table.person; i < g_table.total_number; i++)
	{
		if(strcmp(target_name, p[i].name) == 0)
		{
			if(flag == SUB)
				p[i].money -= money;
			else
				p[i].money += money;
		}
	}
}

void modify_table(FILE *fin)
{
	char tmp[MAX_NAME_LEN] = "";
	char give_name[MAX_NAME_LEN] = "";
	int give_out = 0;
	int give_number = 0;
	int i = 0;
	
	fscanf(fin, "%s\n", give_name);
	fscanf(fin, "%d %d\n", &give_out, &give_number);

	if(give_number == 0)
		return;
	
	for(i = 0; i < give_number; i++)
	{
		fscanf(fin, "%s\n", tmp);
		modify_money(tmp, ADD, give_out/give_number);
	}

	modify_money(give_name, SUB, give_out-(give_out%give_number));

}

void save_result(FILE *fout)
{
	int i = 0;
	for(i = 0; i < g_table.total_number; i++)
	{
		fprintf(fout, "%s %d\n", g_table.person[i].name, g_table.person[i].money);
	}
}

void destroy_g_table(void)
{
	if(g_table.person)
		free(g_table.person);
	return;
}