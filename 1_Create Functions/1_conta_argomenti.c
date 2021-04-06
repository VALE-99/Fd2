#include <stdio.h>
#include <string.h>

int check(char *stringa, char *carattere, size_t *len) {

	int n = 0;

	for (size_t i = 0; i < *len; i++)
	{
		if (stringa[i] == *carattere) {
			++n;
		}
		
	}

	return n;
}


int main(int argc, char *argv[]) {

	/*

	Questa parte di programma legge il numero di argomenti passati e li stampa 

	printf("numero argomenti: %d\n\n", argc);

	for (size_t i = 1; i < 5; i++)
	{
		printf("%s\n", argv[i]);
	}
	*/
	//chiamo la funzione "check" per controllare il numero di occorrenze del primo carattere nella stringa
	//chiamo nuovamente la funzione "check" per controllare il numero di occorrenze del secondo carattere nella stringa
	//stampo il numero di occorrenze trovate
	size_t len = strlen(argv[1]);
	printf("numero argomenti: %d", argc);
	printf("%s\n", argv[0]);
	printf("%s <-- stringa\n", argv[1]);

	int num_occ_1 = check(argv[1], argv[2], &len); 
	printf("il numero di occorrenze del carattere '%s' nella stringa e': %d\n", argv[2], num_occ_1);

	int num_occ_2 = check(argv[1], argv[3], &len);
	printf("il numero di occorrenze del carattere '%s' nella stringa e': %d\n", argv[3], num_occ_2);

	int num_occ_3 = check(argv[1], argv[4], &len);
	printf("il numero di occorrenze del carattere '%s' nella stringa e': %d\n", argv[4], num_occ_3);


}