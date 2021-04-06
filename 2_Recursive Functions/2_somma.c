#include <stdlib.h>
#include <stdio.h>

int Somma(int n) {

	//caso base
	if (n < 0 && n == 0){
		return -1;
	}
	// ricorsione 
	int ris1 = 1;	//imposto la mia variabile risultante ad 1
	int ric = 0;	//la variabile "ric" serve per tenere conto delle somme durante la ricorsione
	if (n > 1) {	//questa condizione esegue la somma, se la mia "n" utilizzata come "contatore" e "sommatore" è > 1
		ric = ric + n;	//tengo traccia dei vari valori durante la ricorsione
		n = n - 1;	//decremento "n" così da poter contare i "cicli primi di uscire" e da poter sommare.
	return ris1 = Somma(n) + ric; //somme delle varie ricorsioni
	}

	return ris1;	//ritorno al main dei miei valori
}


int main() {

	int n = 1;

	printf("La somma e': %d", Somma(n));

	return;
}