#ifndef SLAC_VECTOR_H_
#define SLAC_VECTOR_H_
#include <alloca.h>
#include <slac/types.h>

#define __SLAC_WRAPPER_VECTOR_TO_VECTOR__(FUNC, dest, src) (_Generic((src),\
	float: (FUNC##_scalar_to),\
	double: (FUNC##_scalar_to),\
	long double: (FUNC##_scalar_to),\
	char: (FUNC##_scalar_to),\
	int: (FUNC##_scalar_to),\
	long: (FUNC##_scalar_to),\
	long long: (FUNC##_scalar_to),\
	unsigned char: (FUNC##_scalar_to),\
	unsigned int: (FUNC##_scalar_to),\
	unsigned long: (FUNC##_scalar_to),\
	unsigned long long: (FUNC##_scalar_to),\
	default: (FUNC##_vector_to)\
))(dest, src)
#define __SLAC_WRAPPER_VECTOR_TO_COPY__(FUNC, vec1, vec2) (_Generic((vec2),\
	float: (FUNC ## _scalar_to),\
	double: (FUNC ## _scalar_to),\
	long double: (FUNC ## _scalar_to),\
	char: (FUNC ## _scalar_to),\
	int: (FUNC ## _scalar_to),\
	long: (FUNC ## _scalar_to),\
	long long: (FUNC ## _scalar_to),\
	unsigned char: (FUNC ## _scalar_to),\
	unsigned int: (FUNC ## _scalar_to),\
	unsigned long: (FUNC ## _scalar_to),\
	unsigned long long: (FUNC ## _scalar_to),\
	default: (FUNC ## _vector_to)\
))(slac_vector_copy(vec1), vec2)

#define SLAC_VANUM(...) (sizeof((slac_scalar []){ 0,##__VA_ARGS__ }) / sizeof(slac_scalar))

slac_any slac_setup_vector_memory(unsigned int size, slac_any vec, unsigned int init_amount, slac_scalar *init_values);

/* slac_vector is a 'constructor' for vectors
 * 1. 'arg1' is using a vague name because it can be used as the size or the 
 * 		first member of the vector.
 * 2. I'm using alloca instead of malloc because I want to simulate the 
 * 		allocation of a normal struct on the stack.
 * 		I'm not using a normal struct because I find it more pleasing to write
 * 		'vec[0]' instead of 'vec.members[0]'.
 * 		And I'm not using a simple array defition like '(float [vec_size]) {0}'
 * 		because than I can't make copies of a vector. 
* */
#define slac_vector(arg1 /* 1. */, ...) (\
	SLAC_VANUM(__VA_ARGS__) > 1 ?\
		slac_setup_vector_memory(\
			SLAC_VANUM(__VA_ARGS__),\
			alloca(sizeof(unsigned int) + sizeof(slac_scalar) * (SLAC_VANUM(__VA_ARGS__))),/* 2. */\
			SLAC_VANUM((arg1), __VA_ARGS__),\
			(slac_scalar []){ 0, (arg1), __VA_ARGS__ }\
		) \
	:\
		slac_setup_vector_memory(\
			(arg1),\
			alloca(sizeof(unsigned int) + sizeof(slac_scalar) * (arg1)),/* 2. */\
			0, NULL\
		)\
)
#define slac_vector_size(vec) *(((unsigned int *)(vec)) - 1)

void slac_vector_print(slac_any vec);
#define slac_vector_printl(vec) do {\
	slac_vector_print(vec);\
	putchar('\n');\
} while(0)

slac_any slac_vector_set_vector(slac_any dest, slac_any src);
slac_any slac_vector_add_vector_to(slac_any dest, slac_any src);
slac_any slac_vector_sub_vector_to(slac_any dest, slac_any src);
slac_any slac_vector_mul_vector_to(slac_any dest, slac_any src);
slac_any slac_vector_div_vector_to(slac_any dest, slac_any src);

slac_any slac_vector_set_scalar(slac_any dest, slac_scalar src);
slac_any slac_vector_add_scalar_to(slac_any dest, slac_scalar src);
slac_any slac_vector_sub_scalar_to(slac_any dest, slac_scalar src);
slac_any slac_vector_mul_scalar_to(slac_any dest, slac_scalar src);
slac_any slac_vector_div_scalar_to(slac_any dest, slac_scalar src);

#define slac_vector_copy(vec) slac_vector_set_vector(slac_vector(slac_vector_size(vec)), vec)

#define slac_vector_add_vector(vec1, vec2) slac_vector_add_vector_to(slac_vector_copy(vec1), vec2)
#define slac_vector_sub_vector(vec1, vec2) slac_vector_sub_vector_to(slac_vector_copy(vec1), vec2)
#define slac_vector_mul_vector(vec1, vec2) slac_vector_mul_vector_to(slac_vector_copy(vec1), vec2)
#define slac_vector_div_vector(vec1, vec2) slac_vector_div_vector_to(slac_vector_copy(vec1), vec2)

#define slac_vector_add_scalar(vec, val) slac_vector_add_scalar_to(slac_vector_copy(vec), val)
#define slac_vector_sub_scalar(vec, val) slac_vector_sub_scalar_to(slac_vector_copy(vec), val)
#define slac_vector_mul_scalar(vec, val) slac_vector_mul_scalar_to(slac_vector_copy(vec), val)
#define slac_vector_div_scalar(vec, val) slac_vector_div_scalar_to( slac_vector_copy(vec), val)

#define slac_vector_set(dest, src) (__SLAC_WRAPPER_VECTOR_TO_VECTOR__(slac_vector_set, src)(dest, dest, src))
#define slac_vector_add_to(dest, src) (__SLAC_WRAPPER_VECTOR_TO_VECTOR__(slac_vector_add, dest, src))
#define slac_vector_sub_to(dest, src) (__SLAC_WRAPPER_VECTOR_TO_VECTOR__(slac_vector_sub, dest, src))
#define slac_vector_mul_to(dest, src) (__SLAC_WRAPPER_VECTOR_TO_VECTOR__(slac_vector_mul, dest, src))
#define slac_vector_div_to(dest, src) (__SLAC_WRAPPER_VECTOR_TO_VECTOR__(slac_vector_div, dest, src))
#define slac_vector_add(vec1, vec2) (__SLAC_WRAPPER_VECTOR_TO_COPY__(slac_vector_add, vec1, vec2))
#define slac_vector_sub(vec1, vec2) (__SLAC_WRAPPER_VECTOR_TO_COPY__(slac_vector_sub, vec1, vec2))
#define slac_vector_mul(vec1, vec2) (__SLAC_WRAPPER_VECTOR_TO_COPY__(slac_vector_mul, vec1, vec2))
#define slac_vector_div(vec1, vec2) (__SLAC_WRAPPER_VECTOR_TO_COPY__(slac_vector_div, vec1, vec2))

slac_scalar slac_vector_dot(slac_any vec1, slac_any vec2);
slac_scalar slac_vector_mag_squared(slac_any vec);
slac_scalar slac_vector_mag(slac_any vec);
slac_scalar slac_vector_dist_squared(slac_any vec1, slac_any vec2);
slac_scalar slac_vector_dist(slac_any vec1, slac_any vec2);
slac_any slac_vector_normalize_to(slac_any vec);
slac_any slac_vector_cross_to(slac_any dest, slac_any src);

#define slac_vector_normalize(vec) slac_vector_normalize_to(slac_vector_copy(vec))
#define slac_vector_cross(vec1, vec2) slac_vector_cross_to(slac_vector_copy(vec1), vec2)

_Bool slac_vector_compare_array(slac_any vecs[]);
#define slac_vector_compare(...) slac_vector_compare_array((slac_any []){ __VA_ARGS__, NULL })

_Bool slac_vector_linear_dependent_array(slac_any vecs[]);
#define slac_vector_linear_dependent(...) slac_vector_linear_dependent_array((slac_any []){ __VA_ARGS__, NULL })

_Bool slac_vector_orthogonal(slac_any vec1, slac_any vec2);
_Bool slac_vector_perpendicular(slac_any vec1, slac_any vec2);

slac_scalar slac_vector_angle(slac_any vec1, slac_any vec2);

#ifdef __USING_SLAC__
#define setup_vector_memory slac_setup_vector_memory
#define vector_size slac_vector_size
#define vector_print slac_vector_print
#define vector_printl slac_vector_printl
#define vector_set_vector slac_vector_set_vector
#define vector_add_vector_to slac_vector_add_vector_to
#define vector_sub_vector_to slac_vector_sub_vector_to
#define vector_mul_vector_to slac_vector_mul_vector_to
#define vector_div_vector_to slac_vector_div_vector_to
#define vector_set_scalar slac_vector_set_scalar
#define vector_add_scalar_to slac_vector_add_scalar_to
#define vector_sub_scalar_to slac_vector_sub_scalar_to
#define vector_mul_scalar_to slac_vector_mul_scalar_to
#define vector_div_scalar_to slac_vector_div_scalar_to
#define vector_copy slac_vector_copy
#define vector_add_vector slac_vector_add_vector
#define vector_sub_vector slac_vector_sub_vector
#define vector_mul_vector slac_vector_mul_vector
#define vector_div_vector slac_vector_div_vector
#define vector_set slac_vector_set
#define vector_add_to slac_vector_add_to
#define vector_sub_to slac_vector_sub_to
#define vector_mul_to slac_vector_mul_to
#define vector_div_to slac_vector_div_to
#define vector_add slac_vector_add
#define vector_sub slac_vector_sub
#define vector_mul slac_vector_mul
#define vector_div slac_vector_div
#define vector_dot slac_vector_dot
#define vector_mag_squared slac_vector_mag_squared
#define vector_mag slac_vector_mag
#define vector_dist_squared slac_vector_dist_squared
#define vector_dist slac_vector_dist
#define vector_normalize_to slac_vector_normalize_to
#define vector_cross_to slac_vector_cross_to
#define vector_normalize slac_vector_normalize
#define vector_cross slac_vector_cross
#define vector_linear_dependent_array slac_vector_linear_dependent_array
#define vector_linear_dependent slac_vector_linear_dependent
#define vector_compare_array slac_vector_compare_array
#define vector_compare slac_vector_compare
#define vector_orthogonal slac_vector_orthogonal
#define vector_perpendicular slac_vector_perpendicular
#define vector_angle slac_vector_angle
#endif/*__USING_SLAC__*/

#endif/*SLAC_VECTOR_H_*/
