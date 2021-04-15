#include "torrecartoni.h"

//if (vbest->a < vcurr->a) {
//vbest->a = vcurr->a;
//vbest->peso = vcurr->peso;
//vbest->size = vcurr->size;
//memcpy(vbest->c_ids, vcurr->c_ids, vcurr->peso * sizeof(int));
//		}

//if (i == n) {
//return;
//	}

void TorreCartoniRec(Cartone *c, int n, torre *vcurr, torre *vbest, int i, bool *usati) {

	if (i == n) {
		if (vbest->a < vcurr->a) {
			vbest->a = vcurr->a;
			vbest->peso = vcurr->peso;
			vbest->size = vcurr->size;
			memcpy(vbest->c_ids, vcurr->c_ids, vcurr->size * sizeof(int));
		}
		return;
	}

	TorreCartoniRec(c, n, vcurr, vbest, n, usati);
	
	for (int j = 0; j < n; j++)
	{
		if (!usati[j]) { //se usati alla locazione j-esima è uguale a 0
			if (vcurr->peso < c[j].l) {
				vcurr->a += c[j].a;
				vcurr->c_ids[vcurr->size] = j;
				usati[j] = 1;
				vcurr->peso += c[j].p;
				++vcurr->size;
				TorreCartoniRec(c, n, vcurr, vbest, i + 1, usati);
				usati[j] = 0;
				--vcurr->size;
				vcurr->peso -= c[j].p;
				vcurr->a -= c[j].a;
			}
		}
		
	}
	
}
	


void TorreCartoni(Cartone *c, int n) {
	bool *usati = calloc(n,sizeof(n));
	torre vcurr = { .a = 0,.c_ids = malloc(n * sizeof(int)),.peso = 0,.size = 0 };
	torre vbest = { .a = 0,.c_ids = malloc(n * sizeof(int)),.peso = 0,.size = 0 };
	
	TorreCartoniRec(c, n, &vcurr, &vbest, 0, usati);
	for (unsigned i = 0; i < vbest.size; ++i)
	{
		
			printf("%d\n", vbest.c_ids[i]);
		

	}
	printf("altezza: %d", vbest.a);

	free(vcurr.c_ids);
	free(vbest.c_ids);
	free(usati);
}

