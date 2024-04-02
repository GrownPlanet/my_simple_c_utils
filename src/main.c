#include<stdio.h>

#include "string_utils.h"
#include "array_utils.h"
#include "vector.h"

int main() {
  {
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
  }
  printf("\n");

  {
    // print array
    printf("Split a string by a specific char\n");
    int array[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int size = sizeof(array) / sizeof(int);
    printf("array: \n");
    print_array(array, size);
  }
  printf("\n");

  {
    printf("vectors\n");

    Vec vector = new_vec(16);

    print_vec(&vector);
    for(int i = 0; i < 20; i++) {
      push_vec(&vector, i);
    }
    insert_vec(&vector, 10, 99);
    print_vec(&vector);

    set_vec(&vector, 11, 100);
    printf("%d\n", get_vec(&vector, 11));

    free(vector.data);
  }
  printf("\n");

  return 0;
}
