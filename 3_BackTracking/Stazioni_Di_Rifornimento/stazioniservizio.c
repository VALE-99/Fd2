#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <float.h>

//con & il valore che passo deve essere aggiornato dopo la chiamata
//senza "&" il valore che passo non deve essere aggiornato, ma varia in base a quello che facciamo ad ogni chiamata

typedef struct {

	bool *s; //vettore stazioni
	double prezzo;
	
} rifornimento;

void StazioniServizioRec(double m, double n, double *d, double *p, int i, rifornimento *vcurr, rifornimento *vbest, double dist) {


	if (dist + 600 >= m) {
		//stampa
		if (vcurr->prezzo < vbest->prezzo) {
			vbest->prezzo = vcurr->prezzo;
			memcpy(vbest->s, vcurr->s, (size_t)n*sizeof(bool));
		}
		return;
	}
	
double dp = 0;
double tmp = vcurr->prezzo;

	for (int j = i; j < n; ++j) {
		dp += d[j]; 

		if (dp < 600) {
			vcurr->s[j] = 1;
			vcurr->prezzo += dp * 0.05 *p[j];

			StazioniServizioRec(m, n, d, p, j + 1, vcurr, vbest, dist + dp);
			
			vcurr->s[j] = 0;
			vcurr->prezzo = tmp;
		}
		else {
			break;
		}
	}

}



void StazioniServizio(double m, int n, double *d, double *p) {

	rifornimento vcurr = { .s = calloc(n,sizeof(bool)),.prezzo = 0 };
	rifornimento vbest = { .s = calloc(n,sizeof(bool)),.prezzo = DBL_MAX };
		
	StazioniServizioRec(m, n, d, p, 0, &vcurr, &vbest, 0);

	if (vbest.prezzo == DBL_MAX) {
		printf("risultato non trovato");
	}
	else {
		for (size_t i = 0; i < (size_t)n; i++)
		{
			if (vbest.s[i]) {
				printf("%li ", i);
			}
		}
		printf("\n");
		printf("prezzo: %f", vbest.prezzo);
	}
	
	free(vcurr.s);
	free(vbest.s);

}