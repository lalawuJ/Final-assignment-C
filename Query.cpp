//查询联系人函数
#include"head.h"
#include<iostream>
using namespace std;

void Query(Contect* abs)
{
	system("cls");
	cout << "\t\t\t**************欢迎来到查询联系人功能***************" << endl;
	Person a;
	int sel;
	cout << "\t\t\t-----------------" << endl;
	cout << "\t\t\t1 按编号查询" << endl;
	cout << "\t\t\t2 按姓名查询" << endl;
	cout << "\t\t\t3 返回主菜单" << endl;
	cout << "\t\t\t-----------------" << endl;
	cout << "\t\t\t请选择【1-3】：";
	cin >> sel;
	while (sel < 1 || sel>3)
	{
		cout << "\t\t\t输入不合法,请重新选择【1-3】：";
		cin >> sel;
	}
	if (sel == 1)
	{
		int flag = 0;
		cout << "\t\t\t请输入待查询联系人的编号：";
		cin >> flag;
		if (flag > 0 && flag <= abs->size) {
			cout << "\t\t\t待查询联系人信息如下：" << endl;
			cout << "\t\t\t编号\t" << "姓名\t" << "联系电话\t" << "住址\t\t" << "分组" << endl;
			cout << "\t\t\t" << flag << "\t" << abs->List[flag - 1].name << "\t" << abs->List[flag - 1].phonenumber;
			cout << "\t" << abs->List[flag - 1].address << "\t" << abs->List[flag - 1].relation << endl;
		}
		else if (flag == 0)
			cout << "\t\t\t查无此人！" << endl;

		cout << "\n\t\t\t";
		system("pause");
		Query(abs);
	}
	else if (sel == 2)
	{
		int flag = 0;
		cout << "\t\t\t请输入待查询联系人的姓名：";
		cin >> a.name;
		flag = IsExit(abs, a);
		if (flag != 0) {
			cout << "\t\t\t待查询联系人信息如下：" << endl;
			cout << "\t\t\t编号\t" << "姓名\t" << "电话号码\t" << "住址\t\t" << "分组" << endl;
			cout << "\t\t\t" <<abs->List[flag-1].num<<"\t"<< abs->List[flag - 1].name << "\t" << abs->List[flag - 1].phonenumber;
			cout << "\t" << abs->List[flag - 1].address << "\t" << abs->List[flag - 1].relation << endl;
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