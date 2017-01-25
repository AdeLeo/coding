/*
定义字符串的左旋转操作：把字符串前面的若干个字符移动到字符串的尾部，
如把字符串abcdef左旋转2位得到字符串cdefab。
请实现字符串左旋转的函数，
要求：
	对长度为n的字符串操作的时间复杂度为O(n)，
	空间复杂度为O(1)。
*/

/*
Way1:
	暴力移位法，每次移动一位，移动m位。
*/
#include <stdio.h>
#include <string.h>

#define ARR_SIZE(arr) (sizeof(arr)/sizeof(arr[0]))

void leftshiftone(char *s, int n);
void leftshift(char *s, int n, int m);

int main(void)
{
	char str[] = "123456789";
	const char s[] = "123456789";
	
	int i = 2;
	
	for(i = 0; i < 30; i++)
	{
		leftshift(str, strlen(str), i);
		printf("After shift %d bit:%s\n", i, str);
		strcpy(str, s);
	}
}

void leftshiftone(char *s, int n)
{
	char tmp = s[0];
	int i = 0;
	for(i = 1; i < n; i++)
	{
		s[i-1] = s[i];
	}
	s[n - 1] = tmp;
	//printf("\n\n[Debug]%d %s\n\n",n, s);
}
/*
void leftshift(char *s, int n, int m)
{
	int i = 0;
	m %= n;

	for(i = 0; i < m; i++)
	{
		leftshiftone(s, n);
	}
}*/

void leftshift(char *s, int n, int m)
{
	m %= n;
	int p1 = 0;
	int p2 = m;
	int t = 0;

	while(p2+m-1 <= n)
	{
		t = s[p2];
		s[p2] = s[p1];
		s[p1] = t;
		p1++;
		p2++;
	}

	if(n - p2 > 0)
	{
		char tmp[n - p2];
		strcpy(tmp, s+p2);
		//123456789
		//printf("[Debug]:%s m:%d p1:%d p2:%d\n", tmp, m, p1, p2);
		while(p2 != p1)
		{
			s[p2] = s[p2-1];
			p2--;
		}
		
		n = 0;
		while(tmp[n] != '\0')
			s[p1++] = tmp[n++];
	}
}