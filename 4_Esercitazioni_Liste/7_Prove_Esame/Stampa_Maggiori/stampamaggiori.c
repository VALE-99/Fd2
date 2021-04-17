#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include "list_int.h"


typedef struct item {
	int voto;
	struct item *next;
} nodo;
void stampa_maggiori(nodo *i, int val);

void OrdinaLista(const char *filename) {

	FILE *f = fopen(filename, "r");
	if (!f) {
		return NULL;
	}

	int voto = 0;
	nodo *i = CreateEmptyList(); //creo la lista vuota partendo dalla struct

	for (size_t j = 0; j < 5; j++)
	{
		fscanf(f, "%d",&voto); //leggo il primo voto da file
		if (i == NULL || i->voto > voto) { //se il mio puntatore alle testa di voto è NULL oppure maggiore del voto attuale
			nodo *head = malloc(sizeof(nodo)); //creo un nodo di testa 
			head->voto = voto; //inserisco il voto letto nel nodo di testa
			head->next = i; //collego al next di testa, la lista i
			i = head; //imposto la lista i alla testa, per controllare da qui al prossimo giro
		}
		else {
			nodo *list = i; //creo un nodo lista
			while (list->next != NULL && list->next->voto < voto) { //se il next di lista non è nullo, e il puntatore al next di voto è minore del voto appena letto
				list = list->next; //imposto il puntatore di list al next
			} //In pratica scorro la lista finchè non trovo la sua posizione esatta in base al valore, oppure non arrivo alla fine della lista

			nodo *tmp = list->next; //creo un nodo temporaneo, e lo attacco al next della mia lista
			list->next = malloc(sizeof(nodo));	// aggiungo al next "uno spazio"
			list->next->voto = voto; //inserisco il voto
			list->next->next = tmp; //copio il puntatore al next del next in tmp
		}
	}
	fscanf(f, "\n");
	int num = 0;
	coppie(i, num);
	printf("%d", num);
	fclose(f);
}

coppie(nodo *i, int num) {
	
	while (i->next != NULL) {
		if (i->voto == i->next->voto) {
			num++;
			i = i->next;
		}
		else {
			i = i->next;
		}
	}
	printf("%d", num);
}

int main() {
 OrdinaLista("Data_00.txt");
}