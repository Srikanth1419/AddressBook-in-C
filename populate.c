#include "contact.h"
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
// Dummy contact data
static Contact dummyContacts[] = {
    {"John Doe", "1234567890", "john@example.com"},
    {"Alice Smith", "0987654321", "alice@example.com"},
    {"Bob Johnson", "1112223333", "bob@company.com"},
    {"Carol White", "4445556666", "carol@company.com"},
    {"David Brown", "7778889999", "david@example.com"},
    {"Eve Davis", "6665554444", "eve@example.com"},
    {"Frank Miller", "3334445555", "frank@example.com"},
    {"Grace Wilson", "2223334444", "grace@example.com"},
    {"Hannah Clark", "5556667777", "hannah@example.com"},
    {"Ian Lewis", "8889990000", "ian@example.com"}
};

void populateAddressBook(AddressBook* addressBook)
{

    FILE  *fptr = fopen("contacts.csv", "r");
    if(fptr == NULL)
    {
        printf("File Does not Exist\n");
    }
    
    char str[20];
    fscanf(fptr, "%*c%s", str);
   
    int count = atoi(str);

    char temp_name[50];
    char temp_phone[11];
    char temp_mail[50];
    int i=0;

    addressBook->contactCount=0;
    for(i=0;i<count;i++)
    {
        fscanf(fptr," %[^,],",temp_name);
        fscanf(fptr," %[^,],", temp_phone);
        fscanf(fptr," %[^\n]", temp_mail);

        strcpy(addressBook->contacts[i].name, temp_name);
        strcpy(addressBook->contacts[i].phone, temp_phone);
        strcpy(addressBook->contacts[i].email, temp_mail);
        addressBook->contactCount++;
    }
    fclose(fptr);
   
}

