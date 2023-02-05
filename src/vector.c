#include <stdarg.h>
#include <stdio.h>
#define __USING_SLAC__
#include "vector.h"

#define binary_operation(left, operator, right) do {\
	for (unsigned int i = 0; i < vector_size(left); i++) {\
		if (vector_size(right) < i) break;\
		((float *)(left))[i] operator ((float *)(right))[i];\
	}\
	return (left);\
} while (0)

/*
 * Setup a stack allocated memory to the layout of a vector.
 * This is just to simulate a struct initialization
 * */
any
slac_setup_vector_memory(unsigned int size, any vec, unsigned int init_amount, float *init_values) {
	*((unsigned int *)vec) = size;
	vec += sizeof(unsigned int);
	for (unsigned int i = 0; i < init_amount; i++) {
		((float *)vec)[i] = init_values[i];
	}
	return vec;
}

slac_any
slac_vector_copy_to(slac_any dest, slac_any src) {
	binary_operation(dest, =, src);
}
slac_any
slac_vector_add_to(slac_any dest, slac_any src) {
	binary_operation(dest, +=, src);
}
slac_any
slac_vector_sub_to(slac_any dest, slac_any src) {
	binary_operation(dest, -=, src);
}
slac_any
slac_vector_mul_to(slac_any dest, slac_any src) {
	binary_operation(dest, *=, src);
}
slac_any
slac_vector_div_to(slac_any dest, slac_any src) {
	binary_operation(dest, /=, src);
}
