#include "string_utils.h"

#define checkMalloc(v) if(v==NULL) { printf("malloc failed!\n"); exit(1); }

int count_char(const char* s, char c) {
  int count = 0;
  for (int i = 0; i < strlen(s); i++) {
    if (s[i] == c) {
      count++;
    }
  }
  return count;
}

int* lengs(const char* s, char c, int amount_of_parts) {
  int* lengs = (int*)malloc(sizeof(int) * amount_of_parts);
  checkMalloc(lengs);

  int current = 0;
  for (int i = 0; i < strlen(s); i++) {
    if (s[i] == c) {
      current++;
    } else {
      lengs[current]++;
    }
  }

  return lengs;
}

struct SplitString STRINGU_split_by(const char* str, char ch) {
  int amount_of_parts = count_char(str, ch) + 1;
  int* part_lengs = lengs(str, ch, amount_of_parts);

  char** split_string = (char**)malloc(sizeof(char*) * amount_of_parts);
  checkMalloc(split_string);

  int offset = 0;
  for (int i = 0; i <= amount_of_parts; i++) {
    char* acc = (char*)malloc(sizeof(char) * part_lengs[i]);

    for (int k = 0; k < part_lengs[i]; k++) {
      acc[k] = str[offset + k];
    }
    split_string[i] = acc;

    offset += part_lengs[i] + 1;
  }

  free(part_lengs);

  struct SplitString return_val;

  return_val.strings = split_string;
  return_val.len = amount_of_parts;

  return return_val;
}
