#include <stdio.h>
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

  destroy(&list); // NOTE: & => address of pointer

  return 0;
}
