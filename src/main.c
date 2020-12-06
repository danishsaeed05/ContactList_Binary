#include "contactList.h"
#include<stdio.h>

int main()
{
	char* userInput;
	struct contact *contactLocations;
	/*char *input = getUserInput();
	printf("In main = %s\n", input); */
	long previousRecord = 0;


	printf("Do you wish to enter a new contact (Yes or No)?:");
	
	userInput = getUserInput();

	while(((strcmp(userInput, "Yes")) == 0) || ((strcmp(userInput, "No")) == 0))
	{
		char *firstName, *lastName, *phoneNum, *companyName, *email;
		/*if((strcmp(userInput, "Yes")) == 0)
		{*/

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

			/* To predict the total size of our data. We take the size of our structure and use that to differentiate or point it to the next records (Same concept as linkedList) */
			/* long and unsigned long are each 8 bytes. Our structure has total of 6 x (8 bytes) = 48 bytes */
			contactLocations = (struct contact *)malloc(sizeof(struct contact));
			long size = previousRecord + (sizeof(struct contact));
			printf("%ld\n", size);

			if(strlen(firstName) == 0)
			{
				contactLocations->first_name_posn = size;
			}else {
				contactLocations->first_name_posn = size;
				size = contactLocations->first_name_posn + strlen(firstName)+1;
			}
			printf("Size after firstName = %ld\n", size);

			if(strlen(lastName) == 0)
			{
				contactLocations->last_name_posn = size;
			}else {
				contactLocations->last_name_posn = size;
				size = contactLocations->last_name_posn + strlen(lastName)+1;
			}

			if(strlen(companyName) == 0)
			{
				contactLocations->company_name_posn = size;
			}else {
				contactLocations->company_name_posn = size;
				size = contactLocations->company_name_posn + strlen(companyName)+1;
			}

			if(strlen(email) == 0)
			{
				contactLocations->email_posn = size;
			}else {
				contactLocations->email_posn = size;
				size = contactLocations->email_posn + strlen(email)+1;
			}

			

			/*check if its a number */
			/*
			int i = 0;
			while(i<strlen(phoneNum))
			{

			}

			*/



			printf("Do you wish to enter a new contact (Yes or No)?:");
			userInput = getUserInput();
		/*}else if ((strcmp(userInput, "No")) == 0)
		{



			printf("Do you wish to retrieve a contact (Yes or No)?:");
			userInput = getUserInput();
			if((strcmp(userInput, "No")) == 0)
			{
				break;
			}
			else if((strcmp(userInput, "Yes")) == 0)
			{
				printf("Phone Number: ");
				phoneNum = getUserInput();
				break;
			}
			else {
				printf("Wrong input\n");
			}
		}
*/
	}





	return 0;
}
