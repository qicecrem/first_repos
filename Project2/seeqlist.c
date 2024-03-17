#include"seqlist.h"
 
void SLinit(SL* ps) {
	ps->p = NULL;
	ps->size = ps->capacity = 0;

}
void SLdestroy(SL* ps)
{
	;
}
void SLcheck(SL* ps)
{
	if (ps->size == ps->capacity)
	{
		int newcapacity =( ps->capacity ==0 )? 4 : 2 * ps->capacity;
		sldatatype* tmp = (sldatatype*)realloc(ps->p, newcapacity * sizeof(sldatatype));
		if (tmp == NULL)
		{
			perror("realloc fail");
			exit(1);
		}
		//sucess
		
		ps->p = tmp;
		ps->capacity = newcapacity;
	}
}
void SLpushback(SL* ps, sldatatype x)
{
	//kong jian bu gou
	assert(ps != NULL);
	//space enough
	SLcheck( ps);
	ps->p[ps->size++] = x;


}
void SLpushfront(SL* ps, sldatatype x)
{
	assert(ps != NULL);
	SLcheck(ps);
	for (int i = ps->size; i > 0; i--)
	{
		*(ps->p + i) = *(ps->p) = *(ps->p + i - 1);
	}
	*(ps->p) = x;
	ps->size++;

}
void SLprint(SL* ps) {
	for (int i = 0; i < ps->size; i++)
	{
		printf("%d", *(ps->p + i));

	}
	printf("\n");
}

void SLpopback(SL* ps)
{
	assert(ps);
	assert(ps->size);
	ps->size--;
}
void SLpopfront(SL* ps)
{
	assert(ps);
	assert(ps->size);
	for (int i = 0; i < ps->size-1; i++)
	{
		*(ps->p + i ) = *(ps->p + i+1);
	}
	ps->size--;
}
void SLinsert(SL* ps, int pos, sldatatype x)
{
	assert(ps);
	assert(pos >= 0 && pos <= ps->size);
	SLcheck(ps);
	for (int i = ps->size; i > pos; i--)
	{
		*(ps->p + i) = *(ps->p + i - 1);
	}
	*(ps->p + pos) = x;
	ps->size++;
}
void SLerase(SL* ps, int pos)
{
	assert(ps);
	assert(pos >= 0 && pos < ps->size);
	for (int i = pos; i < ps->size - 1; i++)
	{
		*(ps->p + i) = *(ps->p + i + 1);
	}
	ps->size--;
}