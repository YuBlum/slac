# SLAC

## SLAC stands for Simple Linear Algebra for C, and as the name suggests this project is... a simple linear algebra library for C! To be more especific it uses the C11 standard.

SLAC is designed to be a simple, intuitive and low cost linear algebra library. The fundamental principles of this library are simplicity and readability, so it may not perform best among other linear algebra libraries, but it's definitely not slow. So if you are looking for something simple, stylish and don't care so much about having the best possible performance, this library is for you!

## Goals of SLAC

- [ ] Vectors with N sizes.
- [ ] Vector operations.
- [ ] Built in vector types E.g. vector2.
- [ ] Be easy to create new vector types E.g. vector6.
- [ ] Matrix with N rows and M columns.
- [ ] Matrix basic operations (matrix addition and matrix subtraction).
- [ ] Matrix complex operations E.g. multiplication, determinant, inverse.
- [ ] Built in matrix type E.g. matrix3x3.
- [ ] Like vectors be easy to create new matrices types E.g. matrix5x2.
- [ ] Transformations for 2D and 3D vectors.
- [ ] Transformations for projections and views.

## How to use

### Installation
Clone the repository and in the terminal enter the following command:
```bash
sudo make clean install
```

### Linking the library
After the instalation you will need link SLAC to your project.
Heres an example using GCC:
```bash
cc -o <name-of-output> <name-of-c-file>.c -lslac
```

Than is just include the header files to your c file. All the header files are in a **slac** folder, for example to include the header file with vectors youdo:
```c
#include <slac/vector.h>
```

### Removing the prefix of functions
you will probably notice that all the functions, struct, etc, are using the prefix slac, for example to make a vector you write something like:
```c
slac_vector vec = slac_vector(2);
```

But if you're annoyed by that and would preffer to write like this:
```c
vector vec = vector(2);
```

It's totally possible all you have to do is define *__USING_SLAC__* **before** including the header files of slac E.g.:
```c
#define __USING_SLAC__
#include <slac/vectors.h>
```
