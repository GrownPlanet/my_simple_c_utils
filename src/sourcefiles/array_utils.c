#include "array_utils.h"

void print_array(int* arr, size_t len) {
  printf("["); 
  for (int i = 0; i < len - 1; i++) { 
    printf("%d, ", arr[i]);
  } 
  printf("%d", arr[len - 1]); 
  printf("]\n");
}
