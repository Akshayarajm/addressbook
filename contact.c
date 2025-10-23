#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include "file.h"
#include "populate.h"

void listContacts(AddressBook *addressBook) 
{
	for(int i = 0; i < (addressBook -> contactCount); i++)
		print(i, addressBook);
	printf("Listed all contacts successfully\n");	
    // Sort contacts based on the chosen criteria
}

void initialize(AddressBook *addressBook) {
    addressBook->contactCount = 0;
    //populateAddressBook(addressBook);
    
    // Load contacts from file during initialization (After files)
    loadContactsFromFile(addressBook);
}

void saveAndExit(AddressBook *addressBook) {
    saveContactsToFile(addressBook);
    // Save contacts to file
    exit(EXIT_SUCCESS); // Exit the program
}


void createContact(AddressBook *addressBook)
{
	editname(addressBook -> contactCount, addressBook);
	editphone(addressBook -> contactCount, addressBook);
	editemail(addressBook -> contactCount, addressBook);
	addressBook->contactCount++;
	printf("Created contact successfully\n");
	/* Define the logic to create a Contacts */
    
}

void searchContact(AddressBook *addressBook) 
{
	int choice;
	printf("Enter the choice to search\n1. By name\n2. By phone number\n3. By email\n4. Exit\n");
	scanf("%d", &choice);
	switch(choice)
	{
		case 1: {
				int arr[addressBook -> contactCount];
				searchname(arr, addressBook);
				break;
			}
		case 2: searchphone(addressBook);
			break;
		case 3: searchemail(addressBook);
			break;
		case 4: return;
		default : printf("Enter a valid choice\n");
			  break;
	}
	//goto label4;


    /* Define the logic for search */
}

void editContact(AddressBook *addressBook)
{
label6:	printf("Enter the choice to edit\n1. By name\n2. By phone number\n3. By email\n4. Exit\n");
	int k = indeces(addressBook);
	if(k > -1)
		edit(k , addressBook);
	else if(k == -1)
		return;
	goto label6;
	/* Define the logic for Editcontact */
    
}

void deleteContact(AddressBook *addressBook)
{
	label7: printf("Enter the choice to delete\n1. By name\n2. By phone number\n3. By email\n4. Exit\n");
        int k = indeces(addressBook);
	if(k > -1)
	{
		printf("Do You want to delete(y/n)\n");
		char choice;
		scanf(" %c", &choice);
		switch (choice)
		{
			case 'y': case 'Y':
			{
				for(;k < addressBook -> contactCount; k++)
				{
					strcpy(addressBook -> contacts[k].name, addressBook -> contacts[k + 1].name);
					strcpy(addressBook -> contacts[k].phone, addressBook -> contacts[k + 1].phone);
					strcpy(addressBook -> contacts[k].email, addressBook -> contacts[k + 1].email);
			
				}
				addressBook -> contactCount--;
			}
			case 'n': case 'N':
			{
				goto label7;
				break;
			}
			default: printf("No such choice\n");
		}
		
	}
	else if(k == -1)
		return;
        goto label7;
	/* Define the logic for deletecontact */
   
}

int validatephone(char * ph, AddressBook *addressBook)
{
	if(strlen(ph) != 10)
	{
		printf("Enter 10 digits\n");
		return 0;
	}
	for(int i = 0; i < 10; i++)
	{
		
		if(ph[i] <= 47 || ph[i] >= 58)
		{
			printf("Enter numbers only\n");
			return 0;
		}
	}
	for(int i = 0; i < addressBook->contactCount; i++)
	{
		if(strcmp(ph, addressBook -> contacts[i].phone) == 0)
		{
			printf("Enter unique number\n");
			return 0;
		}
	}
	return 1;

}

int validateemail(char * email, AddressBook *addressBook)
{
	char *b = strchr(email, '@');
	if(strchr(email, '@') == NULL)
	{
		printf("Must contain @ character\n");
		return 0;
	}
	char *a = strstr(email, ".com");
	if(a == NULL)
	{
		printf("Enter .com\n");
		return 0;
	}

	if(*(a + 4))
	{
		printf("must end with .com\n");
		return 0;
	}
	for(int i = 0; i < strlen(email); i++)
	{
		if(email[i] >= 'A' && email[i] <= 'Z')
		{
			printf("Must not contain capital letters\n");
			return 0;
		}
	}
	int flag = 1;
	if((*(b - 1) >= 'a' && *(b - 1) <= 'z') || (*(b - 1) >= '0' && *(b - 1) <= '9'))
		flag = 0;
	if(flag)
	{
		printf("Alphanum before @\n");
		return 0;
	}
	flag = 1;
	if((*(b + 1) >= 'a' && *(b + 1) <= 'z') || (*(b + 1) >= '0' && *(b + 1) <= '9'))
                flag = 0;
	if(flag)
	{
		printf("Alphanum after @\n");
                return 0;
	}
	if(email[0] == '@' || email[strlen(email) - 1] == '@')
	{
		printf("Must not end or start with @\n");
		return 0;
	}
	for(int i = 0; i < addressBook->contactCount; i++)
        {
                if(strcmp(email, addressBook -> contacts[i].email) == 0)
		{
			printf("Must be unique\n");
                        return 0;
		}
        }
	return 1;

}

void print(int i, AddressBook * addressBook)
{
	printf("%s\t%s\t%s\t", addressBook -> contacts[i].name, addressBook -> contacts[i].phone, addressBook -> contacts[i].email);
	printf("\n");
}
void editname(int i, AddressBook * addressBook)
{
	printf("Enter the name : ");
	scanf(" %[^\n]", addressBook -> contacts[i].name);
}
void editphone(int i, AddressBook * addressBook)
{
	label1:	printf("Enter the phone number : ");
	char ph[15];
	scanf("%s", ph);
	if(validatephone(ph, addressBook))
		strcpy(addressBook -> contacts[i].phone, ph);
	else
	{
		printf("Enter valid phone number\n");
		goto label1;
	}
}
void editemail(int i, AddressBook * addressBook)
{
	label2:	printf("Enter the email id : ");
        char email[50];
        scanf(" %s", email);
        if(validateemail(email, addressBook))
                strcpy(addressBook -> contacts[i].email, email);
	else
	{
		printf("Enter valid mail id\n");
		goto label2;
	}
}
void edit(int i, AddressBook * addressBook)
{
label5: int choice;
        printf("Enter the choice to be edited\n1. Name\n2. Phone Number\n3. Email id\n4. Exit\n");
        scanf("%d", &choice);
        switch(choice)
        {
        case 1: editname(i, addressBook);
                break;
        case 2: editphone(i, addressBook);
                break;
        case 3: editemail(i, addressBook);
        	break;
	case 4: return;
        default: printf("No such choice\n");
		 break;
	}
	goto label5;
}
int searchname(int arr[], AddressBook * addressBook)
{
	char name[50];
	arr[1] = -1;
        printf("Enter the name : ");
        scanf(" %[^\n]", name);
        int i, j, flag = -2;
        for(i = 0,j = 0; i < addressBook -> contactCount; i++)
        {
        	if(!strcmp(addressBook -> contacts[i].name, name))
                {
			flag = 0;
			printf("%d\t", j+1);
			print(i , addressBook);
			arr[j] = i;
			j++;
                }
	}
	if(flag)
	{
		printf("No such name\n");
	}
	return flag;
}
int searchphone(AddressBook * addressBook)
{
	char phone[50];
        printf("Enter the phone number : ");
        scanf(" %s", phone);
        int flag = -1;
        for(int i = 0; i < addressBook -> contactCount; i++)
        {
        	if(!strcmp(addressBook -> contacts[i].phone, phone))
                {
			print(i, addressBook);
			flag = i;
                        break;
                }
        }
        if(flag < 0)
        {
        	printf("No such phone number\n");
		flag = -2;
        }
	return flag;
}
int searchemail(AddressBook * addressBook)
{
	char email[50];
	printf("Enter the email : ");
        scanf(" %s", email);
        int flag = -1;
        for(int i = 0; i < addressBook -> contactCount; i++)
        {
        	if(!strcmp(addressBook -> contacts[i].email, email))
                {
			print(i, addressBook);
			flag = i;
                        break;
                }
        }
        if(flag < 0)
        {
        	printf("No such email\n");
		flag = -2;
        }
	return flag;
}
int indeces(AddressBook * addressBook)
{
	int choice , k = -1;
	scanf("%d", &choice);
        switch(choice)
        {
                case 1:
                        {       int arr[addressBook -> contactCount];
				
                                if(!(k = searchname(arr, addressBook)))
                                {
                                        k = 1;
                                        if(arr[1] != -1)
                                        {
                                                printf("Enter the choice\n");
                                                scanf("%d", &k);
                                                printf("%d\t", k);
                                                print(arr[k - 1], addressBook);
                                        }
                                        k = arr[k - 1];
                                }
                                break;
                        }
                case 2: {
                                k = searchphone(addressBook);
                                break;
                        }
                case 3: {
                                k = searchemail(addressBook);
                                break;
                        }
                case 4: break;
                default :{
				 k = -2;
				 printf("Enter a valid choice\n");
                        	 break;
			 }
        }
	return k;
}
