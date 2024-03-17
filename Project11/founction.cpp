#include"founction.h"
int mult(int a, int b) {
	return a * b;
}
void print1(const char* message) {
	cout << message<<endl;
}
void print2(int  a)
{
	cout << a << endl;
}
int  init1() {
	int a = 0;
	return a;
}
void init2() {
	int a(0);
}
void init3() {
	int a{ 0 };
}
void f1()
{
	string mystr;
	float price;
	int quantity;
	cout << "Enter price";
	getline(cin, mystr);
	stringstream(mystr) >> price;
	cout << "Enter quantity";
	getline(cin, mystr);
	stringstream(mystr) >> quantity;
	cout << "Total price:" << price * quantity << endl;
}
int sum(int a, int b)
{
	return a + b;
}
double sum(double a, double b)
{
	return a + b;
}