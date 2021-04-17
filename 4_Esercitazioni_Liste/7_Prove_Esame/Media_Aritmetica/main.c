#define _CRT_SECURE_NO_WARNINGS
#include "list_int.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct item {
	int voto;
	struct item *next;
} nodo;


void LoadList(const char *filename) {

	nodo *i = CreateEmptyList();

	FILE *f = fopen(filename, "r");
	if (!f) {
		return ;
	}
	
	int voto = 0; //voto temporaneo

	for (size_t j = 0; j < 10; j++)
	{
		fscanf(f, "%d", &voto);
		if (i == NULL || i->voto > voto) { //se il voto già presente in lista è maggiore allora ho un nuovo puntatore alla testa 
			nodo *head = malloc(sizeof(nodo)); //visto che la mia lista deve essere ordinata in maniera crescente
			head->voto = voto;
			head->next = i;
			i = head;
		}
		else {	//altrimenti scorro la lista
			nodo *list = i;
			while (list->next != NULL && list->next->voto < voto) { //scorro la lista finchè non trovo la posizione
				list = list->next;
			}

			nodo *tmp = list->next;
			list->next = malloc(sizeof(nodo));
			list->next->voto = voto;
			list->next->next = tmp;
		}
	}
	int sum = 0;
	nodo *head = i;
	for (size_t j = 0; j < 10; j++)
	{
		sum += i->voto;
		i = i->next;
	}
	
	sum /= 10;
	i = head; //ritorno al puntatore di testa
	for (size_t j = 0; j < 10; j++) //stampa
	{
		if (i->voto > sum) {
			printf("%d ", i->voto);
		}
		i = i->next;
	}

	fclose(f);
	
}


stampa_maggiori() {

}

int main() {

	LoadList("Data_00.txt");
}