#pragma once
#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<assert.h>
#include<stdlib.h> 
#include"contach.h"
#define N 100
typedef  struct personinfo SLdatatype;
typedef struct Seqlist
{
	SLdatatype* arr;
	int size;
	int capacity;
}SL;
void SLinit(SL* p);
void SLprint(SL* p);
void SLpushback(SL* p, SLdatatype x);
void SLpushfront(SL* p, SLdatatype x);
void SLpopback(SL* p);
void SLpopfront(SL* p);
void SLcheck(SL* p);
void SLinsert(SL* p, int pose, SLdatatype x);
void SLerase(SL* p, int pose);
