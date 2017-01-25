/*
ID: 13588021
LANG: C
TASK: friday
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define DAYS_PER_WEEK 7
#define START 1900
#define START_MONTH 1
#define MONTH_PER_YEAR 12

#define MONDAY 1
#define TUESDAY 2
#define WEDNESDAY 3
#define THURSDAY 4
#define FRIDAY 5
#define SATUDAY 6
#define SUNDAY 0

int days_per_month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int is_leap_year(int year)
{
	return (year % 4 == 0 && year % 100 != 0 || year % 400 == 0);
}

void day_count(int *day_cnt, int n);

int main()
{
	int day_cnt[DAYS_PER_WEEK] = {0};
	int n;
	FILE *fin, *fout;

	fin = fopen("friday.in", "r");
	fout = fopen("friday.out", "w");

	fscanf(fin, "%d", &n);

	day_count(day_cnt, n);

	fprintf(fout, "%d %d %d %d %d %d %d\n", 
		day_cnt[SATUDAY], day_cnt[SUNDAY], day_cnt[MONDAY],
		day_cnt[TUESDAY], day_cnt[WEDNESDAY], day_cnt[THURSDAY], 
		day_cnt[FRIDAY]);

	exit(0);
}

void day_count(int *day_cnt, int n)
{
	int start_year = START;
	int end_year = START+n;

	int year = start_year;
	int month = START_MONTH;
	int start_time = 13%DAYS_PER_WEEK;

	day_cnt[start_time]++;

	int i = 0;

	for(year = start_year; year < end_year; year++)
	{
		for(month = START_MONTH; month <= MONTH_PER_YEAR; month++)
		{
			if(!(is_leap_year(year) && month == 2)){
				start_time = (start_time + (days_per_month[month] % DAYS_PER_WEEK)) % DAYS_PER_WEEK;
			}

			else{
				start_time = (start_time + ((days_per_month[month] + 1) % DAYS_PER_WEEK)) % DAYS_PER_WEEK;
			}

			day_cnt[start_time]++;
		}
	}

	day_cnt[start_time]--;
}