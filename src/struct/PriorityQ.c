#include "PriorityQ.h"

#include <stdlib.h>
#include <stdio.h>

#define CHAR 0
#define FREQ 1

int pq_size = 0;

int ** pq_initiate()
{
	return (int **)malloc(sizeof(int *));
}

bool pq_empty(int ** pq_this)
{
	return !pq_this;
}

void pq_insert(int * ** pq_this, char character, int frequency)
{
	
	++pq_size; //increased size;

	//memory inserstion
	int ** tmp;
	if (!pq_this)
	{
		//allocation
		*pq_this = (int **)malloc(sizeof(int *));
		*pq_this[0] = (int *)malloc(2 *sizeof(int));
		//information
		*pq_this[0][0] = character;
		*pq_this[0][1] = frequency;
	}
	else
	{
		//reallocation
		tmp = (int **)realloc(*pq_this, pq_size);
		if (!tmp)	//memory error
		{
			puts("ERROR : OUT OF MEMORY !");
			exit(1);
		}
		*pq_this = tmp;
		//suballocation
		*pq_this[pq_size - 1] = (int *)malloc(2* sizeof(int));
		//information
		*pq_this[pq_size - 1][CHAR] = character;
		*pq_this[pq_size - 1][FREQ] = frequency;
	}

	pq_insert_order(pq_this, pq_size - 1);
}

int pq_pop(int * ** pq_this)
{
	int character = *pq_this[0][CHAR];
	pq_swap(pq_this, 0, pq_size - 1);
	free(*pq_this[pq_size - 1]);
	free(*(pq_this + pq_size - 1));

	pq_pop_order(pq_this, 0);
	
}
void pq_insert_order(int * ** pq_this, int pos)
{
	int * tmp;
	if (*pq_this[pq_parent(pos)][FREQ] > *pq_this[pos][FREQ])
	{
		pq_swap(pq_this, pos, pq_parent(pos));
		pq_insert_order(pq_this, pq_parent(pos));
	}
	else return;
}
void pq_pop_order(int * ** pq_this, int pos)
{
	if (*pq_this[pos][FREQ] > *pq_this[pq_left(pos)][FREQ] && pq_left(pos) < pq_size)
	{
		pq_swap(pq_this, pos, pq_left(pos));
		pq_pop_order(pq_this, pq_left(pos));
	}
	if (*pq_this[pos][FREQ] > *pq_this[pq_right(pos)][FREQ] && pq_right(pos) < pq_size)
	{
		pq_swap(pq_this, pos, pq_right(pos));
		pq_pop_order(pq_this, pq_right(pos));
	}
	else return;

}
void pq_swap(int * ** pq_this, int prior, int latter)
{
	int ** tmp = 0;
	tmp = *(pq_this + prior);
	*(pq_this + prior) = *(pq_this + latter);
	*(pq_this + latter) = tmp;
}

int pq_parent(int child)
{
	return (child - 1) / 2;
}
int pq_left(int parent)
{
	return 2 * parent + 1;
}
int pq_right(int parent)
{
	return 2 * parent + 2;
}
