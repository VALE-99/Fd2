#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
typedef struct {
	unsigned p; // Peso
	unsigned a; // Altezza
	unsigned l; // Limite
} Cartone;

extern void torrecartoni(Cartone *c, int n);

typedef struct {

	unsigned a; //altezza torre
	int *c_ids; //vett soluzione corrente
				//Id cartoni --> 0, 2, 1 significa che la torre è costruita con i pacchi in posizione 0,2,1
				// e in particolare signifca che il pacco 0 è in cima alla torre e quello di indice 1, si trova alla base
	unsigned size; // dimensione c_ids 
	unsigned peso; // peso totale
} torre;
