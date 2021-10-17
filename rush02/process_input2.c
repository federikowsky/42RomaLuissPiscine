#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "utils.h"

/* conto quanti caratteri ci sono a ogni riga */
void control_dict(char *string)
{
	int i;

	i = 1;
	while(string[i] != '\0')
	{	
		if(string[i - 1] == '\n' && string[i] == '\n')
			{
				string[i] = '{';
				i++;
			}
		
		else if(string[i - 1] == 32 && string[i] == 32)
		{
			string[i] = '{';
			i++;
		}
	}
}