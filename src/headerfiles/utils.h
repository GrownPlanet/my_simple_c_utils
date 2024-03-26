#pragma once

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// return type when splitting a string
struct SplitString {
  char** strings;
  int len;
};

// split a string by a given char
struct SplitString split_by(const char* string, char ch);

// calculate average
float average(int* arr, size_t size);

// print an array
void print_array(int* arr, size_t len);
