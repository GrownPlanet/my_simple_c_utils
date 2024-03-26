#include<stdio.h>

#include "headerfiles/utils.h"

int main() {
  // split a strign by a char
  printf("Split a string by a specific char\n");
  const char* s = "Hello, World!";
  printf("string: %s, char: ' '\n", s);
  struct SplitString raw_output = split_by(s, ' ');

  char** split_string = raw_output.strings;
  int len = raw_output.len;

  printf("split string: [");
  for (int i = 0; i < len - 1; i++) {
    printf("\"%s\", ", split_string[i]);
  }
  printf("\"%s\"", split_string[len - 1]);
  printf("]\n");

  free(split_string);

  // calculate average
  printf("Split a string by a specific char\n");
  int array[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  int size = sizeof(array) / sizeof(int);
  printf("array: ");
  print_array(array, size);
  float aver = average(array, size);
  printf("%f\n", aver);

  return 0;
}
