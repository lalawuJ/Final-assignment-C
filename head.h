#ifndef HEAD_H_
#define HEAD_H_

#include<string>
using namespace std;
const int MAX = 100;

struct Person {
	int num=0;
	//���
	string name;
	//����
	string phonenumber;
	//�绰����
	string address;
	//סַ
	string relation;
	//����
};

struct Contect {
	Person List[MAX];
	//ͨѶ¼
	int size = 0;
	//ͨѶ¼��ǰ������
};

void Menu(Contect* abs);
void Add(Contect* abs);
int IsExit(Contect* abs,Person a);
void Delate(Contect* abs);
void Query(Contect* abs);
void Modify(Contect* abs);
void Print(Contect* abs);
void Clear(Contect* abs);

#endif