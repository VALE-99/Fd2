#include <stdio.h>
#include <stdlib.h>
int FibonacciRec(int n) {

	//caso base 1
	if (n == 0) {
		return 0;
	}

	if (n == 1) {
		return 1;
	}

	return FibonacciRec(n - 1) + FibonacciRec(n - 2);


}


int Fibonacci(int n) {

	//caso base
	if (n < 0) {
		return -1;
	}

	return FibonacciRec(n);
		
}

int main(void) {


	printf("risultato successione: %d\n", Fibonacci(-1));

	printf("risultato successione: %d\n", Fibonacci(0));

	printf("risultato successione: %d\n", Fibonacci(1));

	printf("risultato successione: %d\n", Fibonacci(2));

	printf("risultato successione: %d\n", Fibonacci(3));

