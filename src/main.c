#include<stdio.h>

#include "file_utils.h"
#include "string_utils.h"
#include "array_utils.h"
#include "vector.h"

int main() {
  {
    // split a strign by a char
    printf("Split a string by a specific char\n");
    const char* s = "Hello, World!";
    printf("string: %s, char: ' '\n", s);
    struct SplitString raw_output = STRINGU_split_by(s, ' ');

    char** split_string = raw_output.strings;
    int len = raw_output.len;

    printf("split string: ");
    ARRAYU_print_string(split_string, len);

    free(split_string);
  }
  printf("\n");

  {
    printf("print an array:\n");
    int array[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int size = sizeof(array) / sizeof(int);
    ARRAYU_print_int(array, size);
  }
  printf("\n");

  {
    printf("vectors\n");

    Vec vector = VECTOR_new_with_capacity(16);

    VECTOR_print(&vector);
    for(int i = 0; i < 20; i++) {
      VECTOR_push(&vector, i);
    }
    VECTOR_insert(&vector, 10, 99);
    VECTOR_print(&vector);

    VECTOR_set_index(&vector, 11, 100);
    printf("11nth val: %d\n", VECTOR_get_index(&vector, 11));

    VECTOR_free(&vector);
  }
  printf("\n"):

  {
    printf("reading a file to string\n");

    char* filename = "src/headerfiles/file_utils.h";
    printf("filename: %s\n", filename);
    char* file = read_to_string(filename);
    printf("file:\n%s", file);
  }
  printf("\n");

  return 0;
}
