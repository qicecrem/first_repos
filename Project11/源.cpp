#include"founction.h"
namespace myNamespace
{
	int a = 1;
	float c = 9.9f;
}
namespace bar
{
	const double pi = 3.1415926;
	double value() { return pi * pi; }
}
class myclass
{
public:
	int x, y;
	int speed;
	void move(int xa, int ya)
	{
		x += xa * speed;
		y += ya * speed;
	}
};
class Entity
{
public:
	float x, y;
	Entity(){
		x = 0.0f;
		y = 0.0f;
	}
	Entity(float a, float b)
	{
		x = a;
		y = b;
	}
	void print()
	{
		cout << x << '\n' << y;
	}
};

int main()
{
	print1("hello world");
	print2(mult(3, 4));
	auto a = init1();
	decltype(a) b = 0;
	char c = 'e';
	cout << c<<endl;
	char arr[22] = "hello world";
	print1(arr);
	string mystring;
	mystring = "this is a string";
	cout << mystring << endl;
	//f1();
	cout << sum(2, 3) << "\n" << sum(9.0, 3.5) << "\n";
	cout << sum<int>(3, 7)<<endl;
	cout << sum<double>(2.8, 3.1)<<endl;
	cout << fixed_multiply<int, 3>(10) << '\n';
	cout <<  myNamespace::c << '\n';
	cout << bar::pi << '\n' << bar::value() << '\n';
	Entity q;
	q.print();

	return 0;
}
