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

//菜单
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
	while (sel<0||sel>6){
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

//添加联系人函数
void Add(Contect* abs)
{
	system("cls");
	cout << "\t\t\t**************欢迎来到添加联系人功能**************" << endl;
	int flag=1;
	int i = 0;
	Person a;
	
	while (flag==1)
	{
		cout << "\t\t\t请输入姓名：";
		cin >> a.name;
		cout << "\t\t\t请输入电话号码：" ;
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

//确定联系人是否存在且返回编号
int IsExit(Contect* abs,Person a)
{
	int b=0;
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

//删除联系人函数
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
		cout << "\t\t\t请输入待删除联系人的编号：" ;
		cin >> flag;
		if (flag > 0 && flag <= abs->size) {
			cout << "\t\t\t待删除联系人信息如下：" << endl;
			cout << "\t\t\t编号\t" << "姓名\t" << "电话号码\t" << "住址\t" << "分组" << endl;
			cout << "\t\t\t" << flag << "\t" << abs->List[flag - 1].name << "\t" << abs->List[flag - 1].phonenumber;
		    cout<< "\t" << abs->List[flag - 1].address << "\t" << abs->List[flag - 1].relation;
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
			for (int i = flag - 1; i < abs->size-1; i++)
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
		cout << "\t\t\t请输入待删除联系人的姓名：" ;
		cin >> a.name;
		flag = IsExit(abs, a);
		if (flag != 0) {
			cout << "\t\t\t待删除联系人信息如下：" << endl;
			cout << "\t\t\t编号\t" << "姓名\t" << "电话号码\t" << "住址\t" << "分组" << endl;
			cout << "\t\t\t" <<abs->List[flag-1].num<<"\t"<< abs->List[flag - 1].name << "\t" << abs->List[flag - 1].phonenumber;
		    cout<< "\t" << abs->List[flag - 1].address << "\t" << abs->List[flag - 1].relation;
		}
		else {
			cout << "\t\t\t查无此人，无法删除！" << endl;
			cout << "\t\t\t请重新输入：";
			cin >> a.name;
		}
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

//修改联系人函数
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
			cout << "\t\t\t编号\t" << "姓名\t" << "联系电话\t" << "家庭地址\t" << "分组" << endl;
			cout << "\t\t\t" << flag << "\t" << abs->List[flag - 1].name << "\t" << abs->List[flag - 1].phonenumber << "\t" << abs->List[flag - 1].address << "\t" << abs->List[flag - 1].relation << endl;
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
			cout << "\t\t\t编号\t" << "姓名\t" << "电话号码\t" << "住址\t" << "分组" << endl;
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

//查询联系人函数
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
			cout << "\t\t\t编号\t" << "姓名\t" << "联系电话\t" << "家庭地址\t" << "分组" << endl;
			cout << "\t\t\t" << flag << "\t" << abs->List[flag - 1].name << "\t" << abs->List[flag - 1].phonenumber;
			cout<< "\t" << abs->List[flag - 1].address << "\t" << abs->List[flag - 1].relation << endl;
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
			cout << "\t\t\t编号\t" << "姓名\t" << "电话号码\t" << "住址\t" << "分组" << endl;
			cout << "\t\t\t" << abs->List[flag - 1].name << "\t" << abs->List[flag - 1].phonenumber;
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
