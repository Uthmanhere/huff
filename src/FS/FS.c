#include "FS.h"

#include <stdio.h>
#include <stdlib.h>

char * file_read(char * file_name)
{
	
	FILE * file_reading = 0;
	
	file_reading = fopen(file_name, "r");
		
	
	//check if file exists
	if (!file_reading)
		exit(1);

	//know the size of the file
	fseek(file_reading, 0, SEEK_END);
	int file_bytesize = ftell(file_reading);

	//back to beginning
	fseek(file_reading, 0, SEEK_SET);
	//memorry allocation
	char * string_reading = (char *)calloc(file_bytesize, sizeof(char));
	//memory error
	if (!string_reading)
		exit(1);
	//reading
	size_t file_readsize = fread(string_reading, sizeof(char), file_bytesize, file_reading);
	
	//read check
/*	if(file_readsize != file_bytesize)
		exit(1);
	puts("File size is same");
*/
	//close file
	fclose(file_reading);
	return string_reading;
}
