#pragma once
#include<iostream>
using namespace std;
template<class T>
class MyArray {
private:
	T* pAddress;
	int m_Capacity;
	int m_Size;
public:
	void push_back(const T& val)
	{
		if (this->m_Capacity == this->m_Size)
		{
			exit(0);
		}
		this->pAddress[this->m_Size] = val;
		this->m_Size++;
	}
	void pop_back()
	{
		if (this->m_Size == 0)
		{
			exit(0);
		}
		this->m_Size--;
	}
	T& operator[](int index)
	{
		return *(this->pAddress+index);
	}
	int getCapacity()
	{
		return this->m_Capacity;
	}
	int getSize()
	{
		return this->m_Size;
	}
	MyArray(int capacity)  
	{
		this->m_Capacity = capacity;
		this->m_Size = 0;
		this->pAddress = new T[this->m_Capacity];

	}
	MyArray(const MyArray& arr)
	{
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		this->pAddress = new T[arr.m_Capacity];
		for (int i = 0; i < this->m_Size; i++)
		{
			this->pAddress[i] = arr.pAddress[i];
		}
	}
	MyArray& operator=(const MyArray& arr)
	{
		if (this->pAddress != NULL)
		{
			delete[] this->pAddress;
			this->pAddress = NULL;
			this->m_Capacity = 0;
			this->m_Size = 0;
		}
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		this->pAddress = new T[arr.m_Capacity];
		for (int i = 0; i < this->m_Size; i++)
		{
			this->pAddress[i] = arr.pAddress[i];
		}
		return *this;
	}
	~MyArray()
	{
		if (this->pAddress != NULL)
		{
			delete[] this->pAddress;
			this->pAddress = nullptr;
		}
	}
};