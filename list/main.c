#include <stdio.h>
#include <assert.h>
#include "list.h"

#define DEBUG(X) printf("%s -> %d\n", (#X), (X))

void print_int(int value) { 
  printf("%d, ", value);
} 

int main(void) {
  list_t *list = create_list();
  DEBUG(length(list));
  print_list(list);

  prepend(list, 1);
  prepend(list, 0);
  DEBUG(length(list));
  print_list(list);

  for_each(list, print_int);
  printf("\n");

  DEBUG(is_sorted(list));
  insert(list, 4);
  insert(list, 3);
  insert(list, 8);
  insert(list, 0);
  insert(list, 3);
  insert(list, 2);
  print_list(list);
  DEBUG(is_sorted(list));
  append(list, 0);
  print_list(list);
  DEBUG(is_sorted(list));

  DEBUG(contains(list, 3));
  DEBUG(contains(list, 4));
  
  int n = length(list);
  print_list(list);
  delete_first(list, 20);
  assert(n == length(list));
  print_list(list);
  delete_all(list, 20);
  assert(n == length(list));
  print_list(list);
  delete_first(list, 0);
  assert(n - 1 == length(list));
  print_list(list);
  delete_first(list, 1);
  assert(n - 2 == length(list));
  print_list(list);
  delete_all(list, 0);
  assert(n - 4 == length(list));
  print_list(list);
  delete_all(list, 3);
  assert(n - 6 == length(list));
  print_list(list);
  delete_all(list, 2);
  assert(n - 7 == length(list));
  print_list(list);
  delete_all(list, 4);
  assert(n - 8 == length(list));
  print_list(list);
  delete_all(list, 8);
  assert(n - 9 == length(list));
  print_list(list);
  delete_all(list, 10);
  assert(0 == length(list));
  print_list(list);

  destroy(&list); // NOTE: & => address of pointer

  return 0;
}
