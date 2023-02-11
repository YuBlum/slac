#include <stdio.h>
#include <math.h>
#include <assert.h>
#define __USING_SLAC__
#include "vector.h"

#define binary_operation(left, operator, right)\
for (unsigned int i = 0; i < vector_size(left); i++) {\
	if (vector_size(right) < i) break;\
	((vector)(left))[i] operator ((vector)(right))[i];\
}\
return (left)\

#define binary_operation_scalar(left, operator, right)\
for (unsigned int i = 0; i < vector_size(left); i++) {\
	((vector)(left))[i] operator (right);\
}\
return (left)\

/*
 * Setup a stack allocated memory to the layout of a vector.
 * This is just to simulate a struct initialization
 * */
any
slac_setup_vector_memory(unsigned int size, any vec, unsigned int init_amount, scalar *init_values) {
	*((unsigned int *)vec) = size;
	vec += sizeof(unsigned int);
	for (unsigned int i = 1; i <= size; i++) {
		if(i < init_amount) ((vector)vec)[i - 1] = init_values[i];
		else ((vector)vec)[i - 1] = 0;
	}
	return vec;
}

void 
vector_print(slac_any vec) {
	printf("[ ");
	for (unsigned int i = 0; i < vector_size(vec); i++) {
		if (i > 0) printf(", ");
		printf("%.2f", ((scalar *)vec)[i]);
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

scalar
vector_dot(any vec1, any vec2) {
	scalar dot = 0;
	for (unsigned int i = 0; i < vector_size(vec1); i++) {
		scalar v1_times_v2 = ((vector)vec1)[i];
		if (vector_size(vec2) > i) v1_times_v2 *= ((vector)vec2)[i];
		dot += v1_times_v2;
	}
	return dot;
}

scalar
vector_mag_squared(any vec) {
	scalar mag = 0;
	for (unsigned int i = 0; i < vector_size(vec); i++)
		mag += ((vector)vec)[i] * ((vector)vec)[i];
	return mag;
}

scalar
vector_mag(any vec) {
	return sqrt(vector_mag_squared(vec));
}

scalar
vector_dist_squared(any vec1, any vec2) {
	scalar dist = 0;
	for (unsigned int i = 0; i < vector_size(vec1); i++) {
		scalar v1_minus_v2 = ((vector)vec1)[i];
		if (vector_size(vec2) > i) v1_minus_v2 -= ((vector)vec2)[i];
		dist += v1_minus_v2 * v1_minus_v2;
	}
	return dist;
}

scalar
vector_dist(any vec1, any vec2) {
	return sqrt(vector_dist_squared(vec1, vec2));
}

any
vector_normalize_to(any vec) {
	scalar mag = vector_mag(vec);
	return vector_div_scalar_to(vec, mag);
}

any
vector_cross_to(any vec1, any vec2) {
	if (vector_size(vec1) != 3 && vector_size(vec2) != 3) return NULL;
	scalar a = ((vector)vec1)[1]*((vector)vec2)[2] - ((vector)vec1)[2]*((vector)vec2)[1],
				 b = ((vector)vec1)[2]*((vector)vec2)[0] - ((vector)vec1)[0]*((vector)vec2)[2],
				 c = ((vector)vec1)[0]*((vector)vec2)[1] - ((vector)vec1)[1]*((vector)vec2)[0];
	((vector)vec1)[0] = a;
	((vector)vec1)[1] = b;
	((vector)vec1)[2] = c;
	return vec1;
}

_Bool
vector_compare_array(any vecs[]) {
	if (vecs[0] == NULL) return 0;
	for (unsigned int i = 1; vecs[i]; i++) {
		if (vector_size(vecs[0]) != vector_size(vecs[i])) return 0;
		for (unsigned int j = 0; j < vector_size(vecs[0]); j++)
			if (((scalar *)(vecs[0]))[j] != ((scalar *)(vecs[i]))[j]) return 0;
	}
	return 1;
}

_Bool
vector_linear_dependent_array(any vecs[]) {
	(void)vecs;
	assert(0 && "not implemented yet");
	return 0;
}

_Bool
vector_orthogonal(any vec1, any vec2) {
	return vector_dot(vec1, vec2) == 0;
}

_Bool
vector_perpendicular(any vec1, any vec2) {
	vector zero_vector = vector(vector_size(vec1));
	return !vector_compare(vec1, zero_vector) && !vector_compare(vec2, zero_vector) && vector_dot(vec1, vec2) == 0;
}

scalar
vector_angle(any vec1, any vec2) {
	scalar angle = vector_dot(vec1, vec2);
	angle /= vector_mag(vec1);
	angle /= vector_mag(vec2);
	angle = acos(angle);
	return angle;
}

