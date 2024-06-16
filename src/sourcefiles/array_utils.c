#include "array_utils.h"

void ARRAYU_print_int(int* arr, size_t len) {
  printf("["); 
  for (int i = 0; i < len - 1; i++) { 
    printf("%d, ", arr[i]);
  } 
  printf("%d", arr[len - 1]); 
  printf("]\n");
}

void ARRAYU_print_string(char** arr, size_t len) {
    printf("[");
    for (int i = 0; i < len - 1; i++) {
      printf("\"%s\", ", arr[i]);
    }
    printf("\"%s\"", arr[len - 1]);
    printf("]\n");
}
