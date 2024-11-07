#pragma once

#include <stdbool.h>

// NOTE: declare that list_t is short for struct list_t
// it does not need to be known outside what it looks like
typedef struct list list_t;

list_t* create_list(void); 
int length(list_t *list); 
bool prepend(list_t *list, int value);
void print_list(list_t *list);

typedef void (*iterator_t)(int value);
void for_each(list_t *list, iterator_t it);
void destroy(list_t **list_handle);

bool append(list_t *list, int value); 
bool is_sorted(list_t *list); 
bool insert(list_t *list, int value); 
