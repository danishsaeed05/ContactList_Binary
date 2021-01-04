#include "contactList.h"
#include<stdio.h>

int main()
{
	char* userInput;
	struct contact *contactLocations;
	/*char *input = getUserInput();
	printf("In main = %s\n", input); */
	long previousRecord = 0;
	FILE *filePointer;
	char *tempNum;

	/* To predict the total size of our data. We take the size of our structure and use that to differentiate or point it to the next records (Same concept as linkedList) */

	/* long and unsigned long are each 8 bytes. Our structure has total of 6 x (8 bytes) = 48 bytes */
	contactLocations = (struct contact *)malloc(sizeof(struct contact));

	/* open file if exits or read and append */
	filePointer = fopen("myContactList.db", "ab+");


	
	do{
		printf("Do you wish to enter a new contact (Yes or No)?:");
		userInput = getUserInput();

		if((strcmp(userInput, "Yes")) == 0) { 
			char *firstName, *lastName, *phoneNum, *companyName, *email;

			printf("First Name: ");
			firstName = getUserInput();

			printf("Last Name: ");
			lastName = getUserInput();

			printf("Company Name: ");
			companyName = getUserInput();

			
			do {
				printf("Phone Number (enter only numbers): ");
				phoneNum = getUserInput();
			}while (isDigit(phoneNum) != 0);

			printf("Email: ");
			email = getUserInput();

			/* Store firs 10 digits ONLY */
			contactLocations->phone_number = strtol(phoneNum, &phoneNum, 10);
			
			int size = previousRecord + (sizeof(struct contact));


			if(strlen(firstName) == 0)
			{
				contactLocations->first_name_posn = size;
			}else {
				contactLocations->first_name_posn = size;
				size = contactLocations->first_name_posn + strlen(firstName)+1;
			}

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

			contactLocations->phone_number = size + strlen(phoneNum) + 1;


			if(strlen(email) == 0)
			{
				contactLocations->email_posn = size;
			}else {
				contactLocations->email_posn = size;
			}			
			
			/* next will contain the size of the entire structure data */
			contactLocations->next = size + strlen(email) + 1;

			/* Store the size of the entire structure into previous Record to keep
			track the size of the previous total size data(structure) */ 
			previousRecord = contactLocations->next;


			/*
			Testing size 
			printf("FName = %ld\n", contactLocations->first_name_posn);
			printf("LName = %ld\n", contactLocations->last_name_posn);
			printf("Comp = %ld\n", contactLocations->company_name_posn);
			printf("Email = %ld\n", contactLocations->email_posn);
			printf("phoneNum = %ld\n", contactLocations->phone_number);
			printf("Next = %ld\n", contactLocations->next);
			*/

			fwrite(contactLocations, 1, sizeof(struct contact), filePointer);
			if(strlen(firstName) ==0)
			{
				fwrite(firstName, 1, strlen(firstName), filePointer);
			}else {
				fwrite(firstName, 1, strlen(firstName) + 1, filePointer);
			}


			if(strlen(lastName) ==0)
			{
				fwrite(lastName, 1, strlen(lastName), filePointer);
			}else {
				fwrite(lastName, 1, strlen(lastName) + 1, filePointer);
			}


			if(strlen(companyName) ==0)
			{
				fwrite(companyName, 1, strlen(companyName), filePointer);
			}else {
				fwrite(companyName, 1, strlen(companyName) + 1, filePointer);
			}


			if(strlen(email) ==0)
			{
				fwrite(email, 1, strlen(email), filePointer);
			}else {
				fwrite(email, 1, strlen(email) + 1, filePointer);
			}

		}
		else if((strcmp(userInput, "No")) == 0)
		{
			int flag2=0;

			do {
				printf("Do you wish to retrieve a contact (Yes or No)?:");
				userInput = getUserInput();

				if((strcmp(userInput, "Yes")) == 0)
				{
					int flag=0;
					fseek(filePointer, 0, SEEK_SET);
					printf("Phone Number: ");
					tempNum = getUserInput();
					printf("Number entered is: %s\n", tempNum);

					contactLocations->first_name_posn = 0;
					contactLocations->last_name_posn = 0;
					contactLocations->company_name_posn = 0;
					contactLocations->phone_number = 0;
					contactLocations->email_posn = 0;
					contactLocations->next = 0;

				/* ONLY reading the first 10 digits */
					long number = strtol(tempNum, &tempNum, 10);

					while(fread(contactLocations, sizeof(struct contact), 1, filePointer))
					{
						char name[100]="";
						char lname[100]="";
						char comname[100]="";
						char email[100]="";

						if(contactLocations->phone_number == number)
						{
							fread(name, contactLocations->last_name_posn - contactLocations->first_name_posn, 1, filePointer);

							fread(lname, contactLocations->company_name_posn - contactLocations->last_name_posn, 1, filePointer);

							fread(comname, contactLocations->email_posn - contactLocations->company_name_posn, 1, filePointer);

							fread(email, contactLocations->next - contactLocations->email_posn, 1, filePointer);

							printf("First Name: %s\n", name);
							printf("Last Name: %s\n", lname);
							printf("Company Name: %s\n", comname);
							printf("Phone Number: %ld\n", contactLocations->phone_number);
							printf("Email: %s\n", email);
							flag= 1;
							flag2=1;
							break;
						}
						else 
						{
							fread(name, contactLocations->last_name_posn - contactLocations->first_name_posn, 1, filePointer);
							fread(lname, contactLocations->company_name_posn - contactLocations->last_name_posn, 1, filePointer);
							fread(comname, contactLocations->email_posn - contactLocations->company_name_posn, 1, filePointer);
							fread(email, contactLocations->next - contactLocations->email_posn, 1, filePointer);

							contactLocations->first_name_posn = 0;
							contactLocations->last_name_posn = 0;
							contactLocations->company_name_posn = 0;
							contactLocations->phone_number = 0;
							contactLocations->email_posn = 0;
							contactLocations->next = 0;
							continue;
						}
					}
					if(flag == 0) {
						printf("No match found.\n");
						break;
					}
				}
				if(flag2 == 1 || (strcmp(userInput, "No") == 0)) 
				{
					break;
				}
			}while (strcmp(userInput, "No") != 0);
		}
	}while(((strcmp(userInput, "No")) != 0));

	fclose(filePointer);
	return 0;
}
