#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

void OmbrelloniRec(int k, int n, int i, bool *vcurr, int cnt, int *nsol) {

	if (cnt == 0 && i == n) {
		++*nsol;	// *(nsol)++; <- incrementa indirizzo
		printf("%d) ", *nsol);
		for (int j = 0; j < i; j++) {
			printf("%i ", vcurr[j]);
		}
		printf("\n");
		return;
	}

	if (i == n) {
		return;
	}
	

	if (i == 0) {
		vcurr[i] = 0;
		OmbrelloniRec(k, n, i + 1, vcurr, cnt , nsol);
		vcurr[i] = 1;
		OmbrelloniRec(k, n, i + 1, vcurr, cnt - 1, nsol);
		return;
	}

	if (vcurr[i - 1] == 0) {
		vcurr[i] = 0;
		OmbrelloniRec(k, n, i + 1, vcurr, cnt , nsol);
		vcurr[i] = 1;
		OmbrelloniRec(k, n, i + 1, vcurr, cnt - 1, nsol);
	}

	else {
		vcurr[i] = 0;
		OmbrelloniRec(k, n, i + 1, vcurr, cnt, nsol);
	}

}


int Ombrelloni(int k, int n) {

	if (k < 0 || n < 0) {
		return 0;
	}

	bool *vcurr = malloc(n*sizeof(bool));
	int nsol = 0;
	int cnt = k;

	OmbrelloniRec(k, n, 0, vcurr, cnt, &nsol);
	free(vcurr);
	return nsol;
}
/*int main(void) {

	Ombrelloni(2, 4);

}
*/
