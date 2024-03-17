#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int Lidatatype;
typedef struct ListNode {
	Lidatatype data;
	struct ListNode* prev;
	struct ListNode* next;
}LN;
void Ltinit(LN** pphead);
void Ldestory(LN** pphead); 
LN* Linit();
void Lpushback(LN* phead, Lidatatype x);
void Lpushfront(LN* phead, Lidatatype x);
void Lprint(LN* phead);
void Lpopback(LN* phead);
void Lpopfront(LN* phead);
void Linsert(LN* pos, Lidatatype x);
void Lerase(LN* pos);
LN* Lifind(LN* phead, Lidatatype x);