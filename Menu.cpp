//菜单函数
#include"head.h"
#include<iostream>
using namespace std;

void Menu(Contect* abs)
{
	int sel;
	system("cls");
	cout << "\t\t\t***********欢迎来到通讯录管理系统***********" << endl;
	cout << "\t\t\t你可以进行以下操作:" << endl;
	cout << "\t\t\t|------------------------------------------|" << endl;
	cout << "\t\t\t|             1   添加联系人               |" << endl;
	cout << "\t\t\t|------------------------------------------|" << endl;
	cout << "\t\t\t|             2   删除联系人               |" << endl;
	cout << "\t\t\t|------------------------------------------|" << endl;
	cout << "\t\t\t|             3   修改联系人               |" << endl;
	cout << "\t\t\t|------------------------------------------|" << endl;
	cout << "\t\t\t|             4   查询联系人               |" << endl;
	cout << "\t\t\t|------------------------------------------|" << endl;
	cout << "\t\t\t|             5   通讯录显示               |" << endl;
	cout << "\t\t\t|------------------------------------------|" << endl;
	cout << "\t\t\t|             6   通讯录清空               |" << endl;
	cout << "\t\t\t|------------------------------------------|" << endl;
	cout << "\t\t\t|             0   退出                     |" << endl;
	cout << "\t\t\t|------------------------------------------|" << endl;
	cout << "\t\t\t请选择【0-6】：";
	cin >> sel;
	while (sel < 0 || sel>6) {
		cout << "\t\t\t输入不合法，请重新选择【0-6】";
		cin >> sel;
	}
	switch (sel)
	{
	case 1:
		Add(abs);
		Menu(abs);
		break;
	case 2:
		Delate(abs);
		Menu(abs);
		break;
	case 3:
		Modify(abs);
		Menu(abs);
		break;
	case 4:
		Query(abs);
		Menu(abs);
		break;
	case 5:
		Print(abs);
		Menu(abs);
	case 6:
		Clear(abs);
		Menu(abs);
	case 0:
		exit(0);
	default:
		Menu(abs);
	}
}