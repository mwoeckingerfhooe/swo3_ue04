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

  destroy(&list); // NOTE: & => address of pointer

  return 0;
}
