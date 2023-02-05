#ifndef SLAC_VECTOR_H_
#define SLAC_VECTOR_H_
#include <alloca.h>

typedef void *slac_any;
typedef float *slac_vector;

slac_any slac_setup_vector_memory(unsigned int size, slac_any vec, unsigned int init_amount, float *init_values);
#define slac_vector(size, ...) slac_setup_vector_memory(\
	size,\
	alloca(sizeof(unsigned int) + sizeof(float) * size),\
	sizeof((float []){ 0##__VA_ARGS__ }) / sizeof(float),\
	(float []){ 0##__VA_ARGS__ }\
)
#define slac_vector_size(vec) *(((unsigned int *)(vec)) - 1)

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

#ifdef __USING_SLAC__
#define any slac_any
#define vector slac_vector
#define setup_vecto_memory slac_setup_vector_memory
#define vector_size slac_vector_size
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
#endif/*__USING_SLAC__*/

#endif/*SLAC_VECTOR_H_*/
