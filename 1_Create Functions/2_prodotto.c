#include <stdio.h>
#include <stdlib.h>
/*
Questo programma prende in input da riga di comando diversi valori, che verranno tradotti da stringa a intero
per poi eseguire il prodotto di essi.
Se non ci dovessero essere valori in input, la funzione restituirà 0.
*/
int main(int argc, char *argv[]) {
	
	int n = 0;

	if (argc != 0) {

		int j = 0;
		n = 1;
		int temp = 0;
		for (int i = 1; i < argc; i++)
		{
			temp = atoi(argv[i]);
			n *= temp;
		}
	}
	printf("prodotto = %d", n);
	return n;
}