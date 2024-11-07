#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "list.h"

typedef struct node {
  int value;
  struct node *next;
} node_t;

// NOTE: definition of struct list
// already typedef'd to list_t
struct list {
  node_t *first;
  int n;
};
