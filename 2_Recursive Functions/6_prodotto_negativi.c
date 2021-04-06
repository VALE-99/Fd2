#include <stdio.h>
int ProdottoNegativi(int a, int b) {


	//caso base 1
	if (a == 0 || b == 0) {
		return 0;
	}

	//caso tutti e due positivi
	if (a > 0 && b > 0) {
		int ris = a;
		if (b == 1) {
			return ris;
		}
		return ris += ProdottoNegativi(a, (b - 1));
	}

	//caso positivo e negativo e viceversa

	if (a > 0 && b < 0) {
		int ris = b;
		if (a == 1) {
			return ris;
		}
		return ris += ProdottoNegativi((a - 1), b);
	}

	if (a < 0 && b > 0) {
		int ris = a;
		if (b == 1) {
			return ris;
		}
		return ris += ProdottoNegativi(a, (b-1));
	}

	//caso tutti e due negativi
	if (a < 0 && b < 0) {
		if (a > b) {
			int ris = b;
			if (a == -1) {
				return ris;
			}
			ris += ProdottoNegativi((a+1), b);
			return ris = -ris;
		}

		if (b > a) {
			int ris = a;
			if (b == -1) {
				return ris;
			}
			ris += ProdottoNegativi(a, (b + 1));
			return ris = -ris;

		}
	}

}

/*
int main(void) {
	int f;
	int d;
	
	f = ProdottoNegativi(3, 2);
	f = ProdottoNegativi(-3, 2);
	d = ProdottoNegativi(3, -2);
	f = ProdottoNegativi(-2, -3);
	f = ProdottoNegativi(-3, -2);

}
*/
