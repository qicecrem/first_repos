#pragma once
#include"Worker.h"
using namespace std;
class Employee : public Worker {
public:
	Employee(int id ,string name,int dId);
	virtual void showInfo() ;
	virtual string getdeptname();
};