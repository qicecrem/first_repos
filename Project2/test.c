#include"seqlist.h"
void test1()
{
	SL s1;
	SLinit(&s1);
	SLpushback(&s1, 1);
	SLprint(&s1);
	SLpushback(&s1, 3);
	SLprint(&s1);
	SLpushback(&s1, 3);
	SLprint(&s1);
	SLpushback(&s1, 3); 
	SLpushback(&s1, 3); 
	SLprint(&s1);

}
void test2()
{
	SL s1;
	SLinit(&s1);
	SLpushfront(&s1, 1);
	SLpushback(&s1, 2);
	SLprint(&s1);
	SLpushback(&s1, 3);
	SLprint(&s1);
	SLpushback(&s1, 4);
	SLprint(&s1);
	SLpushback(&s1, 5);
	SLpushback(&s1, 6);
	SLprint(&s1);
	SLpopback(&s1);
	SLprint(&s1);
	SLpopfront(&s1);
	SLprint(&s1);
	SLinsert(&s1, 4, 9);
	SLerase(&s1, 3);
	SLprint(&s1);
	

}
int main()
{
	//test1();
	test2();
	return 0;
}  