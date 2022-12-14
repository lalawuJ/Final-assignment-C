#pragma once
#ifndef HEAD_H_
#define HEAD_H_

#include<string>
using namespace std;
const int MAX = 100;

struct Person {
	int num;
	string name;
	string phonenumber;
	string address;
	string relation;
};

struct Contect {
	struct Person List[MAX];
	int size;
};

void Menu();
void Add(Contect& abs);
void Delete(Contect& abs);
void Query(Contect& abs);
void Modify(Contect& abs);
void Print(Contect& abs);
void Clear(Contect& abs);

#endif