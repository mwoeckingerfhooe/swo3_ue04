#pragma once

#include <stdbool.h>

// NOTE: declare that list_t is short for struct list_t
// it does not need to be known outside what it looks like
typedef struct list list_t;

list_t* create_list(void); 
int length(list_t *list); 
bool prepend(list_t *list, int value); 
