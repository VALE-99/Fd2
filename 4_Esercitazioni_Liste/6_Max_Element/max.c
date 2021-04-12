#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "list_int.h"

Item *LoadList(const char *filename) {

	Item *i = CreateEmptyList();

	FILE *f = fopen(filename, "r");

	if (!f) {
		return i;
	}

	ElemType tmp;

	while (1) {
		if (1 != fscanf(f, "%i", &tmp)) {
			break;
		}

		i = InsertHeadList(&tmp, i);
	}
	  
	fclose(f);
	return i;
}

ElemType MaxElement(const Item* i) {

	const ElemType *max;
	max = GetHeadValueList(i);
	i = GetTailList(i);

	while (!IsEmptyList(i)) {

		if (ElemCompare(max,GetHeadValueList(i))== -1) {
			max = GetHeadValueList(i);
			}
	i = GetTailList(i);
	}

	return *max;
}


int main(void) {

	Item *i1 = LoadList("data_00.txt");
	ElemType ris = MaxElement(i1);
	WriteStdoutElem(&ris);
	DeleteList(i1);
	ElemDelete(&ris);
}
