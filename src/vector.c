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

#define binary_operation_scalar(left, operator, right)\
for (int i = 0; i < vector_size(left); i++) {\
	((vector)(left))[i] operator (right);\
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
vector_set_vector(any dest, any src) {
	binary_operation(dest, =, src);
}
any
vector_add_vector_to(any dest, any src) {
	binary_operation(dest, +=, src);
}
any
vector_sub_vector_to(any dest, any src) {
	binary_operation(dest, -=, src);
}
any
vector_mul_vector_to(any dest, any src) {
	binary_operation(dest, *=, src);
}
any
vector_div_vector_to(any dest, any src) {
	binary_operation(dest, /=, src);
}

any
vector_set_scalar(any dest, scalar src) {
	binary_operation_scalar(dest, =, src);
}
any
vector_add_scalar_to(any dest, scalar src) {
	binary_operation_scalar(dest, +=, src);
}
any
vector_sub_scalar_to(any dest, scalar src) {
	binary_operation_scalar(dest, -=, src);
}
any
vector_mul_scalar_to(any dest, scalar src) {
	binary_operation_scalar(dest, *=, src);
}
any
vector_div_scalar_to(any dest, scalar src) {
	binary_operation_scalar(dest, /=, src);
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
