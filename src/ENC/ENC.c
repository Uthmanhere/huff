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

	//sorting by frequency
	qsort(sample_ascii, ASCII_N, sizeof(sample_ascii[0]), cmp);

	//counting free nodes
	for(int count = 0; count < 128; ++count)
	{
		if (!sample_ascii[count][1])
			++free_nodes;
	}

	return sample_ascii;
}

