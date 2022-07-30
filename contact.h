#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<conio.h>


void welCome();
void mainMenu();
void newcontact();
void listOfContact();
void edit();
void search_Contact();
void delete_Contact();
int takeIntegerInput();
void menu();

FILE *ptr;
FILE *fp;

struct Contact{
    char name[50];
    char address[50];
    char email[50];
    char mobileNumber[50];
}c;

int takeIntegerInput() {

    int choice;
    start:

    fflush(stdin);
    printf("\n\n\t\t\t\tEnter your Choice: ");

    while(!scanf("%d",&choice))
    {
        printf("\n\t\t\t\tWrong Input.Please Enter a valid Integer Input.........\n\n");
        goto start;
    }

    return choice;
}

void welCome() {

    puts("\t\t\t\t------------------------------------------------------");
    puts("\t\t\t\t|----------------------WEL COME----------------------|");
    puts("\t\t\t\t|---------TO MINI CONTACT MANGEMENT SYSTEM-----------|");
    puts("\t\t\t\t------------------------------------------------------\n\n");
    usleep(1000000);
}

void mainMenu() {

    puts("\t\t\t\t=====================================================");
    puts("\t\t\t\t|\t\t      MAIN MENU\t\t\t    |");
    puts("\t\t\t\t=====================================================");

    puts("\n\t\t\t\t=====================================================");
    printf("\t\t\t\t[1]  Add  a  new Contact\n");
    printf("\t\t\t\t[2]  List  all Contact\n");
    printf("\t\t\t\t[3]  Search Contact\n");
    printf("\t\t\t\t[4]  Delete a contact\n");
    printf("\t\t\t\t[5]  Edit a Contact\n");
    printf("\t\t\t\t[6]  Exit\n");
    puts("\t\t\t\t=====================================================");
}

void menu() {

    int n;
    n=takeIntegerInput();

    switch(n)
    {

    case 1:
        {
            newcontact();
            break;
        }
    case 2:
        {
            listOfContact();
            break;
        }
    default:
        {
            printf("\n\n\t\t\t\tWrong Choice.......");
            break;
        }

    case 6:
        {
            exit(0);
        }

    case 5:
        {
            edit();
            break;
        }
    case 3:
        {
            search_Contact();
            break;
        }
    case 4:
        {
            delete_Contact();
            break;
        }
    }
}

void newcontact() {

    //new contact add
    char ch;
    system("cls");

    welCome();
    usleep(1000000);

    puts("\t\t\t\t=====================================================");
    puts("\t\t\t\t|                  Add a New Contact                |");
    puts("\t\t\t\t=====================================================");


    ptr = fopen("contactlist.txt","a+");

    if ( ptr == NULL )
    {
        printf("\n\n\t\t\t\tFile doesn't open.");
        exit(4);
    }

    do{

        fflush(stdin);

        printf("\n\t\t\t\tEnter  Name: ");
        scanf("%[^\n]%*c",c.name);

        fflush(stdin);

        printf("\t\t\t\tEnter Phone Number:  ");
        scanf("%[^\n]%*c",c.mobileNumber);

        printf("\t\t\t\tEnter  address: ");
        scanf("%[^\n]%*c",c.address);

        printf("\t\t\t\tEnter  E-Mail id: ");
        scanf("%[^\n]%*c",c.email);

        fwrite(&c,sizeof(c),1,ptr);

        printf("\n\t\t\t\tDo you want to add another Contact?(Y/N): ");
        ch = getchar();

    } while ( ch == 'y' || ch == 'Y' );

    fclose(ptr);

    usleep(2000000);

    printf("\n\n\t\t\t\tPress Enter to go to the menu page.......");
    getch();

    system("cls");

    welCome();
    mainMenu();
    printf("\n\n");
    menu();
}

void listOfContact() {

    system("cls");

    welCome();
    usleep(1000000);
    puts("\t\t\t\t=====================================================");
    puts("\t\t\t\t|                  View all List                    |");
    puts("\t\t\t\t=====================================================");


     ptr = fopen("contactlist.txt","r");

    if ( ptr == NULL )
    {
        printf("\n\n\t\t\t\tFile doesn't open.");
        exit(4);
    }

    while ( fread(&c,sizeof(c),1,ptr) != 0)
    {
        usleep(1000000);
        printf("\n\n\t\t\t\tName: %s",c.name);
        printf("\n\t\t\t\tMobile Number: %s",c.mobileNumber);
        printf("\n\t\t\t\tAddress: %s",c.address);
        printf("\n\t\t\t\tEmail Id: %s",c.email);
    }

    fclose(ptr);

    usleep(2000000);
    printf("\n\n\t\t\t\tPress Enter to go to the menu page.......");
    getch();
    system("cls");

    welCome();
    mainMenu();
    menu();

}

void search_Contact() {

    char name[50],mobileNumber[50];
    int f=0;

    system("cls");
    welCome();
    usleep(1000000);
    puts("\t\t\t\t=====================================================");
    puts("\t\t\t\t|                 Search a Contact                  |");
    puts("\t\t\t\t=====================================================");

    ptr = fopen("contactlist.txt","r");

    if ( ptr == NULL )
    {
        printf("\n\n\t\t\t\tFile doesn't open.");
        exit(4);
    }

    printf("\n\n\t\t\t\t1. Search a Contact by Name ");
    printf("\n\t\t\t\t2. Search a Contact by Mobile Number ");

    int choice;
    fflush(stdin);
    choice = takeIntegerInput();

    switch(choice)
    {
    case 1:
        {
            usleep(1000000);
            printf("\n\n\t\t\t\tEnter a Name: ");
            fflush(stdin);
            scanf("%[^\n]%*c",name);

            while ( fread(&c,sizeof(c),1,ptr) != 0)
            {
            //search by name or search by mobile number

                if ( strcmp(name,c.name) == 0) {
                    usleep(1000000);
                    printf("\n\t\t\t\tMobile Number: %s",c.mobileNumber);
                    printf("\n\t\t\t\tAddress: %s",c.address);
                    printf("\n\t\t\t\tEmail Id: %s",c.email);
                    f++;
                }
            }

            if ( f == 0) {
                usleep(1000000);
                printf("\n\n\t\t\t\tResult not found...");
            }

            break;
        }
    case 2:
        {
            f = 0;
            usleep(1000000);
            printf("\n\n\t\t\t\tEnter a Mobile Number: ");
            fflush(stdin);
            scanf("%[^\n]%*c",mobileNumber);

            while ( fread(&c,sizeof(c),1,ptr) != 0)
            {
            //search by name or search by mobile number

                if ( strcmp(mobileNumber,c.mobileNumber) == 0) {
                    usleep(1000000);
                    printf("\n\n\t\t\t\tName: %s",c.name);
                    printf("\n\t\t\t\tAddress: %s",c.address);
                    printf("\n\t\t\t\tEmail Id: %s",c.email);
                    f++;
                }
            }

            if ( f == 0) {
                usleep(1000000);
                printf("\n\n\t\t\t\tResult not found...");
            }
            break;
        }
    }
    fclose(ptr);
    usleep(2000000);
    printf("\n\n\t\t\t\tPress Enter to go to the menu page.......");
    getch();
    system("cls");

    welCome();
    mainMenu();
    printf("\n\n");
    menu();
}

void delete_Contact() {

    char name[50],mobileNumber[50];
    system("cls");
    welCome();
    usleep(1000000);
    puts("\t\t\t\t=====================================================");
    puts("\t\t\t\t|                 Delete a Contact                  |");
    puts("\t\t\t\t=====================================================");

    ptr = fopen("contactlist.txt","r");
    fp = fopen("temp.txt","w");

    if ( ptr == NULL )
    {
        printf("\n\n\t\t\t\tFile doesn't open.");
        exit(4);
    }

    if ( fp == NULL )
    {
        printf("\n\n\t\t\t\tFile doesn't open.");
        exit(4);
    }


    printf("\n\n\t\t\t\t1. Delete a Contact by Name ");
    printf("\n\t\t\t\t2. Delete a Contact by Mobile Number ");

    int choice,f=0;
    fflush(stdin);
    choice = takeIntegerInput();

    switch(choice)
    {
    case 1:
        {
            usleep(1000000);
            printf("\n\n\t\t\t\tEnter a Name: ");
            fflush(stdin);
            scanf("%[^\n]%*c",name);

            while ( fread(&c,sizeof(c),1,ptr) != 0)
            {
                //delete a contact
                if (strcmp(name,c.name) != 0) {
                    fwrite(&c,sizeof(c),1,fp);
                } else {
                    f++;
                }
            }

            if ( f == 1) {
                usleep(1000000);
                printf("\n\n\t\t\t\tDetails deleted Successfully.........");
            } else {
                usleep(1000000);
                printf("\n\n\t\t\t\tResult not found.........");
            }

            break;
        }
    case 2:
        {
            f = 0;
            usleep(1000000);
            printf("\n\n\t\t\t\tEnter a Mobile Number: ");
            fflush(stdin);
            scanf("%[^\n]%*c",mobileNumber);

            while ( fread(&c,sizeof(c),1,ptr) != 0)
            {
                //delete a contact
                if (strcmp(mobileNumber,c.mobileNumber) != 0) {
                    fwrite(&c,sizeof(c),1,fp);
                } else {
                    f++;
                }
            }

            if ( f == 1) {
                usleep(1000000);
                printf("\n\n\t\t\t\tDetails deleted Successfully.........");
            } else {
                usleep(1000000);
                printf("\n\n\t\t\t\tResult not found.........");
            }
            break;
        }
    }

    fclose(ptr);
    fclose(fp);

    remove("contactlist.txt");
    rename("temp.txt","contactlist.txt");

     fclose(ptr);
    usleep(2000000);
    printf("\n\n\t\t\t\tPress Enter to go to the menu page.......");
    getch();
    system("cls");

    welCome();
    mainMenu();
    printf("\n\n");
    menu();
}

void edit() {

    char name[50],mobileNumber[50];
    system("cls");
    welCome();
    usleep(1000000);
    puts("\t\t\t\t=====================================================");
    puts("\t\t\t\t|                 Edit a Contact                  |");
    puts("\t\t\t\t=====================================================");

    ptr = fopen("contactlist.txt","r");
    fp = fopen("temp.txt","w");

    if ( ptr == NULL )
    {
        printf("\n\n\t\t\t\tFile does not open.");
        exit(4);
    }

    if ( fp == NULL )
    {
        printf("\n\n\t\t\t\tFile does not open.");
        exit(4);
    }


    printf("\n\n\t\t\t\t1. Edit a Contact by Name ");
    printf("\n\t\t\t\t2. Edit a Contact by Mobile Number ");

    int choice,f=0;
    fflush(stdin);
    choice = takeIntegerInput();

    switch(choice)
    {
    case 1:
        {
            usleep(1000000);
            printf("\n\n\t\t\t\tEnter a Name: ");
            fflush(stdin);
            scanf("%[^\n]%*c",name);

            while ( fread(&c,sizeof(c),1,ptr) != 0)
            {
                //delete a contact
                if (strcmp(name,c.name) != 0) {
                    fwrite(&c,sizeof(c),1,fp);
                } else {  //if it's same
                    fflush(stdin);

                    printf("\n\t\t\t\tEnter  Name: ");
                    scanf("%[^\n]%*c",c.name);

                    fflush(stdin);

                    printf("\t\t\t\tEnter Phone Number:  ");
                    scanf("%[^\n]%*c",c.mobileNumber);

                    printf("\t\t\t\tEnter address: ");
                    scanf("%[^\n]%*c",c.address);

                    printf("\t\t\t\tEnter E-Mail id: ");
                    scanf("%[^\n]%*c",c.email);

                    fwrite(&c,sizeof(c),1,fp);
                    f++;
                }
            }

            if ( f == 1) {
                usleep(1000000);
                printf("\n\n\t\t\t\tDetails edited Successfully.........");
            } else {
                usleep(1000000);
                printf("\n\n\t\t\t\tResult not found.........");
            }

            break;
        }
    case 2:
        {
            f = 0;
            usleep(1000000);
            printf("\n\n\t\t\t\tEnter a Mobile Number: ");
            fflush(stdin);
            scanf("%[^\n]%*c",mobileNumber);

            while ( fread(&c,sizeof(c),1,ptr) != 0)
            {
                //delete a contact
                if (strcmp(mobileNumber,c.mobileNumber) != 0) {
                    fwrite(&c,sizeof(c),1,fp);
                } else {
                    fflush(stdin);

                    printf("\n\t\t\t\tEnter Name: ");
                    scanf("%[^\n]%*c",c.name);

                    fflush(stdin);

                    printf("\t\t\t\tEnter Phone Number:  ");
                    scanf("%[^\n]%*c",c.mobileNumber);

                    printf("\t\t\t\tEnter address: ");
                    scanf("%[^\n]%*c",c.address);

                    printf("\t\t\t\tEnter E-Mail id: ");
                    scanf("%[^\n]%*c",c.email);

                    fwrite(&c,sizeof(c),1,fp);
                    f++;
                }
            }

            if ( f == 1) {
                usleep(1000000);
                printf("\n\n\t\t\t\tDetails edited Successfully.........");
            } else {
                usleep(1000000);
                printf("\n\n\t\t\t\tResult not found.........");
            }
            break;
        }
    }

    fclose(ptr);
    fclose(fp);

    remove("contactlist.txt");
    rename("temp.txt","contactlist.txt");

     fclose(ptr);
    usleep(2000000);
    printf("\n\n\t\t\t\tPress Enter to go to the menu page.......");
    getch();
    system("cls");

    welCome();
    mainMenu();
    printf("\n\n");
    menu();
}
