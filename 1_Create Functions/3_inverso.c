#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/*
La funzione inverso, trasforma le lettere maiuscole in minuscole e viceversa.
Le modifiche che avvengono al vettore passato dal main, infliggono anche quel vettore non solo quello passato come parametro
*/
char inverso(int n, char *vett) {
	
	for (int i = 0; i < n-1; i++)
	{
		
		if (isupper(vett[i])) {
			vett[i] = tolower(vett[i]);
		}
		else {
			vett[i] = toupper(vett[i]);
		}
	}
	

	
	printf("Dopo:  ");

	for (int i = 0; i < n - 1; i++)
	{
		printf("%c\t", vett[i]);
	}
	printf("\n");
	

	return 0;
}


int main(int argc, char *argv[]) {

	char *new = malloc(argc * sizeof(char));
	new[argc] = 0;
	int j = 0;

	printf("Prima: ");
	for (int i = 1; i < argc; i++)
	{
		printf("%s\t", *(argv + i));
		new[j] = *(*(argv + i));
		++j;
	}
	printf("\n");
	
	inverso(argc, new);
	
	/*

	// prova per vedere se il vettore che modifico nella funzione modifica anche quello del main

	printf("Dopo:  ");

	for (int i = 0; i < argc; i++)
	{
		printf("%c\t", new[i]);
	}
	printf("\n");	
	
	*/
	return;
}