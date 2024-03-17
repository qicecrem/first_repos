#include"List.h"
void Ltinit(LN** pphead) {
	*pphead = (LN*)malloc(sizeof(LN));
	if (*pphead == NULL) {
		perror("error");
		exit(1);
	}
	(*pphead)->data = -11;
	(*pphead)->next = (*pphead)->prev = *pphead;
}
LN* Linit()
{
	LN* pphead = (LN*)malloc(sizeof(LN));
	if (pphead == NULL) {
		perror("error");
		exit(1);
	}
	(pphead)->data = -11;
	(pphead)->next = (pphead)->prev = pphead;
	return pphead;

}
LN* Lbuynode(Lidatatype x) {
	LN* newnode = (LN*)malloc(sizeof(LN));
	if (newnode == NULL) {
		perror("error");
		exit(1);
	}
	newnode->data = x;
	newnode->next = newnode->prev = newnode;
	return newnode;
}
void Lpushback(LN* phead, Lidatatype x) {
	assert(phead);
	LN* newnode = Lbuynode(x);
	newnode->next = phead;
	newnode->prev = phead->prev;
	phead->prev->next = newnode;
	phead->prev = newnode;

}
void Lprint(LN* phead) {
	assert(phead);
	LN* pcur = phead->next;
	while (pcur != phead) {
		printf("%d->", pcur->data);

	}
	printf("\n");
}
void Lpushfront(LN* phead, Lidatatype x) {
	assert(phead);
	LN* newnode = Lbuynode(x);
	newnode->next = phead->next;
	newnode->prev = phead;
	phead->next->prev = newnode;
	phead->next = newnode;
}
void Lpopback(LN* phead) {
	assert(phead);
	assert(phead->next != phead);
	LN* del = phead->prev;
	phead->prev->prev->next = phead;
	phead->prev = phead->prev->prev;
	free(del);
	del = NULL;

}
void Lpopfront(LN* phead) {
	assert(phead);
	assert(phead->next != phead);
	LN* del = phead->next;
	phead->next->next->prev = phead;
	phead->next = phead->next->next;
	free(del);
	del = NULL;
}
LN* Lifind(LN* phead, Lidatatype x) {
	assert(phead);
	LN* pcur = phead->next;
	while (pcur != phead) {
		if (pcur->data == x) {
			return pcur;
		}
		pcur = pcur->next;
	}
	return NULL;
}
void Linsert(LN* pos, Lidatatype x) {
	assert(pos);
	LN* newnode = Lbuynode(x);
	newnode->next = pos->next;
	newnode->prev = pos;
	pos->next ->prev = newnode;
	pos->next = newnode;

}
void Lerase(LN* pos) {
	assert(pos);
	pos->next->prev = pos->prev;
	pos->prev->next = pos->next;
	free(pos);
	pos = NULL;
}
void Ldestory(LN** pphead) {
	assert(pphead);
	assert(*pphead);
	LN* pcur = (*pphead)->next;
	while (pcur != *pphead) {
		LN* next = pcur->next;
		free(pcur);
		pcur = next;
	}
	free(*pphead);
	*pphead = NULL;
}