#ifndef STRING_UTILS_H
#define STRING_UTILS_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// return type when splitting a string
struct SplitString {
  char** strings;
  int len;
};

// split a string by a given char
struct SplitString STRINGU_split_by(const char* string, char ch);

#endif
