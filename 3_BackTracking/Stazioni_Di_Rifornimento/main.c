// m totale km da percorrere
// d, p array distanza e prezzi
// n elementi degli array 
// 0.05 l/km
//serbatoio 30 l

#include <stdlib.h>
#include <stdbool.h>

extern void StazioniServizio(double m, int n, double *d, double *p);

int main(void) {

	double m = 1540;
	int n = 5;
	double d[] = {260.0000 , 284.0000, 308.0000, 332.0000, 356.0000};
	double p[] = {35.0000, 35.0000, 33.0000, 29.0000, 23.0000 };

	StazioniServizio(m,n,d,p);


}