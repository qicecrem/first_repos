#include"manager.h"
Manager::Manager(int id, string name, int dId) {
	this->m_id = id;
	this->m_deptid = dId;
	this->m_Name = name;
}
void Manager::showInfo() {
	cout << "ְ����ţ�" << this->m_id;
	cout << "\tְ��������" << this->m_Name;
	cout << "\t��λ��" << this->getdeptname();
	cout << "\t��λְ������ϰ彻�������񣬸�ְ����������" << endl;
}
string Manager::getdeptname() {
	return string("����");
}