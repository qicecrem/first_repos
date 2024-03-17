#include<iostream>
using namespace std;
class Cvector {
public:
	int x, y;
	Cvector():x(0),y(0) {};
	Cvector(int a,int b): x(a),y(b) {}
	
};
Cvector operator+(const Cvector& lhs, const Cvector& rhs) {
	Cvector temp;
	temp.x = lhs.x + rhs.x;
	temp.y = lhs.y + rhs.y;
	return temp;
}

int main()
{
	Cvector foo{  };
	Cvector bar(1, 2);
	Cvector result;
	result = foo + bar;
	cout << result.x<<"  " <<result.y<< endl;
	

	return 0;
}