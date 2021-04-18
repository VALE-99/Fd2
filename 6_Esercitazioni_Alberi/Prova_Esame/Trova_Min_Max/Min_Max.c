#include "tree_int.h"
#include <stdlib.h>
#include <stdio.h>

void TreeMinRec(const Node *n,  ElemType *min) {

	if (IsEmptyTree(n)) {
		return;
	}

	if (ElemCompare(GetRootValueTree(n), min) < 0) {
		*min = n->value;
	}

	TreeMinRec(n->left, min);
	TreeMinRec(n->right, min);

}

ElemType TreeMin(const Node *n) {

	ElemType *min = GetRootValueTree(n);
	TreeMinRec(n, min);
	return *min;
}



// trova maggiore
void TreeMaxRec(const Node *n, ElemType *max) {

	if (IsEmptyTree(n)) {
		return;
	}

	if (ElemCompare(GetRootValueTree(n), max) > 0) {
		*max = n->value;
	}

	TreeMaxRec(RightTree(n), max);
	TreeMaxRec(LeftTree(n), max);

}

ElemType TreeMax(const Node *n) {

	if (IsEmptyTree(n)) {
		return 0;
	}

	ElemType *max = GetRootValueTree(n);
	TreeMaxRec(n, max);
	return *max;
}



int main(void) {
	//cerca minore
	ElemType v[] = { 0,1,2,3,4,5,6,7,8,9,10,11 };
	Node *n = CreateRootTree(&v[5],
		CreateRootTree(&v[11],
			CreateRootTree(&v[2], CreateEmptyTree(), CreateEmptyTree()),
			CreateRootTree(&v[8], CreateEmptyTree(), CreateEmptyTree())
		),
		CreateRootTree(&v[10],
			CreateEmptyTree(), CreateEmptyTree())
	);
	
	ElemType minore = TreeMin(n);
	printf("minore: ");
	WriteStdoutElem(&minore);
	DeleteTree(n);

	//cerca maggiore
	ElemType e[] = { 0,1,2,3,4,5,6,7,8,9,10,11 };
	Node *t = CreateRootTree(&e[5],
		CreateRootTree(&e[11],
			CreateRootTree(&e[2], CreateEmptyTree(), CreateEmptyTree()),
			CreateRootTree(&e[8], CreateEmptyTree(), CreateEmptyTree())
		),
		CreateRootTree(&e[10],
			CreateEmptyTree(), CreateEmptyTree())
	);

	printf("\n");
	printf("maggiore:");
	ElemType maggiore = TreeMax(n);
	WriteStdoutElem(&maggiore);
	DeleteTree(n);

}