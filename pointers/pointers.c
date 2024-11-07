#include <stdlib.h> // for malloc & free
#include <stdio.h>
#include <string.h> // for strlcpy
#include "utils.h"

#define LENGTH 50

void test_malloc(void) {
  char *s = malloc(sizeof(*s) * LENGTH);
  if (s == NULL) {
    printf("out of memory!\n");
    return;
  }
  strncpy(s, "Hello, dynamic memory!", LENGTH); // C99
  // strncpy_s(s, 50, "Hello, dynamic string!", LENGTH); // C11 Visual Studio
  // strlcpy(s, "Hello, dynamic memory!", LENGTH); // BSD
  printf("%s\n", s);
  free(s);
}

void print_char_array(char s[]) {
  UNUSED(s);
}

void print_char_pointer(char *s) {
  UNUSED(s);
}

void test_print(void) {
}

int my_strncmp(char *a, char *b , int maxlen) {
  UNUSED(a); UNUSED(b); UNUSED(maxlen);
  return 0;
}


void test_my_strncmp(void) {
}

void print_array_of_pointers(const char *a[], int len) {
  UNUSED(a); UNUSED(len);
}

void test_array_of_pointers(void) {
}

void test_pointer_of_pointer(void) {
}

void test_function_pointer(void) {
}

void test_struct(void) {
}


int main(void) {
  test_malloc();
  test_print();
  test_my_strncmp();
  test_array_of_pointers();
  test_pointer_of_pointer();
  test_function_pointer();
  test_struct();

  return 0;
}
