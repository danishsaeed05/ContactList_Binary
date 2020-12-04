# Binary Files and Structures on Disk
#
##### This program is coded in **C** Programming Language
#
## The Problem
The task is to write a program that stores and retrieves structures in a file that are in binary on disk. Overall, this task should be able to store structures to the file and retrieve from the file.

## Purpose of this program
- The purpose of this program is to save space and time using dynamic allocation. Binary files tend to be smaller and faster and this program will help in storing contact information that is not human-readable in binary(ASCII codes):

### **Example :**
- The following is the user interface of the program
        
        $ ./contactList
        Do you wish to enter a new contact (Yes or No)?: Yes
        First Name: John
        Last Name: Mark
        Company Name: Mark's
        Phone Number (enter only numbers): 6458256547
        Email: john23@mark.com
        Do you wish to enter a new contact (Yes or No)?: No
        Do you wish to retrieve a contact (Yes or No)?: Yes
        Phone Number: 4161234456
        No match found.
        Do you wish to enter a new contact (Yes or No)?: No
        Do you wish to retrieve a contact (Yes or No)?: Yes
        Phone Number: 6458256547
        First Name: John
        Last Name: Mark
        Company Name: Mark's
        Phone Number: 6458256547
        Email: john23@mark.com
        Do you wish to enter a new contact (Yes or No)?: No
        Do you wish to retrieve a contact (Yes or No)?: No
        $

## How to run?
- Simply clone or download the repository. Navigate to the folder in your terminal, and type ***make***, it will create the executable file.
- To execute the file, type ***./contactList***
- To remove any object or executable files, type ***make clean***

&copy; This problem or program is solved solely by me.