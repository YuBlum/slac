# Getting Started

## Linking the library

Now that you have SLAC installed into your system all you need to do is link the library to your project. Here are some examples on how to do this with GCC and Clang, but the process must be very simillar among all compilers.
<br />

#### GCC
```bash
cc -o <output> <c-file> -lslac
```
#### Clang
```bash
clang -o <output> <c-file> -lslac
```
<br />
As you can see the process is exactly equal in the two compilers, and as I already stated in most of the compilers it's something like that as well.

## Including the headers

All the header files are located in a folder called *slac* so for example to include the vector header you do:
```c
#include <slac/vector.h>
```
You can also include a general header that will include all the header files at once the name of this header is *slac.h*.

### Prefix

All functions, structs, macros, etc... use a prefix, and yeah you guessed the prefix is **slac**. So for example if I want to create two vectors then print the sum of the two I will have to do something like this:
```c
#include <slac/slac.h>

int
main(void) {
	slac_vector a = slac_vector(2, 3);
	slac_vector b = slac_vector(4, 6);
	slac_vector_printl(slac_vector_add(a, b));
	return 0;
}
```
**OUTPUT:**
```bash
[ 6, 9 ]
```

This is done to prevent conflicts with other libraries that you might have, but if you're 100% sure that there will not be any conflicts and you dont wanna type *slac\_this* *slac\_that* all the time you can "remove" the prefix. All you have to do is define this macro:
```c
#define __USING_SLAC__
```
But remember it has to be **BEFORE** the include files, if you define it after then it'll not work.
With the macro defined the same code from before can be written like this:
```c
#define __USING_SLAC__
#include <slac/slac.h>

int
main(void) {
	vector a = vector(2, 3);
	vector b = vector(4, 6);
	vector_printl(vector_add(a, b));
	return 0;
}
```
