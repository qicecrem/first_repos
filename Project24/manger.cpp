#include"manager.h"
Manager::Manager(int id, string name, int dId) {
	this->m_id = id;
	this->m_deptid = dId;
	this->m_Name = name;
}
void Manager::showInfo() {
	cout << "职工编号：" << this->m_id;
	cout << "\t职工姓名：" << this->m_Name;
	cout << "\t岗位：" << this->getdeptname();
	cout << "\t岗位职责：完成老板交给的任务，给职工分配任务。" << endl;
}
string Manager::getdeptname() {
	return string("经理");
}