#include <stdio.h>

#pragma warning(disable:4996)
#define Namemax 100
#define Gndermax 100
#define Telmax 100
#define Addrmax 100
#define N 100

typedef struct personinfo {
	char name[Namemax];
	int age;
	char gender[Gndermax];
	char tel[Telmax];
	char addr[Addrmax];
}Info;
typedef struct Info SLdatatype;
typedef struct Seqlist
{
	SLdatatype* arr;
	int size;
	int capacity;
}SL;
int main()
{
	SL e;
	int a = 0;
	scanf("%d", &a);
	return 0;
}