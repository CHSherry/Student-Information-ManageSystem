/*Student Information ManageSystem*/
#include<stdio.h>   
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
int size;  //������ ȫ�ֱ���

void close(void)
{
    puts("************************************");
    puts("             ��лʹ�ã�");
    puts("************************************");
    exit(0);
}

void about(void)  //�������������¼����ʱ��Ͱ汾  �ɷ�ͼ��
{
    puts("���ƣ�ѧ���ɼ�����ϵͳ");
    puts("�汾��1.0");
    puts("����ϵͳ��Windows");
    puts("����ʱ�䣺2020��8��");
}

void help(void)
{
    
}

/*����������*/

void aver(void)  //ƽ��ֵ����ֵ
{
    double aver=0;
    int max, min;
    int maxnum, minnum;  //��ֵ����
    maxnum = minnum = 1;
    max = studs[0].grade;
    min = studs[0].grade;
    int i;
    for (i = 0; i < size; i++)
    {
        if (studs[i].grade > max)  //�ҵ��ϴ�ֵ���ʼ��maxnum
        {
            max = studs[i].grade;
            maxnum = 1;
        }
        if (studs[i].grade == max)  //��ͬ�����
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
    printf("����ѧ���ɼ���ƽ��ֵΪ %.1f \n��߷�Ϊ %d �֣����� %d ��\n��ͷ�Ϊ %d �֣����� %d ��\n", aver, max, maxnum, min, minnum);
}

void namesort(void)  //����������
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
    puts("���      ����      ѧ��      �༶      �꼶");
    for (i = 0; i < size; i++)
    {
        printf("%d     %s      %s      %s      %d\n", i + 1, studs[i].name, studs[i].number, studs[i].clas, studs[i].grade);
    }
}

void gradesort(void)  //���ɼ�����
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
    puts("���      ����      ѧ��      �༶      �꼶");
    for (i = 0; i < size; i++)
    {
        printf("%d     %s      %s      %s      %d\n", i + 1, studs[i].name, studs[i].number, studs[i].clas, studs[i].grade);
    }
}

void numbersort(void)  //��ѧ������
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
    puts("���      ����      ѧ��      �༶      �꼶");
    for (i = 0; i < size; i++)
    {
        printf("%d     %s      %s      %s      %d\n", i + 1, studs[i].name, studs[i].number, studs[i].clas, studs[i].grade);
    }
}

void nor(void)
{
    int excel, bad;  //����������������������
    excel = bad = 0;
    int i;
    for (i = 0; i < size; i++)
    {
        if (studs[i].grade >= 90)
            excel++;
        if (studs[i].grade < 80)
            bad++;
    }
    int ok = 0;  //�ж��Ƿ���̬
    if (excel * 5 > size)  //��������������20%
    {
        puts("����(>=90��)������������20%");
        ok++;
    }
    if (bad * 10 < size * 3)  //��������������С��30%
    {
        puts("��������(<80��)������������30%");
        ok++;
    }
    if (ok == 0)
    {
        puts("������̬�ֲ�Ҫ��");
    }
}

void sort(void)  //����
{
    puts("��ѡ������ʽ:");
    puts("1.������ƴ������");
    puts("2.���ɼ��Ӹߵ�������");
    puts("3.��ѧ������");
    char choice;
    choice = getchar();
    while (getchar() != '\n')  //�ж������Ƿ�Ϸ�
    {
        puts("�Ƿ����룡  ������1~3֮���һ��");
        while (getchar() != '\n');
        choice = getchar();
    }
    while (1)
    {
        if (choice < '1' || choice > '3')  //�ж������Ƿ�Ϸ�
        {
            puts("��ѡ��1-3֮���һ��");
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
    puts("��ѡ��");
    puts("1.ƽ��ֵ����ֵ");
    puts("2.����");
    puts("3.��̬�ֲ��ж�");
    puts("��Ҫ�˳�������q");  //����
    char choice;
    choice = getchar();
    while (getchar() != '\n')
    {
        puts("�Ƿ����룡  ������1~3��q�е�һ��");
        while (getchar() != '\n');
        choice = getchar();
    }
    while (choice != 'q')  //�ж�����
    {
        if (choice < 1 || choice > 3)  //�ж������Ƿ�Ϸ�
        {
            puts("��ѡ��1-3֮���һ��������q�˳�");
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