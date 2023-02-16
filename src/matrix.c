#define __USING_SLAC__
#include <slac/matrix.h>

any
setup_matrix_memory(slacsz rows, slacsz cols, any mat, scalar *init_values) {
	((slacsz *)mat)[0] = rows;
	((slacsz *)mat)[1] = cols;
	mat += sizeof(slacsz) * 2;
	for (slacsz i = 0; i < rows * cols; i++) {
		((scalar *)mat)[i] = init_values ? init_values[i] : 0;
	}
	return mat;
}

any
matrix_set_identity(any mat) {
	for (slacsz i = 0; i < matrix_rows(mat); i++) {
		for (slacsz j = 0; j < matrix_cols(mat); j++) {
			((scalar *)mat)[i * matrix_cols(mat) + j] = i == j ? 1 : 0;
		}
	}
	return mat;
}

void
matrix_print(any mat) {
	printf("[ ");
	for (slacsz i = 0; i < matrix_rows(mat); i++) {
		if (i > 0) printf("; ");
		for (slacsz j = 0; j < matrix_cols(mat); j++) {
			if (j > 0) printf(", ");
			printf("%.1f", ((scalar*)mat)[i * matrix_cols(mat) + j]);
		}
	}
	printf(" ]\n");
}

void
matrix_printf(any mat) {
	for (slacsz i = 0; i < matrix_rows(mat); i++) {
		for (slacsz j = 0; j < matrix_cols(mat); j++) {
			if (j > 0) printf(", ");
			printf("%.1f", ((scalar*)mat)[i * matrix_cols(mat) + j]);
		}
		printf("\n");
	}
}
