//ɾ����ϵ�˺���
#include"head.h"
#include<iostream>
using namespace std;

void Delate(Contect* abs)
{
	system("cls");
	cout << "\t\t\t**************��ӭ����ɾ����ϵ�˹���***************" << endl;
	int sel = 0;
	cout << "\t\t\t-----------------" << endl;
	cout << "\t\t\t1 �����ɾ��" << endl;
	cout << "\t\t\t2 ������ɾ��" << endl;
	cout << "\t\t\t3 �������˵�" << endl;
	cout << "\t\t\t-----------------" << endl;
	cout << "\t\t\t��ѡ��1-3����";
	cin >> sel;
	while (sel < 1 || sel>3)
	{
		cout << "\t\t\t���벻�Ϸ���������ѡ��1-3����";
		cin >> sel;
	}
	if (sel == 1)
	{
		int flag = 0;
		cout << "\t\t\t�������ɾ����ϵ�˵ı�ţ�";
		cin >> flag;
		if (flag > 0 && flag <= abs->size) {
			cout << "\t\t\t��ɾ����ϵ����Ϣ���£�" << endl;
			cout << "\t\t\t���\t" << "����\t" << "�绰����\t" << "סַ\t\t" << "����" << endl;
			cout << "\t\t\t" << flag << "\t" << abs->List[flag - 1].name << "\t" << abs->List[flag - 1].phonenumber;
			cout << "\t" << abs->List[flag - 1].address << "\t" << abs->List[flag - 1].relation;
		}
		else {
			cout << "\t\t\t���޴��ˣ��޷�ɾ����" << endl;
			cout << "\t\t\t���������룺";
			cin >> flag;
		}
		cout << endl;
		cout << "\t\t\tȷ��ɾ������1 �� 0 ��" << endl;
		cout << "\t\t\t��ѡ��0-1����";
		int sel_2 = 0;
		cin >> sel_2;
		while (sel_2 < 0 || sel_2>1)
		{
			cout << "\t\t\t���벻�Ϸ�,������ѡ��0-1����";
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
			cout << "\t\t\tɾ���ɹ���";
		}

		cout << "\n\t\t\t";
		system("pause");
		Delate(abs);
	}
	else if (sel == 2)
	{
		Person a;
		int flag = 0;
		cout << "\t\t\t�������ɾ����ϵ�˵�������";
		cin >> a.name;
		flag = IsExit(abs, a);
		if (flag != 0) {
			cout << "\t\t\t��ɾ����ϵ����Ϣ���£�" << endl;
			cout << "\t\t\t���\t" << "����\t" << "�绰����\t" << "סַ\t\t" << "����" << endl;
			cout << "\t\t\t" << abs->List[flag - 1].num << "\t" << abs->List[flag - 1].name << "\t" << abs->List[flag - 1].phonenumber;
			cout << "\t" << abs->List[flag - 1].address << "\t" << abs->List[flag - 1].relation;
		}
		else {
			cout << "\t\t\t���޴��ˣ��޷�ɾ����" << endl;
			cout << "\t\t\t���������룺";
			cin >> a.name;
		}
		cout << endl;
		cout << "\t\t\tȷ��ɾ������1 �� 0 ��" << endl;
		cout << "\t\t\t��ѡ��0-1����";
		int sel_3;
		cin >> sel_3;
		while (sel_3 < 0 || sel_3>1)
		{
			cout << "\t\t\t���벻�Ϸ�,������ѡ��0-1����";
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
			cout << "\t\t\tɾ���ɹ���";
		}

		cout << "\n\t\t\t";
		system("pause");
		Delate(abs);
	}
	else if (sel == 3)
		return;
}
