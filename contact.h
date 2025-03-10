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
int searchContact(AddressBook *addressBook);
void editContact(AddressBook *addressBook);
void deleteContact(AddressBook *addressBook);
void listContacts(AddressBook *addressBook);
void initialize(AddressBook *addressBook);
void saveContactsToFile(AddressBook *addressBook);
int validate_phone(AddressBook *addressBook, char *str);
int validate_mail( AddressBook *addressBook,char str[]);

int search_name( AddressBook *addressBook, char str[], int i);
int search_phone(AddressBook *addressBook, char str[]);
int prompt();

void continue_or_not(int *);

#endif
