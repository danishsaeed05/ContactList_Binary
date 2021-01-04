

#ifndef _CONTACTLISTH_
#define _CONTACTLISTH_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

struct contact {
	unsigned long phone_number;
	long first_name_posn;
	long last_name_posn;
	long company_name_posn;
	long email_posn;
	long next;
};

char* getUserInput();
int isDigit(char *phoneNumber);

#endif
