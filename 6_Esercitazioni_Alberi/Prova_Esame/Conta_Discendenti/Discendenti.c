#include <stdio.h>
#include "tree_int.h"

void ContaElem(Node *t, ElemType *ndis) {
	if (IsEmptyTree(t)) {
		return;
	}
	else {
		++(*ndis);
	}
	ContaElem(LeftTree(t), ndis);
	ContaElem(RightTree(t), ndis);
}

void ContaRec(Node *t, ElemType ndis) {
	if (IsLeafTree(t)) {
		return;
	}
	else {
		ContaElem(t, &ndis);
		--ndis;
		if (t->value > ndis) {
			printf("%d\t", t->value);
		}
	}
	ContaRec(LeftTree(t), ndis); //mostra i discendenti di sinistra
	ContaRec(RightTree(t), ndis); //mostra i discendenti di destra
}

void app(Node *t) {
	ElemType s = 0;
	ContaRec(t, s);
	return;
}

int main() {

	ElemType v[] = { 0,1,2,3,4,5,6,7,8,9,10,11 };
	Node *n = CreateRootTree(&v[5],
		CreateRootTree(&v[11],
			CreateRootTree(&v[2], CreateEmptyTree(), CreateEmptyTree()),
			CreateRootTree(&v[8], CreateEmptyTree(), CreateEmptyTree())
		),
		CreateRootTree(&v[10],
			CreateEmptyTree(), CreateEmptyTree())
	);
	app(n);

}