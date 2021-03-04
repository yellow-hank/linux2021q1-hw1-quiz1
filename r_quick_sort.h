#ifndef R_QUICK_SORT_H
#define R_QUICK_SORT_H
typedef struct __node {                   
    int value;
    struct __node *next;
} node_t;


void quicksort(node_t **list);
#endif