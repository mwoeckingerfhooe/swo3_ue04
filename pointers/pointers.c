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
  int x = 123;
  int *p = &x;
  int **pp = &p;
  printf("x = %d\n", x);
  printf("pointer (%p) to x = %d\n", (void*)p, *p);
  printf("pointer (%p) to pointer (%p) to x = %d\n", (void*)pp, (void*)*pp, **pp);
}

int add(int a, int b) { return a + b; } 
int sub(int a, int b) { return a - b; } 
char invalid_int_op(char a, char b) { return a + b;} 

typedef int (*binary_int_op_t)(int, int); 

void test_function_pointer(void) {
  binary_int_op_t ops[] = {&add, &sub};
  ops[0] = invalid_int_op; // still works, produces compiler warning
  for (size_t i = 0; i<ALEN(ops); i++) {
    printf("operation %zu: result = %d\n", i, ops[i](3, 5));
  }
}

typedef struct address { 
  char street[40]; // NOTE: must contain size or be pointer
  int nr;
  int zip;
  char *city; // NOTE: for pointer, only address is copied
} address_t; 

void print_address(const address_t* a) {
  // printf("%s %d\n%d %s\n", a.street, a.nr, a.zip, a.city);
  printf("%s %d\n%d %s\n", (*a).street, a->nr, a->zip, a->city);
}

void test_struct(void) {
  address_t a;
  strncpy(a.street, "Softwarepark", ALEN(a.street));
  a.nr = 11;
  a.zip = 4232;
  a.city = malloc(sizeof(*a.city) * 50);
  if (a.city == NULL) {
    printf("out of memory!\n");
    return;
  }
  strncpy(a.city, "Hagenberg", 50);
  // print_address(a);
  print_address(&a);

  printf("copying address...\n");
  address_t a2 = a; // NOTE: copied
  // print_address(a2);
  print_address(&a2);

  printf("updating address 1...\n");
  // strncpy(a.street, "Hauptplatz", 40);
  // a.nr = 1;
  // a.zip = 4020;
  strncpy(a.city, "LINZ!", 50); // NOTE: city now both Linz

  printf("address 1:\n");
  // print_address(a);
  print_address(&a);

  printf("address 2 (implicitly updated through common pointer):\n");
  // print_address(a2);
  print_address(&a2);

  free(a.city); // NOTE: always free allocated memory
  printf("sizeof(a) = %zu", sizeof(a));
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
