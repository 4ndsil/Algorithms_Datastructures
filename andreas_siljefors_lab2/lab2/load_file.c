#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "load_file.h"
FILE* file;
errno_t err;


int* load_file(const char* fName)
{
	int input[MAX_NUM_ELEMENTS];

	int num_elements = 0;

	err = fopen_s(&file,fName, "r");

  if ( file == NULL ) 
  {

    printf("Error: file does not exist. Exiting...\n");

    exit(1);
  }
	char line[256];

	while (fgets(line, sizeof(line), file)) 
	{
		input[num_elements++] = atoi(line);

		//printf("%d", atoi(line));
	}
	fclose(file);
	
	int* data = (int*)malloc((num_elements+1)*sizeof(int));

	for ( int i = 1 ; i <= num_elements ; i++ ) 
	{
		data[i] = input[i-1];
	}

	data[0] = num_elements;

	return data;
}


