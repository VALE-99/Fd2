#define _CRT_SECURE_NO_WARNINGS
#include "list_int.h"
#include <stdio.h>
#include <stdbool.h>

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

bool contains(const Item *i, const ElemType *e) { 
	bool found = false; //set found to false
	while (!IsEmptyList(i) && !found) { //until empty list "i" or found become true
		found = (ElemCompare(GetHeadValueList(i), e) == 0); //modify "found" value if we find the same value inside the list
		i = GetTailList(i);	////move to next Item of list i1
	}
	return found; //return found value

}
Item* Intersect(const Item* i1, const Item* i2) {

	Item *i3 = CreateEmptyList();	//create new list

	while (!IsEmptyList(i1)) {	//until list i1 is empty
		const ElemType *cur = GetHeadValueList(i1); //set cur to head value list i1
		if (contains(i2, cur)) { //call functions contains
			i3 = InsertHeadList(GetHeadValueList(i1), i3);//insert "cur" value if contains return true
		}
		i1 = GetTailList(i1); //move to next Item of list i1
	}




	return i3;
}

int main(void) {
	Item *i1 = LoadList("data_00.txt");
	WriteStdoutList(i1);
	Item *i2 = LoadList("data_01.txt");
	WriteStdoutList(i2);
	Item *f = Intersect(i1, i2);
	WriteStdoutList(f);
	DeleteList(f);


}