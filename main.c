#include "strlst.h"
#include <errno.h>
#include <stdio.h>


int main(){
    strlst_t* list = (strlst_t*)(malloc(sizeof(strlst_t)));;
    if (list == NULL) {
        perror("memory allocation error");
    }
    if (read_lines(list) < 0) {
        perror("sring list error:");
        exit(0);
    }

    delete_list(list);
    exit(0);
}


