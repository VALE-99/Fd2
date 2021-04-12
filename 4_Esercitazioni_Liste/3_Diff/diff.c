#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "list_int.h"
#include <stdlib.h>

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

bool ContainsNoPrimitives(const Item *i, const ElemType *e) {

	bool found = false;

	while (i != NULL && !found) { //i != null è come dire finchè la lista non è vuota
		
		//setto found = 1 se il valore dell'elemento corrente della lista "i" è uguale all'emento che sto cercando
		found = (i->value == *e);	

		i = i->next; // mi sposto all'elemento successivo della lista
	}
	return found; //ritorno il valore di found -> se ho trovato l'elemento la variabile "found" sarà uguale a 1
}

Item* Diff(const Item* i1, const Item* i2) {

	Item *r = NULL;

	while (i1) {
		ElemType cur = i1->value; //imposto in cur il valore di testa di i1
		if (!ContainsNoPrimitives(i2, &cur)) {	//se l'elemento non è contenuto in lista lo aggiungo alla lista nuova
			Item *new_i = malloc(sizeof(Item)); //creo nuova lista
			new_i->value = cur;	//imposto il valore corrente dell'elemento della lista
			new_i->next = r; //imposto il valore successivo a NULL
			r = new_i; //creo in next un'altra "malloc" (espando la lista)
		}
		i1 = i1->next;	// mi sposto all'elemento successivo della lista
	}
	return r; //ritorno la nuova lista
}

int main(void) {

	Item *i1 = LoadList("data_00.txt");	//Carico la lista su i1
	Item *i2 = LoadList("data_02.txt"); //Carico la lista su i2
	Item *i3 = Diff(i1, i2); //chiamo la funzione Diff sulle lista i1, i2
	WriteStdoutList(i3);	//stampo la nuova lista
	DeleteList(i1);	//elimino la lista
	DeleteList(i2);
	DeleteList(i3);
}