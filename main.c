#include<stdio.h>

#include "headerfiles/utils.h"

int main() {
  const char* s = "Hello, World!";
  struct SplitString raw_output = split_by(s, ' ');

  char** split_string = raw_output.strings;
  int len = raw_output.len;

  printf("[");
  for (int i = 0; i < len - 1; i++) {
    printf("\"%s\", ", split_string[i]);
  }
  printf("\"%s\"", split_string[len - 1]);
  printf("]\n");

  free(split_string);
  return 0;
}
