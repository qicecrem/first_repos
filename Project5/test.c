#include"Slist.h"
void test1()
{
		SLN* node1 = (SLN*)malloc(sizeof(SLN));
		node1->data = 1;
		SLN* node2 = (SLN*)malloc(sizeof(SLN));
		node2->data = 2;
		SLN* node3 = (SLN*)malloc(sizeof(SLN));
		node3->data = 3;
		SLN* node4 = (SLN*)malloc(sizeof(SLN));
		node4->data = 4;
		node1->next = node2;
		node2->next = node3;
		node3->next = node4;
		node4->next = NULL;
		Slprint(node1);
		Slpopback(&node1);
		Slprint(node1);
}

int main()
{
	test1();
	return 0;
}