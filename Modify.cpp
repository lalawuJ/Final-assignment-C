//�޸���ϵ�˺���
#include"head.h"
#include<iostream>
using namespace std;

void Modify(Contect* abs)
{
	system("cls");
	cout << "\t\t\t**************��ӭ�����޸���ϵ�˹���***************" << endl;
	int sel = 0;
	cout << "\t\t\t-----------------" << endl;
	cout << "\t\t\t1 ������޸�" << endl;
	cout << "\t\t\t2 �������޸�" << endl;
	cout << "\t\t\t3 �������˵�" << endl;
	cout << "\t\t\t-----------------" << endl;
	cout << "\t\t\t��ѡ��1-3����";
	cin >> sel;
	while (sel < 1 || sel>3)
	{
		cout << "\t\t\t���벻�Ϸ�,���������롾1-3����";
		cin >> sel;
	}
	if (sel == 1)
	{
		int flag = 0;
		cout << "\t\t\t��������޸ĵ���ϵ�˵ı�ţ�";
		cin >> flag;
		if (flag > 0 && flag <= abs->size) {
			cout << "\t\t\t����ѯ��ϵ����Ϣ���£�" << endl;
			cout << "\t\t\t���\t" << "����\t" << "��ϵ�绰\t" << "��ַ\t\t" << "����" << endl;
			cout << "\t\t\t" << flag << "\t" << abs->List[flag - 1].name << "\t" << abs->List[flag - 1].phonenumber;
			cout << "\t" << abs->List[flag - 1].address << "\t" << abs->List[flag - 1].relation << endl;
			Person a;
			cout << "\t\t\t�����޸ĺ����ϵ����Ϣ��" << endl;
			cout << "\t\t\t����������";
			cin >> a.name;
			cout << "\t\t\t����绰��";
			cin >> a.phonenumber;
			cout << "\t\t\t�����ַ��";
			cin >> a.address;
			cout << "\t\t\t������飺";
			cin >> a.relation;
			a.num = flag;
			cout << "\t\t\tȷ���޸ģ���1 �� 0 ��" << endl;
			cout << "\t\t\t��ѡ��0-1����";
			cin >> sel;
			while (sel < 0 || sel>1)
			{
				cout << "\t\t\t���벻�Ϸ�,������ѡ��0-1����";
				cin >> sel;
			}
			if (sel == 0);

			else if (sel == 1)
				abs->List[flag - 1] = a;
		}
		else if (flag == 0)
			cout << "\t\t\t���޴��ˣ��޷��޸ģ�" << endl;

		cout << "\n\t\t\t";
		system("pause");
		Query(abs);
	}
	else if (sel == 2)
	{
		int flag = 0;
		Person a;
		cout << "\t\t\t���������ѯ��ϵ�˵�������";
		cin >> a.name;
		flag = IsExit(abs, a);
		if (flag != 0) {
			cout << "\t\t\t����ѯ��ϵ����Ϣ���£�" << endl;
			cout << "\t\t\t���\t" << "����\t" << "�绰����\t" << "סַ\t\t" << "����" << endl;
			cout << "\t\t\t" << flag << "\t" << abs->List[flag - 1].name << "\t" << abs->List[flag - 1].phonenumber;
			cout << "\t" << abs->List[flag - 1].address << "\t" << abs->List[flag - 1].relation << endl;
			cout << "\t\t\t�����޸ĺ����ϵ����Ϣ��" << endl;
			cout << "\t\t\t����������";
			cin >> a.name;
			cout << "\t\t\t����绰��";
			cin >> a.phonenumber;
			cout << "\t\t\t�����ַ��";
			cin >> a.address;
			cout << "\t\t\t������飺";
			cin >> a.relation;
			a.num = flag;
			cout << "\t\t\tȷ���޸ģ���1 �� 0 ��" << endl;
			cout << "\t\t\t��ѡ��0-1����";
			cin >> sel;
			while (sel < 0 || sel>1)
			{
				cout << "\t\t\t���벻�Ϸ�,������ѡ��0-1����";
				cin >> sel;
			}
			if (sel == 0);

			else if (sel == 1)
				abs->List[flag - 1] = a;
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