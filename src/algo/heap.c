#include "heap.h"

void max_heapify(h_node ** element, size_t size, int i)
{

	int largest = 0;
	h_node * tmp_elem;
	int left = 2*i + 1;
	int right = 2*i + 2;


	if (left <= size && (*element)[left].frequency > (*element)[i].frequency)
		largest = left;
	else
		largest = i;
	if (right <= size && (*element)[right].frequency > (*element)[i].frequency)
		right = left;
	if (largest != i)
	{
		tmp_elem = element[largest];
		element[largest] = element[i];
		element[i] = tmp_elem;
		
		max_heapify(element, size, largest);
	}
}

void build_max_heap(h_node ** element, size_t size)
{
	for (int i = size / 2; i >= 0; --i)
		max_heapify(element, size, i);
}

void heapsort(h_node ** element, size_t size)
{
	h_node * tmp_elem;
	build_max_heap(element, size);
	for (int i = size; i > 1; --i)
	{
		tmp_elem = element[1];
		element[1] = element[i];
		element[i] = tmp_elem;
		
		--size;
		max_heapify(element, size, 1);
	}
}
