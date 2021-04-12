#define _CRT_SECURE_NO_WARNINGS
#include "list_int.h"
#include <stdio.h>

Item* LoadList(const char *filename) {

	FILE *f = fopen(filename, "r");

	Item *i = CreateEmptyList();

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


int main(void) {


	Item *f = LoadList("data_00.txt");
	WriteStdoutList(f);
	return;
}