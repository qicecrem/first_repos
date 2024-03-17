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
		std::cout << "文件不存在" << endl;
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
		std::cout << "文件为空！" << endl;
		this->m_Empum = 0;
		this->m_Fileisempty = true;
		this->m_EmpArray = nullptr;
		ifs.close();
		return;
	}
	int num = this->get_Empnum();
	std::cout << "职工个数为：" << num << endl;
	this->m_Empum = num;
	this->m_EmpArray = new Worker * [this->m_Empum];
	init_Emp();
	for (int i = 0; i < m_Empum; i++)
	{
		cout << "职工号：" << this->m_EmpArray[i]->m_id
			<< "  职工姓名： " << this->m_EmpArray[i]->m_Name
			<< "  部门编号： " << this->m_EmpArray[i]->m_deptid << endl;
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
	cout << "---------欢迎使用职工管理系统--------" << endl;
	cout << "------------0.退出系统---------------" << endl;
	cout << "------------1.增加职工信息-----------" << endl;
	cout << "------------2.显示职工信息-----------" << endl;
	cout << "------------3.删除职工信息-----------" << endl;
	cout << "------------4.修改职工信息-----------" << endl;
	cout << "------------5.查找职工信息-----------" << endl;
	cout << "------------6.按照编号排序-----------" << endl;
	cout << "------------7.清空所有文档-----------" << endl;
	cout << "-------------------------------------" << endl;
	cout << endl;
}
void Workmanger::exitSystem()
{
		cout << "欢迎下次使用" << endl;
		getchar();
		exit(0);
}
void Workmanger::Add_Emp()
{
	cout << "请输入增加职工数量：" << endl;
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
			cout << "请输入第" << i + 1 << "个行职工编号: " << endl;
			cin >> id;
			cout << "请输入第" << i + 1 << "个新职工姓名：" << endl;
			cin >> name;
			cout << "请选择该职工的岗位：" << endl;
			cout << "1.普通职工" << endl;
			cout << "2.经理" << endl;
			cout << "3老板" << endl;
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
		cout << "成功添加" << addNum << "名新职工！" << endl;
		this->save();
	}
	else
	{
		cout << "有误" << endl;
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
		cout << "文件不存在" << endl;
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
		cout << "文件不存在" << endl;
	}
	else
	{
		cout << "请输入想删除职工编号：" << endl;
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
			cout << "删除成功！" << endl;
		}
		else {
			cout << "未找到职工，失败" << endl;
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
		cout << "文件不存在！" << endl;
	}
	else {
		cout << "请输入修改职工的信息：" << endl;
		int id;
		cin >> id;
		int ret = this->IsExit(id);
		if (ret != -1)
		{
			delete this->m_EmpArray[ret];
			int newId = 0;
			string newname;
			int dselect;
			cout << "查到：" << id << "号职工，请重新输入职工号：" << endl;
			cin >> newId;
			cout << "请重新输入姓名：" << endl;
			cin >> newname;
			cout << "请重新输入岗位：" << endl;
			cout << "1.普通职工" << endl;
			cout << "2.经理" << endl;
			cout << "3.老板" << endl;
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
			cout << "修改成功！" << this->m_EmpArray[ret]->m_deptid << endl;
			this->save();

		}
		else
		{
			cout << "修改失败，查无此人" << endl;
		}
		getchar();
		system("cls");
	}
}
void Workmanger::Find_Emp()
{
	if (this->m_Fileisempty)
	{
		cout << "文件不存在" << endl;
	}
	else {
		cout << "请输入查找的方式：" << endl;
		cout << "1.按职工编号查找" << endl;
		cout << "2.按姓名查找" << endl;
		int select = 0;
		cin >> select;
		if (select == 1)
		{
			int id;
			cout << "请输入查找的职工编号：" << endl;
			cin >> id;
			int ret = IsExit(id);
			if (ret != -1)
			{
				cout << "查找成功" << endl;
				this->m_EmpArray[ret]->showInfo();
			}
			else {
				cout << "查找失败，查无此人" << endl;
			}
		}
		else if(select==2) {
			string name;
			cout << "请输入查找的姓名：" << endl;
			cin >> name;
			bool flag = false;
			for (int i = 0; i < m_Empum; i++)
			{
				if (m_EmpArray[i]->m_Name == name)
				{
					cout << "查找成功，职工编号为："
						<< m_EmpArray[i]->m_id << " "
						<< "号的信息如下：" << endl;
					flag = true;
					this->m_EmpArray[i]->showInfo();
				}
			}
			if (flag == false)
			{
				cout << "查找失败，查无此人" << endl;
			}
		}
		else {
			cout << "输入选项有误 " << endl;
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
		cout << "文件不存在或为空 " << endl;
		getchar();
		system("cls");

	}
	else {
		{
			quickSort(m_EmpArray, 0, m_Empum - 1);
		}
		cout << "排序成功，排序结果为： " << endl;
		this->save();
		this->show_Emp();
	}
}

void Workmanger::Clean_File()
{
	cout << "确定清空？" << endl;
	cout << "1.确定" << endl;
	cout << "2.返回" << endl;
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
		cout << "清空成功" << endl;
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