/*
ID: 13588021
LANG: C
TASK: crypt1
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int is_right(int target, int number[], int len);

int main()
{
	FILE *fin, *fout;
	fin = fopen("crypt1.in", "r");
	fout = fopen("crypt1.out", "w");
	assert(fin != NULL && fout != NULL);

	int cnt_number = 0;
	fscanf(fin, "%d\n", &cnt_number);
	int number[cnt_number];

	int a, b, c, d, e;
	int t = 0;
	int i = 0;
	int cnt = 0;
	int tmp1, tmp2;

	for(i = 0; i < cnt_number; i++)
	{
		fscanf(fin, "%d", &number[i]);
	}

	for(a = 0; a < cnt_number; a++)
	{
		if(number[a] == 0)
			continue;

		for(b = 0; b < cnt_number; b++)
		{
			for(c = 0; c < cnt_number; c++)
			{
				t = number[a]*100 + number[b]*10 + number[c];
				for(d = 0; d < cnt_number; d++)
				{
					if(number[d] == 0 || (tmp1=number[d]*t) >= 1000)
						continue;

					for(e = 0; e < cnt_number; e++)
					{
						if((tmp2=number[e]*t) >= 1000)
							continue;

						if(is_right(tmp1, number, cnt_number) && is_right(tmp2, number, cnt_number) && is_right(tmp1*10+tmp2, number, cnt_number))
						{
							// printf("%d\n", t * (number[d]*10 + number[e]));
							cnt++;
						}
					}
				}
			}
		}
	}

	// printf("%d\n", cnt);
	fprintf(fout, "%d\n", cnt);

	fclose(fin);
	fclose(fout);

	return 0;
}

int is_right(int target, int number[], int len)
{
	assert(number != NULL && len > 0);

	int tmp;
	int i = 0;
	int j = 0;
	
	while(target != 0)
	{
		j++;
		tmp = target % 10;
		for(i = 0; i < len; i++)
		{
			if(tmp == number[i])
				break;
		}

		if(i == len || j > 4)
			return 0;

		target /= 10;
	}

	return 1;
}