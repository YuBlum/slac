#ifndef SLAC_VECTOR_H_
#define SLAC_VECTOR_H_
#include <alloca.h>

typedef void *slac_any;
typedef float *const slac_vector;

#define SLAC_VANUM(...) (sizeof((float []){ 0,##__VA_ARGS__ }) / sizeof(float))

slac_any slac_setup_vector_memory(unsigned char size, slac_any vec, int init_amount, float *init_values);
#define slac_vector(arg1 /* can be used as the size or the first member of the vector */, ...) (SLAC_VANUM(__VA_ARGS__) > 1 ?\
	slac_setup_vector_memory(\
		SLAC_VANUM(__VA_ARGS__),\
		alloca(sizeof(unsigned char) + sizeof(float) * (SLAC_VANUM(__VA_ARGS__) % 0xff)),\
		SLAC_VANUM((arg1), __VA_ARGS__) % 0xff,\
		(float []){ 0, (arg1), __VA_ARGS__ }\
	) :\
	slac_setup_vector_memory(\
		(arg1),\
		alloca(sizeof(unsigned char) + sizeof(float) * ((arg1) % 0xff)),\
		0, NULL\
	)\
)
#define slac_vector_size(vec) *(((unsigned char *)(vec)) - 1)

void slac_vector_print(slac_any vec);
#define slac_vector_printl(vec) do {\
	slac_vector_print(vec);\
	putchar('\n');\
} while(0)

slac_any slac_vector_copy_to(slac_any dest, slac_any src);
slac_any slac_vector_add_to(slac_any dest, slac_any src);
slac_any slac_vector_sub_to(slac_any dest, slac_any src);
slac_any slac_vector_mul_to(slac_any dest, slac_any src);
slac_any slac_vector_div_to(slac_any dest, slac_any src);

#define slac_vector_copy(vec) slac_vector_copy_to(\
	slac_vector(slac_vector_size(vec)), vec\
)
#define slac_vector_add(vec1, vec2) slac_vector_add_to(\
	slac_vector_copy(vec1), vec2\
)
#define slac_vector_sub(vec1, vec2) slac_vector_sub_to(\
	slac_vector_copy(vec1), vec2\
)
#define slac_vector_mul(vec1, vec2) slac_vector_mul_to(\
	slac_vector_copy(vec1), vec2\
)
#define slac_vector_div(vec1, vec2) slac_vector_div_to(\
	slac_vector_copy(vec1), vec2\
)

float slac_vector_dot(slac_any vec1, slac_any vec2);
float slac_vector_mag_squared(slac_any vec);
float slac_vector_mag(slac_any vec);
float slac_vector_dist_squared(slac_any vec1, slac_any vec2);
float slac_vector_dist(slac_any vec1, slac_any vec2);

#ifdef __USING_SLAC__
#define any slac_any
#define vector slac_vector
#define setup_vector_memory slac_setup_vector_memory
#define vector_size slac_vector_size
#define vector_print slac_vector_print
#define vector_printl slac_vector_printl
#define vector_copy_to slac_vector_copy_to
#define vector_add_to slac_vector_add_to
#define vector_sub_to slac_vector_sub_to
#define vector_mul_to slac_vector_mul_to
#define vector_div_to slac_vector_div_to
#define vector_copy slac_vector_copy
#define vector_add slac_vector_add
#define vector_sub slac_vector_sub
#define vector_mul slac_vector_mul
#define vector_div slac_vector_div
#define vector_dot slac_vector_dot
#define vector_mag_squared slac_vector_mag_squared
#define vector_mag slac_vector_mag
#define vector_dist_squared slac_vector_dist_squared
#define vector_dist slac_vector_dist
#endif/*__USING_SLAC__*/

#endif/*SLAC_VECTOR_H_*/
