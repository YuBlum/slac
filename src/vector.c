#include <math.h>
#include <assert.h>
#define __USING_SLAC__
#include "vector.h"

#define binary_operation(left, operator, right)\
for (slacsz i = 0; i < vector_size(left); i++) {\
	if (vector_size(right) < i) break;\
	((vector)(left))[i] operator ((vector)(right))[i];\
}\
return (left)\

#define binary_operation_scalar(left, operator, right)\
for (slacsz i = 0; i < vector_size(left); i++) {\
	((vector)(left))[i] operator (right);\
}\
return (left)\

/*
 * Setup a stack allocated memory to the layout of a vector.
 * This is just to simulate a struct initialization
 * */
any
slac_setup_vector_memory(slacsz size, any vec, scalar *init_values) {
	*((slacsz *)vec) = size;
	vec += sizeof(slacsz);
	for (slacsz i = 0; i < size; i++) {
		((vector)vec)[i] = init_values ? init_values[i] : 0;
	}
	return vec;
}

void 
vector_print(slac_any vec) {
	printf("[ ");
	for (slacsz i = 0; i < vector_size(vec); i++) {
		if (i > 0) printf(", ");
		printf("%.2f", ((vector)vec)[i]);
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
	scalar inv_src = 1 / src;
	binary_operation_scalar(dest, *=, inv_src);
}

any
vector_set_scalars(any dest, scalar src[], slacsz src_amount) {
	for (slacsz i = 0; i < src_amount; i++) {
		((vector)dest)[i] = src[i];
	}
	return dest;
}

scalar
vector_dot(any vec1, any vec2) {
	scalar dot = 0;
	for (slacsz i = 0; i < vector_size(vec1); i++) {
		scalar v1_times_v2 = ((vector)vec1)[i];
		if (vector_size(vec2) > i) v1_times_v2 *= ((vector)vec2)[i];
		dot += v1_times_v2;
	}
	return dot;
}

scalar
vector_mag_squared(any vec) {
	scalar mag = 0;
	for (slacsz i = 0; i < vector_size(vec); i++)
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
	for (slacsz i = 0; i < vector_size(vec1); i++) {
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
vector_cross_to(any dest, any src) {
	if (vector_size(dest) != 3 || vector_size(src) != 3) return NULL;

	scalar 
	a=((vector)dest)[1]*((vector)src)[2]-((vector)dest)[2]*((vector)src)[1],
	b=((vector)dest)[2]*((vector)src)[0]-((vector)dest)[0]*((vector)src)[2],
	c=((vector)dest)[0]*((vector)src)[1]-((vector)dest)[1]*((vector)src)[0];

	((vector)dest)[0] = a;
	((vector)dest)[1] = b;
	((vector)dest)[2] = c;
	return dest;
}

_Bool
vector_compare_array(any vecs[]) {
	if (vecs[0] == NULL) return 0;
	for (slacsz i = 1; vecs[i]; i++) {
		if (vector_size(vecs[0]) != vector_size(vecs[i])) return 0;
		for (slacsz j = 0; j < vector_size(vecs[0]); j++)
			if (((vector)(vecs[0]))[j] != ((vector)(vecs[i]))[j]) return 0;
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
	return !vector_compare(vec1, vector(vector_size(vec1)))
			&& !vector_compare(vec2, vector(vector_size(vec2)))
			&& vector_dot(vec1, vec2) == 0;
}

scalar
vector_angle(any vec1, any vec2) {
	scalar angle = vector_dot(vec1, vec2);
	angle /= vector_mag(vec1) * vector_mag(vec2);
	angle = acos(angle);
	return angle;
}

