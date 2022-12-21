//修改联系人函数
#include"head.h"
#include<iostream>
using namespace std;

void Modify(Contect* abs)
{
	system("cls");
	cout << "\t\t\t**************欢迎来到修改联系人功能***************" << endl;
	int sel = 0;
	cout << "\t\t\t-----------------" << endl;
	cout << "\t\t\t1 按编号修改" << endl;
	cout << "\t\t\t2 按姓名修改" << endl;
	cout << "\t\t\t3 返回主菜单" << endl;
	cout << "\t\t\t-----------------" << endl;
	cout << "\t\t\t请选择【1-3】：";
	cin >> sel;
	while (sel < 1 || sel>3)
	{
		cout << "\t\t\t输入不合法,请重新输入【1-3】：";
		cin >> sel;
	}
	if (sel == 1)
	{
		int flag = 0;
		cout << "\t\t\t请输入待修改的联系人的编号：";
		cin >> flag;
		if (flag > 0 && flag <= abs->size) {
			cout << "\t\t\t待查询联系人信息如下：" << endl;
			cout << "\t\t\t编号\t" << "姓名\t" << "联系电话\t" << "地址\t\t" << "分组" << endl;
			cout << "\t\t\t" << flag << "\t" << abs->List[flag - 1].name << "\t" << abs->List[flag - 1].phonenumber;
			cout << "\t" << abs->List[flag - 1].address << "\t" << abs->List[flag - 1].relation << endl;
			Person a;
			cout << "\t\t\t输入修改后的联系人信息：" << endl;
			cout << "\t\t\t输入姓名：";
			cin >> a.name;
			cout << "\t\t\t输入电话：";
			cin >> a.phonenumber;
			cout << "\t\t\t输入地址：";
			cin >> a.address;
			cout << "\t\t\t输入分组：";
			cin >> a.relation;
			a.num = flag;
			cout << "\t\t\t确认修改？（1 是 0 否）" << endl;
			cout << "\t\t\t请选择【0-1】：";
			cin >> sel;
			while (sel < 0 || sel>1)
			{
				cout << "\t\t\t输入不合法,请重新选择【0-1】：";
				cin >> sel;
			}
			if (sel == 0);

			else if (sel == 1)
				abs->List[flag - 1] = a;
		}
		else if (flag == 0)
			cout << "\t\t\t查无此人，无法修改！" << endl;

		cout << "\n\t\t\t";
		system("pause");
		Query(abs);
	}
	else if (sel == 2)
	{
		int flag = 0;
		Person a;
		cout << "\t\t\t请输入待查询联系人的姓名：";
		cin >> a.name;
		flag = IsExit(abs, a);
		if (flag != 0) {
			cout << "\t\t\t待查询联系人信息如下：" << endl;
			cout << "\t\t\t编号\t" << "姓名\t" << "电话号码\t" << "住址\t\t" << "分组" << endl;
			cout << "\t\t\t" << flag << "\t" << abs->List[flag - 1].name << "\t" << abs->List[flag - 1].phonenumber;
			cout << "\t" << abs->List[flag - 1].address << "\t" << abs->List[flag - 1].relation << endl;
			cout << "\t\t\t输入修改后的联系人信息：" << endl;
			cout << "\t\t\t输入姓名：";
			cin >> a.name;
			cout << "\t\t\t输入电话：";
			cin >> a.phonenumber;
			cout << "\t\t\t输入地址：";
			cin >> a.address;
			cout << "\t\t\t输入分组：";
			cin >> a.relation;
			a.num = flag;
			cout << "\t\t\t确认修改？（1 是 0 否）" << endl;
			cout << "\t\t\t请选择【0-1】：";
			cin >> sel;
			while (sel < 0 || sel>1)
			{
				cout << "\t\t\t输入不合法,请重新选择【0-1】：";
				cin >> sel;
			}
			if (sel == 0);

			else if (sel == 1)
				abs->List[flag - 1] = a;
		}
		else
			cout << "\t\t\t查无此人！" << endl;

		cout << "\n\t\t\t";
		system("pause");
		Query(abs);
	}
	else if (sel == 3)
		return;
}