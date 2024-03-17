#include"MyArray.hpp"
using namespace std;
void test()
{
	MyArray<int> arr(5);
	for (int i = 0; i < 5; i++)
	{
		arr.push_back(i);
	}
	for (int i = 0; i < arr.getSize(); i++)
	{
		cout << arr[i] << endl;
	}
}
int main()
{
	test();
	return 0;
}