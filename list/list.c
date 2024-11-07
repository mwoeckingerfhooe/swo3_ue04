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

static void print_node(node_t *node) { 
  printf("%d", node->value);
} 

void print_list(list_t *list) { 
  printf("n=%d: ", list->n);
  node_t *current = list->first;
  while(current != NULL) {
    print_node(current);
    current = current->next;
    if (current != NULL)
      printf(", ");
  }
  printf("\n");
}

void for_each(list_t *list, iterator_t it) { 
  node_t *current = list->first;
  while (current != NULL) {
    it(current->value);
    current = current->next;
  }
} 

// NOTE: list_t** => we can set the pointer to NULL in function
void destroy(list_t **list_handle) { 
  if (*list_handle == NULL)
    return;
  node_t *current = (*list_handle)->first;
  while (current != NULL) {
    node_t *next = current->next;
    free(current);
    current = next;
  }
  free(*list_handle);
  *list_handle = NULL;
} 

bool append(list_t *list, int value) { 
  node_t *new_node = create_node(value);
  if (new_node == NULL)
    return false;
  node_t *current;
  if (list->first == NULL) {
    list->first = new_node;
  } else {
    current = list->first;
    while (current->next != NULL) {
      current = current->next;
    }
    current->next = new_node;
  }
  list->n++;
  return true;
} 

bool is_sorted(list_t *list) { 
  node_t *current = list->first;
  node_t *prev = NULL;
  while (current != NULL) {
    if (prev != NULL && prev->value > current->value)
      return false;
    prev = current;
    current = current->next;
  }
  return true;
} 

bool insert(list_t *list, int value) { 
  assert(is_sorted(list));
  node_t *new_node = create_node(value);
  if (new_node == NULL) {
    return false;
  }
  node_t *curr = list->first;
  node_t *prev = NULL;
  while (curr != NULL && curr->value < value) {
    prev = curr;
    curr = curr->next;
  }
  if (prev == NULL) {
    list->first = new_node;
  } else {
    prev->next = new_node;
  }
  new_node->next = curr;
  list->n++;
  assert(is_sorted(list));
  return true;
}

static node_t* find_next(node_t *start, int value) { 
  node_t *current = start;
  while (current != NULL) {
    if (current->value == value) {
      return current;
    }
    current = current->next;
  }
  return NULL;
} 

bool contains(list_t *list, int value) { 
  return find_next(list->first, value) != NULL;
}
