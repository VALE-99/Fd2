#include <stdio.h>

int Prodotto(int a, int b) {
	//caso base 0
	if (a < 0 || b < 0) {
		return -1;
	}

	//caso base 1
	if (a == 0 || b == 0) {
		return 0;
	}

	int ris = a;
	
	if (b == 1) {
		return a;
	}

	

	ris = ris + Prodotto(a, (b - 1));
	
	return ris;

}
/*
int main() {
	
	int f;
	f = Prodotto(-2,3);
	f = Prodotto(0,2);
	f = Prodotto(2,1);
	f = Prodotto(2,2);
	f = Prodotto(5,5);
	f = Prodotto(10,2);
}
*/