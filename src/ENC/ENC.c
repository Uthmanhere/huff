#include "ENC.h"

#include <stdio.h>
#include <stdlib.h>

#define ASCII_N 128

int free_nodes = 0;

//comparison
int cmp(const void * a, const void * b)
{
	const int * row_a = *(int **)a;
	const int * row_b = *(int **)b;
	return ( row_a[1] - row_b[1] );
}



int ** sample_freq(char * sample)
{
	//allocating the ascii code length array
	int ** sample_ascii = (int **)calloc(ASCII_N, sizeof(int *));
	for (int count = 0; count < ASCII_N; ++count)
		sample_ascii[count] = (int *)calloc(2, sizeof(int));
	for (int count = 0; count < ASCII_N; ++count)
		sample_ascii[count][0] = count;

	//measuring frequency of each ascii
	for (long int counter = 0; sample[counter] != '\0'; ++counter)
		++sample_ascii[sample[counter]][1];

	return sample_ascii;
}

h_node tree_formation(int ** data)
{
	h_node * huff = (h_node *)calloc(1, sizeof(h_node));
	for (int count = 0; count < ASCII_N; ++count)
	{
		if (!data[count][1])
			pq_insert(&huff, data[count][0], data[count][1]);
	}

	h_node * huff_alpha;
	h_node * huff_beta;
	h_node * huff_gamma;

	while (get_pq_size() > 1)
	{
		huff_alpha = pq_pop(&huff);
		huff_beta = pq_pop(&huff);

		huff_gamma->left = huff_alpha;
		huff_gamma->right = huff_beta;
		huff_gamma->frequency = huff_alpha->frequency + huff_beta->frequency;
		huff_gamma->character = '\0';

		pq_insertNode(&huff, huff_gamma);
	}
	
	return *huff;
}
