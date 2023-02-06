#include <stdio.h>
#define __USING_SLAC__
#include <slac/vector.h>
#include <math.h>

int
main(void) {
	vector v = vector_add_to(vector(5, 0), vector(2, 3));
	vector_printl(vector_add_to(v, 5));
	vector_printl(v);
	return 0;
}
