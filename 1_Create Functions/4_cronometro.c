//150,121 -> /1000 trovo i secondi -> /60 trovo i minuti

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int main(int argc, char *argv[]) {

	int min= 0;
	int sec= 0;
	int ms = 0;

	int tot = atoi(argv[1]);
	
	ms = tot % 1000;
	tot /= 1000;
	min = tot / 60;
	sec = (tot % 60);

	printf("%d min, %d sec e %d ms",min,sec,ms);

	return;
}