#include "nr_quick_sort.h"

#include <stdio.h>

static inline void list_add_node_t(node_t **list, node_t *node_t) {
    node_t->next = *list;
    *list = node_t;
}



void nr_quicksort(node_t **list)
{
    #define MAX_LEVELS 1000
    //list is empty or only one in it
    if(!*list || !(*list)->next)
        return;

    int top;//for stack
    node_t *stack[MAX_LEVELS];
    node_t *result =  NULL;
    node_t *pivot ;

    stack[0] = (*list);

    while(top>=0) {

        if(!stack[top]) {
            top--;
            continue;
        }
        if(!stack[top]->next) {
            stack[top]->next = result;
            result = stack[top];
            top--;
            continue;
        }
        pivot = stack[top];
        node_t *n = pivot->next;
        int value = pivot->value;
        pivot->next = NULL; 
        node_t *right = NULL,*left = NULL;
        while(n) {
            node_t *tmp = n;
            n = n->next;
            list_add_node_t(tmp->value > value ? &right : &left, tmp);
        }

        stack[top++] = left;
        stack[top++] = pivot;
        stack[top] = right;

    }

    *list = result;
    return;
}