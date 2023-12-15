#include <stdio.h> /* to import standard input and output */

#include <string.h>

#include <conio.h>

#include <unistd.h> /* for providing sleep function */

#include <stdlib.h>

struct Book /* define a structure for a book */
{
    char Title[100];

    char Author[100];

    float Price;

    char issue_Date[9];
};

struct Library
{
    struct Book books[100];

    int bookCount;
};

/* function prototype */

void show_welcome();

void show_exit_message();

int authorization_screen();

void show_menu();

void enter_choice(struct Library *library);

void add_book();

void show_all_books(struct Library *library);

void search_books_by_name();

void search_books_by_author();

void delete_last_book(struct Library *library);

void any_book_delete(struct Library *library);


int main()
{
    struct Library library  = {0};   // initialize book count to 0

    if(authorization_screen() == 1)
    {
        enter_choice(&library);
    }

    return 0;
}

void show_welcome()
{
    /* to print first three row of the pattern */
    for(int i = 0; i < 3; i++)
    {
        printf("\n\t|");

        for(int j = 0; j < 94; j++)
        {
            printf("*|");
        }
    }

    printf("\n"); /* creates new line for the next rows */

    /* to print the upper three row of the text */
    for(int i = 0; i < 6; i++)
    {
        printf("\t|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|                                                                                 |*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|\n");

        /* to print the middle row with the text */
        if(i == 2)
        {
            printf("\t|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|                             WELCOME TO EWU LIBRARY                              |*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|\n");
        }

    }

    /* to print last three row of the pattern */
    for(int i = 0; i < 3; i++)
    {
        printf("\t|");

        for(int j = 0; j < 94; j++)
        {
            printf("*|");
        }

        printf("\n"); /* creates new line for the next rows */
    }

    printf("\n\n\n");


    for (int i = 0; i < 1; i++)
    {

        for (int j = 0; j < 61; j++)
        {
            printf("*_");

            printf(" ");
        }
    }

    printf("*");

    for (int i = 0; i < 1; i++)
    {

        for (int j = 0; j < 61; j++)
        {
            printf(" ");
        }
    }

    printf("*\n");

    printf("\t\t\t\t\t\t\t\t\t\t\tAdd A New Book\t\t\t\t\t\t\t\t\t\t\t\n");

    for (int i = 0; i < 1; i++)
    {
        for (int j = 0; j < 61; j++)
        {
            printf(" ");

            printf("*_");
        }
    }

    printf("*");
}

void show_exit_message()
{
    printf("\n");

    printf("\n");

    for(int i = 0; i < 2; i++) /* to print first two rows of the pattern */
    {
        printf("\n\t\t\t\t\t\t|"); /* help patterns to adjust in the middle of the console */

        for(int j = 0; j < 15; j++)
        {
            printf("*|");
        }

        printf("     |");

        for(int j = 20; j < 35; j++)
        {
            printf("*|");
        }

        printf("     |");

        for(int j = 40; j < 55; j++)
        {
            printf("*|");
        }
    }

    printf("\n");

    printf("\n");

    for(int i = 0; i < 6; i++) /* to print middle patterns */
    {
        sleep(1);

        printf("\t\t\t\t\t\t|*|*|*|*|*|*|*|*|*|*|                                                             |*|*|*|*|*|*|*|*|*|*|\n");

        if(i == 2)
        {
            printf("\t\t\t\t\t\t|*|*|*|*|*|*|*|*|*|*|                Thanks For Using EWU Library                 |*|*|*|*|*|*|*|*|*|*|\n");
        }
    }

    for(int i = 0; i < 2; i++) /* to print last two rows of the pattern */
    {
        printf("\n\t\t\t\t\t\t|");

        for(int j = 0; j < 15; j++)
        {
            printf("*|");
        }

        printf("     |");

        for(int j = 20; j < 35; j++)
        {
            printf("*|");
        }

        printf("     |");

        for(int j = 40; j < 55; j++)
        {
            printf("*|");
        }
    }
    printf("\n\n\n");
}

int authorization_screen()
{
    char username[20], password[20];

    char ch;

    int i = 0;

    printf("\nPlease enter your username: ");

    scanf("%s", username);

    printf("\nPlease enter your password: ");
    do
    {
        ch = getch();

        password[i++] = ch;

        printf("*"); // Display an asterisk for each entered character
    }
    while (ch != 13);   // Stop at the Enter key

    password[i - 1] = '\0'; // Replace the last character (Enter key) with null terminator

    if (strcmp(username, "Admin") == 0 && strcmp(password, "password123") == 0)
    {
        return 1;
    }
    else
    {
        printf("\n\nInvalid username or password! \n\tPlease try again.\n");

        return 0;
    }
}

void show_menu()
{
    printf("\n\n1 . Add a Book");

    printf("\n2 . Search Book by Name");

    printf("\n3 . Search Book by Author");

    printf("\n4 . Show All Book's Information");

    printf("\n5 . Delete Last Book");

    printf("\n6 . Any Book Delete");

    printf("\n7 . Exit");
}

void enter_choice(struct Library *library) /* char parameter type will take any key character from user and will show the result accordingly the code */
{
    char choice;

    do
    {
        show_menu();

        printf("\n\nEnter your choice (1 to 6): ");

        scanf(" %c", &choice); /* Fix the input stream by adding a space before the format specifier */

        system("cls");

        switch (choice) /* multiple selection statement of 'Switch' applied */
        {
        case '1':

            add_book(&library);

            break;

        case '2':
            search_books_by_name(&library);

            break;

        case '3':

            search_books_by_author(&library);

            break;

        case '4':

            show_all_books(&library);

            break;

        case '5':

            delete_last_book(&library);

            break;

        case '6':

            any_book_delete(&library);

            break;

        case '7':

            show_exit_message();

            break;

        default: /* this key word will apply when the user will not input choice between 1 to 6 */

            printf("\nSorry, you have entered a wrong choice!\n\n\tPlease Try Again.");

            break;
        }
    }
    while(choice != '7');
}

void add_book(struct Library *library)
{
    for (int i = 0; i < 1; i++)
    {

        for (int j = 0; j < 61; j++)
        {
            printf("*_");

            printf(" ");
        }
    }

    printf("*");

    for (int i = 0; i < 1; i++)
    {

        for (int j = 0; j < 61; j++)
        {

            printf(" ");
        }
    }


    printf("*\n");
    printf("                                                                                     Add New Book                                                                                                                \n");

    for (int i = 0; i < 1; i++)
    {
        for (int j = 0; j < 61; j++)
        {
            printf(" ");
            printf("*_");
        }
    }

    printf("*");

    if((*library).bookCount < 100)
    {
        struct Book newBook;

        printf("\n\n");

        printf("Please Enter Book Name: ");

        scanf(" %[^\n]s", newBook.Title);

        printf("Please Enter Book Author Name: ");

        scanf(" %[^\n]s", newBook.Author);

        printf("Please Enter Book Price: ");

        scanf("%f", &newBook.Price);

        printf("Please Enter Book Issue Date(DD/MM/YY): ");

        scanf(" %[^\n]s", newBook.issue_Date);

        (*library).books[(*library).bookCount++]= newBook;  /* add a new book to library */

        printf("\n\tBook Added Successfully!");
    }
    else
    {
        printf("\nLibrary is Full.");
    }
}

void show_all_books(struct Library *library)
{
    for (int i = 0; i < (*library).bookCount; i++) /* checking inputs using a loop */
    {
        printf("\n");

        printf("Book Number      : %d\n", i + 1);

        printf("Book Name        : %s\n", (*library).books[i].Title);

        printf("Book Author Name : %s\n", (*library).books[i].Author);

        printf("Book Price       : %.2f\n", (*library).books[i].Price);

        printf("Book Issue Date  : %s\n", (*library).books[i].issue_Date);
    }

    if((*library).bookCount == 0)
    {
        printf("Sorry There's No Book In The Inventory");
    }
}

void search_books_by_name(struct Library *library)
{
    char searchTitle[50];

    printf("\nPlease Enter The Book's Name: ");

    scanf(" %[^\n]s", &searchTitle);

    int found = 0;

    for(int i = 0; i < (*library).bookCount; i++)
    {
        if(strcmp((*library).books[i].Title, searchTitle) == 0)
        {
            printf("\n\tBOOK FOUND\n\n");

            printf("Book Number     : %d\n", i + 1);

            printf("Book Name       : %s\n", (*library).books[i].Title);

            printf("Book Author Name: %s\n", (*library).books[i].Author);

            printf("Book Price      : %.2f\n", (*library).books[i].Price);

            printf("Book Issue Date : %s\n", (*library).books[i].issue_Date);

            found = 1;

            break;
        }
    }

    if(!found)
    {
        printf("\n|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|                                Sorry ! NO BOOK FOUND                             |*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|\n\n");

    }
}

void search_books_by_author()
{
}

void delete_last_book(struct Library *library)
{
    if((*library).bookCount == 0)
    {
        printf("\nNo book is available to delete!");
    }
    else
    {
        (*library).bookCount--;

        printf("\nYour last book is successfully deleted.");

        printf("\n\nTotal Available Books: %d", (*library).bookCount);
    }
}

void any_book_delete(struct Library *library)
{
    char deleteBook[50];

    printf("Please Enter the Book Name to Delete: ");

    scanf(" %[^\n]s", &deleteBook);

    int found = 0;

    for(int i = 0; i < (*library).bookCount; i++)
    {
        if(strcmp((*library).books[i].Title, deleteBook) == 0)
        {
            for(int j = i; j < (*library).bookCount - 1; j++)
            {
                (*library).books[j] = (*library).books[j + 1];
            }

            ((*library).bookCount)--;

            found = 1;

            printf("Book Deleted Successfully!");

            printf("\n\nTotal Available Books: %d", (*library).bookCount);
        }
    }

    if(!found)
    {
        printf("Book %s was Not Not Found.\n", deleteBook);
    }
}
