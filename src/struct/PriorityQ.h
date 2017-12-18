#ifndef __PRIORITYQ_
#define __PRIORITYQ_

#include <stdbool.h>

int ** pq_initiate();
bool pq_empty(int **);
void pq_insert(int * **, char, int);
int pq_pop(int * **);

int pq_parent(int);
int pq_left(int);
int pq_right(int);

void pq_insert_order(int * **, int);
void pq_pop_order(int * **, int);
void pq_swap(int * **, int , int);
#endif
