#pragma once
#include"Worker.h"
class Manager :public Worker {
public:
	Manager(int id, string name, int dId);
	void showInfo() ;
	 string getdeptname();
};