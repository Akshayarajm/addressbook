#ifndef CONTACT_H
#define CONTACT_H

#define MAX_CONTACTS 100

typedef struct {
    char name[50];
    char phone[20];
    char email[50];
} Contact;

typedef struct {
    Contact contacts[100];
    int contactCount;
} AddressBook;

void createContact(AddressBook *addressBook);
void searchContact(AddressBook *addressBook);
void editContact(AddressBook *addressBook);
void deleteContact(AddressBook *addressBook);
void listContacts(AddressBook *addressBook);
void initialize(AddressBook *addressBook);
void saveContactsToFile(AddressBook *AddressBook);
int validatephone(char * ph, AddressBook *addressBook);
int validateemail(char * email, AddressBook *addressBook);
void print(int i, AddressBook *addressBook);
void editname(int i, AddressBook *addressBook);
void editphone(int i, AddressBook *addressBook);
void editemail(int i, AddressBook *addressBook);
void edit(int i, AddressBook * addressBook);
int searchname(int arr[], AddressBook *addressBook);
int searchphone(AddressBook *addressBook);
int searchemail(AddressBook *addressBook);
int indeces(AddressBook * addressbook);
#endif
