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

//�˵�
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
	while (sel<0||sel>6){
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

//�����ϵ�˺���
void Add(Contect* abs)
{
	system("cls");
	cout << "\t\t\t**************��ӭ���������ϵ�˹���**************" << endl;
	int flag=1;
	int i = 0;
	Person a;
	
	while (flag==1)
	{
		cout << "\t\t\t������������";
		cin >> a.name;
		cout << "\t\t\t������绰���룺" ;
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

//ȷ����ϵ���Ƿ�����ҷ��ر��
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

//ɾ����ϵ�˺���
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
		cout << "\t\t\t�������ɾ����ϵ�˵ı�ţ�" ;
		cin >> flag;
		if (flag > 0 && flag <= abs->size) {
			cout << "\t\t\t��ɾ����ϵ����Ϣ���£�" << endl;
			cout << "\t\t\t���\t" << "����\t" << "�绰����\t" << "סַ\t" << "����" << endl;
			cout << "\t\t\t" << flag << "\t" << abs->List[flag - 1].name << "\t" << abs->List[flag - 1].phonenumber;
		    cout<< "\t" << abs->List[flag - 1].address << "\t" << abs->List[flag - 1].relation;
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
			for (int i = flag - 1; i < abs->size-1; i++)
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
		cout << "\t\t\t�������ɾ����ϵ�˵�������" ;
		cin >> a.name;
		flag = IsExit(abs, a);
		if (flag != 0) {
			cout << "\t\t\t��ɾ����ϵ����Ϣ���£�" << endl;
			cout << "\t\t\t���\t" << "����\t" << "�绰����\t" << "סַ\t" << "����" << endl;
			cout << "\t\t\t" <<abs->List[flag-1].num<<"\t"<< abs->List[flag - 1].name << "\t" << abs->List[flag - 1].phonenumber;
		    cout<< "\t" << abs->List[flag - 1].address << "\t" << abs->List[flag - 1].relation;
		}
		else {
			cout << "\t\t\t���޴��ˣ��޷�ɾ����" << endl;
			cout << "\t\t\t���������룺";
			cin >> a.name;
		}
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

//�޸���ϵ�˺���
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
			cout << "\t\t\t���\t" << "����\t" << "��ϵ�绰\t" << "��ͥ��ַ\t" << "����" << endl;
			cout << "\t\t\t" << flag << "\t" << abs->List[flag - 1].name << "\t" << abs->List[flag - 1].phonenumber << "\t" << abs->List[flag - 1].address << "\t" << abs->List[flag - 1].relation << endl;
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
			cout << "\t\t\t���\t" << "����\t" << "�绰����\t" << "סַ\t" << "����" << endl;
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

//��ѯ��ϵ�˺���
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
			cout << "\t\t\t���\t" << "����\t" << "��ϵ�绰\t" << "��ͥ��ַ\t" << "����" << endl;
			cout << "\t\t\t" << flag << "\t" << abs->List[flag - 1].name << "\t" << abs->List[flag - 1].phonenumber;
			cout<< "\t" << abs->List[flag - 1].address << "\t" << abs->List[flag - 1].relation << endl;
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
			cout << "\t\t\t���\t" << "����\t" << "�绰����\t" << "סַ\t" << "����" << endl;
			cout << "\t\t\t" << abs->List[flag - 1].name << "\t" << abs->List[flag - 1].phonenumber;
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
