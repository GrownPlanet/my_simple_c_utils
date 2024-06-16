#include "vector.h"

#define die(s, ...) printf(s, ##__VA_ARGS__); exit(1);

Vec VECTOR_new() {
  int* data = (int*)malloc(0);

  if (data == NULL) {
    die("malloc failed\n");
  }

  int len = 0;
  int capacity = 0;

  Vec vector = {len, capacity, data};

  return vector;
}

Vec VECTOR_new_with_capacity(size_t capacity) {
  size_t len = 0;
  int* data = (int*)malloc(sizeof(int) * capacity);

  if (data == NULL) {
    die("malloc failed!\n");
  }

  Vec vector = {len, capacity, data};

  return vector;
}

void VECTOR_push(Vec* vec, int val) {
  if (vec->len >= vec->capacity) {
    if (vec -> capacity == 0) {
      vec-> capacity += 1;
    }

    vec->capacity *= 2;
    vec->data = (int*)realloc(vec->data, vec->capacity * sizeof(int));

    if(vec->data == NULL) {
      die("realloc failed!\n");
    }
  }

  vec->data[vec->len] = val;
  vec->len++;
}

void VECTOR_insert(Vec* vec, size_t index, int val) {
  if (index > vec->len) {
    die("index (= %ld) should be greater or equal than the len (= %ld)\n", index, vec->len);
  }

  if (vec->len >= vec->capacity) {
    vec->capacity *= 2;
    vec->data = (int*)realloc(vec->data, vec->capacity * sizeof(int));

    if(vec->data == NULL) {
      die("realloc failed\n");
    }
  }

  for (int i = vec->len - 1; i >= index; i--) {
    vec->data[i + 1] = vec->data[i];
  }
  vec->data[index] = val;

  vec->len++;
}

int VECTOR_get_index(Vec* vec, size_t index) {
  return vec->data[index];
}

void VECTOR_set_index(Vec* vec, size_t index, int val) {
  vec->data[index] = val;
}

void VECTOR_free(Vec* vec) {
  free(vec->data);
}

void VECTOR_print(Vec* vec) {
  printf("lenght: %ld, capacity: %ld\n", vec->len, vec->capacity);
  if (vec->len > 0) {
    printf("[");
    for(int i = 0; i < vec->len - 1; i++) {
      printf("%d, ", vec->data[i]);
    }
    printf("%d]\n", vec->data[vec->len-1]);
  } else {
    printf("[]\n");
  }
}
