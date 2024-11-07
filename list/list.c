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

//-----------------------------------------------------------------------------
list_t* create_list() { 
  list_t *list = malloc(sizeof(list_t));
  if (list == NULL) // propagate error
    return NULL;

  list->first = NULL;
  list->n = 0;
  return list;
} 

int length(list_t *list) { 
  assert(list != NULL);
  return list->n;
} 

static node_t* create_node(int value) { 
  node_t *n = malloc(sizeof(node_t));
  if (n == NULL)
  return NULL;

  n->value = value;
  n->next = NULL;
  return n;
} 

bool prepend(list_t *list, int value) { 
  node_t *new_node = create_node(value);

  if (new_node == NULL) {
    printf("WARNING: out of memory, could not prepend node\n");
    return false;
  } else {
    new_node->next = list->first;
    list->first = new_node;
    list->n++;
    return true;
  }
} 
