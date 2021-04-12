#include "list_int2.h"
#include <stdlib.h>
Item *loadlist(ElemType *v, size_t n)
{
	Item *l = CreateEmptyList();
	for (size_t i = 0; i < n; i++)
	{
		l = InsertBackList(l, &v[i]);
	}
	return l;
}
Item *SortList(Item *l)
{
	if (IsEmptyList(l))
	{
		return l;
	}
	Item *l2 = l;
	ElemType *v = malloc(sizeof(ElemType));
	 size_t cnt = 1;
	int i = 0;
	while (!IsEmptyList(l2))
	{
		v[i] = l2->value;
		++i;
		++cnt;
		v = realloc(v, sizeof(ElemType)*cnt);
		l2 = GetTailList(l2);
	}
	for ( size_t  i = 0; i <cnt; i++)
	{
		for (size_t j=i+1 ; j< cnt-1; j++)
		{
			if (v[i] > v[j])
			{
				ElemType tmp = v[i];
				v[i] = v[j];
				v[j] = tmp;

			}
		}
		
	}
	i = 0;
	while (!IsEmptyList(l))
	{
		l->value= ElemCopy(&v[i]);
		++i;
		l = GetTailList(l);


	}
	free(v);
	return l;


}