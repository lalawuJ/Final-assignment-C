//�����ϵ�˺���
#include"head.h"
#include<iostream>
using namespace std;

void Add(Contect* abs)
{
	system("cls");
	cout << "\t\t\t**************��ӭ���������ϵ�˹���**************" << endl;
	int flag = 1;
	int i = 0;
	Person a;

	while (flag == 1)
	{
		cout << "\t\t\t������������";
		cin >> a.name;
		cout << "\t\t\t������绰���룺";
		cin >> a.phonenumber;
		cout << "\t\t\t������סַ��";
		cin >> a.address;
		cout << "\t\t\t��������飺";
		cin >> a.relation;
		a.num = i + 1;
		abs->List[i] = a;
		++i;
		++abs->size;
		cout << "\t\t\t��ӳɹ����Ƿ������ӣ� ��1 �� 0 ��" << endl;
		cout << "\t\t\t��ѡ��0-1����";
		cin >> flag;
		if (flag != 0 && flag != 1)
		{
			cout << "\t\t\t���벻�Ϸ���������ѡ��0-1��";
			cin >> flag;
		}
		if (i == MAX - 1) {
			cout << "\t\t\tͨѶ¼���������������ϵ��";
			break;
		}
	}

	cout << "\n\t\t\t";
	system("pause");
}