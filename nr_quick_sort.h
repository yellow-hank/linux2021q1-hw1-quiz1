#ifndef NR_QUICK_SORT_H
#define NR_QUICK_SORT_H
typedef struct __node {                   
    int value;
    struct __node *next;
} node_t;


void nr_quicksort(node_t **list);
#endif