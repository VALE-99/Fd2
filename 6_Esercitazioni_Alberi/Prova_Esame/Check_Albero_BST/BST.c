#include "tree_int.h"

void visit(Node *tree, int *is_it) {
	
	if (!tree || (is_it) == 0) //controlla che l'albero non sia NULL
		return;

	//caso solo figlio destro
	if (!tree->left && tree->right) { //se non c'è il valore di sinistro, ma solo quello di destra
		if (tree->right->value < tree->value) { //controllo figlio destro minore del padre, nel caso esco
			*is_it = 0;
			return;
		}
	}
	
	//caso solo figlio sinistro
	if (tree->left && !tree->right) { // se abbiamo solo figlio sinistro
		if (tree->left->value > tree->value) { //controlliamo che il figlio sinistro sia maggiore del padre, nel caso torniamo
			*is_it = 0;
			return;
		}
	}

	//caso abbiamo tutti e due i figli
	if (tree->left && tree->right) { 
		if (tree->left->value > tree->value) { //controllo il sinitro
			*is_it = 0;
			return;
		}
		if (tree->right->value < tree->value) {
			*is_it = 0;
			return;
		}

	}
	
	visit(LeftTree(tree), is_it);
	visit(RightTree(tree), is_it);
}

int is_bst(Node *tree) {
	int is_it = 1;
	visit(tree, &is_it);
	return is_it;
}


int main() {
	ElemType v[] = { 0, 1,2,3,4,5,6,7,8,9,10,11 }; // valori
	Node *n = CreateRootTree(&v[5], //valore per il nodo
		CreateRootTree(&v[4],
			CreateRootTree(&v[2], CreateEmptyTree(), CreateEmptyTree()),
			CreateRootTree(&v[8], CreateEmptyTree(), CreateEmptyTree())
		),
		CreateRootTree(&v[10], CreateEmptyTree(), CreateEmptyTree())
	);

	is_bst(n);
}