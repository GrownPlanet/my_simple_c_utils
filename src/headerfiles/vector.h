#ifndef VECTOR_H
#define VECTOR_H

#include <stdlib.h>
#include <stdio.h>

typedef struct {
  size_t len;
  size_t capacity;
  int* data;
} Vec;

// create a new vector with a given capacity
Vec new_vec(size_t capacity);

// push a value to the vector
void push_vec(Vec* vec, int val);

// insert a value
void insert_vec(Vec* vec, size_t index, int val);

// free the vector
void free_vec(Vec* vec);

// print the vector
void print_vec(Vec* vec);

// get value at a given index
int get_vec(Vec* vec, size_t index);

// set value at a given index
void set_vec(Vec* vec, size_t index, int val);

#endif
