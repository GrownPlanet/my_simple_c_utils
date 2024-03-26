#pragma once

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct SplitString {
  char** strings;
  int len;
};

struct SplitString split_by(const char* string, char ch);
