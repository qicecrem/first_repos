//#include<iostream>
//using namespace std;
//int main()
//{
//	int socre[3][3] = { {100,100,100},{90,50,100},{60,70,80} };
//	for (int i = 0; i < 3; i++)
//	{
//		int sum = 0;
//		for (int j = 0; j < 3; j++)
//		{
//			sum += socre[i][j];
//			cout << socre[i][j] << "  ";
//		}
//		cout << sum;
//		cout << endl;
//	}
//	return 0;
////}
//#include<iostream>
//using namespace std;
//#define studentsnum 5
//#include<string>
//#include<random>
//struct students {
//	string name;
//	int score;
//};
//struct teachers {
//	string name;
//	struct students arr[studentsnum];
//};
//void allocatespace(struct teachers tarr[], int len)
//{
//	string nameseed = "ABCDE";
//	for (int i = 0; i < 3; i++)
//	{
//		tarr[i].name = "teacher_";
//		tarr[i].name += nameseed[i];
//
//		for (int j = 0; j < 5; j++)
//		{
//			tarr[i].arr[j].name = "student_";
//			tarr[i].arr[j].name += nameseed[j];
//			tarr[i].arr[j].score = 0;
//		}
//	}
//}
//void printinfo(struct teachers tarr[],int len)
//{
//	random_device rd;
//	mt19937 gen(rd());
//	uniform_int_distribution<int>dis(0, 100);
//	for (int i = 0; i < len; i++)
//	{
//		cout << tarr[i].name<<": ";
//		for (int j = 0; j < studentsnum; j++)
//		{
//			int rand = dis(gen);
//			tarr[i].arr[j].score = rand;
//			cout << tarr[i].arr[j].name << "--";
//			cout << tarr[i].arr[j].score << "  ,";
//		}
//		cout << endl;
//	}
//}
//int main()
//{
//	
//	struct teachers tarr[3];
//	int len = sizeof(tarr) / sizeof(tarr[0]);
//	allocatespace(tarr, len);
//	printinfo(tarr,len);
//	return 0;
//}


//#include<iostream>
//using namespace std;
//class Person {
//public:
//	int age;
//	Person() :age(10) { cout << "Person()"<<endl; }
//	Person(const Person& p)
//	{
//		cout << "Person(const Person& p" << endl;
//		age = p.age + 1;
//	}
//	~Person() { cout << "~" << endl; }
//};
//Person test2(Person a)
//{
//	cout << "qw" << endl;
//	cout << a.age << endl;
//	system("pause");
//	return a;
//}
//void test1()
//{
//	Person a;
//	cout << a.age << endl;
//	Person b=test2(a);
//	cout << b.age << endl;
//	system("pause");
//}
//int main()
//{
//	test1();
//
//	return 0;
//}
//#include<iostream>
//using namespace std;
//class Person {
//public:
//	int weight;
//	int* m_height;
//	Person() {}
//	Person(int age, int* height)
//	{
//		cout << "Person(int ,int)" << endl;
//		weight = age;
//		m_height = new int(*height);
//	}
//	Person(const Person& p)
//	{
//		cout << "Person(const Person&)" << endl;
//		weight = p.weight;
//		m_height = new int(*p.m_height);
//	}
//	~Person() {}
//	
//};
//void test1()
//{
//	int* b = new int(10);
//	Person a{ 10,b };
//	Person c{ a };
//	cout << *c.m_height << endl;
//	cout << c.weight << endl;
//}
//int main()
//{
//	test1();
//	return 0;
//}
//#include<iostream>
//#include<string>
//using namespace std;
//class Phone {
//public:
//	string Phonename;
//	~Phone(){}
//	Phone() {}
//	Phone(string a) :Phonename(a) { cout << "Phone(string)" << endl; }
//	Phone(const Phone& p) : Phonename(p.Phonename) { cout << "Phone(const Phone&)" << endl; }
//};
//class Person {
//public:
//	string name;
//	Phone phone;
//	Person() {};
//	Person(string a, string b) : name(a), phone(b) { cout << "Person(string,Phone);" << endl; }
//	~Person(){}
//	Person(const Person& p) :name(p.name), phone(p.phone) { cout << "Person(const Person&)" << endl; }
//
//};
//void test1()
//{
//	Person a{ "xhe","ace"};
//	Person b{ a };
//}
//int main() {
//	test1();
//	return 0;
//}
//#include<iostream>
//#include<string>
//using namespace std;
//class Person {
//public:
//	static int m_a;
//};
//int Person::m_a = 10;
//int main()
//{
//	cout << Person::m_a << endl;
//	Person::m_a = 100;
//	cout << Person::m_a << endl;
//	int& a = Person::m_a;
//	Person::m_a = 19;
//	cout << a << endl;
//	return 0;
//}
//#include<iostream>
//#include<string>
//using namespace std;
//class Person {
//public:
//	int a;
//	Person() {}
//	Person(int a) {
//		this->a = a;
//	}
//	Person(const Person& p)
//	{
//		this->a = p.a;
//	}
//	~Person() {}
//	Person& Add(const Person& p)
//	{
//		this->a += p.a;
//		
//		return *this;
//	}
//};
//void test1()
//{
//	Person a{ 12 };
//	Person b{ 12 };
//	a.Add(b).Add(a);
//	cout << a.a << endl;
//}
//int main()
//{
//	test1();
//	return 0;
//}
//#include<iostream>
//#include<string>
//using namespace std;
//class Building {
//	friend void build(Building*);
//public:
//	string m_sittingroom;
//private:
//	string m_bedroom;
//
//};
//void build(Building* p)
//{
//	p->m_sittingroom = "keting";
//	p->m_bedroom = "woshi";
//	cout << p->m_sittingroom << endl;
//	cout << p->m_bedroom << endl;
//
//}
//void test1()
//{
//	Building a;
//	build(&a);
//	
//}
//int main()
//{
//	test1();
//	return 0;
//}
//#include<iostream>
//#include<string>
//using namespace std;
//class Building {
//	friend class Godgay;
//public:
//	string m_sittingroom;
//private:
//	string m_bedroom;
//public:
//	~Building() {}
//
//
//};
//class Godgay {
//public:
//	Godgay() {
//		a.m_sittingroom = "keting";
//		a.m_bedroom = "woshi";
//
//
//	}
//	void vist1();
//	void vist2();
//	~Godgay(){}
//	Building a;
//};
//
//void Godgay::vist1()
//{
//	cout << a.m_sittingroom << endl;
//}
//void Godgay::vist2()
//{
//	cout << a.m_bedroom << endl;
//}
//void test1()
//{
//	Godgay a;
//	a.vist1();
//	a.vist2();
//}
//int main()
//{
//	test1();
//	return 0;
//}

//#include<iostream>
//#include<string>
//using namespace std;
//class Person {
//	public:
//		Person():x(0),y(0){}
//		int  x;
//		int  y;
//		Person(int a,int b):x(a),y(b){}
//		Person(double a, double b) {
//			x = (double)x;
//			y = (double)y;
//			x = a;
//			y = b;
//		}
//		Person operator+=(const Person& p)
//		{
//			this->x += p.x;
//			this->y += p.y;
//			return *this;
//		}
//		~Person(){}
//		
//};
//Person& operator+(Person& a,Person& b)
//{
//	a.x = a.x + b.x;
//	a.y = a.y + b.y;
//	return a;
//}
//void test1()
//{
//	Person a{ 1,2 };
//	Person b{ 3,4 };
//	Person c{ 2.3,2.4 };
//	c += a;
//	b += a;
//	cout << b.x << "\t" << b.y << endl;
//	cout << a.x << "\t" << a.y << endl;
//	cout << c.x << '\t' << c.y << endl;
//}
//int main()
//{
//	test1();
//	return 0;
//}

//#include<iostream>
//#include<string>
//using namespace std;
//
//class Person {
//    friend ostream& operator<<(ostream& cout, const Person& p);
//private:
//    int x;
//    int y;
//public:
//    Person() : x(0), y(0) {}
//    Person(int a, int b) : x(a), y(b) {}
//
//    
//};
//ostream& operator<<(ostream& cout, const Person& p)
//{
//    cout << p.x << " " << p.y;
//    return cout;
//}
//void test1()
//{
//    Person a{ 12,12 };
//    cout << a << endl;
//}
//int main()
//{
//    test1();
//    return 0;
//
//}
//#include<iostream>
//#include<string>
//using namespace std;
//class MyInteger {
//private:
//	int mn;
//public :
//		MyInteger(): mn(0) {}
//		MyInteger& operator++()
//		{
//			mn++;
//			return *this;
//		}
//		MyInteger& operator++(int)
//		{
//			MyInteger temp = *this;
//			mn++;
//			return temp;
//}
//		 friend ostream& operator<<(ostream& cout,const MyInteger& p)
//		{
//
//			cout << p.mn;
//			return cout;
//		}
//};
//void test1()
//{
//	MyInteger a;
//	cout<< a++ << endl;
//	cout<< ++a << endl;
//}
//int main()
//{
//	test1();
//	return 0;
//}
//#include <iostream>
//
//class Person {
//public:
//    Person(int age) : m_Age(new int(age)) {}
//
//    // Copy assignment operator
//    Person& operator=(const Person& p) {
//        if (this == &p) // Self-assignment check
//            return *this;
//
//        // Deallocate existing memory
//        if (m_Age != nullptr) {
//            delete m_Age;
//            m_Age = nullptr;
//        }
//
//        // Allocate new memory and copy data
//        if (p.m_Age != nullptr) {
//            m_Age = new int(*p.m_Age);
//        }
//
//        return *this;
//    }
//
//    ~Person() {
//        delete m_Age;
//    }
//
//    int* m_Age;
//};
//
//int main() {
//    Person p1(18);
//    Person p2(20);
//    Person p3 = p2 = p1;
//    std::cout << "p1: " << *(p1.m_Age) << std::endl;
//    std::cout << "p2: " << *(p2.m_Age) << std::endl;
//    std::cout << "p3: " << *(p3.m_Age) << std::endl;
//
//    return 0;
//}
//#include<iostream>
//#include<string>
//using namespace std;
//class Person {
//private:
//	string name;
//	int age;
//public:
//	Person(string a,int b):name(a),age(b) {}
//	bool operator==(const Person ptr)
//	{
//		if (this->age == ptr.age)
//		{
//			return true;
//		}
//		else
//			return false;
//	}
//	bool operator<(const Person p)
//	{
//		if (this->age < p.age)
//		{
//			return true;
//		}
//		else
//			return false;
//	}
//	bool operator>(const Person p)
//	{
//		if (this->age > p.age)
//		{
//			return true;
//		}
//		else
//			return false;
//	}
//};
//
//void test1()
//{
//	Person p1{ "Tom",18 };
//	Person p2{ "Tom",18 };
//	Person p3{ "Marry",19 };
//	if (p1 == p2)
//	{
//		cout << "=="<<endl;
//		
//	}
//	if (p1 < p3)
//	{
//		cout << "<"<<endl;
//
//	}
//	if (p3 > p2)
//	{
//		cout << ">"<<endl;
//	}
//}
//int main()
//{
//	test1();
//	return 0;
//}

//#include<iostream>
//#include<string>
//using namespace std;
//class Myprint {
//public:
//	void operator()(const string& a)
//	{
//		cout << a << endl;
//	}
//};
//
//void test()
//{
//	Myprint a;
//	a("hello world");
//}
//int main()
//{
//	test();
//	return 0;
//}
//#include<iostream>
//#include<string>
//using namespace std;
//class Father {
//public:
//	static int a;
//};
// int Father::a = 0;
// class Son :public Father {
// public:
//	 static int a;
//};
// int Son::a = 1;
// void test()
// {
//	 cout << Father::a << endl;
//	 cout << Son::a << endl;
//	 cout << Son::Father::a << endl;
// }
// int main()
// {
//	 test();
//	 return 0;
// }
//#include<iostream>
//#include<string>
//using namespace std;
//class Animal {
//public:
//	virtual void speak()
//	{
//		cout << "Animal" << endl;
//	}
//	
//};
//class Cat :public Animal {
//public:
//	void speak()
//	{
//		cout << "Cat" << endl;
//	}
//};
//class Dog :public Animal {
//public:
//	void speak()
//	{
//		cout << "Dog" << endl;
//	}
//};
//void test()
//{
//	Animal animal;
//	animal.speak();
//	Cat cat;
//	cat.speak();
//	Dog dog;
//	dog.speak();
//}
//int main()
//{
//	test();
//	return 0;
//}
//#include<iostream>
//#include<string>
//using namespace std;
//class calcutor {
//public:
//	int a;
//	int b;
//	void get(int x, int y)
//	{
//		a = x;
//		b = y;
//}
//};
//class Multitly: public calcutor{
//public:
//	int  mu()
//	{
//		return a * b;
//}
//};
//class Div :public calcutor {
//public:
//	int div()
//	{
//		return a / b;
//	}
//};
//class Add :public calcutor
//{
//public:
//	int add()
//	{
//		return a + b;
//	}
//};
//class Sub :public calcutor
//{
//public:
//	int sub()
//	{
//		return a - b;
//	}
//};
//void test1()
//{
//	Add a;
//	a.get(12, 3);
//	cout << a.add() << endl;
//	Div b;
//	b.get(12, 4);
//	cout << b.div() << endl;
//
//
//}
//int main()
//{
//	test1();
//	return 0;
//}

//#include<iostream>
//#include<string>
//using namespace std;
//class Abstractdrinking {
//public:
//	virtual void Boil() = 0;
//	virtual void Brew() = 0;
//	virtual void Pourincup() = 0;
//	virtual void Putsomething() = 0;
//	void makerDrink()
//	{
//		Boil();
//		Brew();
//		Pourincup();
//		Putsomething();
//		cout << "Finish" << endl;
//	}
//};
//class Coffee :public Abstractdrinking
//{
//public:
//	virtual void Boil()
//	{
//		cout << "lufu" << endl;
//	}
//	virtual void Brew()
//	{
//		cout << "brew coffee" << endl;
//	}
//	virtual void Pourincup()
//	{
//		cout << "pour in cup" << endl;
//	}
//	virtual void Putsomething()
//	{
//		cout << "input sugar" << endl;
//	}
//};
//class Tea :public Abstractdri nking {
//	virtual void Boil() {
//		cout << "yibao" << endl;
//	}
//	virtual void Brew() {
//		cout << "intput tea in cup" << endl;
//	}
//	virtual void Pourincup() {
//		cout << "input in cup all" << endl;
//	}
//	virtual void Putsomething() {
//		cout << "input milk" << endl;
//	}
//};
//void Dowork(Abstractdrinking* abs)
//{
//	abs->makerDrink();
//	delete abs;
//}
//void test()
//{
//	Dowork(new Coffee);
//	cout << "____________________" << endl;
//	Dowork(new Tea);
//}
//int main()
//{
//	test();
//	return 0;
//}
//#include<iostream>
//#include<string>
//using namespace std;
//class Cpu {
//public:
//	virtual void caculate() = 0;
//};
//class Videocar {
//public:
//	virtual void display() = 0;
//};
//class Memory {
//public:
//	virtual void storge() = 0;
//};
//class Computer {
//public:
//	Computer(Cpu* cpu, Videocar* vc, Memory* st)
//	{
//		m_cpu = cpu;
//		m_vc = vc;
//		m_st = st;
//	}
//	void work()
//	{
//		m_cpu->caculate();
//		m_vc->display();
//		m_st->storge();
//	}
//	~Computer()
//	{
//		if (m_cpu != nullptr)
//		{
//			delete m_cpu;
//			m_cpu = nullptr;
//		}
//		if (m_vc != nullptr)
//		{
//			delete m_vc;
//			m_vc = nullptr;
//		}
//		if (m_st != nullptr)
//		{
//			delete m_st;
//			m_st = nullptr;
//		}
//	}
//private:
//	Cpu* m_cpu;
//	Videocar* m_vc;
//	Memory* m_st;
//};
//class Intelcpu :public Cpu {
//public:
//	void caculate()
//	{
//		cout << "Intelcpu start work" << endl;
//	}
//};
//class Intelvideocar :public Videocar
//{
//public:
//	void display()
//	{
//		cout << "IntelGPU is starting work" << endl;
//	}
//};
//class Intelmemory :public Memory {
//public:
//	void storge()
//	{
//		cout << "IntelMemory is starting woork" << endl;
//	}
//};
//class Lenovecpu :public Cpu {
//public:
//	void caculate()
//	{
//		cout << "Lenovecpu start work" << endl;
//	}
//};
//class Lenovevideocar :public Videocar
//{
//public:
//	void display()
//	{
//		cout << "LenoveGPU is starting work" << endl;
//	}
//};
//class Lenovememory :public Memory {
//public:
//	void storge()
//	{
//		cout << "LenoveMemory is starting woork" << endl;
//	}
//};
//
//void test()
//{
//	Cpu* intelcpu = new Intelcpu;
//	Videocar* ivc = new Intelvideocar;
//	Memory* mem = new Intelmemory;
//	Computer* computer1 = new Computer(intelcpu, ivc, mem);
//	computer1->work();
//	cout << "------------------" << endl;
//	delete computer1;
//	Computer* computer2 = new Computer(new Lenovecpu, new Lenovevideocar, new Lenovememory);
//	computer2->work();
//}
//int main()
//{
//	test();
//	return 0;
//}
// 
// 
// 
// 
// 
// 
// 
//                                          ÎÄ¼þ²Ù×÷
//#include<iostream>
//#include<fstream>
//using namespace std;
// void test()
//{
//	 ofstream a;
//	 a.open("test.txt", ios::out);
//	 for (int i = 0; i < 32; i++)
//	 {
//		 for (int j = 0; j < 23; j++)
//		 {
//			 a << j << endl;
//		}
//		 cout << endl;
//	 }
//	 a.close();
//	 
//}
// int main()
// {
//	 test();
//	 return 0;
// }
//#include<iostream>
//#include<string>
//#include<fstream>
//using namespace std;
//void test()
//{
	//int arr[1024] = { 0 };
	/*ifstream b;
	b.open("test.txt", ios::in);
	if (!b.is_open())
	{
		cout << "fail" << endl;
	}*/
	/*string buf;
	while (getline(b, buf))
	{
		cout << buf<<endl;
	}*/
	/*while (b >> arr[0])
	{
		cout << arr[0] << endl;
	}*/
	/*b.close();



}
int main()
{
	test();
		return 0;
}*/
//#include<iostream>
//#include<fstream>
//using namespace std;
//class Person {
//public:
//	
//	char name[22];
//	int age;
//};
//void test()
//{
//	ofstream a("test.txt", ios::out | ios::trunc | ios::binary);
//	Person b = { "zhangsan",18 };
//	a.write((const char*)&b, sizeof(b));
//	a.close();
//}
//int main()
//{
//	test();
//	return 0;
//}
//
//#include<iostream>
//#include<fstream>
//using namespace std;
//class Person {
//public:
//	char name[22];
//	int age;
//};
//void test()
//{
//	ifstream b;
//	b.open("test.txt", ios::in | ios::binary);
//	if (!b.is_open())
//	{
//		cout << "fail" << endl;
//		exit(1);
//	}
//	Person c;
//	b.read((char*)&c, sizeof(c));
//	cout << c.name << "  " << c.age << endl;
//	b.close();
//}
//int main()
//{
//	test();
//	return 0;
//}

