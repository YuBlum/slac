# Functions and macros

- [vector\_size()](./vector_functions_macros.html#vector_size)
- [vector\_copy()](./vector_functions_macros.html#vector_copy)
- [vector\_print()](./vector_functions_macros.html#vector_print)
- - [vector\_printl()](./vector_functions_macros.html#vector_printl)
- [vector\_set()](./vector_functions_macros.html#vector_set)
- - [vector\_set\_vector()](./vector_functions_macros.html#vector_set_vector)
- - [vector\_set\_scalar()](./vector_functions_macros.html#vector_set_scalar)
- [vector\_add()](./vector_functions_macros.html#vector\_add)
- - [vector\_add\_to()](./vector_functions_macros.html#vector\_add\_to)
- - - [vector\_add\_vector\_to()](./vector_functions_macros.html#vector\_add\_vector\_to)
- - - [vector\_add\_scalar\_to()](./vector_functions_macros.html#vector\_add\_scalar\_to)
- - [vector\_add\_vector()](./vector_functions_macros.html#vector\_add\_vector)
- - [vector\_add\_scalar()](./vector_functions_macros.html#vector\_add\_scalar)
- [vector\_sub()](./vector_functions_macros.html#vector\_sub)
- - [vector\_sub\_to()](./vector_functions_macros.html#vector\_sub\_to)
- - - [vector\_sub\_vector\_to()](./vector_functions_macros.html#vector\_sub\_vector\_to)
- - - [vector\_sub\_scalar\_to()](./vector_functions_macros.html#vector\_sub\_scalar\_to)
- - [vector\_sub\_vector()](./vector_functions_macros.html#vector\_sub\_vector)
- - [vector\_sub\_scalar()](./vector_functions_macros.html#vector\_sub\_scalar)
- [vector\_mul()](./vector_functions_macros.html#vector\_mul)
- - [vector\_mul\_to()](./vector_functions_macros.html#vector\_mul\_to)
- - - [vector\_mul\_vector\_to()](./vector_functions_macros.html#vector\_mul\_vector\_to)
- - - [vector\_mul\_scalar\_to()](./vector_functions_macros.html#vector\_mul\_scalar\_to)
- - [vector\_mul\_vector()](./vector_functions_macros.html#vector\_mul\_vector)
- - [vector\_mul\_scalar()](./vector_functions_macros.html#vector\_mul\_scalar)
- [vector\_div()](./vector_functions_macros.html#vector\_div)
- - [vector\_div\_to()](./vector_functions_macros.html#vector\_div\_to)
- - - [vector\_div\_vector\_to()](./vector_functions_macros.html#vector\_div\_vector\_to)
- - - [vector\_div\_scalar\_to()](./vector_functions_macros.html#vector\_div\_scalar\_to)
- - [vector\_div\_vector()](./vector_functions_macros.html#vector\_div\_vector)
- - [vector\_div\_scalar()](./vector_functions_macros.html#vector\_div\_scalar)
- [vector\_dot()](./vector_functions_macros.html#vector\_dot)
- [vector\_mag()](./vector_functions_macros.html#vector\_mag)
- - [vector\_mag\_squared()](./vector_functions_macros.html#vector\_mag\_squared)
- [vector\_dist()](./vector_functions_macros.html#vector\_dist)
- - [vector\_dist\_squared()](./vector_functions_macros.html#vector\_dist\_squared)
- [vector\_normalize()](./vector_functions_macros.html#vector\_normalize)
- - [vector\_normalize\_to()](./vector_functions_macros.html#vector\_normalize\_to)
- [vector\_cross()](./vector_functions_macros.html#vector\_cross)
- - [vector\_cross\_to()](./vector_functions_macros.html#vector\_cross\_to)
- [vector\_compare()](./vector_functions_macros.html#vector\_compare)
- - [vector\_compare\_array()](./vector_functions_macros.html#vector\_compare\_array)
- [vector\_orthogonal()](./vector_functions_macros.html#vector\_orthogonal)
- [vector\_perpendicular()](./vector_functions_macros.html#vector\_perpendicular)
- [vector\_angle()](./vector_functions_macros.html#vector\_angle)

## vector\_size

This is a macro that returns the numbers of elements in a vector.

### Arguments
**vec** : vector to get the number of elements.

### Returns
Numbers of elements of a vector as a unsigned int value.

### Usage example
```c
vector v = vector(1, 2, 3, 4, 5, 6);
printf("%u\n", vector_size(v));
```
```bash
OUTPUT:

6
```

## vector\_copy

This is a macro that copies a vector into a new vector and return it.

### Arguments
**vec** : vector to be copied.

### Returns
A copy of the vector passed as an argument.

### Usage example
```c
vector a = (1, 2, 3);
vector3 b = vector_copy(a);
b->x += 2;
vector_printl(b);
```
```bash
OUTPUT:

[ 3, 2, 3 ]
```

## vector\_print

This is a helper function for printing a vector.

## Arguments
**vec** : vector to be printed.

## Usage example
```c
vector v = vector(4, 8);
vector_print(v);
printf(" <- this is a vector\n")
```
```bash
OUTPUT:

[ 4, 8 ] <- this is a vector
```

## vector\_printl

This is a macro that expands from the [vector\_print](./vector_print.html#vector_printvec) function, so it prints a vector and automatically adds a new line.

## Arguments
**vec** : vector to be printed.

## Usage example
```c
vector v = vector(4, 8);
vector_printl(v);
printf(" <- this is a vector\n")
```
```bash
OUTPUT:

[ 4, 8 ]
 <- this is a vector
```

## vector\_set\_vector

This is a function that copy the elements of a vector to another vector.

### Arguments
**dest** : vector that will be set.

**src** : vector to get elements from.

### Returns
The destination vector.

### Usage example
```c
vector a = vector(1, 2, 3);
vector b = vector(3);
vector_set_vector(b, a);
vector_printl(a);
vector_printl(b);
```
```bash
OUTPUT:

[ 1, 2, 3 ]
[ 1, 2, 3 ]
```

## vector\_set\_scalar

This is a functiona that set all the elements of a vector to a given scalar.

### Arguments
**dest** : vector that will be set.

**src** : the scalar that will be copied into the **dest** elements.

### Returns
The destination vector.

### Usage example
```c
vector v = vector(4);
vector_set_scalar(v, 8);
vector_printl(v);
```
```bash
OUTPUT:

[ 8, 8, 8, 8 ]
```

## vector\_set

This is a wrapper macro that will call [vector\_set\_vector](vector\_functions\_macros.html#vector\_set\_vector) or [vector\_set\_scalar](vector\_functions\_macros.html#vector\_set\_scalar) depending on the **src** argument type.

### Arguments
**dest** : vector that will be set.

**src** : vector or scalar that will be copied into **dest**.

### Returns
The destination vector.

### Usage example
```c
vector v = vector(4);
vector_set(v, 8);
vector_printl(v);
vector_set(v, vector(1, 2, 3, 4));
vector_printl(v);
```
```bash
OUTPUT:

[ 8, 8, 8, 8 ]
[ 1, 2, 3, 4 ]
```

## vector\_add\_vector\_to

This is a function that adds the elements of a vector to another vector.

### Arguments
**dest** : left hand side and the destination of the addition.

**src** : right hand side of the addition.

### Returns
The destination vector.

### Usage example
```c
vector a = vector(1, 2);
vector b = vector(3, 4);
vector_add_vector_to(a, b);
vector_printl(a);
```
```bash
OUTPUT:

[ 4, 6 ]
```

## vector\_add\_scalar\_to

This is a function that adds a scalar to all the elements of a vector.

### Arguments
**dest** : left hand side and the destination of the addition.

**src** : right hand side of the addition.

### Returns
The destination vector.

### Usage example
```c
vector v = vector(2, 4);
vector_add_scalar_to(a, 1);
vector_printl(a);
```
```bash
OUTPUT:

[ 3, 5 ]
```

## vector\_add\_to

This is a wrapper macro that will call [vector\_add\_vector\_to](vector\_functions\_macros.html#vector\_add\_vector\_to) or [vector\_add\_scalar\_to](vector\_functions\_macros.html#vector\_add\_scalar\_to) depending on the **src** argument type.

### Arguments
**dest** : left hand side and the destination of the addition.

**src** : right hand side of the addition.

### Returns
The destination vector.

### Usage example
```c
vector v = vector(1, 1, 1);
vector_printl(v);

vector_add_to(v, 3);
vector_printl(v);

vector_add_to(v, vector(1, 2, 3));
vector_printl(v);
```
```bash
OUTPUT:

[ 1, 1, 1 ]
[ 4, 4, 4 ]
[ 5, 6, 7 ]
```

## vector\_add\_vector

This is a macro that adds the elements of a vector to another vector and returns a new vector with the result.

### Arguments
**vec1** : left hand side of the addition.

**vec2** : right hand side of the addition.

### Returns
A new vector with the result of the addition between **vec1** and **vec2**.

### Usage example
```c
vector a = vector(1, 2);
vector b = vector(3, 4);
vector c = vector_add_vector(a, b);

vector_printl(a);
vector_printl(b);
vector_printl(c);
```
```bash
OUTPUT:

[ 1, 2 ]
[ 3, 4 ]
[ 4, 6 ]
```

## vector\_add\_scalar

This is a macro that adds a scalar to all the elements of a vector and returns a new vector with the result.

### Arguments
**vec** : left hand side of the addition.

**val** : right hand side of the addition.

### Returns
A new vector with the result of the addition between **vec** and **val**.

### Usage example
```c
vector a = vector(2, 4);
vector b = vector_add_scalar(a, 2);
vector_printl(a);
vector_printl(b);
```
```bash
OUTPUT:

[ 2, 4 ]
[ 4, 6 ]
```

## vector\_add

This is a wrapper macro that will call [vector\_add\_vector](vector\_functions\_macros.html#vector\_add\_vector) or [vector\_add\_scalar](vector\_functions\_macros.html#vector\_add\_scalar) depending on the **val** argument type.

### Arguments
**vec** : left hand side and the destination of the addition.

**val** : right hand side of the addition.

### Returns
A new vector with the result of the addition between **vec** and **val**.

### Usage example
```c
vector a = vector(1, 1, 1);
vector_printl(a);

vector b = vector_add(a, 3);
vector_printl(b);

vector c = vector_add(a, vector(1, 2, 3));
vector_printl(c);
```
```bash
OUTPUT:

[ 1, 1, 1 ]
[ 4, 4, 4 ]
[ 2, 3, 4 ]
```

## vector\_sub\_vector\_to

This is a function that subs the elements of a vector to another vector.

### Arguments
**dest** : left hand side and the destination of the subtraction.

**src** : right hand side of the subtraction.

### Returns
The destination vector.

### Usage example
```c
vector a = vector(3, 4);
vector b = vector(1, 2);
vector_sub_vector_to(a, b);
vector_printl(a);
```
```bash
OUTPUT:

[ 2, 2 ]
```

## vector\_sub\_scalar\_to

This is a function that subs a scalar to all the elements of a vector.

### Arguments
**dest** : left hand side and the destination of the subtraction.

**src** : right hand side of the subtraction.

### Returns
The destination vector.

### Usage example
```c
vector v = vector(2, 4);
vector_sub_scalar_to(a, 1);
vector_printl(a);
```
```bash
OUTPUT:

[ 1, 3 ]
```

## vector\_sub\_to

This is a wrapper macro that will call [vector\_sub\_vector\_to](vector\_functions\_macros.html#vector\_sub\_vector\_to) or [vector\_sub\_scalar\_to](vector\_functions\_macros.html#vector\_sub\_scalar\_to) depending on the **src** argument type.

### Arguments
**dest** : left hand side and the destination of the subtraction.

**src** : right hand side of the subtraction.

### Returns
The destination vector.

### Usage example
```c
vector v = vector(5, 6, 7);
vector_printl(v);

vector_sub_to(v, 3);
vector_printl(v);

vector_sub_to(v, vector(1, 2, 3));
vector_printl(v);
```
```bash
OUTPUT:

[ 5, 6, 7 ]
[ 2, 3, 4 ]
[ 1, 1, 1 ]
```

## vector\_sub\_vector

This is a macro that subs the elements of a vector to another vector and returns a new vector with the result.

### Arguments
**vec1** : left hand side of the subtraction.

**vec2** : right hand side of the subtraction.

### Returns
A new vector with the result of the subtraction between **vec1** and **vec2**.

### Usage example
```c
vector a = vector(3, 4);
vector b = vector(1, 2);
vector c = vector_sub_vector(a, b);

vector_printl(a);
vector_printl(b);
vector_printl(c);
```
```bash
OUTPUT:

[ 3, 4 ]
[ 1, 2 ]
[ 2, 2 ]
```

## vector\_sub\_scalar

This is a macro that subs a scalar to all the elements of a vector and returns a new vector with the result.

### Arguments
**vec** : left hand side of the subtraction.

**val** : right hand side of the subtraction.

### Returns
A new vector with the result of the subtraction between **vec** and **val**.

### Usage example
```c
vector a = vector(2, 4);
vector b = vector_sub_scalar(a, 2);
vector_printl(a);
vector_printl(b);
```
```bash
OUTPUT:

[ 2, 4 ]
[ 0, 2 ]
```

## vector\_sub

This is a wrapper macro that will call [vector\_sub\_vector](vector\_functions\_macros.html#vector\_sub\_vector) or [vector\_sub\_scalar](vector\_functions\_macros.html#vector\_sub\_scalar) depending on the **val** argument type.

### Arguments
**vec** : left hand side and the destination of the subtraction.

**val** : right hand side of the subtraction.

### Returns
A new vector with the result of the subtraction between **vec** and **val**.

### Usage example
```c
vector a = vector(4, 5, 6);
vector_printl(a);

vector b = vector_sub(a, 3);
vector_printl(b);

vector c = vector_sub(a, vector(1, 2, 3));
vector_printl(c);
```
```bash
OUTPUT:

[ 4, 5, 6 ]
[ 1, 2, 3 ]
[ 3, 3, 3 ]
```

## vector\_mul\_vector\_to

This is a function that muls the elements of a vector to another vector.

### Arguments
**dest** : left hand side and the destination of the multiplication.

**src** : right hand side of the multiplication.

### Returns
The destination vector.

### Usage example
```c
vector a = vector(1, 2);
vector b = vector(3, 4);
vector_mul_vector_to(a, b);
vector_printl(a);
```
```bash
OUTPUT:

[ 3, 8 ]
```

## vector\_mul\_scalar\_to

This is a function that muls a scalar to all the elements of a vector.

### Arguments
**dest** : left hand side and the destination of the multiplication.

**src** : right hand side of the multiplication.

### Returns
The destination vector.

### Usage example
```c
vector v = vector(2, 4);
vector_mul_scalar_to(a, 2);
vector_printl(a);
```
```bash
OUTPUT:

[ 4, 8 ]
```

## vector\_mul\_to

This is a wrapper macro that will call [vector\_mul\_vector\_to](vector\_functions\_macros.html#vector\_mul\_vector\_to) or [vector\_mul\_scalar\_to](vector\_functions\_macros.html#vector\_mul\_scalar\_to) depending on the **src** argument type.

### Arguments
**dest** : left hand side and the destination of the multiplication.

**src** : right hand side of the multiplication.

### Returns
The destination vector.

### Usage example
```c
vector v = vector(1, 1, 1);
vector_printl(v);

vector_mul_to(v, 3);
vector_printl(v);

vector_mul_to(v, vector(1, 2, 3));
vector_printl(v);
```
```bash
OUTPUT:

[ 1, 1, 1 ]
[ 3, 3, 3 ]
[ 3, 6, 9 ]
```

## vector\_mul\_vector

This is a macro that muls the elements of a vector to another vector and returns a new vector with the result.

### Arguments
**vec1** : left hand side of the multiplication.

**vec2** : right hand side of the multiplication.

### Returns
A new vector with the result of the multiplication between **vec1** and **vec2**.

### Usage example
```c
vector a = vector(1, 2);
vector b = vector(3, 4);
vector c = vector_mul_vector(a, b);

vector_printl(a);
vector_printl(b);
vector_printl(c);
```
```bash
OUTPUT:

[ 1, 2 ]
[ 3, 4 ]
[ 3, 8 ]
```

## vector\_mul\_scalar

This is a macro that muls a scalar to all the elements of a vector and returns a new vector with the result.

### Arguments
**vec** : left hand side of the multiplication.

**val** : right hand side of the multiplication.

### Returns
A new vector with the result of the multiplication between **vec** and **val**.

### Usage example
```c
vector a = vector(2, 4);
vector b = vector_mul_scalar(a, 2);
vector_printl(a);
vector_printl(b);
```
```bash
OUTPUT:

[ 2, 4 ]
[ 4, 8 ]
```

## vector\_mul

This is a wrapper macro that will call [vector\_mul\_vector](vector\_functions\_macros.html#vector\_mul\_vector) or [vector\_mul\_scalar](vector\_functions\_macros.html#vector\_mul\_scalar) depending on the **val** argument type.

### Arguments
**vec** : left hand side and the destination of the multiplication.

**val** : right hand side of the multiplication.

### Returns
A new vector with the result of the multiplication between **vec** and **val**.

### Usage example
```c
vector a = vector(3, 3, 3);
vector_printl(a);

vector b = vector_mul(a, 3);
vector_printl(b);

vector c = vector_mul(a, vector(1, 2, 3));
vector_printl(c);
```
```bash
OUTPUT:

[ 3, 3, 3 ]
[ 9, 9, 9 ]
[ 3, 6, 9 ]
```

## vector\_div\_vector\_to

This is a function that divs the elements of a vector to another vector.

### Arguments
**dest** : left hand side and the destination of the division.

**src** : right hand side of the division.

### Returns
The destination vector.

### Usage example
```c
vector a = vector(8, 9);
vector b = vector(2, 3);
vector_div_vector_to(a, b);
vector_printl(a);
```
```bash
OUTPUT:

[ 4, 3 ]
```

## vector\_div\_scalar\_to

This is a function that divs a scalar to all the elements of a vector.

### Arguments
**dest** : left hand side and the destination of the division.

**src** : right hand side of the division.

### Returns
The destination vector.

### Usage example
```c
vector v = vector(2, 4);
vector_div_scalar_to(a, 2);
vector_printl(a);
```
```bash
OUTPUT:

[ 1, 2 ]
```

## vector\_div\_to

This is a wrapper macro that will call [vector\_div\_vector\_to](vector\_functions\_macros.html#vector\_div\_vector\_to) or [vector\_div\_scalar\_to](vector\_functions\_macros.html#vector\_div\_scalar\_to) depending on the **src** argument type.

### Arguments
**dest** : left hand side and the destination of the division.

**src** : right hand side of the division.

### Returns
The destination vector.

### Usage example
```c
vector v = vector(12, 12, 12);
vector_printl(v);

vector_div_to(v, 2);
vector_printl(v);

vector_div_to(v, vector(1, 2, 6));
vector_printl(v);
```
```bash
OUTPUT:

[ 12, 12, 12 ]
[ 6, 6, 6 ]
[ 6, 3, 1 ]
```

## vector\_div\_vector

This is a macro that divs the elements of a vector to another vector and returns a new vector with the result.

### Arguments
**vec1** : left hand side of the division.

**vec2** : right hand side of the division.

### Returns
A new vector with the result of the division between **vec1** and **vec2**.

### Usage example
```c
vector a = vector(8, 9);
vector b = vector(2, 3);
vector c = vector_div_vector(a, b);

vector_printl(a);
vector_printl(b);
vector_printl(c);
```
```bash
OUTPUT:

[ 8, 9 ]
[ 2, 3 ]
[ 4, 3 ]
```

## vector\_div\_scalar

This is a macro that divs a scalar to all the elements of a vector and returns a new vector with the result.

### Arguments
**vec** : left hand side of the division.

**val** : right hand side of the division.

### Returns
A new vector with the result of the division between **vec** and **val**.

### Usage example
```c
vector a = vector(2, 4);
vector b = vector_div_scalar(a, 2);
vector_printl(a);
vector_printl(b);
```
```bash
OUTPUT:

[ 2, 4 ]
[ 1, 2 ]
```

## vector\_div

This is a wrapper macro that will call [vector\_div\_vector](vector\_functions\_macros.html#vector\_div\_vector) or [vector\_div\_scalar](vector\_functions\_macros.html#vector\_div\_scalar) depending on the **val** argument type.

### Arguments
**vec** : left hand side and the destination of the division.

**val** : right hand side of the division.

### Returns
A new vector with the result of the division between **vec** and **val**.

### Usage example
```c
vector a = vector(12, 12, 12);
vector_printl(a);

vector b = vector_div(a, 2);
vector_printl(b);

vector c = vector_div(a, vector(1, 2, 6));
vector_printl(c);
```
```bash
OUTPUT:

[ 12, 12, 12 ]
[ 6, 6, 6 ]
[ 12, 6, 2 ]
```

## vector\_dot

This is a function to get the dot product between two vectors.

### Arguments
**vec1** : first vector to the dot operation.

**vec2** : second vector to the dot operation.

### Returns
The dot product between **vec1** and **vec2** which is a scalar (a.k.a float).

### Usage example
```c
vector i = vector(1, 0);
vector j = vector(0, 1);

printf("%.1f\n", vector_dot(i, j));
```
```bash
OUTPUT:

0.0
```

## vector\_mag\_squared

This is a function to get the squared magnitude of a vector.

If you ever need the magnitude squared use this function for better performance.

### Arguments
**vec** : vector to get the magnitude.

### Returns
The magnitude of **vec** squared.

### Usage example
```c
vector v = vector(3, 2);
printf("%.2f\n", vector_mag_squared(v));
```
```bash
OUTPUT:

13.00
```

## vector\_mag

This is a function to get the magnitude of a vector.

### Arguments
**vec** : vector to get the magnitude.

### Returns
The magnitude of **vec**.

### Usage example
```c
vector v = vector(3, 2);
printf("%.2f\n", vector_mag(v));
```
```bash
OUTPUT:

3.61
```

## vector\_dist\_squared

This is a function to get the squared distance between two vectors.

If you ever need the distance squared use this function for better performance.

### Arguments
**vec1** : starting vector of the distance.
**vec2** : ending vector of the distance.

### Returns
The distance between **vec1** and **vec2** squared.

### Usage example
```c
vector a = vector(4.120f, 2);
vector b = vector(6.355f, 9);
printf("%.2f\n", vector_dist_squared(a, b));
```
```bash
OUTPUT:

69.00
```

## vector\_dist

This is a function to get the distance between two vectors.

### Arguments
**vec1** : starting vector of the distance.
**vec2** : ending vector of the distance.

### Returns
The distance between **vec1** and **vec2**.

### Usage example
```c
vector a = vector(4.120f, 2);
vector b = vector(6.355f, 9);
printf("%.2f\n", vector_dist(a, b));
```
```bash
OUTPUT:

8.31
```

## vector\_normalize\_to

This is function normalizes a vector and stores the result in the same vector.

### Arguments
**vec** : vector to be normalized.

### Returns
The **vec** vector.

### Usage example
```c
vector v = vector(8, 3);
vector_normalize_to(v);
vector_printl(v);
```
```bash
OUTPUT:

[ 0.94, 0.35 ]
```

## vector\_normalize

This is macro that normalizes a vector and stores the result in a new vector.

### Arguments
**vec** : vector to be normalized.

### Returns
A new vector with the **vec** vector normalized.

### Usage example
```c
vector a = vector(8, 3);
vector b = vector_normalize(v);
vector_printl(a);
vector_printl(b);
```
```bash
OUTPUT:

[ 8.00, 3.00 ]
[ 0.94, 0.35 ]
```

## vector\_cross\_to

This is function that get the cross product between two vectors with 3 dimensions and stores the result in the **dest** vector.

### Arguments
**dest** : left hand side and the destination of the cross product.

**src** : right hand side.

### Returns
The **dest** vector.

### Usage example
```c
vector a = vector(8, 3, 2);
vector b = vector(1, -4, 9);
vector_cross_to(a, b);
vector_printl(a);
vector_printl(b);
```
```bash
OUTPUT:

[ 35.00, -70.00, -35.00 ]
[ 1.00, -4.00, 9.00 ]
```

## vector\_cross

This is macro that get the cross product between two vectors with 3 dimensions and stores the result in a new vector.

### Arguments
**vec1** : left hand side.

**vec2** : right hand side.

### Returns
A new vector with the cross product between **vec1** and **vec2**.

### Usage example
```c
vector a = vector(8, 3, 2);
vector b = vector(1, -4, 9);
vector c = vector_cross(a, b);
vector_printl(a);
vector_printl(b);
vector_printl(c);
```
```bash
OUTPUT:

[ 8.00, 3.00, 2.00 ]
[ 1.00, -4.00, 9.00 ]
[ 35.00, -70.00, -35.00 ]
```

## vector\_compare\_array

This is function that compare if all vectors in a array are equal, this function continues to compare the vectors until find ***NULL*** on the array.

### Arguments
**vecs** : array of vectors.

### Returns
If all the vectors in the array are equal returns 1, if the sizes or the elements are not equal then it returns 0.

### Usage example
```c
any vecs[] = {
	vector(8, 3, 2),
	vector(8, 3, 2),
	vector(8, 3),
	NULL
};
printf("%s\n", vector_compare_array(vecs) ? "equal" : "not equal");
```
```bash
OUTPUT:

not equal
```

## vector\_compare

This is wrapper macro for comparing vectors, it automatically creates an array and calls [vector\_compare\_array](./vector_functions_macros.html#vector_compare_array).

### Arguments
This macro is variadic, all the arguments must be vectors.

### Returns
If all the vectors passed are equal returns 1, if the sizes or the elements are not equal then it returns 0.

### Usage example
```c
vector a = vector(8, 3, 2);
vector b = vector(8, 3, 2);
vector c = vector(8, 3);
printf("%s\n", vector_compare(a, b) ? "equal" : "not equal");
printf("%s\n", vector_compare(a, b, c) ? "equal" : "not equal");
```
```bash
OUTPUT:

equal
not equal
```

## vector\_orthogonal

This functions check if two vectors are orthogonal.

### Arguments
**vec1** vector to be checked.

**vec2** vector to be checked.

### Returns
If the vectors are orthogonal to each other returns 1, if not return 0.

### Usage example
```c
vector a = vector(1, 0);
vector b = vector(0, 1);
printf("orthogonal : %s\n", vector_orthogonal(a, b) ? "true" : "false");
vector c = vector(0, 0);
vector d = vector(1, 1);
printf("orthogonal : %s\n", vector_orthogonal(c, d) ? "true" : "false");
```
```bash
OUTPUT:

orthogonal : true
orthogonal : true
```

## vector\_perpendicular

This functions check if two vectors are perpendicular.

### Arguments
**vec1** vector to be checked.

**vec2** vector to be checked.

### Returns
If the vectors are perpedicular to each other returns 1, if not return 0.

### Usage example
```c
vector a = vector(1, 0);
vector b = vector(0, 1);
printf("perpendicular : %s\n", vector_perpendicular(a, b) ? "true" : "false");
vector c = vector(0, 0);
vector d = vector(1, 1);
printf("perpendicular : %s\n", vector_perpendicular(c, d) ? "true" : "false");
```
```bash
OUTPUT:

perpendicular : true
perpendicular : false
```

## vector\_angle

Get the angle between two vectors.

### Arguments
**vec1** vector to get the angle.

**vec2** vector to get the angle.

### Returns
Returns the angle between **vec1** and **vec2** in radians.

### Usage example
```c
vector a = vector(1, 0);
vector b = vector(0, 1);
printf("%f\n", vector_angle(a, b));
```
```bash
OUTPUT:

1.570796
```
