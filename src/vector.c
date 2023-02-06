#include <stdarg.h>
#include <stdio.h>
#include <math.h>
#define __USING_SLAC__
#include "vector.h"

#define binary_operation(left, operator, right)\
for (int i = 0; i < vector_size(left); i++) {\
	if (vector_size(right) < i) break;\
	((vector)(left))[i] operator ((vector)(right))[i];\
}\
return (left)\

/*
 * Setup a stack allocated memory to the layout of a vector.
 * This is just to simulate a struct initialization
 * */
any
slac_setup_vector_memory(unsigned char size, any vec, int init_amount, float *init_values) {
	*((unsigned char *)vec) = size;
	vec += sizeof(unsigned char);
	printf("%u\n", init_amount);
	for (unsigned char i = 1; i < init_amount; i++) {
		((vector)vec)[i - 1] = init_values[i];
	}
	return vec;
}

void 
vector_print(slac_any vec) {
	printf("[ ");
	for (unsigned char i = 0; i < vector_size(vec); i++) {
		if (i > 0) printf(", ");
		printf("%.2f", ((float *)vec)[i]);
	}
	printf(" ]");
}

any
vector_copy_to(any dest, any src) {
	binary_operation(dest, =, src);
}
any
vector_add_to(any dest, any src) {
	binary_operation(dest, +=, src);
}
any
vector_sub_to(any dest, any src) {
	binary_operation(dest, -=, src);
}
any
vector_mul_to(any dest, any src) {
	binary_operation(dest, *=, src);
}
any
vector_div_to(any dest, any src) {
	binary_operation(dest, /=, src);
}

float
vector_dot(any vec1, any vec2) {
	float dot = 0;
	for (int i = 0; i < vector_size(vec1); i++) {
		float v1_times_v2 = ((vector)vec1)[i];
		if (vector_size(vec2) > i) v1_times_v2 *= ((vector)vec2)[i];
		dot += v1_times_v2;
	}
	return dot;
}

float
vector_mag_squared(any vec) {
	float mag = 0;
	for (int i = 0; i < vector_size(vec); i++)
		mag += ((vector)vec)[i] * ((vector)vec)[i];
	return mag;
}

float
vector_mag(any vec) {
	return sqrt(vector_mag_squared(vec));
}

float
vector_dist_squared(any vec1, any vec2) {
	float dist = 0;
	for (int i = 0; i < vector_size(vec1); i++) {
		float v1_minus_v2 = ((vector)vec1)[i];
		if (vector_size(vec2) > i) v1_minus_v2 -= ((vector)vec2)[i];
		dist += v1_minus_v2 * v1_minus_v2;
	}
	return dist;
}

float
vector_dist(any vec1, any vec2) {
	return sqrt(vector_dist_squared(vec1, vec2));
}
