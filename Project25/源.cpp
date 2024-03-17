#include<iostream>
#include<string>
#include<ctime>
using namespace std;
class Person {
public:
	Person(int a) :age(a){}
	int age;
};
template<class T>
int partition(T* p, int low, int high)
{
	T pivot = p[high];
	int i = low - 1;
	for (int j = low; j <= high - 1; j++)
	{
		if (p[j] > pivot)
		{
			i++;
			swap(p[i], p[j]);
		}
	}
	swap(p[i + 1], p[high]);
	return i + 1;
}
template<> int partition(Person** p, int low, int high)
{
	Person* pivot = p[high];
	int i = low - 1;
	for (int j = low; j <= high - 1; j++)
	{
		if (p[j]->age < pivot->age)
		{
			i++;
			swap(p[i], p[j]);
		}
	}
	swap(p[i + 1], p[high]);
	return i + 1;
}
template<class T>
void quickSort(T* p, int low, int high)
{
	if (low < high)
	{
		int pi = partition(p, low, high);
			quickSort(p, low, pi - 1);
			quickSort(p, pi + 1, high);
	}
}
void test()
{
	srand(time(NULL));
	int arr[5] = { 3,2,1,4,5 };
	quickSort(arr, 0, 4);
	for (int i = 0; i < 5; i++)
	{
		cout << arr[i] << endl;
	}
	Person** p = new Person * [22];
	for (int i = 0; i < 22; i++)
	{
		p[i] =new Person( rand() % 101);
	}
	quickSort(p, 0, 21);
	for (int j = 0; j < 21; j++)
	{
		cout << p[j]->age << "   ";
	}

}
int main()
{
	test();

	return 0;
}