#include <stdio.h>

static int MinimoRec(const int *v, int v_size, int i) {
	if (v_size - 1 == i) {
		return v[i];
	}

	int min = MinimoRec(v, v_size, i + 1);

	if (v[i] < min) {
		return v[i];
	}
	else {
		return min;
	}
}


int Minimo(const int *v, int v_size) {

	return MinimoRec(v, v_size, 0);
}

int main(void) {


int vet[] = { 2,4,5,2,3,4 };

int len = 6;

printf("minimo: %d", Minimo(vet, len));

}