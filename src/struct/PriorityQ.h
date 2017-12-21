#ifndef __PRIORITYQ_
#define __PRIORITYQ_

#include <stdbool.h>

#include "struct/HNode.c"

bool pq_empty(h_node **);
void pq_insert(h_node **, char, int);
void pq_insertNode(h_node **, h_node *);
h_node * pq_pop(h_node **);
h_node * pq_peek(h_node **);
int get_pq_size();


int pq_parent(int);
int pq_left(int);
int pq_right(int);

void pq_insert_order(h_node **, int);
void pq_pop_order(h_node **, int);
void pq_swap(h_node **, int , int);
#endif
