#define _CRT_SECURE_NO_WARNINGS
#include "list_int.h"
#include <stdio.h>

Item *LoadList(const char *filename) {

	Item *r = CreateEmptyList();

	FILE *f = fopen(filename, "r");
	if (!f) {
		return r;
	}

	ElemType tmp;
	while (1) {
		if (1 != fscanf(f, "%i", &tmp)) {
			break;
		}
		r = InsertHeadList(&tmp, r);
	}

	fclose(f);
	return r;
}

bool contains (const Item *i2, const ElemType *cur) {

	bool found = false;

	while (!found && !IsEmptyList(i2)) {
		if (ElemCompare(cur,GetHeadValueList(i2)) == 0) {
			found = true;
		}
		i2 = GetTailList(i2);
	}

	return found;

}

Item* DiffNoRep(const Item* i1, const Item* i2) {

	Item *i = CreateEmptyList();
	while (i1) {
		const ElemType *cur = GetHeadValueList(i1);
		if (contains(i2, cur)) {
			i = InsertHeadList(cur,i);
		}
	i1 = GetTailList(i1);
	}
	return i;
}

Item* IntersectNoRep(const Item* i1, const Item* i2) {

	Item* i3 = CreateEmptyList();

	while (!IsEmptyList(i1)) {
		const ElemType *cur = GetHeadValueList(i1);
		if (contains(i2, cur)) {
			i3 = InsertHeadList(cur, i3);
		}
		i1 = GetTailList(i1);
	}

	return i3;
}

int main(void) {
	
	{
		Item *i1 = LoadList("data_00.txt");
		Item *i2 = LoadList("data_01.txt");
		Item *ris = DiffNoRep(i1, i2);
		WriteStdoutList(ris);
		DeleteList(i1);
		DeleteList(i2);
		DeleteList(ris);
		printf("\n");
	}

	{
		Item *i1 = LoadList("data_00.txt");
		Item *i2 = LoadList("data_02.txt");
		Item *ris = DiffNoRep(i1, i2);
		WriteStdoutList(ris);
		DeleteList(i1);
		DeleteList(i2);
		DeleteList(ris);
		printf("\n");

	}

	{
		Item *i1 = LoadList("data_01.txt");
		Item *i2 = LoadList("data_02.txt");
		Item *ris = DiffNoRep(i1, i2);
		WriteStdoutList(ris);
		DeleteList(i1);
		DeleteList(i2);
		DeleteList(ris);
		printf("\n");

	}

	printf("\n");
	printf("\n");
	printf("INTERSECT:");
	printf("\n");
	printf("\n");

	{
		Item *i1 = LoadList("data_00.txt");
		Item *i2 = LoadList("data_01.txt");
		Item *ris = IntersectNoRep(i1, i2);
		WriteStdoutList(ris);
		DeleteList(i1);
		DeleteList(i2);
		DeleteList(ris);
		printf("\n");
	}

	{
		Item *i1 = LoadList("data_00.txt");
		Item *i2 = LoadList("data_02.txt");
		Item *ris = IntersectNoRep(i1, i2);
		WriteStdoutList(ris);
		DeleteList(i1);
		DeleteList(i2);
		DeleteList(ris);
		printf("\n");
	}

	{
		Item *i1 = LoadList("data_02.txt");
		Item *i2 = LoadList("data_01.txt");
		Item *ris = IntersectNoRep(i1, i2);
		WriteStdoutList(ris);
		DeleteList(i1);
		DeleteList(i2);
		DeleteList(ris);
		printf("\n");
	}
}