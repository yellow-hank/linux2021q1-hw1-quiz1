#include "nr_quick_sort.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include<time.h>

static node_t* list_make_node_t(node_t *list, int value)
{
    node_t *p = malloc(sizeof(node_t));
    if(!p)
        return list;
    p->value = value;
    if(!list) {
        return p;
    } else {
        p->next = list;
        list = p;
        return list;
    }
        
}

static void list_free(node_t** list)
{
    node_t *i;
    for(;*list;) {
        i = *list;
        *list = (*list)->next;
        free(i);
    }
}

static bool list_is_ordered(node_t *list) {
    bool first = true;
    int value;
    while (list) {
        if (first) {
            value = list->value;
            first = false;
        } else {
            if (list->value < value)
                return false;
            value = list->value;
        }
        list = list->next;
    }
    return true;
}

static void list_display(node_t *list) {
    printf("%s IN ORDER : ", list_is_ordered(list) ? "   " : "NOT");
    while (list) {
        printf("%d ", list->value);
        list = list->next;
    }
    printf("\n");
}

int main(int argc, char **argv) {
    size_t count = 20;
    srand(time(NULL));
    node_t *list = NULL;
    while (count--)
        list = list_make_node_t(list, rand() % 1024);

    list_display(list);
    nr_quicksort(&list);
    list_display(list);

    if (!list_is_ordered(list))
        return EXIT_FAILURE;

    list_free(&list);
    return EXIT_SUCCESS;
}