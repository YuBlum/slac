#include <stdio.h>
#define __USING_SLAC__
#include <slac/vector.h>

int
main(void) {
	vector a = vector_add(2, vector(2, 2, 4), vector_mul(2, vector(2, 1, 2), vector(2, 2, 2)));
	printf("%.1f, %.1f\n", a[0], a[1]);
	return 0;
}
