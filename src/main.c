#include "contactList.h"
#include<stdio.h>

int main()
{
	char* userInput;

	/*char *input = getUserInput();
	printf("In main = %s\n", input); */


	printf("Do you wish to enter a new contact (Yes or No)?:");
	
	userInput = getUserInput();

	if(strcmp(userInput, "Yes") == 0)
	{
		char *firstName, *lastName, *phoneNum, *companyName, *email;
		
		printf("First Name: ");
		firstName = getUserInput();

		printf("Last Name: ");
		lastName = getUserInput();

		printf("Company Name: ");
		companyName = getUserInput();

		printf("Phone Number: ");
		phoneNum = getUserInput();

		printf("Email: ");
		email = getUserInput();

		printf("\n-------------\n");
		printf("'%s'\n", firstName);
		printf("'%s'\n", lastName);
		printf("'%s'\n", companyName);
		printf("'%s'\n", phoneNum);
		printf("'%s'\n", email);

	}
	else {
		printf("No match\n");
	}





	printf("Do you wish to retrieve a contact (Yes or No)?:");

	return 0;
}
