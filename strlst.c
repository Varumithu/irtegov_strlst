#include "strlst.h"

#include <stdlib.h>
#include <stdio.h>

#define BUFSIZE 50

int read_lines(strlst_t* return_value){
    strlst_t res;
    res.amount = 0;

    res.first = (strlst_node_t*)(malloc(sizeof(strlst_node_t)));
    if (res.first == NULL) {
        return -1;
    }
    strlst_node_t* cur = res.first;
    cur->prev = NULL;
    cur->next = NULL;
    cur->content = NULL;
    char temp;
    size_t linelength = 0, allocs = 1;
    cur->content = (char*)(malloc(sizeof(char) * BUFSIZE));
    if (cur->content == NULL) {
        return -1;
    }
    FILE* debug = fopen("text.txt", "r");
    //FILE* debug = stdin;
    while (fscanf(debug, "%c", &temp) == 1) {
        if (temp == '\n') {
            cur->next = (strlst_node_t*)(malloc(sizeof(strlst_node_t)));
            if (cur->next == NULL) {
                return -1;
            }
            cur->content[linelength] = '\0';
            cur->next->next = NULL;
            cur->next->prev = cur;
            cur = cur->next;
            linelength = 0;
            allocs = 1;
            ++res.amount;
            cur->content = (char*)(malloc(sizeof(char) * BUFSIZE));
            if (cur->content == NULL) {
                return -1;
            }
        }
        else if (linelength == 0 && temp == '.'){
            --res.amount;
            cur = cur->prev;
            free(cur->next->content);
            free(cur->next);
            cur->next = NULL;
            break;
        }
        else if (linelength >= BUFSIZE * allocs) {
            ++linelength;
            ++allocs;
            cur->content = realloc(cur->content, BUFSIZE * allocs);
            if (cur->content == NULL){
                //TODO
            }
            cur->content[linelength - 1] = temp;
        }
        else {
            ++linelength;
            cur->content[linelength - 1] = temp;  
        }
    }

    *return_value = res;
    return 0;
}

void delete_list(strlst_t* obj){
   strlst_node_t* cur = obj->first;
   while (cur != NULL) {
        free(cur->content);
        strlst_node_t* temp = cur;
        cur = cur->next;
        free(temp);
        
    }
   free(obj);
}






