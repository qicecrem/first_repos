#pragma once
#include"seqlist.h"
#define Namemax 100
#define Gndermax 100
#define Telmax 100
#define Addrmax 100
typedef struct Seqlist Contact;

typedef struct personinfo {
	char name[Namemax];
	int age;
	char gender[Gndermax];
	char tel[Telmax];
	char addr[Addrmax];
}Info;

void Contactinit(Contact* p);

void Contactadd(Contact* p);
void Contactdel(Contact* p);
void  Contactfindn(Contact* p);
void Contactshow(Contact* p);
void Contactmodify(Contact* p);
void menu();
