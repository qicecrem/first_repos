#include"employee.h"
Employee::Employee(int id, string name, int dId) {
	this->m_id = id;
	this->m_deptid = dId;
	this->m_Name = name;
}
void Employee::showInfo() {
	cout << "ְ����ţ�" << this->m_id;
	cout << "\tְ��������" << this->m_Name;
	cout << "\t��λ��" << this->getdeptname();
	cout << "\t��λְ����ɾ�����������" << endl;
 }
string Employee::getdeptname() {
	return string("Ա��");
 }