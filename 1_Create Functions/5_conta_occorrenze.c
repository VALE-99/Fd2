#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

check_occ(FILE *f, char *string) {
	int n = 0;
	int count = 0;
	char a = fgetc(f);
	size_t len = strlen(string);
	int j = 0;
	while (a != EOF)
	{
		if (a == string[j]) {
			++j;
		}
		else {
			j = 0;
		}

		a = fgetc(f);

		if (j == 4) {
			++n;
			j = 0;
		}
		
	}

	return n;
}


			
	
int main(int argc, char *argv[]) {

	FILE *f = fopen("testo.txt","r");
	if (f == NULL) {
		printf("file non trovato!");
		return;
	}

	int n = check_occ(f,argv[1]);
	fclose(f);

	printf("numero occorrenze: %d",n);
	return n;
}