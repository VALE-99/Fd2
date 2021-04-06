#include <stdlib.h>
extern void BabboNatale(const int *pacchi, size_t pacchi_size, int p);

int main(void) {

	int p = 20;
	int pacchi[] = { 10, 11, 1, 3, 3 };
	int pacchi_size = 5;

	BabboNatale(pacchi, pacchi_size, p);

}