# Types
The only difference between a vector type and another is simply how he access the elements of a vector.

## Generic vector type
This type of vector acts like an array. With this type you can make vectors with N elements. the name of this type is simply ```vector```.

### Examples of usage
```c
vector a = vector(2);
vector b = vector(3);
vector c = vector(4);

vector d = vector(10);
```

### Accessing elements
```c
vector v = vector(3, 4);
float a = v[0]; /* a = 3 */
float b = v[1]; /* b = 4 */
```

## Specific vector types (vector2, vector3, vector4)
This types of vectors are structs so with them you can access vectors members as members of a struct.

### Examples of usage
```c
vector2 a = vector(1, 2);
vector3 b = vector(1, 2, 3);
vector4 c = vector(1, 2, 3, 4);
```

### Acessing elements
All these vector types are in reality not just a simple struct, but multiple structs merged into a union, this is done so you can access the same elements with specific names.

Here are the definition of the unions:
```c
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
```
As you can see you can access the first element of a vector with the variables **x**, **r** and **s**.

But since vectors are arrays in memory, these types are all pointers, so to access the elements you have to do something like:
```c
vector2 v = vector(3, 4);
float a = v->x; /* a = 3 */
float b = v->y; /* a = 4 */
```

Note that you can also do:
```c
vector4 v = vector(1, 2);
```
But I strongly advise you not to, because when you access for example ```v->w``` you'll be acessing memory that isn't yours causing undefined behaviour.
