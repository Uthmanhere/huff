#include "FS.h"

#include <stdio.h>
#include <stdlib.h>

char * file_read(char * file_name)
{
	
	FILE * file_reading = 0;
	char character = '\0';
	char * character_reading = (char *)calloc(0, sizeof(char));
	char * new_character_reading;
	
	file_reading = fopen(file_name, "r");
	
		
	if (!file_reading)
		exit(1);
	
	for (int counter = 0; (character = getc(file_reading)) != EOF; ++counter )
	{
		
		new_character_reading = realloc(character_reading, counter * sizeof(char));

		puts("here i am");
		if (character_reading)
			character_reading = new_character_reading;
		else
			exit(1);
		puts("almost there");
		printf("%c", character);
		* (character_reading + counter) = character;
		puts("lost here");
	}

	fclose(file_reading);
	
	
	return character_reading;
}
