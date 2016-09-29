#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
    问题描述：
        老师录入成绩，直到遇到条件查询语句：
        录入格式：
        LOG GRADE:NAME=XIAOMING,MATH=100,LANG=80
        查询格式：
        LST GRADE:NAME=XIAOMING

    样例输入：
        LOG GRADE:NAME=XIAOMING,MATH=100,LANG=70
        LOG GRADE:NAME=XIAOBAI,MATH=90,LANG=90
        LOG GRADE:NAME=XIAOHONG,LANG=70,MATH=80
        LST GRADE:NAME=XIAOHONG

    样例输出：
        (姓名    数学成绩  语文成绩 总排名)
        XIAOHONG 100       70       3
 */

typedef struct stu
{
    char *name;
    int math;
    int lang;
    struct stu *next;
}stu_t;

stu_t head;

static void head_init(void)
{
    bzero(head, sizeof(head));
    head.next = NULL;
}

void insertLog(const char *str)
{
    stu_t *p = (stu_t *)malloc(sizeof(stu_t));
    p->next = NULL;

}

void printLST(char *str)
{

}

int main()
{
    char buffer[1024] = "";
    head_init();

    while(scanf("%s", buffer) != EOF)
    {
        if(0 == strcmp(buffer, "LOG GRADE:"))
        {
            insertLog(buffer);
        }

        else if(0 == strcmp(buffer, "LST GRADE:"))
        {
            printLST(buffer);
            deleteLog();
        }

        bzero(buffer, sizeof(buffer));
    }
}
