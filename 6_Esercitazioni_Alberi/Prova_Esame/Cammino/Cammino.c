#define _CRT_SECURE_NO_WARNINGS
#include "tree_int.h"
// #include "stampa.albero.h"
#include <stdio.h>

Node *creazione(Node *t, ElemType *e) {
	if (IsEmptyTree(t)) {
		return CreateRootTree(e, CreateEmptyTree(), CreateEmptyTree());
	}

	if (ElemCompare(e, GetRootValueTree(t)) <= 0) {
		return CreateRootTree(GetRootValueTree(t), creazione(LeftTree(t), e), RightTree(t));
	}
		else {
		return CreateRootTree(GetRootValueTree(t), LeftTree(t), creazione(RightTree(t), e));
		}
}

Node *ricerca(Node *t, ElemType *e) {
	if (ElemCompare(e, GetRootValueTree(t)) == 0) {
		return t;
	}

	if (ElemCompare(e, GetRootValueTree(t)) < 0) {
		return ricerca(LeftTree(t), e);
	}
	else {
		return ricerca(RightTree(t), e);
	}
}

void stampa(Node *t) {
	if (IsEmptyTree(t)) {
		return;
	}
	if(IsLeafTree(t)) {
		return;
	}
	printf("%d", t->value);
	stampa(LeftTree(t));
	stampa(RightTree(t));
}

int main() {

	ElemType v[] = { 1, 7, 8, 6, 2, 5 };
	Node *n = CreateRootTree(&v[5],CreateEmptyTree(), CreateEmptyTree());
	creazione(n, v);

	ElemType e[] = { 0,1,2,3,4,5,6,7,8,9,10,11 };
	Node *t = CreateRootTree(&e[5],
		CreateRootTree(&e[11],
			CreateRootTree(&e[2], CreateEmptyTree(), CreateEmptyTree()),
			CreateRootTree(&e[8], CreateEmptyTree(), CreateEmptyTree())
		),
		CreateRootTree(&e[10],
			CreateEmptyTree(), CreateEmptyTree())
	);

	stampa(t);
}