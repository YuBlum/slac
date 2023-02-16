#include <stdio.h>
#define __USING_SLAC__
#include <slac/slac.h>

int
main(void) {
	vector4 v = vector(1, 2, 3, 4);
	vector_printl(v);
	vector_printl(vector_add(v, 4));
	v->x += 2;
	v->w -= 2;
	vector_printl(v);
	vector_printl(v);
	printf("%d\n", vector_compare(v, vector(3, 2, 3, 2)));
	printf("%f\n", vector_angle(vector(0, 1), vector(1, 0)));

	matrix4 m = slac_matrix_identity(4,4);
	matrix_printf(m);
	return 0;
}
