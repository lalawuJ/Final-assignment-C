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

//ȷ����ϵ���Ƿ�����ҷ��ر��
int IsExit(Contect* abs, Person a)
{
	int b = 0;
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

//��ʾͨѶ¼����
void Print(Contect* abs)
{
	system("cls");
	cout << "\t\t\t***************��ӭ����ͨѶ¼��ʾ����***************" << endl;
	int i = 0;
	if (abs->size == 0)
		cout << "\t\t\tͨѶ¼Ϊ�գ��޷���ʾ��" << endl;
	else if (abs->size != 0)
	{
		cout << "\t\t\t-----------------------------------------------------" << endl;
		cout << "\t\t\t���\t" << "����\t" << "��ϵ�绰\t" << "��ͥ��ַ\t" << "����" << endl;
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

//���ͨѶ¼����
void Clear(Contect* abs)
{
	int sel = 0;
	system("cls");
	cout << "\t\t\t**************��ӭ����ͨѶ¼��չ���*************" << endl;
	if (abs->size == 0)
		cout << "\t\t\tͨѶ¼Ϊ�գ��޷���գ�" << endl;
	else if (abs->size != 0)
	{
		cout << "\t\t\t-----------------" << endl;
		cout << "\t\t\t1 ȷ�����ͨѶ¼" << endl;
		cout << "\t\t\t2 �������˵�" << endl;
		cout << "\t\t\t-----------------" << endl;
		cout << "\t\t\t������ѡ��1-2����";
		cin >> sel;
		while (sel < 1 || sel>2)
		{
			cout << "\t\t\t���벻�Ϸ�,���������롾1-2����";
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
