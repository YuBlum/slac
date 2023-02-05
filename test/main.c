#include <stdio.h>
#define __USING_SLAC__
#include <slac/vector.h>
#include <math.h>

int
main(void) {
	vector a = vector(3, 2);
	vector b = vector(1, 4);
	printf("%f\n", vector_dist(a, b));
	return 0;
}
