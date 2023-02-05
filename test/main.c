#include <stdio.h>
#include <slac/vector.h>

int
main(void) {
	vector a = vector(2);
	printf("%u\n", vector_size(a));
	return 0;
}
