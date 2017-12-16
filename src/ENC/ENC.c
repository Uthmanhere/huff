#include "ENC.h"

#include <stdio.h>
#include <stdlib.h>

#define ASCII_N 128

int * sample_freq(char * sample)
{
	//allocating the ascii code length array
	int * sample_ascii = (int *)calloc(ASCII_N, sizeof(int));

	//measuring frequency of each ascii
	for (long int counter = 0; sample[counter] != '\0'; ++counter)
		++sample_ascii[sample[counter]];
	

	return sample_ascii;
}
