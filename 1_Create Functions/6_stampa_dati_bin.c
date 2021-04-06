#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//dichiaro la struct
struct data
{
	int giorni;
	int mesi;
	int anni;
};

// & argc ->  *n  <- nella funzione 
void filecopy(int n, char *nome, char *cognome, struct data dati, char *luogo, char *indirizzo, char *cf, FILE *f) {
	
	size_t l = strlen(nome);
	fwrite(nome, sizeof(char),l, f);

	 l = strlen(cognome);
	fwrite(cognome, sizeof(char), l, f);

	fwrite(&dati.giorni, sizeof(int), 1, f);
	fwrite(&dati.mesi, sizeof(int), 1, f);
	fwrite(&dati.anni, sizeof(int), 1, f);
	
	 l = strlen(luogo);
	fwrite(luogo, sizeof(char), l, f);

	 l = strlen(indirizzo);
	fwrite(indirizzo, sizeof(char), l, f);

	 l = strlen(cf);
	fwrite(cf, sizeof(char), l, f);
	
	// stampa
	
	printf("%s\t", nome);
	printf("%s\t", cognome);

	printf("%d\t", dati.giorni);
	printf("%d\t", dati.mesi);
	printf("%d\t", dati.anni);

	printf("%s\t", luogo);
	printf("%s\t", indirizzo);
	printf("%s\t", cf);
	

	
}


int main(int argc, char *argv[]) {
	FILE *f = fopen("record2.txt", "wb");
	if (f == NULL) {
		return;
	}
	struct data dati = { 11, 10, 1999 };
	filecopy(argc, argv[1], argv[2], dati, argv[3], argv[4], argv[5], f);
	fclose(f);

}