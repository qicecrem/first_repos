#include<iostream>
#include<string>
using namespace std;
class Example {
	string* p;
public:
	Example() : p(new string){}
	Example(const string& str) : p(new string(str)) {}
	~Example() { delete p;}
	const string& content() const { return *p; }


};
int main()
{
	Example foo;
	Example bar{ "Example" };
	cout << bar.content() << '\n';
	cout << foo.content() << '\n';
}