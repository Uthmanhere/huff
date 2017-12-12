#include "FS.h"

#include <stdio.h>
#include <stdlib.h>

char * file_read(char * file_name)
{
	
	FILE * file_reading = 0;
	char character = '\0';
	char * character_reading = (char *)malloc(sizeof(char));

	file_reading = fopen(file_name, "r");

	if (file_reading)
	{
		for ( int counter = 0; (character = getc(file_reading)) != EOF; ++counter )
		{
			
			character_reading = realloc(character_reading, counter * sizeof(char));
			if (!character_reading)
			{
				printf("\nERROR : Memory Allocation > reading file %s\n", file_name);
				exit(1);
			}
//			(character_reading + counter) = (char *)malloc(sizeof(char));
			* (character_reading + counter) = character;
		}

	fclose(file_reading);
	}
}
