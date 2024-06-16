#ifndef VECTOR_H
#define VECTOR_H

#include <stdlib.h>
#include <stdio.h>

typedef struct {
  size_t len;
  size_t capacity;
  int* data;
} Vec;

// create a new vector
Vec VECTOR_new();

// create a new vector with a given capacity
Vec VECTOR_new_with_capacity(size_t capacity);

// push a value to the vector
void VECTOR_push(Vec* vec, int val);

// insert a value
void VECTOR_insert(Vec* vec, size_t index, int val);

// free the vector
void VECTOR_free(Vec* vec);

// print the vector
void VECTOR_print(Vec* vec);

// get value at a given index
int VECTOR_get_index(Vec* vec, size_t index);

// set value at a given index
void VECTOR_set_index(Vec* vec, size_t index, int val);

#endif
