//添加联系人函数
#include"head.h"
#include<iostream>
using namespace std;

void Add(Contect* abs)
{
	system("cls");
	cout << "\t\t\t**************欢迎来到添加联系人功能**************" << endl;
	int flag = 1;
	int i = 0;
	Person a;

	while (flag == 1)
	{
		cout << "\t\t\t请输入姓名：";
		cin >> a.name;
		cout << "\t\t\t请输入电话号码：";
		cin >> a.phonenumber;
		cout << "\t\t\t请输入住址：";
		cin >> a.address;
		cout << "\t\t\t请输入分组：";
		cin >> a.relation;
		a.num = i + 1;
		abs->List[i] = a;
		++i;
		++abs->size;
		cout << "\t\t\t添加成功！是否继续添加？ （1 是 0 否）" << endl;
		cout << "\t\t\t请选择【0-1】：";
		cin >> flag;
		if (flag != 0 && flag != 1)
		{
			cout << "\t\t\t输入不合法，请重新选择【0-1】";
			cin >> flag;
		}
		if (i == MAX - 1) {
			cout << "\t\t\t通讯录已满，不能添加联系人";
			break;
		}
	}

	cout << "\n\t\t\t";
	system("pause");
}