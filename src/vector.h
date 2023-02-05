#ifndef SLAC_VECTOR_H_
#define SLAC_VECTOR_H_

typedef float *vector;

void *setup_vector_memory(unsigned int size, void *header, void *vec);

#define vector(size, ...) setup_vector_memory(\
	size,\
	(float [size]) { 0##__VA_ARGS__ },\
	(unsigned int [1]){ 0 }\
)

#define vector_size(vec) *(((unsigned int *)(vec)) - 1)

#endif/*SLAC_VECTOR_H_*/
