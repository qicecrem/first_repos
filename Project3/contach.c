#include"contach.h"

void menu() {
	printf("**************CONTACH*************\n");
	printf("************1.添加****************\n");
	printf("************2.删除****************\n");
	printf("************3.修改****************\n");
	printf("************4.查找****************\n");
	printf("************5.查看****************\n");
	printf("************6.退出****************\n");
}
void Contactinit(Contact* p) {
	SLinit(p);
}

void Contactadd(Contact* p) {
	Info info;
	printf("name:");
	scanf("%s", info.name);
	printf("age:");
	scanf("%d", &info.age);
	printf("gender:");
	scanf("%s", info.gender);
	printf("tel:");
	scanf("%s", info.tel);
	printf("address:");
	scanf("%s", info.addr);
	SLpushback(p, info);
}

int  Contactfind(Contact* p, char* name) {

	for (int i = 0; i < p->size; i++)
	{
		if (strcmp(p->arr[i].name, name) == 0) {
			return i;
		}
	}
	return -1;
}
void Contactdel(Contact* p) {
	printf("please input name:");
	char name[Namemax];
	scanf("%s", name);
	int findindex = Contactfind(p, name);
	if (findindex < 0) {
		printf("nothing\n");
		return;
	}
	SLerase(p, findindex);
	printf("sucess\n");

}
void Contactshow(Contact* p) {
	printf("%6s %6s %6s %6s %6s\n", "name", "gender", "age", "tel", "addr");
	for (int i = 0; i < p->size; i++)
	{
		printf("%6s %6s %6d %6s %6s\n", p->arr[i].name, p->arr[i].gender, p->arr[i].age, p->arr[i].tel, p->arr[i].addr);
	}
}
void Contactmodify(Contact* p) {
	char name[Namemax];
	printf("please input name\n");
	scanf("%s", name);

	int findex = Contactfind(p, name);
	if (findex < 0) {
		printf("nothing\n");
		return;
	}
	printf("input name:\n");
	scanf("%s", p->arr[findex].name);
	printf("input gender:\n");
	scanf("%s", p->arr[findex].gender);
	printf("input age\n");
	scanf("%d", p->arr[findex].age);
	printf("input tel\n");
	scanf("%s", p->arr[findex].tel);
	printf("input addr\n");
	scanf("%s", p->arr[findex].addr);
}
void  Contactfindn(Contact* p) {
	char name[Namemax];
	printf("please input name\n");
	scanf("%s", name);

	int findex = Contactfind(p, name);
	if (findex < 0) {
		printf("nothing\n");
		return;
	}
	printf("sucess");
	printf("%s %s %d %s %s\n", p->arr[findex].name, p->arr[findex].gender, p->arr[findex].age, p->arr[findex].tel, p->arr[findex].addr);
}
