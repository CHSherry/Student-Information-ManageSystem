#include<stdio.h>   /*Student Information ManageSystem*/
#include<string.h>

struct stu  //�����������С����Ϊsize
{
    int ide;
    char name[20];
    char number[20];  //ѧ��
    char clas[20];
    int grade;
} studs[500];
int size;  //������ ȫ�ֱ���

/*����������*/
void analy(void)
{
    puts("��ѡ��");
    puts("1.ƽ��ֵ����ֵ");
    puts("2.����");
    puts("3.��̬�ֲ��ж�");
    puts("��Ҫ�˳�������q");  //����
    char choice;
    scanf("%c", &choice);
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

void aver(void)  //ƽ��ֵ����ֵ
{
    double aver;
    int max, min;
    int maxnum, minnum;  //��ֵ����
    maxnum = minnum = 1;
    max = studs[0].grade;
    min = studs[0].grade;
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

void sort(void)  //����    ����
{
    puts("��ѡ������ʽ:");
    puts("1.������ƴ������");
    puts("2.���ɼ��Ӹߵ�������");
    puts("3.��ѧ������");
    int choice;
    scanf("%d", &choice);
    while (1)
    {
        if (choice < 1 || choice > 3)  //�ж������Ƿ�Ϸ�
        {
            puts("��ѡ��1-3֮���һ��������q�˳�");
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
int main(void)
{


    return 0;
}