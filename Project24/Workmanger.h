#pragma once
#include<fstream>
#include<iostream>
#include<fstream>
#include<string>
#include"Worker.h"
#define Filename "example.txt"
using  std::cout;
using std::cin;

class Workmanger {
public:
	Workmanger();
	void Show_Menu();
	~Workmanger();
	void exitSystem();
	void Add_Emp();
	int m_Empum;
	Worker** m_EmpArray;
	void save();
	bool m_Fileisempty;
	int get_Empnum();
	void init_Emp();
	void show_Emp();
	void Del_Emp();
	int IsExit(int id);
	void Mod_Emp();
	void Find_Emp();
	void Sort_Emp();
	void Clean_File();

};

