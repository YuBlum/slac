#include <stdarg.h>
#include <stdio.h>
#include "vector.h"

void *
setup_vector_memory(unsigned int size, void *vec, void *header) {
	*(unsigned int *)header = size;
	return vec;
}
