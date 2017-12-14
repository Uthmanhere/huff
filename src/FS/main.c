/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  12/12/2017 11:32:25 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Muhammad Usman (), uthmanhere@gmail.com
 *   Organization:  SEECS, NUST
 *
 * =====================================================================================
 */

#include <stdio.h>

#include "FS.h"

int main()
{
	char * file_str = file_read("index.txt");

	printf("So the fucking file is : \n%s\n", file_str);

	return 0;
}
