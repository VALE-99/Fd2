#include "list_int.h"

struct node {

	int valore;
	struct node* prev;
	struct node* next;

}

void lista(node* head) {
	node *h = head; //assegno al puntatore la testa della lista
	while (!IsEmptyList(head)) { // finchè non è vuota la lista
		if (head->prev && head->next) { //se sono presenti il precedente ed il prossimo
			int sum = head->prev->value + head->next->value; //sommo precedente e prossimo
			if (sum == head->value) { //verifico che la somma non sia uguale al valore dell'elemento centrale
				head->prev->next = head->next; //il next del valore precedente (ovvero del mio elemento corrente) lo sostituisco con il valore successivo
				head->next->prev = head->prev; //e cambio il precedente del valore successivo con quello precedente all'elemento corrente
			}
		}
		head = head->next; //scorro all'elemento successivo
	}
	head = h;//assegno ad head il valore h
}
