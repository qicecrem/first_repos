#include"seqlist.h"
void SLinit(SL* p) {
	p->arr = NULL;
	p->size = p->capacity = 0;
}
void SLprint(SL* p) {
	for (int i = 0; i < p->size; i++)
	{
		printf("%d", *(p->arr + i));
	}
	printf("\n");
}
void SLpushback(SL* p,SLdatatype x) 
{
	assert(p);
	SLcheck(p);
	*(p->arr + p->size) = x;
	p->size++;
}
void SLcheck(SL* p) {
	if (p->size == p->capacity)
	{
		int newcapacity = (p->capacity == 0) ? 4 : 2 * p->capacity;
		SLdatatype* tmp = (SLdatatype*)realloc(p->arr, newcapacity * sizeof(SLdatatype));
		if (tmp == NULL)
		{
			perror("realloc fai;");
			exit(1);
		}
		p->arr = tmp;
		p->capacity = newcapacity;
	}

}
void SLpushfront(SL* p, SLdatatype x) {
	assert(p);
	SLcheck(p);
	for (int i = p->size;i>0;i--)
	{
		p->arr[i] = p->arr[i - 1];
	}
	p->arr[0] = x;
	p->size++;
}
void SLpopback(SL* p) {
	assert(p);
	assert(p->size);
	p->size--;
}
void SLpopfront(SL* p) {
	assert(p);
	assert(p->size);
	for (int i = 0; i < p->size - 1; i++)
	{
		p->arr[i] = p->arr[i + 1];
	}
	p->size--;
}
void SLinsert(SL* p, int pose, SLdatatype x) {
	assert(p);
	assert(pose >= 0 && pose <= p->size);
	for (int i = pose; i <p-> size ; i++)
	{
		p->arr[i + 1] = p->arr[i];
	}
	p->arr[pose] = x;
	p->size++;
}
void SLerase(SL* p, int pose) {
	assert(p);
	assert(pose >= 0 && pose < p->size);
	for (int i = pose; i < p->size-1; i++)
	{
		p->arr[i] = p->arr[i + 1];
	}
	p->size--;
}