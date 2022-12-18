#ifndef HEAD_H_
#define HEAD_H_

#include<string>
using namespace std;
const int MAX = 100;

struct Person {
	int num=0;
	//编号
	string name;
	//姓名
	string phonenumber;
	//电话号码
	string address;
	//住址
	string relation;
	//分组
};

struct Contect {
	Person List[MAX];
	//通讯录
	int size = 0;
	//通讯录当前的人数
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