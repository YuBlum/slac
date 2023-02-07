#include <stdio.h>
#define __USING_SLAC__
#include <slac/slac.h>
#include <math.h>

int
main(void) {
	vector4 v = vector(1, 2, 3, 4);
	vector_printl(v);
	vector_printl(vector_add(v, 4));
	v->x += 2;
	v->w -= 2;
	vector_printl(v);
	return 0;
}
