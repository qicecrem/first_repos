#include<iostream>
#include<iostream>
#include<string>
using namespace std;
class Example {
	string* p;
public:
	Example(const string& str): p(new string(str)) {}
	~Example() { delete p; }
	Example(Example& x) : p(x.p) { x.p = nullptr; }
	Example& operator=(Example& x) {
		delete p;
		p = x.p;
		x.p = nullptr;
		return *this;
	}
	const string& content() const { return *p; }
	Example operator+(const Example& rhs) {
		return Example(content()+rhs.content());
	}
};
int main()
{
	Example foo("Example");
	Example bar = Example("ple");
	foo =foo+ bar;
	cout << foo.content() << '\n';
		return 0;
}