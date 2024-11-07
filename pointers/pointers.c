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
  for (int i = 0; s[i] != '\0'; i++)
    putchar(s[i]);
}

void print_char_pointer(char *s) {
  while (*s != '\0') {
    putchar(*s);
    s++;
  }
}

void test_print(void) {
  char s[] = "Hello, World!\n";
  print_char_array(s);
  print_char_pointer(s);
}

int my_strncmp(char *a, char *b , int maxlen) {
  int i; 
  for (i = 0; i<maxlen && a[i] != '\0' && b[i] != '\0'; i++) { 
    if (a[i] != b[i]) 
      return (int)a[i] - (int)b[i]; 
  } 
  if (a[i] != '\0') return (int)a[i]; 
  if (b[i] != '\0') return -(int)b[i]; 
  return 0; 
}

#define MYCMP(a, b) DEBUG(my_strncmp(a, b, MIN_ALEN(a, b)))

void test_my_strncmp(void) {
  char a[] = "AAA";
  char aa[] = "AAAA";
  char b[] = "AAB";
  char c[] = "C";
  char empty[] = "";

  printf("a = '%s', aa = '%s', b = '%s', c = '%s', empty = '%s'\n",  a, aa, b, c, empty);
  MYCMP(a, aa);
  MYCMP(a, b);
  MYCMP(a, c);
  MYCMP(a, empty);
  MYCMP(aa, b);
  MYCMP(aa, c);
  MYCMP(aa, empty);
  MYCMP(b, c);
}

void print_array_of_pointers(const char *a[], int len) {
  for (int i = 0; i<len; i++) {
    printf("%s ", a[i]);
  }
  printf("\n");
}

void test_array_of_pointers(void) {
  const char *a[] = {"Hello", "dynamic", "array"}; 
  print_array_of_pointers(a, ALEN(a)); 
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
