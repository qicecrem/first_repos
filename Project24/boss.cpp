#include"boss.h"
Boss::Boss(int id, string name, int dId) {
	this->m_id = id;
	this->m_deptid = dId;
	this->m_Name = name;
}
void Boss::showInfo() {
	cout << "职工编号：" << this->m_id;
	cout << "\t职工姓名：" << this->m_Name;
	cout << "\t岗位：" << this->getdeptname();
	cout << "\t岗位职责：给经理分配任务。" << endl;
}
string Boss::getdeptname() {
	return string("老板");
}