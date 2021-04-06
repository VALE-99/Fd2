#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

void BabboNataleRec(const int *pacchi, size_t pacchi_size, int p, int i,
	bool *vcurr, bool *vbest, int *max, int cnt, int sum, int *nsol, int *vsum) {

	//stampa
	if (sum < p && i == pacchi_size) {
		*nsol++; //aggiorno numero soluzioni trovate
		//if (vcurr[0] == true && vcurr[1] == false && vcurr[2] == true && vcurr[3] == true && vcurr[4] == true) {
		//	printf("\n");
		//}
		if (cnt > *max && sum >= *vsum) { //se numero pacchi in sol vbest è < di cnt, allora ho trovato soluzione migliore
			*max = cnt;	//aggiorno i parametri
			*vsum = sum; // peso vettore best
			for (size_t j = 0; j < pacchi_size; j++)	//stampo e sostituisco vbest con la nuova soluzione
			{
				vbest[j] = vcurr[j];
			}
		//	printf("\n");
		}
		
		return;
	}

	if (i == pacchi_size) {
		return;
	}

	if (i == 0) {
		vcurr[i] = 0;
		BabboNataleRec(pacchi, pacchi_size, p, i + 1, vcurr, vbest, max, cnt, sum, nsol, vsum);
		vcurr[i] = 1;
		BabboNataleRec(pacchi, pacchi_size, p, i + 1, vcurr, vbest, max, ++cnt, sum + pacchi[i], nsol, vsum);
		return;
	}

	if (i > 0) {
		vcurr[i] = 0;
		BabboNataleRec(pacchi, pacchi_size, p, i + 1, vcurr, vbest, max, cnt, sum, nsol,vsum);
		vcurr[i] = 1;
		BabboNataleRec(pacchi, pacchi_size, p, i + 1, vcurr, vbest, max, ++cnt, sum + pacchi[i], nsol,vsum);
	}

	vcurr[i] = 0;
	BabboNataleRec(pacchi, pacchi_size, p, i + 1, vcurr, vbest, max, cnt, sum, nsol,vsum);

	
	return;

}


void BabboNatale(const int *pacchi, size_t pacchi_size, int p) {

	bool *vcurr = malloc(pacchi_size * sizeof(bool));
	bool *vbest = malloc(pacchi_size * sizeof(bool));
	int cnt = 0;
	int max = 0;
	int sum = 0;
	int nsol = 0;
	int vsum = 0;
	BabboNataleRec(pacchi, pacchi_size, p, 0, vcurr, vbest, &cnt, max, sum, &nsol, &vsum);
	
	// printf("soluzioni totali: %d\n", nsol);
	for (size_t j = 0; j < pacchi_size; j++)
	{
		printf("%i ", vbest[j]);
	}

	free(vcurr);
	free(vbest);
}
