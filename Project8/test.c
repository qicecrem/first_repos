#include"snack.h"
void test()
{
	int ch = 0;
	srand((unsigned int)time(NULL));
	do {
		Snake snake = { 0 };

		Gamestart(&snake);
		Gamerun(&snake);
		Gameend(&snake);
		Setpos(20, 15);
		printf("再来一局吗？(y/n)");
		ch = getchar();
		getchar();
	} while (ch=='y'||ch=='Y');
	Setpos(0, 26);

	
}

int main()
{

	setlocale(LC_ALL, "");
	test();
		return 0;
}