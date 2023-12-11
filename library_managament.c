#include <stdio.h>
#include<string.h>
#include<conio.h>

struct Book          //define a structure for a book
{

    char Title[100];

    char Author[100];

    float Price;

    char issue_Date[11];

    int bookNumber;
};

struct Library
{

    struct Book books[100];

    int bookCount;
};

//function prototype
void show_welcome();
void show_exit_message();
int authorization_screen();
void show_menu();
void enter_choice();
void add_book();
void show_all_books();
void search_books_by_name();
void search_books_by_author();




int main()
{
    struct Library library  = {0};   // initialize book count to 0

    if(authorization_screen() == 1)
    {

        enter_choice();

    }
    else
    {

        printf("Authorization failed. Exiting...\n");
    }


    return 0;
}

void show_welcome()
{
    /* to print first three row of the pattern */
    for(int i = 0; i < 3; i++)
    {
        printf("\n|");

        for(int j = 0; j < 94; j++)
        {
            printf("*|");
        }

    }

    printf("\n"); /* creates new line for the next rows */

    /* to print the upper three row of the text */
    for(int i = 0; i < 6; i++)
    {
        printf("|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|                                                                                 |*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|\n");

        /* to print the middle row with the text */
        if(i == 2)
        {
            printf("|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|                             WELCOME TO EWU LIBRARY                              |*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|\n");
        }

    }

    /* to print last three row of the pattern */
    for(int i = 0; i < 3; i++)
    {
        printf("|");

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

    if (strcmp(username, "admin") == 0 && strcmp(password, "password123") == 0)
    {
        return 1;
    }
    else
    {
        printf("\nInvalid username or password. Please try again.\n");
        return 0;
    }

}

void show_menu()
{
    int choice;

    printf("\n\n1 . Add a Book ");
    printf("\n2 . Search Book By Name ");
    printf("\n3 . Search Book By Author ");
    printf("\n4 . Show All Book Information ");
    printf("\n5 . Delete a Book ");
    printf("\n6 . Exit ");

    printf("\n\nPlease Enter Your Choice: ");
    scanf("%d", &choice);

    return choice;
}

void enter_choice()
{
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
    printf("                                                                                     Add A New Book                                                                                                                \n");

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

        printf("\nPlease Enter Book Name: ");

        scanf(" %[^\n]s", newBook.Title);

        printf("Please Enter Book Author Name: ");

        scanf(" %[^\n]s", newBook.Author);

        printf("Please Enter Book Price: ");

        scanf("%f", &newBook.Price);

        printf("Please Enter Book Issue Date(DD/MM/YY): ");

        scanf(" %[^\n]s", newBook.issue_Date);

        (*library).books[(*library).bookCount]= newBook;  //add a new book to library//


        printf("\nBook added successfully!");

    }
    else
    {

        printf("\nLibrary is Full.");
    }

}

void show_all_books()
{
}

void search_books_by_name(struct Library *library)
{

    char searchTitle[50];

    printf("Please Enter The Book's Name; ");

    scanf("%[^\n]s", &searchTitle);

    int found = 0;

    for(int i = 0; i < (*library).bookCount; i++)
    {

        if(strcmp((*library).books[i].Title, searchTitle) == 0)
        {

            printf("BOOK FOUND\n");

            printf("Book Number: %d\n", (*library).books[i].bookNumber);

            printf("Book Name: %s\n", (*library).books[i].Title);

            printf("Book Author Name: %s\n", (*library).books[i].Author);

            printf("Book Price: %f\n", (*library).books[i].Price);

            printf("Book Issue Date: %s\n", (*library).books[i].issue_Date);

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
