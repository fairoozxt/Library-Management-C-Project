#include <stdio.h>

#include <string.h>  /* to use string functions */

#include <conio.h>   /* to use getch function */

#include <unistd.h>  /* for providing sleep function */

#include <stdlib.h>  /* to clear selective console */

struct Book          /* define a structure for a book */
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


int main()
{
    struct Library library  = {0};   // initialize books and book count to 0

    show_welcome();

    if(authorization_screen() == 1)
    {
        enter_choice(&library);
    }

    else
    {
        authorization_screen();
    }

    return 0;
}

void show_welcome()
{
    //sleep(1);

    for(int i = 0; i < 3; i++)      /* to print first two rows of the pattern */
    {
        printf("\n\t\t\t  |");

        for(int j = 0; j < 55; j++)
        {
            printf("*|");
        }

    }

    printf("\n");

    for(int i = 0; i < 6; i++) /* to print Welcome messsage inside patterns */
    {
        sleep(1);

            printf("\t\t\t  |*|*|*|*|*|*|*|*|*|*|*|*|                                                           |*|*|*|*|*|*|*|*|*|*|*|*|*|\n");

        if(i == 2)
        {
            printf("\t\t\t  |*|*|*|*|*|*|*|*|*|*|*|*|                WELCOME TO EWU LIBRARY                     |*|*|*|*|*|*|*|*|*|*|*|*|*|\n");
        }
    }

    for(int i = 0; i < 3; i++)     /* to print last three rows of the pattern */
    {
        printf("\t\t\t  |");

        for(int j = 0; j < 55; j++)
        {
            printf("*|");
        }

        printf("\n");   /* creates new line for every rows */
    }

    printf("\n\n\n");
}

void show_exit_message()
{
    system("cls");

    printf("\n\n");

    for(int i = 0; i < 2; i++)      /* to print first two rows of the pattern */
    {
        printf("\n\t\t\t  |");  /* help patterns to adjust in the middle of the console */

        for(int j = 0; j < 16; j++)
        {
            printf("*|");
        }

        printf("     |");

        for(int j = 20; j < 36; j++)
        {
            printf("*|");
        }

        printf("     |");

        for(int j = 40; j < 56; j++)
        {
            printf("*|");
        }
    }

    printf("\n\n");

    for(int i = 0; i < 6; i++) /* to print middle patterns */
    {
        sleep(1);

        printf("\t\t\t  |*|*|*|*|*|*|*|*|*|*|*|*|                                                           |*|*|*|*|*|*|*|*|*|*|*|*|\n");

        if(i == 2)
        {
            printf("\t\t\t  |*|*|*|*|*|*|*|*|*|*|*|*|              Thanks For Using EWU Library                 |*|*|*|*|*|*|*|*|*|*|*|*|\n");
        }
    }

    for(int i = 0; i < 2; i++) /* to print last two rows of the pattern */
    {
        printf("\n\t\t\t  |");

        for(int j = 0; j < 16; j++)
        {
            printf("*|");
        }

        printf("     |");

        for(int j = 20; j < 36; j++)
        {
            printf("*|");
        }

        printf("     |");

        for(int j = 40; j < 56; j++)
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

    printf("\n\n\t\t\t  ");

    for (int j = 0; j < 37; j++)
    {
        printf("*_ ");
    }

    printf("*\n\n");

    printf("\t\t\t\t Please enter your username: ");

    scanf("%s", username);

    printf("\n\t\t\t\t Please enter your password: ");
    do
    {
        ch = getch();
        password[i++] = ch;
        printf("*");          // Display an asterisk for each entered character

    }
    while (ch != 13);         // Stop at the Enter key

    password[i - 1] = '\0';   // Replace the last character (Enter key) with null terminator

    if (strcmp(username, "Admin") == 0 && strcmp(password, "password123") == 0)   /* comparing user input with stored username and password */
    {
        printf("\n\n\t\t\t  ");

        for (int j = 0; j < 37; j++)
        {
            printf("*_ ");
        }

        printf("*");

        return 1;
    }
    else
    {

        printf("\n\n\n\t\t\t\t\t\t\t    Incorrect username or password. Please try again  \n");

        return 0;
    }
}

void show_menu()
{
    char choice;

    printf("\n\n\n\t\t\t  ");

    for (int j = 0; j < 37; j++)
    {
        printf("*_ ");
    }
    printf("*\n");

    printf("\n\n\n\t\t\t\t1 . Add a Book ");
    printf("\n\t\t\t\t2 . Search Book By Name ");
    printf("\n\t\t\t\t3 . Search Book By Author ");
    printf("\n\t\t\t\t4 . Show All Book Information ");
    printf("\n\t\t\t\t5 . Delete a Book ");
    printf("\n\t\t\t\t6 . Exit ");

    printf("\n\n");


    return choice;
}

void enter_choice(struct Library *library)
{
    char choice;

    do
    {
        show_menu();

        printf("\n\n\t\t\t\tEnter your choice (1 to 6): ");

        scanf(" %c", &choice);   /* Fix the input stream by adding a space before the format specifier */

        switch (choice)   /* multiple selection statement of 'Switch' applied */
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

            show_exit_message();

            break;

        default:          /* this key word will apply when the user will not input choice between 1 to 6 */

            printf("\n\t\t\t\t\t\t\t  Sorry, you have entered a wrong choice!\n\n\t\t\t\t\t\t\t  Please Try Again.");

            break;
        }
    }
    while(choice != '6');
}

void add_book(struct Library *library)
{

    printf("\n\n\n\n\t\t\t  ");

    for (int j = 0; j < 37; j++)
    {
        printf("*_ ");
    }

    printf("*\n");

    printf("\n\n\t\t\t\t\t\t\t\t\t    Add A New Book \n\n\n");

    printf("\t\t\t  ");

    for (int j = 0; j < 37; j++)
    {
        printf("*_ ");
    }

    printf("*");

    printf("\n\n\n");

    if((*library).bookCount < 100)    // this indicates that the library can store 100 books until book count limit is reached
    {
        struct Book newBook;

        printf("\n\n");

        printf("\n\t\t\t\tPlease Enter Book Name: ");

        scanf(" %[^\n]s", newBook.Title);

        printf("\n\t\t\t\tPlease Enter Book Author Name: ");

        scanf(" %[^\n]s", newBook.Author);

        printf("\n\t\t\t\tPlease Enter Book Price: ");

        scanf("%f", &newBook.Price);

        printf("\n\t\t\t\tPlease Enter Book Issue Date(DD/MM/YY): ");

        scanf(" %[^\n]s", newBook.issue_Date);

        (*library).books[(*library).bookCount++] = newBook; // add a new book to library//

        printf("\n\n\n\n");

        printf("\n\n\t\t\t\t\t\t\t\t\t~Book added successfully!~  \n");

    }
    else
    {

        printf("\n\n\t\t\t\t\t\t\t\t\t\t  ~Library is Full~  ");    // this message will be shown on the screen if the limit of 100 books is filled

    }
}

void show_all_books(struct Library *library)
{
    for (int i = 0; i < (*library).bookCount; i++)   /* checking inputs using a loop */
    {
        printf("\n\n");

        printf("\n\t\t\t\tBook Number      : %d\n", i+1);

        printf("\n\t\t\t\tBook Name        : %s\n", (*library).books[i].Title);

        printf("\n\t\t\t\tBook Author Name : %s\n", (*library).books[i].Author);

        printf("\n\t\t\t\tBook Price       : %.2f\n", (*library).books[i].Price);

        printf("\n\t\t\t\tBook Issue Date  : %s\n", (*library).books[i].issue_Date);
    }

    if((*library).bookCount == 0)     /* checking if book count is zero */
    {
        printf("\n\n\n\t\t\t  |*|*|*|*|*|*|*|*|*|*|*|*|\t\tSorry There's No Book In The Inventory\t\t|*|*|*|*|*|*|*|*|*|*|*|*|\n\n");
    }
}

void search_books_by_name(struct Library *library)
{
    char searchTitle[50];

    printf("\n\n\n\t\t\t  ");

    for (int j = 0; j < 37; j++)
    {
        printf("*_ ");
    }
    printf("*\n\n");

    printf("\n\t\t\t\t\t\t\t\t\t   Search Book By Title \n\n\n");

    printf("\t\t\t  ");

    for (int j = 0; j < 37; j++)
    {
        printf("*_ ");
    }
    printf("*\n\n");


    printf("\n\t\t\t\tPlease Enter The Book's Name: ");

    scanf(" %[^\n]s", &searchTitle);

    printf("\n\n");

    int found = 0;

    for(int i = 0; i < (*library).bookCount; i++)   /* for loop to find book information until the limit is reached */
    {
        if(strcmp((*library).books[i].Title, searchTitle) == 0)    /* comparing user input with stored book information */
        {
            printf("\n\n\n\t\t\t  |*|*|*|*|*|*|*|*|*|*|*|*|\t\t\t    BOOK FOUND   \t\t\t|*|*|*|*|*|*|*|*|*|*|*|*|\n\n\n");

            printf("\t\t\t  ");

            for (int j = 0; j < 37; j++)
            {
                printf("*_ ");
            }
            printf("*\n\n");

            printf("\n\t\t\t\tBook Number      : %d\n", i+1);

            printf("\n\t\t\t\tBook Name        : %s\n", (*library).books[i].Title);

            printf("\n\t\t\t\tBook Author Name : %s\n", (*library).books[i].Author);

            printf("\n\t\t\t\tBook Price       : %.2f\n", (*library).books[i].Price);

            printf("\n\t\t\t\tBook Issue Date  : %s\n", (*library).books[i].issue_Date);

            found = 1;

            break;

        }
    }

    if(!found)
    {

        printf("\n\n\n\t\t\t  |*|*|*|*|*|*|*|*|*|*|*|*|\t\t\tSorry ! NO BOOK FOUND \t\t\t|*|*|*|*|*|*|*|*|*|*|*|*|\n\n\n");

        printf("\t\t\t  ");

        for (int j = 0; j < 37; j++)
        {
            printf("*_ ");
        }
        printf("*\n\n");

    }
}

void search_books_by_author(struct Library *library)
{
    char searchAuthor[100];

    printf("\n\n\n\t\t\t  ");

    for (int j = 0; j < 37; j++)
    {
        printf("*_ ");
    }
    printf("*\n\n");

    printf("\n\t\t\t\t\t\t\t\t\t   Search Book By Author \n\n\n");

    printf("\t\t\t  ");

    for (int j = 0; j < 37; j++)
    {
        printf("*_ ");
    }
    printf("*\n\n");

    printf("\n\t\t\t\tPlease Enter The Author's Name: ");

    scanf(" %[^\n]s", &searchAuthor);

    int found = 0;

    for (int i = 0; i < (*library).bookCount; i++)     /* checking inputs using a loop */
    {

        if (strcmp((*library).books[i].Author, searchAuthor) == 0)     /* comparing user's author name input with the stored inputs */
        {

            printf("\n\n\n\t\t\t  |*|*|*|*|*|*|*|*|*|*|*|*|\t\t\t   BOOK FOUND   \t\t\t|*|*|*|*|*|*|*|*|*|*|*|*|\n\n\n");

            printf("\t\t\t  ");

            for (int j = 0; j < 37; j++)
            {
                printf("*_ ");
            }
            printf("*\n\n");

            printf("\n\t\t\t\tBook Number: %d\n", i+1);

            printf("\n\t\t\t\tBook Name: %s\n", (*library).books[i].Title);

            printf("\n\t\t\t\tBook Author Name: %s\n", (*library).books[i].Author);

            printf("\n\t\t\t\tBook Price: %f\n", (*library).books[i].Price);

            printf("\n\t\t\t\tBook Issue Date: %s\n", (*library).books[i].issue_Date);

            printf("\t\t\t  ");

            for (int j = 0; j < 37; j++)
            {
                printf("*_ ");
            }
            printf("*\n\n");

            found = 1;

            break;
        }
    }

    if (!found)   /* !found = not found */
    {
        printf("\n\n\n\t\t\t  |*|*|*|*|*|*|*|*|*|*|*|*|\t\t\tSorry ! NO BOOK FOUND \t\t\t|*|*|*|*|*|*|*|*|*|*|*|*|\n\n\n");

        printf("\t\t\t  ");

        for (int j = 0; j < 37; j++)
        {
            printf("*_ ");
        }
        printf("*\n\n");

    }

}

void delete_last_book(struct Library *library)
{
    if((*library).bookCount == 0)    /* if book count is zero then the following message will be shown */
    {
        printf("\n\n\n\t\t\t  |*|*|*|*|*|*|*|*|*|*|*|*|\t\t\tNo book is available to delete\t\t |*|*|*|*|*|*|*|*|*|*|*|*|\n\n\n");

    }
    else
    {
        (*library).bookCount--;      /* if book is found that this statement decrements the last book and shows the following message */

        printf("\n\n\n\t\t\t  |*|*|*|*|*|*|*|*|*|*|*|*|\t\tYour last book is successfully deleted\t\t|*|*|*|*|*|*|*|*|*|*|*|*|\n\n\n");
    }
}
