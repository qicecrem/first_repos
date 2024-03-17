#pragma once
#include<stdio.h>
#include<assert.h>
//jingtai
#define N 100
typedef int sldatatype;
struct SeqList
{
	sldatatype a[N];
	int size;
	
};
//dong tai
typedef struct Seqlist
{
	sldatatype* p;
	int size;
	int capacity;
}SL;

void SLinit(SL* s1);
void SLdestroy(SL* s1);
void SLprint(SL* s1);
void SLcheck(SL* s1);
void SLpushback(SL* s1, sldatatype x);
void SLpopback(SL* s1);
void SLpopfront(SL* s1);
void SLpushfront(SL* s1, sldatatype x);
void SLinsert(SL* s1, int pos, sldatatype x);
void SLerase(SL* ps, int pos);

