//删除联系人函数
#include"head.h"
#include<iostream>
using namespace std;

void Delate(Contect* abs)
{
	system("cls");
	cout << "\t\t\t**************欢迎来到删除联系人功能***************" << endl;
	int sel = 0;
	cout << "\t\t\t-----------------" << endl;
	cout << "\t\t\t1 按编号删除" << endl;
	cout << "\t\t\t2 按姓名删除" << endl;
	cout << "\t\t\t3 返回主菜单" << endl;
	cout << "\t\t\t-----------------" << endl;
	cout << "\t\t\t请选择【1-3】：";
	cin >> sel;
	while (sel < 1 || sel>3)
	{
		cout << "\t\t\t输入不合法，请重新选择【1-3】：";
		cin >> sel;
	}
	if (sel == 1)
	{
		int flag = 0;
		cout << "\t\t\t请输入待删除联系人的编号：";
		cin >> flag;
		if (flag > 0 && flag <= abs->size) {
			cout << "\t\t\t待删除联系人信息如下：" << endl;
			cout << "\t\t\t编号\t" << "姓名\t" << "电话号码\t" << "住址\t\t" << "分组" << endl;
			cout << "\t\t\t" << flag << "\t" << abs->List[flag - 1].name << "\t" << abs->List[flag - 1].phonenumber;
			cout << "\t" << abs->List[flag - 1].address << "\t" << abs->List[flag - 1].relation;
		}
		else {
			cout << "\t\t\t查无此人，无法删除！" << endl;
			cout << "\t\t\t请重新输入：";
			cin >> flag;
		}
		cout << endl;
		cout << "\t\t\t确认删除？（1 是 0 否）" << endl;
		cout << "\t\t\t请选择【0-1】：";
		int sel_2 = 0;
		cin >> sel_2;
		while (sel_2 < 0 || sel_2>1)
		{
			cout << "\t\t\t输入不合法,请重新选择【0-1】：";
			cin >> sel_2;
		}
		if (sel_2 == 0);

		else if (sel_2 == 1)
		{
			for (int i = flag - 1; i < abs->size - 1; i++)
			{
				--abs->List[i + 1].num;
				abs->List[i] = abs->List[i + 1];
			}

			--abs->size;
			cout << "\t\t\t删除成功！";
		}

		cout << "\n\t\t\t";
		system("pause");
		Delate(abs);
	}
	else if (sel == 2)
	{
		Person a;
		int flag = 0;
		cout << "\t\t\t请输入待删除联系人的姓名：";
		cin >> a.name;
		flag = IsExit(abs, a);
		if (flag != 0) {
			cout << "\t\t\t待删除联系人信息如下：" << endl;
			cout << "\t\t\t编号\t" << "姓名\t" << "电话号码\t" << "住址\t\t" << "分组" << endl;
			cout << "\t\t\t" << abs->List[flag - 1].num << "\t" << abs->List[flag - 1].name << "\t" << abs->List[flag - 1].phonenumber;
			cout << "\t" << abs->List[flag - 1].address << "\t" << abs->List[flag - 1].relation;
		}
		else {
			cout << "\t\t\t查无此人，无法删除！" << endl;
			cout << "\t\t\t请重新输入：";
			cin >> a.name;
		}
		cout << endl;
		cout << "\t\t\t确认删除？（1 是 0 否）" << endl;
		cout << "\t\t\t请选择【0-1】：";
		int sel_3;
		cin >> sel_3;
		while (sel_3 < 0 || sel_3>1)
		{
			cout << "\t\t\t输入不合法,请重新选择【0-1】：";
			cin >> sel_3;
		}
		if (sel_3 == 0);

		else if (sel_3 == 1)
		{
			for (int i = flag - 1; i < abs->size - 1; i++)
			{
				--abs->List[i + 1].num;
				abs->List[i] = abs->List[i + 1];
			}

			--abs->size;
			cout << "\t\t\t删除成功！";
		}

		cout << "\n\t\t\t";
		system("pause");
		Delate(abs);
	}
	else if (sel == 3)
		return;
}
