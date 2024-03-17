#pragma once
#include<iostream>
#include<string>
#include<sstream>
using namespace std;
#include<string>
int mult(int a ,int b);
void print1(const char* message);
void print2(int a);
int  init1();
void init2();
void init3();
void f1();
int sum(int, int);
double sum(double, double);

template<class SomeType>
SomeType sum(SomeType a, SomeType b)
{
	return a + b;
}

template <class T,int N>
T fixed_multiply(T val)
{
	return val * N;
}
