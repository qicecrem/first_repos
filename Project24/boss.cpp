#include"boss.h"
Boss::Boss(int id, string name, int dId) {
	this->m_id = id;
	this->m_deptid = dId;
	this->m_Name = name;
}
void Boss::showInfo() {
	cout << "ְ����ţ�" << this->m_id;
	cout << "\tְ��������" << this->m_Name;
	cout << "\t��λ��" << this->getdeptname();
	cout << "\t��λְ�𣺸������������" << endl;
}
string Boss::getdeptname() {
	return string("�ϰ�");
}