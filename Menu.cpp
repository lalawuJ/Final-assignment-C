//�˵�����
#include"head.h"
#include<iostream>
using namespace std;

void Menu(Contect* abs)
{
	int sel;
	system("cls");
	cout << "\t\t\t***********��ӭ����ͨѶ¼����ϵͳ***********" << endl;
	cout << "\t\t\t����Խ������²���:" << endl;
	cout << "\t\t\t|------------------------------------------|" << endl;
	cout << "\t\t\t|             1   �����ϵ��               |" << endl;
	cout << "\t\t\t|------------------------------------------|" << endl;
	cout << "\t\t\t|             2   ɾ����ϵ��               |" << endl;
	cout << "\t\t\t|------------------------------------------|" << endl;
	cout << "\t\t\t|             3   �޸���ϵ��               |" << endl;
	cout << "\t\t\t|------------------------------------------|" << endl;
	cout << "\t\t\t|             4   ��ѯ��ϵ��               |" << endl;
	cout << "\t\t\t|------------------------------------------|" << endl;
	cout << "\t\t\t|             5   ͨѶ¼��ʾ               |" << endl;
	cout << "\t\t\t|------------------------------------------|" << endl;
	cout << "\t\t\t|             6   ͨѶ¼���               |" << endl;
	cout << "\t\t\t|------------------------------------------|" << endl;
	cout << "\t\t\t|             0   �˳�                     |" << endl;
	cout << "\t\t\t|------------------------------------------|" << endl;
	cout << "\t\t\t��ѡ��0-6����";
	cin >> sel;
	while (sel < 0 || sel>6) {
		cout << "\t\t\t���벻�Ϸ���������ѡ��0-6��";
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