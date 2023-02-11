#ifndef SLAC_TYPES_H_
#define SLAC_TYPES_H_

typedef void *slac_any;
typedef float slac_scalar;
typedef slac_scalar *const slac_vector;

typedef union {
	struct { slac_scalar x, y; };
	struct { slac_scalar r, g; };
	struct { slac_scalar s, t; };
} *const slac_vector2;
typedef union {
	struct { slac_scalar x, y, z; };
	struct { slac_scalar r, g, b; };
	struct { slac_scalar s, t, p; };
} *const slac_vector3;
typedef union {
	struct { slac_scalar x, y, z, w; };
	struct { slac_scalar r, g, b, a; };
	struct { slac_scalar s, t, p, q; };
} *const slac_vector4;

#ifdef __USING_SLAC__
#define any slac_any
#define scalar slac_scalar
#define vector slac_vector
#define vector2 slac_vector2
#define vector3 slac_vector3
#define vector4 slac_vector4
#endif/*__USING_SLAC__*/

#endif/*SLAC_TYPES_H_*/
