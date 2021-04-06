
unsigned long long Fattoriale(int n) {
	//caso base 1
	if (n < 0) {
		return 0;
	}

	//caso base 2
	if (n == 0) {
		return 1;
	}

	unsigned long long ris = n;
	if (n == 1) {
		return ris;
	}

	return ris *= Fattoriale(n - 1);
	 

}
/*int main(void) {

	unsigned long long f;
	f = Fattoriale(-1);
	f = Fattoriale(0);
	f = Fattoriale(1);
	f = Fattoriale(2);
	f = Fattoriale(3);

}
*/
