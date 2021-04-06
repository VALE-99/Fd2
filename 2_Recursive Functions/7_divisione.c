
int DivisioneRec(int a, int b) {
	int ris = 0;

	if (a < b)
	{
		return 0;
	}

	return ris += DivisioneRec(a - b, b) + 1;


}

int Divisione(int a, int b) {
	//caso base 1
	if (b <= 0 || a < 0) {
		return -1;
	}

	//caso base 2
	if (a == 0) {
		return 0;
	}

	int ris = 0;
	ris = DivisioneRec(a, b);
	return ris;


}

/*
int main(void) {


	int f = Divisione(15, 3);
}
*/