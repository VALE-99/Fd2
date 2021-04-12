#include "list_int2.h"
extern Item *loadlist(ElemType *v, size_t n);
extern Item *SortList(Item *l);

int main2(void)
{
	ElemType v[] = { 2,3,1,4,6,5 };
	size_t n = sizeof(v) / sizeof(ElemType);
	Item *l = loadlist(v, n);
	SortList(l);
	return 0;

}