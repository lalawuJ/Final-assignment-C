//��ѯ��ϵ�˺���
#include"head.h"
#include<iostream>
using namespace std;

void Query(Contect* abs)
{
	system("cls");
	cout << "\t\t\t**************��ӭ������ѯ��ϵ�˹���***************" << endl;
	Person a;
	int sel;
	cout << "\t\t\t-----------------" << endl;
	cout << "\t\t\t1 ����Ų�ѯ" << endl;
	cout << "\t\t\t2 ��������ѯ" << endl;
	cout << "\t\t\t3 �������˵�" << endl;
	cout << "\t\t\t-----------------" << endl;
	cout << "\t\t\t��ѡ��1-3����";
	cin >> sel;
	while (sel < 1 || sel>3)
	{
		cout << "\t\t\t���벻�Ϸ�,������ѡ��1-3����";
		cin >> sel;
	}
	if (sel == 1)
	{
		int flag = 0;
		cout << "\t\t\t���������ѯ��ϵ�˵ı�ţ�";
		cin >> flag;
		if (flag > 0 && flag <= abs->size) {
			cout << "\t\t\t����ѯ��ϵ����Ϣ���£�" << endl;
			cout << "\t\t\t���\t" << "����\t" << "��ϵ�绰\t" << "סַ\t\t" << "����" << endl;
			cout << "\t\t\t" << flag << "\t" << abs->List[flag - 1].name << "\t" << abs->List[flag - 1].phonenumber;
			cout << "\t" << abs->List[flag - 1].address << "\t" << abs->List[flag - 1].relation << endl;
		}
		else if (flag == 0)
			cout << "\t\t\t���޴��ˣ�" << endl;

		cout << "\n\t\t\t";
		system("pause");
		Query(abs);
	}
	else if (sel == 2)
	{
		int flag = 0;
		cout << "\t\t\t���������ѯ��ϵ�˵�������";
		cin >> a.name;
		flag = IsExit(abs, a);
		if (flag != 0) {
			cout << "\t\t\t����ѯ��ϵ����Ϣ���£�" << endl;
			cout << "\t\t\t���\t" << "����\t" << "�绰����\t" << "סַ\t\t" << "����" << endl;
			cout << "\t\t\t" <<abs->List[flag-1].num<<"\t"<< abs->List[flag - 1].name << "\t" << abs->List[flag - 1].phonenumber;
			cout << "\t" << abs->List[flag - 1].address << "\t" << abs->List[flag - 1].relation << endl;
		}
		else
			cout << "\t\t\t���޴��ˣ�" << endl;

		cout << "\n\t\t\t";
		system("pause");
		Query(abs);
	}
	else if (sel == 3)
		return;
}