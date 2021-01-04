

#include "contactList.h"

/* get the user's input by having method, in which it returns a pointer to where the char is located/stored */
char* getUserInput()
{
	char *input, c = ' ';
	int size = 2;
	int index = 0;

	input = (char *) malloc(1* sizeof(char));

	while(c != EOF && c != '\n')
	{
		c = getchar();
		input[index] = c;

		input = (char *) realloc(input, sizeof(char) * size);

		size++;
		index++;
	}
	input[index-1] = '\0';

	/*
	Testing:
	printf("The length of string is : %s\n", strlen(input));
	*/

	return input;
}

int isDigit(char *phoneNumber)
{
	int i;
	if(strlen(phoneNumber) == 0)
	{
		return 1;
	}

	for(i=0; i<strlen(phoneNumber); i++)
	{
		/* if any of the characters is NOT a digit, then return 1 */
		if(!isdigit(phoneNumber[i]))
		{
			return 1;
		}
	}
	return 0;
}





