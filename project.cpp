#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>   /*Student Information ManageSystem*/
#include<string.h>
#include<stdlib.h>

struct stu  //�����������С����Ϊsize
{
    int ide;
    char name[20];
    char number[20];  //ѧ��
    char clas[20];
    int grade;
} studs[500];
int size=0;  //������ ȫ�ֱ���
char putout[5][12] = { "序号","姓名","学号","班级","成绩" };   //选择分支
char clases[6][20] = { "Calculus","LinearAlgebra","History","Physics","ComputerScience","Art" };


//------------函数声明
int menu();
void add(void);
void del(void);
void search(void);
void correct(void);
void show(void);
void filter(void);
void analy(void);
void aver(void);
void sort(void);
void nor(void);
void help(void);
void about(void);
void close(void);


//-------------主函数
int main(void)
{

    int choice;
    puts("\t\t\t欢迎使用学生信息管理系统");
    puts("\t\t\n\n------初次使用请首先阅读帮助信息");
    puts("\n---------功能菜单\n");
    puts("         --------------------------    -------------------------");
    puts("          *      0.增加学生信息           1.删除学生信息      * ");
    puts("          *      2.搜索学生信息           3.修改学生信息      * ");
    puts("          *      4.显示学生信息           5.筛选学生信息      * ");
    puts("          *      6.分析学生信息           7.帮助              * ");
    puts("          *      8.关于                   9.退出系统          * ");
    puts("         --------------------------    -------------------------");
    while (1)
    {
        switch (choice = menu())
        {
        case 0:add(); break;
        case 1:del(); break;
        case 2:search(); break;
        case 3:correct(); break;
        case 4:show(); break;
        case 5:filter(); break;
        case 6:analy(); break;
        case 7:help(); break;
        case 8:about(); break;
        case 9:close(); break;
        }
    }


    return 0;
}

//-------------菜单选项
int menu()
{
    char choice;
    int flag = 1;

    printf("\n");
    printf("         请选择菜单编号：");

    //输入合法判断
    while (1)
    {
        choice = getchar();
        flag = 1;
        while (getchar() != '\n')
        {
            flag = 0;
        }
        if (flag == 0)
        {
            printf("您输入的编号有误，请输入正确编号。");
        }
        else
        {
            if (choice >= '0' && choice <= '9')
            {
                return choice - '0';
            }
            else
            {
                printf("您输入的编号有误，请输入正确编号。");
            }
        }
    }
}
//-------------增加学生信息
void add(void)
{
    char index;
    int i = 0, status = 5, size0,status_num = 1,num;
    int flag = 1;
    FILE* fp;
    char addre[100];
    puts("         --------------------------    -------------------------");
    puts("\n         请选择增加学生信息的方式：1.文件输入；2.键盘输入");
    puts("\n按q退出");
    printf("\n         请选择菜单编号：");

    //输入合法判断
    while (1)
    {
        index = getchar();
        flag = 1;
        while (getchar() != '\n')
        {
            flag = 0;
        }
        if (flag == 0)
        {
            printf("您输入的编号有误，请输入正确编号:");
        }
        else
        {
            if (index == '1' || index == '2' || index == 'q')
            {
                break;
            }
            else
            {
                printf("您输入的编号有误，请输入正确编号:");
            }
        }
    }

    //输入处理
    switch (index)
    {
    case'1':
        printf("\n请确保文件中数据格式为:序号 姓名 学号 班级 成绩（各项之间间隔一个空格并且保证每一个数据以回车结束）\n");
        printf("例如：00000000 zhangsan 3190100001 calculus 100\n");
        while (1)
        {
            printf("\n         请输入含有学生信息的文件地址：");
            gets_s(addre);
            fp = fopen(addre,"r");
            if (fp == NULL)
            {
                printf("         没有找到该文件,请输入正确地址。");
            }
            else
            {
                break;
            }
        }
        while (feof(fp) == 0)
        {
            status=fscanf(fp, "%d %s %s %s %d", &studs[size].ide, studs[size].name, studs[size].number, studs[size].clas, &studs[size].grade);
            if (status == 5)
            {
                size++;
            }
            else
            {
                break;
            }
            if (size > 500)
            {
                printf("文件包含过多数据。\n");
            }
        }
        if (status != 5)
        {
            printf("文件中包含错误数据，请重新检查后输入。\n");
        }
        fclose(fp);
        break;
    case'2':
        printf("\n请确保键盘输入的数据格式为:序号 姓名 学号 班级 成绩（各项之间间隔一个空格并且保证每一个数据以回车结束）\n");
        printf("例如：00000000 zhangsan 3190100001 calculus 100\n");
        printf("\n请输入您将要录入的学生信息的个数:\n");
        while (1)
        {
           status_num=scanf("%d",&num);
            flag = 1;
            while (getchar() !='\n')
            {
                flag = 0;
            }
            if (flag == 0)
            {
                printf("您输入的数字有误，请输入正确数字:");
            }
            else
            {
                break;
            }
        }
        size0 = size;
        for (i = 0; i < num; i++)
        {
            //数据合法判断2.0版本
            status=scanf("%d %s %s %s %d", &studs[i+size0].ide, studs[i+size0].name, studs[i+size0].number, studs[i+size0].clas, &studs[i+size0].grade);
            while (getchar() != '\n')
            {
                ;
            }
            if (status == 5)
            {
                size++;
            }
            else
            {
                printf("键入错误数据，请重新输入。\n");
                break;
            }
            if (size > 500)
            {
                printf("文件包含过多数据。\n");
                break;
            }
        }
        break;
    case'q':
        printf("已退出。");
        break;
    }
}
//-------------删除学生信息
void del(void)
{
    int flag = 1;//输入合法判断
    int name_ex = -1, num_ex = -1;//判断姓名、学号是否存在
    int i,num0=0,status_num0=1,flag_num0=1,num0_i;//循环控制变量+删除学生个数
    char name[20], num[20];
    char choice;
    printf("\n\n\n------请选择删除方式:\n\t\b1.按学号删除\n\t\b2.按姓名删除");
    puts("\n按q退出");
    printf("\n         请选择菜单编号：");

    //与用户交互的界面
    //输入合法判断
    while (1)
    {
        choice = getchar();
        flag = 1;
        while (getchar() != '\n')
        {
            flag = 0;
        }
        if (flag == 0)
        {
            printf("您输入的编号有误，请输入正确编号:");
        }
        else
        {
            if (choice == '1' || choice == '2' || choice=='q')
            {
                break;
            }
            else
            {
                printf("您输入的编号有误，请输入正确编号:");
            }
        }
    }

    //处理
    switch (choice)
    {
    case'1':
        printf("请输入您要删除的学生个数：\n");
        while (1)
        {
            status_num0 = scanf("%d", &num0);
            flag_num0 = 1;
            while (getchar() != '\n')
            {
                flag_num0 = 0;
            }
            if (flag_num0 == 0)
            {
                printf("您输入的数字有误，请输入正确数字:");
            }
            else
            {
                if (status_num0 != 1)
                {
                    printf("您输入的数字有误，请输入正确数字:");
                }
                else
                {
                    break;
                }
            }
        }
        if (num0 > size)
        {
            printf("您要删除的数据个数大于存储的数据个数。\n");
        }
        else
        {
            for (num0_i = 0; num0_i < num0; num0_i++)
            {
                printf("\n请输入学生学号：");
                gets_s(num);
                while (getchar() != '\n')
                {
                    ;
                }
                for (i = 0; i < size; i++)
                {
                    if (strcmp(num, studs[i].number) == 0)
                    {
                        num_ex = i;
                        break;
                    }
                }
                if (num_ex == -1)
                {
                    printf("没有找到有关该学号的信息，请重新检查。\n");
                    num0_i--;
                }
                else
                {
                    for (; i < size - 1; i++)
                    {
                        studs[i] = studs[i + 1];
                    }
                    size--;
                }
            }
        }
        break;
    case'2':
        printf("请输入您要删除的学生个数：\n");
        while (1)
        {
            status_num0 = scanf("%d", &num0);
            flag_num0 = 1;
            while (getchar() != '\n')
            {
                flag_num0 = 0;
            }
            if (flag_num0 == 0)
            {
                printf("您输入的数字有误，请输入正确数字:");
            }
            else
            {
                if (status_num0 != 1)
                {
                    printf("您输入的数字有误，请输入正确数字:");
                }
                else
                {
                    break;
                }
            }
        }
        if (num0 > size)
        {
            printf("您要删除的数据个数大于存储的数据个数。\n");
        }
        else
        {
            for (num0_i = 0; num0_i < num0; num0_i++)
            {
                printf("\n请输入学生姓名：");
                gets_s(name);
                while (getchar() != '\n')
                {
                    ;
                }
                for (i = 0; i < size; i++)
                {
                    if (strcmp(name, studs[i].name) == 0)
                    {
                        name_ex = i;
                        break;
                    }
                }
                if (name_ex == -1)
                {
                    printf("没有找到有关该学号的信息，请重新检查。\n");
                    num0_i--;
                }
                else
                {
                    for (; i < size - 1; i++)
                    {
                        studs[i] = studs[i + 1];
                    }
                    size--;
                }
            }
        }
        break;
    case'q':
        printf("quit.\n");
        break;
    }
}
//-------------搜索学生信息
void search(void)
{
    int flag = 1;//输入合法判断
    int name_ex = -1, num_ex = -1;//判断姓名、学号是否存在
    int num0 = 0, status_num0 = 1, flag_num0 = 1, num0_i;
    int i;//循环控制变量
    char name[20], num[20];
    char choice;
    printf("\n\n\n------请选择查找方式:\n\t\b1.按学号查找\n\t\b2.按姓名查找");
    printf("\n         请选择菜单编号：");

    //与用户交互的界面
    //输入合法判断（1个版本）
    while (1)
    {
        choice = getchar();
        flag = 1;
        while (getchar() != '\n')
        {
            flag = 0;
        }
        if (flag == 0)
        {
            printf("您输入的编号有误，请输入正确编号:");
        }
        else
        {
            if (choice >= '1' && choice <= '2')
            {
                break;
            }
            else
            {
                printf("您输入的编号有误，请输入正确编号:");
            }
        }
    }

    printf("请输入您要查找的学生个数：\n");
    while (1)
    {
        status_num0 = scanf("%d", &num0);
        flag_num0 = 1;
        while (getchar() != '\n')
        {
            flag_num0 = 0;
        }
        if (flag_num0 == 0)
        {
            printf("您输入的数字有误，请输入正确数字:");
        }
        else
        {
            if (status_num0 != 1)
            {
                printf("您输入的数字有误，请输入正确数字:");
            }
            else
            {
                break;
            }
        }
    }

    //处理
    switch (choice)
    {
    case'1':
        for (num0_i = 0; num0_i < num0; num0_i++)
        {
            printf("\n请输入学生学号：");
            gets_s(num);
            while (getchar() != '\n')
            {
                ;
            }
            for (i = 0; i < size; i++)
            {
                if (strcmp(num, studs[i].number) == 0)
                {
                    num_ex = i;
                    break;
                }
            }
            if (num_ex == -1)
            {
                printf("没有找到有关该学号的信息，请重新检查。\n");
            }
            else
            {
                printf("%d %s %s %s %d\n", studs[num_ex].ide, studs[num_ex].name, studs[num_ex].number, studs[num_ex].clas, studs[num_ex].grade);
            }
        }
        break;
    case'2':
        for (num0_i = 0; num0_i < num0; num0_i++)
        {
            printf("\n请输入学生姓名：");
            gets_s(name);
            while (getchar() != '\n')
            {
                ;
            }
            for (i = 0; i < size; i++)
            {
                if (strcmp(name, studs[i].name) == 0)
                {
                    name_ex = i;
                    break;
                }
            }
            if (name_ex == -1)
            {
                printf("没有找到有关该学号的信息，请重新检查。\n");
            }
            else
            {
                printf("%d %s %s %s %d\n", studs[num_ex].ide, studs[num_ex].name, studs[num_ex].number, studs[num_ex].clas, studs[num_ex].grade);
            }
        }
        break;
    }
}
//-------------修改学生信息
void correct(void)
{
    struct stu stud;
    int grade, str_ex=-1;
    int i, j;
    int flag, status,num0, status_num0, flag_num0; 
    char str[20];

    if (size == 0)
    {
        printf("         还没有录入学生信息，请重新录入。\n");
    }
    else
    {
        printf("请输入您要修改的学生信息个数：\n");
        while (1)
        {
            status_num0 = scanf("%d", &num0);
            flag_num0 = 1;
            while (getchar() != '\n')
            {
                flag_num0 = 0;
            }
            if (flag_num0 == 0)
            {
                printf("您输入的数字有误，请输入正确数字:");
            }
            else
            {
                if (status_num0 != 1)
                {
                    printf("您输入的数字有误，请输入正确数字:");
                }
                else
                {
                    break;
                }
            }
        }
        for (i = 0; i < num0; i++)
        {
            printf("\n\n\n------请输入需要修改的学生姓名或者学号：");
            gets_s(str);
            for (j = 0; j < size; j++)
            {
                if (strcmp(str,studs[j].name) == 0 || strcmp(str,studs[j].number) == 0)
                {
                    str_ex = j;
                    break;
                }
            }
            if (str_ex == -1)
            {
                i--;
                printf("没有找到有关该姓名或学号的信息，请重新检查并再次输入。\n");
            }
            else
            {
                printf("%s    %s     %s     %s     %s", putout[0], putout[1], putout[2], putout[3], putout[4]);
                printf("%08d %s %s %s %d\n", studs[str_ex].ide, studs[str_ex].name, studs[str_ex].number, studs[str_ex].clas, studs[str_ex].grade);
                printf("\n请输入该学生的真实信息，请确保数据格式依次为序号 姓名 学号 班级 成绩（各项之间间隔一个空格并且保证每一个数据以回车结束）\n");
                printf("例如：00000000 zhangsan 3190100001 calculus 100\n");
                while (1)
                {
                    status=scanf("%d %s %s %s %d", &stud.ide, stud.name, stud.number, stud.clas, &stud.grade);
                    while (getchar() != '\n')
                    {
                        ;
                    }
                    if (status != 5)
                    {
                        printf("输入格式错误请重新输入:\n");
                    }
                    else
                    {
                        break;
                    }
                }
                studs[str_ex] = stud;
            }
        }
    }
}
//-------------显示学生信息
void show(void)
{
    int i,flag;
    char choice;
    if (size == 0)
    {
        printf("         还没有录入学生信息，请重新录入。\n");
    }
    else
    {
        printf("\n\n\n------请选择显示方式:\n\t\b 1.按姓名排序\n\t\b2.按学号排序\n\t\b3.按成绩排序\n\t\b按q退出\n\n\t\b请输入您的选择:");

        while (1)
        {
            choice = getchar();
            flag = 1;
            while (getchar() != '\n')
            {
                flag = 0;
            }
            if (flag == 0)
            {
                printf("您输入的编号有误，请输入正确编号:");
            }
            else
            {
                if (choice == '1' || choice == '2' || choice == '3' || choice == 'q')
                {
                    break;
                }
                else
                {
                    printf("您输入的编号有误，请输入正确编号:");
                }
            }
        }

        switch (choice)
        {
        case'1':
            namesort();
            printf("\n         一共有%d名学生\n", size);
            for (i = 0; i < size; i++)
            {
                printf("%d %s %s %s %d", &studs[i].ide, studs[i].name, studs[i].number, studs[i].clas, &studs[i].grade);
            }
            break;
        case'2':
            numbersort();
            printf("\n         一共有%d名学生\n", size);
            for (i = 0; i < size; i++)
            {
                printf("%d %s %s %s %d", &studs[i].ide, studs[i].name, studs[i].number, studs[i].clas, &studs[i].grade);
            }
            break;
        case'3':
            gradesort();
            printf("\n         一共有%d名学生\n", size);
            for (i = 0; i < size; i++)
            {
                printf("%d %s %s %s %d", &studs[i].ide, studs[i].name, studs[i].number, studs[i].clas, &studs[i].grade);
            }
            break;
        case'q':break;
        }

    }


}
//-------------筛选学生信息
void filter(void)
{
    char choice,choice2;
    int i,flag,size0;
    printf("\n\n\n------请选择筛选方式:\n\t\b1.按成绩筛选\n\t\b2.按班级筛选\n\t\bq.退出");
    printf("\n         请选择菜单编号：");

    while (1)
    {
        choice = getchar();
        flag = 1;
        while (getchar() != '\n')
        {
            flag = 0;
        }
        if (flag == 0)
        {
            printf("您输入的编号有误，请输入正确编号:");
        }
        else
        {
            if (choice == '1' || choice == '2' ||  choice == 'q')
            {
                break;
            }
            else
            {
                printf("您输入的编号有误，请输入正确编号:");
            }
        }
    }

    switch(choice)
    {
    case'1':
        if (size == 0)
        {
            printf("         还没有录入学生信息，请重新录入。\n");
        }
        else
        {
            printf("\n\n\n------请选择筛选方式:\n\t\b1.筛选成绩前20%\n\t\b2.筛选成绩后20%\n\t\bq.退出");
            printf("\n         请选择菜单编号：");
            while (1)
            {
                choice2 = getchar();
                flag = 1;
                while (getchar() != '\n')
                {
                    flag = 0;
                }
                if (flag == 0)
                {
                    printf("您输入的编号有误，请输入正确编号:");
                }
                else
                {
                    if (choice2 == '1' || choice2 == '2' || choice2 == 'q')
                    {
                        break;
                    }
                    else
                    {
                        printf("您输入的编号有误，请输入正确编号:");
                    }
                }
            }
            switch(choice2)
            { 
            case'1':
                gradesort();
                size0 = size / 5;
                for (i = 0; i < size0; i++)
                {
                    printf("%08d %s %s %s %d\n", studs[i].ide, studs[i].name, studs[i].number, studs[i].clas, studs[i].grade);

                }
                while (studs[i].grade == studs[size0 - 1].grade)
                {
                    printf("%08d %s %s %s %d\n", studs[i].ide, studs[i].name, studs[i].number, studs[i].clas, studs[i].grade);
                    i++;
                }
                break;
            case'2':
                gradesort();
                size0 = size / 5;
                for (i = size; i >size-size0; i--)
                {
                    printf("%08d %s %s %s %d\n", studs[i].ide, studs[i].name, studs[i].number, studs[i].clas, studs[i].grade);

                }
                while (studs[i].grade == studs[size0 - 1].grade)
                {
                    printf("%08d %s %s %s %d\n", studs[i].ide, studs[i].name, studs[i].number, studs[i].clas, studs[i].grade);
                    i--;
                }
                break;
            case'q':
                break;
            }
        }
        break;
    case'2':
        if (size == 0)
        {
            printf("         还没有录入学生信息，请重新录入。\n");
        }
        else
        {
            printf("\n\n\n------请选择筛选班级:\n\t\b1.Calculus\n\t\b2.LinearAlgebra\n\t\bq.退出");
            printf("\n         请选择菜单编号：");
            while (1)
            {
                choice2 = getchar();
                flag = 1;
                while (getchar() != '\n')
                {
                    flag = 0;
                }
                if (flag == 0)
                {
                    printf("您输入的编号有误，请输入正确编号:");
                }
                else
                {
                    if (choice2 == '1' || choice2 == '2' || choice2 == 'q')
                    {
                        break;
                    }
                    else
                    {
                        printf("您输入的编号有误，请输入正确编号:");
                    }
                }
            }
            switch (choice2)
            {
            case'1':
                for (i = 0; i < size; i++)
                {
                    if (studs[i].clas == clases[choice-'1'])
                    {
                        printf("%08d %s %s %s %d\n", studs[i].ide, studs[i].name, studs[i].number, studs[i].clas, studs[i].grade);
                    }
                }
                break;
            case'2':
                for (i = 0; i < size; i++)
                {
                    if (studs[i].clas == clases[choice - '1'])
                    {
                        printf("%08d %s %s %s %d\n", studs[i].ide, studs[i].name, studs[i].number, studs[i].clas, studs[i].grade);
                    }
                }
                break;
            case'q':
                break;
            }
        }
        break;
    case'q':
        break;
    }
}
//-------------平均值
void aver(void)  //平均值和最值
{
    double aver = 0;
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
//-------------按姓名排序
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
//-------------按成绩排序
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
//-------------按学号排序
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
//-------------排序
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
//-------------正态分布判定
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
//-------------分析学生信息
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
//-------------关闭
void close(void)
{
    puts("************************************");
    puts("             感谢使用！");
    puts("************************************");
    exit(0);
}
//-------------关于
void about(void)  //后续若更新则记录更新时间和版本  可放图标
{
    puts("名称：学生成绩管理系统");
    puts("版本：1.0");
    puts("适用系统：Windows");
    puts("更新时间：2020年8月");
}
//-------------帮助
void help(void)
{
    ;
}