#ifndef SLAC_VECTOR_H_
#define SLAC_VECTOR_H_
#include <alloca.h>

typedef void *slac_any;
typedef float scalar;
typedef scalar *const slac_vector;
typedef union {
	struct { float x, y; };
	struct { float r, g; };
	struct { float s, t; };
} *slac_vector2;
typedef union {
	struct { float x, y, z; };
	struct { float r, g, b; };
	struct { float s, t, p; };
} *slac_vector3;
typedef union {
	struct { float x, y, z, w; };
	struct { float r, g, b, a; };
	struct { float s, t, p, q; };
} *slac_vector4;

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

#define SLAC_VANUM(...) (sizeof((scalar []){ 0,##__VA_ARGS__ }) / sizeof(scalar))

slac_any slac_setup_vector_memory(unsigned char size, slac_any vec, int init_amount, scalar *init_values);

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
			alloca(sizeof(unsigned char) + sizeof(scalar) * (SLAC_VANUM(__VA_ARGS__) % 0xff)),/* 2. */\
			SLAC_VANUM((arg1), __VA_ARGS__) % 0xff,\
			(scalar []){ 0, (arg1), __VA_ARGS__ }\
		) \
	:\
		slac_setup_vector_memory(\
			(arg1),\
			alloca(sizeof(unsigned char) + sizeof(scalar) * ((arg1) % 0xff)),/* 2. */\
			0, NULL\
		)\
)
#define slac_vector_size(vec) *(((unsigned char *)(vec)) - 1)

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

slac_any slac_vector_set_scalar(slac_any dest, scalar src);
slac_any slac_vector_add_scalar_to(slac_any dest, scalar src);
slac_any slac_vector_sub_scalar_to(slac_any dest, scalar src);
slac_any slac_vector_mul_scalar_to(slac_any dest, scalar src);
slac_any slac_vector_div_scalar_to(slac_any dest, scalar src);

#define slac_vector_copy(vec) slac_vector_set_vector(slac_vector(slac_vector_size(vec)), vec)

#define slac_vector_add_vector(vec1, vec2) slac_vector_add_vector_to(slac_vector_copy(vec1), vec2)
#define slac_vector_sub_vector(vec1, vec2) slac_vector_sub_vector_to(slac_vector_copy(vec1), vec2)
#define slac_vector_mul_vector(vec1, vec2) slac_vector_mul_vector_to(slac_vector_copy(vec1), vec2)
#define slac_vector_div_vector(vec1, vec2) slac_vector_div_vector_to(slac_vector_copy(vec1), vec2)

#define slac_vector_add_scalar(vec1, vec2) slac_vector_add_scalar_to(slac_vector_copy(vec1), vec2)
#define slac_vector_sub_scalar(vec1, vec2) slac_vector_sub_scalar_to(slac_vector_copy(vec1), vec2)
#define slac_vector_mul_scalar(vec1, vec2) slac_vector_mul_scalar_to(slac_vector_copy(vec1), vec2)
#define slac_vector_div_scalar(vec1, vec2) slac_vector_div_scalar_to( slac_vector_copy(vec1), vec2)

#define slac_vector_set(dest, src) (__SLAC_WRAPPER_VECTOR_TO_VECTOR__(slac_vector_set, src)(dest, dest, src))
#define slac_vector_add_to(dest, src) (__SLAC_WRAPPER_VECTOR_TO_VECTOR__(slac_vector_add, dest, src))
#define slac_vector_sub_to(dest, src) (__SLAC_WRAPPER_VECTOR_TO_VECTOR__(slac_vector_sub, dest, src))
#define slac_vector_mul_to(dest, src) (__SLAC_WRAPPER_VECTOR_TO_VECTOR__(slac_vector_mul, dest, src))
#define slac_vector_div_to(dest, src) (__SLAC_WRAPPER_VECTOR_TO_VECTOR__(slac_vector_div, dest, src))
#define slac_vector_add(vec1, vec2) (__SLAC_WRAPPER_VECTOR_TO_COPY__(slac_vector_add, vec1, vec2))
#define slac_vector_sub(vec1, vec2) (__SLAC_WRAPPER_VECTOR_TO_COPY__(slac_vector_sub, vec1, vec2))
#define slac_vector_mul(vec1, vec2) (__SLAC_WRAPPER_VECTOR_TO_COPY__(slac_vector_mul, vec1, vec2))
#define slac_vector_div(vec1, vec2) (__SLAC_WRAPPER_VECTOR_TO_COPY__(slac_vector_div, vec1, vec2))

scalar slac_vector_dot(slac_any vec1, slac_any vec2);
scalar slac_vector_mag_squared(slac_any vec);
scalar slac_vector_mag(slac_any vec);
scalar slac_vector_dist_squared(slac_any vec1, slac_any vec2);
scalar slac_vector_dist(slac_any vec1, slac_any vec2);
slac_any slac_vector_normalize_to(slac_any vec);
#define slac_vector_normalize(vec) slac_vector_normalize_to(slac_vector_copy(vec))

#ifdef __USING_SLAC__
#define any slac_any
#define vector slac_vector
#define vector2 slac_vector2
#define vector3 slac_vector3
#define vector4 slac_vector4
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
#define vector_dot slac_vector_vector_dot
#define vector_mag_squared slac_vector_mag_squared
#define vector_mag slac_vector_mag
#define vector_dist_squared slac_vector_dist_squared
#define vector_dist slac_vector_dist
#define vector_normalize_to slac_vector_normalize_to
#define vector_normalize slac_vector_normalize
#endif/*__USING_SLAC__*/

#endif/*SLAC_VECTOR_H_*/
