#include<iostream>
#include"head.h"

#define _CRT_SECURE_NO_WARNINGS

int main()
{
    system("color 70");
	Contect MailList;
	Menu(&MailList);
	return 0;
}

//确定联系人是否存在且返回编号
int IsExit(Contect* abs, Person a)
{
	int b = 0;
	for (int i = 0; i < abs->size; i++)
	{
		if (abs->List[i].name == a.name)
			b = i + 1;
		else
			b = 0;
	}
	if (b != 0)
		return b;
	else
		return 0;
}

//显示通讯录函数
void Print(Contect* abs)
{
	system("cls");
	cout << "\t\t\t***************欢迎来到通讯录显示功能***************" << endl;
	int i = 0;
	if (abs->size == 0)
		cout << "\t\t\t通讯录为空，无法显示！" << endl;
	else if (abs->size != 0)
	{
		cout << "\t\t\t-----------------------------------------------------" << endl;
		cout << "\t\t\t序号\t" << "姓名\t" << "联系电话\t" << "家庭地址\t" << "分组" << endl;
		cout << "\t\t\t-----------------------------------------------------" << endl;
		for (i; i < abs->size; i++)
		{
			cout << "\t\t\t" <<abs->List[i].num<<"\t"<< abs->List[i].name << "\t" << abs->List[i].phonenumber;
			cout << "\t" << abs->List[i].address << "\t" << abs->List[i].relation << endl;
		}
		cout << "\t\t\t-----------------------------------------------------" << endl;
	}
	
	cout << "\n\t\t\t";
	system("pause");
}

//清空通讯录函数
void Clear(Contect* abs)
{
	int sel = 0;
	system("cls");
	cout << "\t\t\t**************欢迎来到通讯录清空功能*************" << endl;
	if (abs->size == 0)
		cout << "\t\t\t通讯录为空，无法清空！" << endl;
	else if (abs->size != 0)
	{
		cout << "\t\t\t-----------------" << endl;
		cout << "\t\t\t1 确认清空通讯录" << endl;
		cout << "\t\t\t2 返回主菜单" << endl;
		cout << "\t\t\t-----------------" << endl;
		cout << "\t\t\t请慎重选择【1-2】：";
		cin >> sel;
		while (sel < 1 || sel>2)
		{
			cout << "\t\t\t输入不合法,请重新输入【1-2】：";
			cin >> sel;
		}
		if (sel == 1)
		{
			for (int i = 0; i < abs->size; i++)
			{
				abs->List[i] = { 0 };
			}
			abs->size = 0;
		}
		else if (sel == 2)
			return;
	}
	cout << "\n\t\t\t";
	system("pause");
}
