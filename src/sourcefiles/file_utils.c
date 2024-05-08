#include "file_utils.h"

char* read_to_string(char* filename) {
  FILE* file = fopen(filename, "r");

  if (file == NULL) {
    printf("Failed to open file!\n");
    exit(1);
  }

  fseek(file, 0L, SEEK_END);
  int file_len = ftell(file);
  rewind(file);

  char* file_data = (char*)malloc(sizeof(char) * file_len);

  if (file_data == NULL) {
    printf("malloc failed!\n");
    exit(1);
  }

  for (int i = 0; i < file_len; i++) {
    char c = fgetc(file);
    file_data[i] = c;
  }

  fclose(file);

  return file_data;
}
