#include <stdio.h>
#include "list.h"

#define DEBUG(X) printf("%s -> %d\n", (#X), (X))

int main(void) {
  list_t *list = create_list();
  DEBUG(length(list));
  print_list(list);

  prepend(list, 1);
  prepend(list, 0);
  DEBUG(length(list));
  print_list(list);

  return 0;
}
