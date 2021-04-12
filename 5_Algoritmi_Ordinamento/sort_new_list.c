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
	
	while (!IsEmptyList(l))
	{
		Item *l2 = l;
		l2 = GetTailList(l2);
		while (!IsEmptyList(l2))
		{
			if (ElemCompare(GetHeadValueList(l), GetHeadValueList(l2))>0)
			{
				ElemType t = ElemCopy(GetHeadValueList(l));
				l->value = ElemCopy(GetHeadValueList(l2));
				l2->value = ElemCopy(&t);

			}
			l2 = GetTailList(l2);


		}
		l = GetTailList(l);

	}
	return l;


}