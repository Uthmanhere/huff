#include "PriorityQ.h"

#include <stdlib.h>
#include <stdio.h>


#define CHAR 0
#define FREQ 1

int pq_size = 0;

bool pq_empty(h_node ** pq_this)
{
	return !&pq_this;
}
void pq_insertNode(h_node ** pq_this, h_node * huff_gamma)
{
	++pq_size;
	if(!pq_size)
	{
		*pq_this = huff_gamma;
	}
	else
	{
		*pq_this = (h_node *)realloc(*pq_this, pq_size);
		pq_this[pq_size - 1] = huff_gamma;
		pq_insert_order(pq_this, pq_size - 1);
	}
}
void pq_insert(h_node ** pq_this, char character, int frequency)
{
	
	++pq_size; //increased size;

	//memory inserstion
	h_node * tmp;
	if (!pq_size)
	{
		//allocation
		*pq_this = (h_node *)malloc(sizeof(h_node));
		//information
		(*pq_this)->character = character;
		(*pq_this)->frequency = frequency;
	}
	else
	{
		//reallocation
		tmp = (h_node *)realloc(*pq_this, pq_size);
		if (!tmp)	//memory error
		{
			puts("ERROR : OUT OF MEMORY !");
			exit(1);
		}
		*pq_this = tmp;
		//information
		pq_this[pq_size - 1]->character = character;
		pq_this[pq_size - 1]->frequency = frequency;
	}

	pq_insert_order(pq_this, pq_size - 1);
}

h_node * pq_pop(h_node ** pq_this)
{
	h_node * tmp = 0;

	pq_swap(pq_this, 0, pq_size - 1);
	pq_this[pq_size - 1] = 0;

	pq_pop_order(pq_this, 0);


	return tmp;
}


void pq_insert_order(h_node ** pq_this, int pos)
{
	int * tmp;
	if (pq_this[pq_parent(pos)]->frequency > pq_this[pos]->frequency)
	{
		pq_swap(pq_this, pos, pq_parent(pos));
		pq_insert_order(pq_this, pq_parent(pos));
	}
	else return;
}
void pq_pop_order(h_node ** pq_this, int pos)
{
	if (pq_this[pos]->frequency > pq_this[pq_left(pos)]->frequency && pq_left(pos) < pq_size)
	{
		pq_swap(pq_this, pos, pq_left(pos));
		pq_pop_order(pq_this, pq_left(pos));
	}
	if (pq_this[pos]->frequency > pq_this[pq_right(pos)]->frequency && pq_right(pos) < pq_size)
	{
		pq_swap(pq_this, pos, pq_right(pos));
		pq_pop_order(pq_this, pq_right(pos));
	}
	else return;

}
void pq_swap(h_node ** pq_this, int prior, int latter)
{
	h_node * tmp = 0;
	tmp = *(pq_this + prior);
	*(pq_this + prior) = *(pq_this + latter);
	*(pq_this + latter) = tmp;
}

int get_pq_size()
{
	return pq_size;
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
