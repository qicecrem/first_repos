#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int Sldatatype;
typedef struct  SlistNode {
	Sldatatype data;
	struct SlistNode* next;
}SLN;
void Slprint(SLN* p);
void Slpushback(SLN** phead, Sldatatype x);
void Slpushfront(SLN** phead, Sldatatype x);
void Slpopfront(SLN** pphead);
void Slpopback(SLN** pphead);
SLN* Slfind(SLN** pphead, Sldatatype x);
void Slinsert(SLN** pphead, SLN* pos, Sldatatype x);
void Slinsertafter(SLN* pos, Sldatatype x);
void Slerase(SLN** pphead, SLN* pos);
void Sleraseafter(SLN* pos);
void Slistdestory(SLN** pphead);