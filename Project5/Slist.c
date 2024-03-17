#include"Slist.h"

void Slprint(SLN* phead) {
	SLN* p = phead;
	while (p) {
		printf("%d->", p->data);
		p = p->next;
	}
	printf("NULL\n");
}
void Slpushback(SLN** pphead, Sldatatype x) {
	assert(pphead);
	SLN* newnode = (SLN*)malloc(sizeof(SLN));
	newnode->data = x;
	newnode->next = NULL;
	SLN* ptail = *pphead;
	if (*pphead == NULL) {
		*pphead = newnode;
		return;
	}
	while (ptail->next) {
		ptail = ptail->next;
	}
	ptail->next = newnode;
}
void Slpushfront(SLN** pphead, Sldatatype x) {
	assert(pphead);
	SLN* newnode = (SLN*)malloc(sizeof(SLN));
	newnode->data = x;
	newnode->next = *pphead;
	*pphead = newnode;
}
void Slpopback(SLN** pphead) {
	assert(pphead);
	assert(*pphead);
	if ((*pphead)->next == NULL) {
		free(*pphead);
		*pphead = NULL;
		return;
	}
	SLN* ptail = *pphead;
	SLN* prev = NULL;
	while (ptail->next) {
		prev = ptail;
		ptail = ptail->next;
	}
	prev->next = NULL;
	free(ptail);
	ptail = NULL;


 }
SLN* Slbuynode(Sldatatype x) {
	SLN* newnode = (SLN*)malloc(sizeof(SLN));
	if (newnode == NULL) {
		perror("fail");
		exit(1);
	}
	newnode->data = x;
	newnode->next = NULL;
	return newnode;
}
void Slpopfront(SLN** pphead) {
	assert(pphead);
	assert(*pphead);
	SLN* p = (*pphead)->next;
	free(*pphead);
	*pphead = p;
}
SLN* Slfind(SLN** pphead, Sldatatype x) {
	assert(pphead);
	SLN* pcur = *pphead;
	while (pcur) {
		if (pcur->data == x) {
			return pcur;
		}
		pcur = pcur->next;
	}
	return NULL;
} 
void Slinsert(SLN** pphead, SLN* pos, Sldatatype x) {
	assert(pphead);
	assert(pos);
	assert(*pphead);
	SLN* newnode = Slbuynode(x);
	if (pos == *pphead) {
		Slpushfront(pphead, x);
		return;
	}
	SLN* pre = *pphead;
	while (pre->next != pos)
	{
		pre = pre->next;
	}
	pre->next = newnode;
	newnode->next = pos;
}
void Slinsertafter(SLN* pose, Sldatatype x) {
	assert(pose);
	SLN* newnode = Slbuynode(x);
	newnode->next = pose->next;
	pose->next = newnode;
}
void Slerase(SLN** pphead, SLN* pose) {
	assert(pose);
	assert(*pphead);
	assert(pphead);
	SLN* pre = *pphead;
	if (pose == *pphead) {
		Slpopfront(pphead);
		return;
	}
	while (pre->next != pose) {
		pre = pre->next;

	}
	pre->next = pose->next;
	free(pose);
	pose = NULL;

}
void Sleraseafter(SLN* pose) {
	assert(pose);
	assert(pose->next);
	SLN* del = pose->next;
	pose->next = pose->next->next;
	free(del);
	del = NULL;
}
void Slistdestory(SLN** pphead) {
	assert(pphead);
	assert(*pphead);
    SLN* pcur = *pphead;
	while (pcur) {
		SLN* next = pcur->next;
		free(pcur);
		pcur = next;
	}
	*pphead = NULL;
}