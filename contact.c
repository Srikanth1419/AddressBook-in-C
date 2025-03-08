#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include "populate.h"

static int count2=0;

void initialize(AddressBook *addressBook) 
{
    addressBook->contactCount = 0;
    populateAddressBook(addressBook);
    printf("%d ",addressBook->contactCount);
}
// displaying contacts
void listContacts(AddressBook *addressBook )
{
    int i=0;
    printf("%-20s%-20s%s\n","NAME", "MOBILE NO.", "E-MAIL ID");
    for(i=0;i<addressBook->contactCount;i++)
    {
        printf("%-20s",(addressBook->contacts[i].name));
        printf("%-20s",(addressBook->contacts[i].phone));
        printf("%s\n",(addressBook->contacts[i].email));
    }
}

// creating contact
void createContact(AddressBook *addressBook)
{
   char str_name[50];
   char temp_phone[11];
   char temp_mail[50];

    int flag =1;
    while(flag)
    {

            printf("enter the contact details\n");
            printf("Enter The  Name\n");
            getchar();
            scanf("%[^\n]",str_name);
            getchar();

            printf("enter the phone number\n");
            scanf("%s", temp_phone);
             __fpurge(stdin);
            

            int ret = validate_phone(addressBook, temp_phone);
            //printf("ret = %d\n", ret);

                while(ret)
                {
                    if(ret == -1)
                    {
                        printf("Number already Exists!!\n");
                    }
                    printf("Re Enter the mobile number\n");
                    scanf("%s", temp_phone);                   
                    ret = validate_phone(addressBook,temp_phone);
                }
            

            printf("enter the E-Mail ID\n");
            getchar();
            scanf("%[^\n]",temp_mail);
            getchar();
            
            ret = validate_mail(addressBook, temp_mail);
            while(ret)
            {
            if(ret != -1)
            {
                printf("E-mail ID already exists!\n");
            }
                printf("Re Enter the email id\n");
                scanf("%[^\n]", temp_mail);
                getchar();
                ret = validate_mail(addressBook,temp_mail);
                    
            }

            strcpy( (addressBook->contacts[addressBook->contactCount].name), str_name);
            strcpy( (addressBook->contacts[addressBook->contactCount].phone), temp_phone);
            strcpy( (addressBook->contacts[addressBook->contactCount].email), temp_mail);
            addressBook->contactCount++;
            printf("contact created succcessfully!!\n");

        printf("Do You Want To Continuue:");
        continue_or_not(&flag);
    }
}

// used for searching the contacts
int searchContact(AddressBook *addressBook) 
{
    char temp_name[50];
    char temp_phone[11];
    char temp_mail[50];
  
  int flag =1;
  while(flag)
  {
    int i=0;
    printf("Do Search By:\n");
            int choice = prompt();
            if(choice == 1)
            {
            printf("Enter The Name To Search\n");
            __fpurge(stdin);
            scanf("%[^\n]", temp_name); 
            int ret  = search_name( addressBook, temp_name,i);
            printf("ret in name= %d\n", ret);
            if(ret)
            {

               
                while(ret)
                {   
                        i=ret-1;
                        printf("%d. %s ",i,(addressBook->contacts[i].name));
                        printf("\t%s ",(addressBook->contacts[i].phone));
                        printf("\t%s\n",(addressBook->contacts[i].email));
                        count2++;
                        ret = search_name(addressBook, temp_name, i+1);  
                            
                }
                return i;
                
            }
            else
            {
         
                printf("contact not found!!\n");
                printf("Do You Want To Continue To Search:\n");
                continue_or_not(&flag);
                return -1;
            }  
        }
        else if(choice == 2)
        {
            printf("Enter The Mobile Number To Search\n");
            __fpurge(stdin);
            scanf("%[^\n]", temp_phone);
             i=0;
           
            int ret = validate_phone(addressBook, temp_phone);
           
               int flag1=1;
                while(flag1)
                {
                  
                    
                        if(ret == -1)
                        {
                            printf("enter valid mobile number\n");
                            __fpurge(stdin);
                            scanf("%s", temp_phone);
                            ret = validate_phone(addressBook, temp_phone);
                        }
                        else
                        {
                           if(ret>0)
                           {
                            i= ret-1;
                            printf("%d. %s ",i,(addressBook->contacts[i].name));
                            printf("\t%s ",(addressBook->contacts[i].phone));
                            printf("\t%s\n",(addressBook->contacts[i].email));
                            count2++;
                            return i;
                           }  
                        }
                    if(ret == 0)
                    {
                        printf("Contact Not Found!!\n");
                        printf("Do You Want To Continue To Search:\n");
                        continue_or_not(&flag);
                        return -1;
                    }
                } 
        }
        else if(choice == 3)
        {
            
            printf("Enter The E-Mail ID To Search: ");
            __fpurge(stdin);
            scanf("%[^\n]", temp_mail);

                int flag1=1;
                int ret = validate_mail(addressBook, temp_mail);
                while(flag1)
                {
                    
                    if(ret == -1)
                    {
                        printf("Please! Enter valid mail id\n");
                        __fpurge(stdin);
                        scanf("%[^\n]", temp_mail);
                        ret = validate_mail(addressBook, temp_mail);
                       
                    }
                    else if(ret>0)
                    {
                        int  i=ret-1;
                        printf("%d. %s ",i,(addressBook->contacts[i].name));
                        printf("\t%s ",(addressBook->contacts[i].phone));
                        printf("\t%s\n ",(addressBook->contacts[i].email));
                        count2++;
                         return i;
                        
                    }
              
                    if(ret == 0)
                    {
                        printf("contact not Found!!\n");
                        printf("Do You Want To Continue To Search:\n");
                        continue_or_not(&flag);
                        return -1;
                    }
                }
        }
        else
        {
            return -1;
            flag =0;
        }
    }
  }

// function to edit contacts
void editContact(AddressBook *addressBook)
{
    char temp_name[50];
    char temp_phone[11];
    char temp_mail[50];
    int choice;
    int flag =1;
    while(flag)
    {
        int index =searchContact(addressBook);
        //printf("%d\n", index);
        if(index>=0)
        { 
                if(count2 !=1 )
                {
                    printf("count2 = %d\n", count2);
                    printf("Which Contact Do You Want To EDIT:\n");
                    printf("Choose Index Value To EDIT:\n");
                    __fpurge(stdin);
                    scanf("%d", &index);
                }
            printf("What You Want To Edit:\n");
            int opt = prompt();
            printf("opt = %d\n", opt);
            __fpurge(stdin);

            if(opt ==1)
            {
                printf("enter the name to Edit:");
                scanf("%[^\n]",temp_name);
                __fpurge(stdin);

                strcpy(addressBook->contacts[index].name, temp_name);
                printf("Name Edited successfully!!\n");
            }
            else if(opt == 2)
            {
                
                int flag1=1;
                int i=0;
               while(flag1)
               {
                printf("enter the Number to Edit:\n");
                scanf("%[^\n]", temp_phone);
                __fpurge(stdin);
                int ret = validate_phone(addressBook, temp_phone);
                int flag=1;
                    if(ret==0)
                    {
                            printf("index = %d\n", ret);
                            strcpy(addressBook->contacts[index].phone, temp_phone);
                            printf("Number Edited successfully!!\n");
                            flag1 =0;
                    }
                    else if(ret >0)
                    {
                        printf("Number Already Eixsts..\n");
                        flag1 =0;
                    }
                    else
                    {
                        printf("Number is Not Valid\n");
                       flag1 =1;
                    }
                    
                }

            }
            else if(opt ==3)
            {
                //int flag1 =1;

                int flag =1;

                while(flag)
                {
                    printf("Enter Email-ID to Edit:\n");
                __fpurge(stdin);
                scanf("%[^\n]", temp_mail);
                int ret = validate_mail(addressBook,temp_mail);
                
                    if(ret==0)
                    {
                            printf("index = %d\n", ret);
                            strcpy(addressBook->contacts[index].email, temp_mail);
                            printf("E-Mail ID Edited successfully!!\n");
                            flag =0;
                    }
                    else if(ret >0)
                    {
                        printf("E-Mail ID  Already Eists..\n");
                        flag =0;
                    }
                    else
                    {
                        printf("E-Mil ID  is Not Valid\n");
                        flag =1;
                    }
                   
                }
              
            }
            else
            {
                flag =0;
            }
        }
        printf("Do You Want To Continue The Edit  Operation:\n");
        continue_or_not(&flag);
    }
}

// used to delete the contacts
void deleteContact(AddressBook *addressBook)
{
    char temp_name[50];
    char temp_phone[11];
    char temp_mail[50];

    int index;
    int choice;
    int flag =1;
    while(flag)
    {
         index = searchContact(addressBook); 
   
         //printf("index = %d\n", index);
         
        if(index>=0)
        {
           // printf("count = %d\n", count2);
            if(count2 !=1 )
            {
                printf("Which Contact Do You Want To Delete:\n");
                printf("Choose Index Value To Delete:\n");
                __fpurge(stdin);
                scanf("%d", &index);
            }
           
            printf("Do You Want To Delete:1.Yes\n2.No\n");
            __fpurge(stdin);
            scanf("%d", &choice);
            if(choice == 1)
            {
                for(int i=index;i<addressBook->contactCount;i++)
                {
                    strcpy(addressBook->contacts[i].name, addressBook->contacts[i+1].name);
                    strcpy(addressBook->contacts[i].phone, addressBook->contacts[i+1].phone);
                    strcpy(addressBook->contacts[i].email, addressBook->contacts[i+1].email);
                }
                addressBook->contactCount--;
                printf("Contact Deleted Successfully!!\n");
            }
        }  
         printf("Do You Want To Continue The Delete Operation:\n");
       continue_or_not(&flag);
    }


}

//for saving
void saveContactsToFile(AddressBook *addressBook)
{
    FILE *fptr = fopen("contacts.csv", "w");
    if(fptr == NULL)
    {
        printf("File Does not Exist\n");

    }
    printf("contact count = %d\n",addressBook->contactCount);
    fprintf(fptr, "#%d\n",addressBook->contactCount);

    int i;
    for(i=0;i<addressBook->contactCount;i++)
    {
        fprintf(fptr, "%s,%s,%s\n", addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
    }
    fclose(fptr);
    printf("Contacts Saved Successfully!!\n");
}

// va;lidating phone and checking it is present in addressbook or not
int validate_phone(AddressBook *addressBook, char *str)
{
    int count=0;
    
    int j=0;
    while(str[j] !='\0')
    {
        if(str[j] >= '0' && str[j] <='9')
        {
            count++;
           
        }
        j++;
    }

    if(count ==10)
    {
        int i=0;
        
        while(i<(addressBook->contactCount))
        {
            int ret = strcmp(addressBook->contacts[i].phone, str);
            if(ret ==0)
            {
                return i+1;
            }
            i++;
            
        }
        return 0;
        
    }
    else 
    {
        return -1;
    }
         
}

int my_strstr( char *str, char *  sub)
{
    int i=0, j;
    while(str[i] != '\0')
    {
        if(str[i] == sub[0])
        {
            int k=i;
            j=0;
            while(sub[j] !='\0')
            {
                if(str[k] != sub[j])
                {
                    break;
                }
                k++;
                j++;
            }
            if(sub[j] =='\0')
            {
                return 1;
            }
           
        }
        i++;
    }
    return 0;
}
int my_strchr(char *str, char ch)
{
    int i=0;

    while(str[i] != '\0')
    {
        if(str[i] == ch)
        {
            return 1;
        }
        i++;
    }
    return 0;
}
// validates for mail and checks it is present in addressbook or not
int validate_mail( AddressBook *addressBook,char str[])
{
        int i=0;
        while(str[i] != '\0')
        {
            if(str[i] >= 'A' && str[i] <= 'Z')
            {
                return -1;
                break;
            }
            i++;
        }
        if(my_strstr(str, "@.com"))
        {
            return -1;
        }
         char *res = strchr(str, ' ');
        if( !res)
        {
                int ret = my_strchr( str, '@');
                if(ret ==1)
                {
                    
                    int ret1 = my_strstr(str, ".com");
                
                    if(ret1 == 1)
                    {
                        int i=0;
                        while(i<(addressBook->contactCount))
                        {
                            int ret = strcmp(addressBook->contacts[i].email, str);
                            if(ret ==0)
                            {

                                return i+1;
                            }
                            i++;
                        }
                        return 0;  
                    }
                    else
                    {
                        return -1;
                    }
                    
                }
                else
                {
                    return -1;
                }
        }
            else
            {
                return -1;
            }


}

// used to search the name in addresssbook
int search_name( AddressBook *addressBook, char str[], int i)
{
    int flag =0;
    while(i<addressBook->contactCount)
    {
        int ret = strcmp(addressBook->contacts[i].name, str);
        if(ret == 0)
        {
            flag =1;
            return i+1;
        }
        else
        {
            char *ret = strstr(addressBook->contacts[i].name, str);
            if(ret != NULL)
            {
                flag =1;
                 return i+1;
            }
        }
        i++;
        
    }

    if(flag == 0)
    {
        return 0;
    }
}

// printing prompt messages
int prompt()
{
    
    int opt;
    int flag=1;

    while(flag)
    {
        printf("1.NAME\n");
        printf("2.MObile Number\n");
        printf("3.E-Mail ID\n");
        printf("4.EXIT\n");
        printf("Select One option:\n");
        __fpurge(stdin);
        scanf("%d",&opt);
        if(opt>=1 && opt<=4)
        {
            return opt;
            flag=0;
        }
        else
        {
            printf("INVALID Option!!\n");
            flag=1;
        }
    }

   
}
// function to ask the user continue the operation or not
void continue_or_not(int *flag)
{
    printf("1.YES\n2.NO\n");
    int opt;
    __fpurge(stdin);
    scanf("%d", &opt);
    if(opt ==1)
    {
        *flag =1;
    }
    else
    {
        *flag =0;
    }
}
