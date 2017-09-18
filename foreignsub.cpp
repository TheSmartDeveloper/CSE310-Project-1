#include "foreignsub.h"
#include <iostream>

int sub(int n, int *a, int *b, int *c) {
	std::cout << "BGN SUB" << std::endl;
	for (int i = 0; i < n; i++) {
		a[i] = -1;
		b[i] = -1;
		c[i] = -1;
	}
	std::cout << "END SUB" << std::endl;
	return a[0];
}
