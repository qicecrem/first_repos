#pragma once
#include<iostream>
#include<string>
using namespace std;
class Worker {
public:
	virtual void showInfo() = 0;
	virtual string getdeptname() = 0;
	int m_id;
	string m_Name;
	int m_deptid;
};
