#include <stdio.h>
#define __USING_SLAC__
#include <slac/vector.h>

int
main(void) {
	vector a = vector_add(vector(2, 1, 2), vector_mul(vector(2, 3, 4), vector(2, 5, 6)));
	printf("%.1f, %.1f\n", a[0], a[1]);
	return 0;
}
