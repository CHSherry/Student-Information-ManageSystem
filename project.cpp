/*Student Information ManageSystem*/
#include<stdio.h>   
#include<string.h>
#include<stdlib.h>

struct stu  //主程序数组大小变量为size
{
    int ide;
    char name[20];
    char number[20];  //学号
    char clas[20];
    int grade;
} studs[500];
int size;  //总人数 全局变量

void close(void)
{
    puts("************************************");
    puts("             感谢使用！");
    puts("************************************");
    exit(0);
}

void about(void)  //后续若更新则记录更新时间和版本  可放图标
{
    puts("名称：学生成绩管理系统");
    puts("版本：1.0");
    puts("适用系统：Windows");
    puts("更新时间：2020年8月");
}

void help(void)
{
    
}

/*分析函数组*/

void aver(void)  //平均值和最值
{
    double aver=0;
    int max, min;
    int maxnum, minnum;  //最值人数
    maxnum = minnum = 1;
    max = studs[0].grade;
    min = studs[0].grade;
    int i;
    for (i = 0; i < size; i++)
    {
        if (studs[i].grade > max)  //找到较大值则初始化maxnum
        {
            max = studs[i].grade;
            maxnum = 1;
        }
        if (studs[i].grade == max)  //相同则计数
        {
            maxnum++;
        }
        if (studs[i].grade < min)
        {
            min = studs[i].grade;
            minnum = 1;
        }
        if (studs[i].grade == min)
        {
            minnum++;
        }
        aver += studs[i].grade;
    }
    aver /= size;
    printf("所有学生成绩的平均值为 %.1f \n最高分为 %d 分，共有 %d 人\n最低分为 %d 分，共有 %d 人\n", aver, max, maxnum, min, minnum);
}

void namesort(void)  //按姓名排序
{
    int i, j;
    struct stu temp;
    for (i = 0; i < size; i++)
    {
        for (j = i; j < size - 1; j++)
        {
            if (strcmp(studs[j].name, studs[j + 1].name) > 0)
            {
                temp = studs[j];
                studs[j] = studs[j + 1];
                studs[j + 1] = temp;
            }
        }
    }
    puts("序号      姓名      学号      班级      年级");
    for (i = 0; i < size; i++)
    {
        printf("%d     %s      %s      %s      %d\n", i + 1, studs[i].name, studs[i].number, studs[i].clas, studs[i].grade);
    }
}

void gradesort(void)  //按成绩排序
{
    int i, j;
    struct stu temp;
    for (i = 0; i < size; i++)
    {
        for (j = i; j < size - 1; j++)
        {
            if (studs[j].grade < studs[j + 1].grade)
            {
                temp = studs[j];
                studs[j] = studs[j + 1];
                studs[j + 1] = temp;
            }
        }
    }
    puts("序号      姓名      学号      班级      年级");
    for (i = 0; i < size; i++)
    {
        printf("%d     %s      %s      %s      %d\n", i + 1, studs[i].name, studs[i].number, studs[i].clas, studs[i].grade);
    }
}

void numbersort(void)  //按学号排序
{
    int i, j;
    struct stu temp;
    for (i = 0; i < size; i++)
    {
        for (j = i; j < size - 1; j++)
        {
            if (strcmp(studs[j].number, studs[j + 1].number) > 0)
            {
                temp = studs[j];
                studs[j] = studs[j + 1];
                studs[j + 1] = temp;
            }
        }
    }
    puts("序号      姓名      学号      班级      年级");
    for (i = 0; i < size; i++)
    {
        printf("%d     %s      %s      %s      %d\n", i + 1, studs[i].name, studs[i].number, studs[i].clas, studs[i].grade);
    }
}

void nor(void)
{
    int excel, bad;  //优秀人数和良好以下人数
    excel = bad = 0;
    int i;
    for (i = 0; i < size; i++)
    {
        if (studs[i].grade >= 90)
            excel++;
        if (studs[i].grade < 80)
            bad++;
    }
    int ok = 0;  //判断是否正态
    if (excel * 5 > size)  //优秀人数不超过20%
    {
        puts("优秀(>=90分)人数比例超过20%");
        ok++;
    }
    if (bad * 10 < size * 3)  //良好以下人数不小于30%
    {
        puts("良好以下(<80分)人数比例低于30%");
        ok++;
    }
    if (ok == 0)
    {
        puts("符合正态分布要求");
    }
}

void sort(void)  //排序
{
    puts("请选择排序方式:");
    puts("1.按姓名拼音排序");
    puts("2.按成绩从高到低排序");
    puts("3.按学号排序");
    char choice;
    choice = getchar();
    while (getchar() != '\n')  //判断输入是否合法
    {
        puts("非法输入！  请输入1~3之间的一个");
        while (getchar() != '\n');
        choice = getchar();
    }
    while (1)
    {
        if (choice < '1' || choice > '3')  //判定输入是否合法
        {
            puts("请选择1-3之间的一个");
            continue;
        }
        switch (choice)
        {
        case '1': namesort(); break;
        case '2': gradesort(); break;
        case '3': numbersort(); break;
        }
        break;
    }
}

void analy(void)
{
    puts("请选择：");
    puts("1.平均值和最值");
    puts("2.排序");
    puts("3.正态分布判定");
    puts("若要退出请输入q");  //返回
    char choice;
    choice = getchar();
    while (getchar() != '\n')
    {
        puts("非法输入！  请输入1~3或q中的一个");
        while (getchar() != '\n');
        choice = getchar();
    }
    while (choice != 'q')  //判定返回
    {
        if (choice < 1 || choice > 3)  //判定输入是否合法
        {
            puts("请选择1-3之间的一个或输入q退出");
            continue;
        }
        switch (choice)
        {
        case '1': aver(); break;
        case '2': sort(); break;
        case '3': nor(); break;
        }
        break;
    }
}

int main(void)
{
    close();
    return 0;
}