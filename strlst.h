#ifndef _MYSTRLISTDOTH_
#define _MYSTRLISTDOTH_

#include <stdlib.h>

typedef struct strlst_node {
    char* content;
    struct strlst_node* prev, *next;
} strlst_node_t;

typedef struct strlst {
    strlst_node_t* first;
    size_t amount;

} strlst_t;

int read_lines(strlst_t* return_value);

void delete_list(strlst_t* obj);

#endif 

