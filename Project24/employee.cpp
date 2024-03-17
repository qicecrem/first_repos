#include"employee.h"
Employee::Employee(int id, string name, int dId) {
	this->m_id = id;
	this->m_deptid = dId;
	this->m_Name = name;
}
void Employee::showInfo() {
	cout << "职工编号：" << this->m_id;
	cout << "\t职工姓名：" << this->m_Name;
	cout << "\t岗位：" << this->getdeptname();
	cout << "\t岗位职责：完成经理交给的任务" << endl;
 }
string Employee::getdeptname() {
	return string("员工");
 }