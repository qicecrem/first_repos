#include"Workmanger.h"
#include"employee.h"
#include"Worker.h"
#include"manager.h"
#include"boss.h"
Workmanger::~Workmanger()
{
	if (this->m_EmpArray != nullptr)
	{
		for (int i = 0; i < this->m_Empum; i++)
		{
			if (this->m_EmpArray[i] != NULL)
			{
				delete this->m_EmpArray[i];
			}
		}
		delete[] this->m_EmpArray;
		this->m_EmpArray = nullptr;
		
	}
}
Workmanger::Workmanger()
{
	ifstream ifs;
	ifs.open(Filename, ios::in);
	if (!ifs.is_open())
	{
		std::cout << "�ļ�������" << endl;
		this->m_Empum = 0;
		this->m_EmpArray = NULL;
		this->m_Fileisempty = true;
		ifs.close();
			return;
	}
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		std::cout << "�ļ�Ϊ�գ�" << endl;
		this->m_Empum = 0;
		this->m_Fileisempty = true;
		this->m_EmpArray = nullptr;
		ifs.close();
		return;
	}
	int num = this->get_Empnum();
	std::cout << "ְ������Ϊ��" << num << endl;
	this->m_Empum = num;
	this->m_EmpArray = new Worker * [this->m_Empum];
	init_Emp();
	for (int i = 0; i < m_Empum; i++)
	{
		cout << "ְ���ţ�" << this->m_EmpArray[i]->m_id
			<< "  ְ�������� " << this->m_EmpArray[i]->m_Name
			<< "  ���ű�ţ� " << this->m_EmpArray[i]->m_deptid << endl;
	}


	
}
int Workmanger::get_Empnum()
{
	ifstream ifs;
	ifs.open(Filename, ios::in);
	int id;
	string name;
	int dId;
	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		num++;
	}
	ifs.close();
	return num;
}

void Workmanger::Show_Menu()
{
	cout << "-------------------------------------" << endl;
	cout << "---------��ӭʹ��ְ������ϵͳ--------" << endl;
	cout << "------------0.�˳�ϵͳ---------------" << endl;
	cout << "------------1.����ְ����Ϣ-----------" << endl;
	cout << "------------2.��ʾְ����Ϣ-----------" << endl;
	cout << "------------3.ɾ��ְ����Ϣ-----------" << endl;
	cout << "------------4.�޸�ְ����Ϣ-----------" << endl;
	cout << "------------5.����ְ����Ϣ-----------" << endl;
	cout << "------------6.���ձ������-----------" << endl;
	cout << "------------7.��������ĵ�-----------" << endl;
	cout << "-------------------------------------" << endl;
	cout << endl;
}
void Workmanger::exitSystem()
{
		cout << "��ӭ�´�ʹ��" << endl;
		getchar();
		exit(0);
}
void Workmanger::Add_Emp()
{
	cout << "����������ְ��������" << endl;
	int addNum = 0;
	cin >> addNum;
	if (addNum > 0)
	{
		int newSize = this->m_Empum + addNum;
		Worker** newSpace = new Worker * [newSize];
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_Empum;i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}
		for (int i = 0; i < addNum; i++)
		{
			int id;
			string name;
			int dSelect;
			cout << "�������" << i + 1 << "����ְ�����: " << endl;
			cin >> id;
			cout << "�������" << i + 1 << "����ְ��������" << endl;
			cin >> name;
			cout << "��ѡ���ְ���ĸ�λ��" << endl;
			cout << "1.��ְͨ��" << endl;
			cout << "2.����" << endl;
			cout << "3�ϰ�" << endl;
			cin >> dSelect;
			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1:
				worker = new Employee(id, name, 1);
				break;
			case 2:
				worker = new Manager(id, name, 2);
				break;
			case 3:
				worker = new Boss(id, name, 3);
				break;
			default:
				break;

			}
			newSpace[this->m_Empum + i] = worker;

		}
		delete[] this->m_EmpArray;
		this->m_EmpArray = newSpace;
		this->m_Empum = newSize;
		this->m_Fileisempty = false;
		cout << "�ɹ����" << addNum << "����ְ����" << endl;
		this->save();
	}
	else
	{
		cout << "����" << endl;
	}
	getchar();
	system("cls");
}
void Workmanger::save()
{
	ofstream ofs;
	ofs.open(Filename, ios::out);
	for (int i = 0; i < this->m_Empum; i++)
	{
		ofs << this->m_EmpArray[i]->m_id << " "
			<< this->m_EmpArray[i]->m_Name << " "
			<< this->m_EmpArray[i]->m_deptid << endl;
	}
	ofs.close();
}
void Workmanger::init_Emp()
{
	ifstream ifs;
	ifs.open(Filename, ios::in);
	int id;
	string name;
	int dId;
	int dex = 0;
	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		Worker* worker = NULL;
		if (dId == 1)
		{
			worker = new Employee(id, name, dId);
		}
		else if (dId == 2)
		{
			worker = new Manager(id, name, dId);
		}
		else
		{
			worker = new Boss(id, name,dId);
		}
		this->m_EmpArray[dex] = worker;
		dex++;

	}

}
void Workmanger::show_Emp()
{
	if (this->m_Fileisempty) {
		cout << "�ļ�������" << endl;
	}
	else {
		for (int i = 0; i < m_Empum; i++)
		{
			this->m_EmpArray[i]->showInfo();
		}
	}
	getchar();
	getchar();
	system("cls");

}
void Workmanger::Del_Emp()
{
	if (this->m_Fileisempty)
	{
		cout << "�ļ�������" << endl;
	}
	else
	{
		cout << "��������ɾ��ְ����ţ�" << endl;
		int id = 0;
		cin >> id;
		int dex=this->IsExit(id);
		if (dex != -1)
		{
			for (int i = dex; i < this->m_Empum - 1; i++)
			{
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
             
			}
			this->m_Empum--;
			this->save();
			cout << "ɾ���ɹ���" << endl;
		}
		else {
			cout << "δ�ҵ�ְ����ʧ��" << endl;
		}
	
	}
	getchar();
	system("cls");

}
int Workmanger::IsExit(int id)
{
	int dex = -1;
	for (int i = 0; i < this->m_Empum; i++)
	{
		if (this->m_EmpArray[i]->m_id == id)
		{
			dex = i;
			break;
		}
	}
	return dex;
}
void Workmanger::Mod_Emp()
{
	if (this->m_Fileisempty)
	{
		cout << "�ļ������ڣ�" << endl;
	}
	else {
		cout << "�������޸�ְ������Ϣ��" << endl;
		int id;
		cin >> id;
		int ret = this->IsExit(id);
		if (ret != -1)
		{
			delete this->m_EmpArray[ret];
			int newId = 0;
			string newname;
			int dselect;
			cout << "�鵽��" << id << "��ְ��������������ְ���ţ�" << endl;
			cin >> newId;
			cout << "����������������" << endl;
			cin >> newname;
			cout << "�����������λ��" << endl;
			cout << "1.��ְͨ��" << endl;
			cout << "2.����" << endl;
			cout << "3.�ϰ�" << endl;
			cin >> dselect;
			Worker* worker = NULL;
			switch (dselect)
			{
			case 1:
				worker = new Employee(newId, newname, dselect);
				break;
			case 2:
				worker = new Manager(newId, newname, dselect);
				break;
			case 3:
				worker = new Boss(newId, newname, dselect);
				break;
			default:
				break;
			}
			this->m_EmpArray[ret] = worker;
			cout << "�޸ĳɹ���" << this->m_EmpArray[ret]->m_deptid << endl;
			this->save();

		}
		else
		{
			cout << "�޸�ʧ�ܣ����޴���" << endl;
		}
		getchar();
		system("cls");
	}
}
void Workmanger::Find_Emp()
{
	if (this->m_Fileisempty)
	{
		cout << "�ļ�������" << endl;
	}
	else {
		cout << "��������ҵķ�ʽ��" << endl;
		cout << "1.��ְ����Ų���" << endl;
		cout << "2.����������" << endl;
		int select = 0;
		cin >> select;
		if (select == 1)
		{
			int id;
			cout << "��������ҵ�ְ����ţ�" << endl;
			cin >> id;
			int ret = IsExit(id);
			if (ret != -1)
			{
				cout << "���ҳɹ�" << endl;
				this->m_EmpArray[ret]->showInfo();
			}
			else {
				cout << "����ʧ�ܣ����޴���" << endl;
			}
		}
		else if(select==2) {
			string name;
			cout << "��������ҵ�������" << endl;
			cin >> name;
			bool flag = false;
			for (int i = 0; i < m_Empum; i++)
			{
				if (m_EmpArray[i]->m_Name == name)
				{
					cout << "���ҳɹ���ְ�����Ϊ��"
						<< m_EmpArray[i]->m_id << " "
						<< "�ŵ���Ϣ���£�" << endl;
					flag = true;
					this->m_EmpArray[i]->showInfo();
				}
			}
			if (flag == false)
			{
				cout << "����ʧ�ܣ����޴���" << endl;
			}
		}
		else {
			cout << "����ѡ������ " << endl;
		}

	}
	getchar();
	system("cls");
}

void quickSort(Worker** p, int low, int high);

void Workmanger::Sort_Emp()
{
	if (this->m_Fileisempty)
	{
		cout << "�ļ������ڻ�Ϊ�� " << endl;
		getchar();
		system("cls");

	}
	else {
		{
			quickSort(m_EmpArray, 0, m_Empum - 1);
		}
		cout << "����ɹ���������Ϊ�� " << endl;
		this->save();
		this->show_Emp();
	}
}

void Workmanger::Clean_File()
{
	cout << "ȷ����գ�" << endl;
	cout << "1.ȷ��" << endl;
	cout << "2.����" << endl;
	int select = 0;
	cin >> select;
	if (select == 1)
	{
		ofstream ofs(Filename, ios::trunc);
		ofs.close();
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_Empum; i++)
			{
				if (this->m_EmpArray[i] != NULL)
				{
					delete this->m_EmpArray[i];
				}
			}
			this->m_Empum = 0;
			delete[] this->m_EmpArray;
			this->m_EmpArray = nullptr;
			this->m_Fileisempty = true;
		}
		cout << "��ճɹ�" << endl;
	}
	getchar();
	system("cls");

}
int partition(Worker** p, int low, int high)
{
	Worker* pivot = p[high];
	int i = low - 1;
	for (int j = low; j <= high - 1; j++)
	{
		if (p[j]->m_id < pivot->m_id)
		{
			i++;
			swap(p[i], p[j]);
		}
	}
	swap(p[i + 1], p[high]);
	return i + 1;

}
void quickSort(Worker** p, int low, int high)
{
	if (low < high)
	{
		int pi = partition(p, low, high);
		quickSort(p, low, pi - 1);
		quickSort(p, pi + 1, high);
	}
 }