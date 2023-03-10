# SLAC

SLAC stands for Simple Linear Algebra for C, and as the name suggests this project is... a simple linear algebra library for C! To be more especific it uses the C11 standard.

*Note that this is just an overview, if you want something more in depth you can check the [documentation](https://yublum.github.io/slac/).*

### Who this library is for

SLAC is designed to be a simple, intuitive and low memory cost linear algebra library. The fundamental principles of this library are simplicity and readability, so it may not perform best among other linear algebra libraries, but it's definitely not slow. So if you are looking for something simple, stylish and don't care so much about having the best possible performance, this library is for you!

### Goals

- [x] Vectors with N sizes.
- [x] Vector operations.
- [x] Built in vector types E.g. vector2.
- [x] Be easy to create new vector types.
- [ ] Matrix with N rows and M columns.
- [ ] Matrix basic operations (matrix addition and matrix subtraction).
- [ ] Matrix complex operations (multiplication, determinant, inverse).
- [ ] Built in matrix type E.g. matrix3x3.
- [ ] Like vectors be easy to create new matrices types.
- [ ] Transformations for 2D and 3D vectors.
- [ ] Transformations for projections and views.


## Installation

### Linux

Clone the repository and in the terminal enter the following command:
```bash
sudo make clean install
```

### Windows

For now SLAC uses only Makefiles for the installation, but you can try compile it with an external compiler E.g. Visual Studio.

## Usage

After instalation, you will need to link SLAC to your project.
Heres an example using GCC:
```bash
cc -o <name-of-output> <name-of-c-file>.c -lslac
```

Than just include the header files into your c file. All the header files are in a **slac** folder, for example to include the header file with vectors you just need to `#include <slac/vector.h>`. You can also include the *slac.h* header file than all the headers will be included at once.

## Removing the prefix

you will probably notice that everything(functions, structs, etc...) are using the prefix **slac**, for example to make a vector you write something like:
```c
slac_vector vec = slac_vector(1, 2, 3);
```

But if you're annoyed by that and would preffer to write like this:
```c
vector vec = vector(1, 2, 3);
```

It's totally possible, all you have to do is define \_\_USING\_SLAC\_\_ **before** including the header files of slac:
```c
#define __USING_SLAC__
#include <slac/vector.h>
```
