# Initialization

## The **vector()** macro

Vectors are initialized using the ```vector()``` macro. You can use this macro in two different ways:

The first one is just giving the amount of elements the vector will have.
```c
vector v = vector(2);
```
This create a vector with 2 elements and initilize all elements to zero before return it.

The second method is to pass the values of all elements in the vector.
```c
vector v = vector(3, 5);
```
This create a vector with 2 elements, it will give the values 3 for the first and 5 for the second element, after that return it.

## Memory layout
Vectors have the following layout in memory:
```
[ 2 ][ 5,3 ]
  ^     ^
  |     |
size elements
```
So what's returned to you in the ```vector()``` macro is the elements part, that way you can access all the members as it was just a regular array.

## Freeing memory
You don't have to worry about freeing any memory with vectors, all vectors are allocated on the stack, just like normal variables.

Please keep the amount of vectors elements low, if you, for example, try to create a vector with 1000000 elements the chances of stack overflow is pretty high. Knowing that try to not create unnecessary vectors.
