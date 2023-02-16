#ifndef SLAC_MATRIX_H_
#define SLAC_MATRIX_H_
#include <alloca.h>
#include <slac/types.h>
#include <stdio.h>

slac_any slac_setup_matrix_memory(slacsz rows, slacsz cols, slac_any mat, slac_scalar *init_values);

#define slac_matrix(rows, cols, ...) (\
	slac_setup_matrix_memory(\
		(rows), (cols),\
		alloca(sizeof(slacsz) * 2 + sizeof(slac_scalar) * (cols) * (rows)),\
		SLAC_VANUM(__VA_ARGS__) > 0 ? (slac_scalar []){ __VA_ARGS__ } : NULL\
	)\
)
#define slac_matrix_rows(mat) *(((slacsz *)(mat)) - 2)
#define slac_matrix_cols(mat) *(((slacsz *)(mat)) - 1)

slac_any slac_matrix_set_identity(slac_any mat);
#define slac_matrix_identity(arg1, ...) (\
	SLAC_VANUM(__VA_ARGS__) > 0 ?\
		slac_matrix_set_identity(slac_matrix(arg1, __VA_ARGS__))\
	:\
		slac_matrix_set_identity((slac_any)arg1)\
)

void slac_matrix_print(slac_any mat);
void slac_matrix_printf(slac_any mat);
#define slac_matrix_printl(mat) do {\
	slac_matrix_print(mat);\
	putchar('\n');\
} while(0)

#ifdef __USING_SLAC__
#define setup_matrix_memory slac_setup_matrix_memory
#define matrix slac_matrix
#define matrix_rows slac_matrix_rows
#define matrix_cols slac_matrix_cols
#define matrix_set_identity slac_matrix_set_identity
#define matrix_identity slac_matrix_identity;
#define matrix_print slac_matrix_print
#define matrix_printf slac_matrix_printf
#define matrix_printl slac_matrix_printl
#endif

#endif/*SLAC_MATRIX_H_*/
