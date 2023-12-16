#include <stdio.h>   /* to import standard input and output */

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
};

struct Library       /* define a structure for a Library */
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

void add_book(struct Library *library);

void show_all_books(struct Library *library);

void search_books_by_name(struct Library *library);

void search_books_by_author(struct Library *library);

void delete_last_book(struct Library *library);

void delete_any_book(struct Library *library);


int main()
{
    show_welcome();

    struct Library library  = {0};   // initialize books and book count to 0

    if(authorization_screen() == 1)
    {
        system("cls");

        enter_choice(&library);
    }

    else
    {
        printf("\n\n\n\t\t\t\t\t\t\t\t  Sorry! Incorrect username or password.  \n");
    }

    return 0;
}

void show_welcome()
{
    for(int i = 0; i < 3; i++)      /* to print first two rows of the pattern */
    {
        printf("\n\t\t\t  |");

        for(int j = 0; j < 55; j++)
        {
            printf("*|");
        }
    }

    printf("\n");

    for(int i = 0; i < 6; i++)     /* to print Welcome message inside patterns */
    {
        printf("\t\t\t  |*|*|*|*|*|*|*|*|*|*|*|*|                                                           |*|*|*|*|*|*|*|*|*|*|*|*|*|\n");

        if(i == 2)
        {
            printf("\t\t\t  |*|*|*|*|*|*|*|*|*|*|*|*|                  WELCOME TO EWU LIBRARY                   |*|*|*|*|*|*|*|*|*|*|*|*|*|\n");
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
    printf("\n\n");

    for(int i = 0; i < 2; i++)      /* to print first two rows of the pattern */
    {
        printf("\n\t\t\t     |");   /* help patterns to adjust in the middle of the console */

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

        printf("\t\t\t     |*|*|*|*|*|*|*|*|*|*|*|*|                                                           |*|*|*|*|*|*|*|*|*|*|*|*|\n");

        if(i == 2)
        {
            printf("\t\t\t     |*|*|*|*|*|*|*|*|*|*|*|*|              Thanks For Using EWU Library                 |*|*|*|*|*|*|*|*|*|*|*|*|\n");
        }
    }

    for(int i = 0; i < 2; i++) /* to print last two rows of the pattern */
    {
        printf("\n\t\t\t     |");

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

    printf("*\n\n\n");

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

    printf("\n\n\t\t\t\t2 . Search Book By Name ");

    printf("\n\n\t\t\t\t3 . Search Book By Author ");

    printf("\n\n\t\t\t\t4 . Show All Book Information ");

    printf("\n\n\t\t\t\t5 . Delete the Last Book ");

    printf("\n\n\t\t\t\t6 . Delete Any Book ");

    printf("\n\n\t\t\t\t7 . Exit ");

    printf("\n\n");
}

void enter_choice(struct Library *library)
{
    char choice;

    show_welcome();

    do
    {
        show_menu();

        printf("\n\t\t\t\tEnter your choice (1 to 6): ");

        scanf(" %c", &choice);   /* Fix the input stream by adding a space before the format specifier */

        system("cls");

        switch (choice)   /* multiple selection statement of 'Switch' applied */
        {
        case '1':

            show_welcome();

            system("cls");

            show_welcome();

            add_book(&library);

            break;

        case '2':

            system("cls");

            show_welcome();

            search_books_by_name(&library);

            break;

        case '3':

            system("cls");

            show_welcome();

            search_books_by_author(&library);

            break;

        case '4':

            system("cls");

            show_welcome();

            show_all_books(&library);

            break;

        case '5':

            system("cls");

            show_welcome();

            delete_last_book(&library);

            break;

        case '6':

            system("cls");

            show_welcome();

            delete_any_book(&library);

            break;

        case '7':

            show_exit_message();

            break;

        default:          /* this key word will apply when the user will not input the choice between 1 to 6 */

            show_welcome();

            printf("\n\t\t\t\t\t\t\t  Sorry, you have entered a wrong choice!\n\n\t\t\t\t\t\t\t  Please Try Again.");

            break;
        }
    }
    while(choice != '7');
}

void add_book(struct Library *library)
{
    printf("\n\n\t\t\t  ");

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

        scanf(" %[^\n]s", newBook.Title); //  %[^\n]s - reads a line of text until the first newline character is encountered

        printf("\n\t\t\t\tPlease Enter Book Author's Name: ");

        scanf(" %[^\n]s", newBook.Author);

        printf("\n\t\t\t\tPlease Enter Book Price: ");

        scanf("%f", &newBook.Price);

        printf("\n\t\t\t\tPlease Enter Book Issue Date (DD/MM/YY): ");

        scanf(" %[^\n]s", newBook.issue_Date);

        (*library).books[(*library).bookCount++] = newBook; // add a new book to library//

        printf("\n\n\n");

        printf("\n\n\t\t\t\t\t\t\t\t\t~Book Added Successfully!~  \n");

    }
    else
    {

        printf("\n\n\t\t\t\t\t\t\t\t\t\t  ~Library Is Full~  ");    // this message will be shown on the screen if the limit of 100 books is filled

    }
}

void show_all_books(struct Library *library)
{
    for (int i = 0; i < (*library).bookCount; i++)   /* checking inputs using a loop */
    {
        printf("\n");

        printf("\n\t\t\t\tBook Number      : %d\n", i+1);

        printf("\n\t\t\t\tBook Name        : %s\n", (*library).books[i].Title);

        printf("\n\t\t\t\tBook Author Name : %s\n", (*library).books[i].Author);

        printf("\n\t\t\t\tBook Price       : %.2f\n", (*library).books[i].Price);

        printf("\n\t\t\t\tBook Issue Date  : %s\n", (*library).books[i].issue_Date);

        printf("\n\n\t\t\t  ");

    for (int j = 0; j < 37; j++)
    {
        printf("*_ ");
    }

    printf("*\n");
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

    printf("\n\t\t\t\t\t\t\t\t\t Search Book By Title \n\n\n");

    printf("\t\t\t  ");

    for (int j = 0; j < 37; j++)
    {
        printf("*_ ");
    }
    printf("*\n\n");


    printf("\n\t\t\t\tPlease Enter The Book's Name: ");

    scanf(" %[^\n]s", &searchTitle);

    printf("\n\n");

    int found = 0; /* for checking true or false statement */

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

        printf("\n\n\n\t\t\t  |*|*|*|*|*|*|*|*|*|*|*|*|\t\t\tSorry! NO BOOK FOUND\t\t\t|*|*|*|*|*|*|*|*|*|*|*|*|\n\n\n");

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

    printf("\n\t\t\t\t\t\t\t\t\tSearch Book By Author \n\n\n");

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

            printf("\n\n\t\t\t  |*|*|*|*|*|*|*|*|*|*|*|*|*|\t\t\t     BOOK FOUND     \t\t\t|*|*|*|*|*|*|*|*|*|*|*|*|*|\n\n\n");

            printf("\t\t\t  ");

            for (int j = 0; j < 37; j++)
            {
                printf("*_ ");
            }
            printf("*\n\n");

            printf("\n\t\t\t\tBook Number: %d\n", i+1);

            printf("\n\t\t\t\tBook Name: %s\n", (*library).books[i].Title);

            printf("\n\t\t\t\tBook Author Name: %s\n", (*library).books[i].Author);

            printf("\n\t\t\t\tBook Price: %.2f\n", (*library).books[i].Price);

            printf("\n\t\t\t\tBook Issue Date: %s\n", (*library).books[i].issue_Date);

            printf("\n\n\t\t\t  ");

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
        printf("\n\n\n\t\t\t  |*|*|*|*|*|*|*|*|*|*|*|*|\t\t\tSORRY! NO BOOK FOUND \t\t\t|*|*|*|*|*|*|*|*|*|*|*|*|\n\n\n");

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
        printf("\n\n\n\t\t\t  |*|*|*|*|*|*|*|*|*|*|*|*|\t\tThere Is No Book Available To Delete.\t\t|*|*|*|*|*|*|*|*|*|*|*|*|\n\n\n");

    }
    else
    {
        (*library).bookCount--;      /* if book is found then this statement decrements the last book and shows the following message */

        printf("\n\n\n\t\t\t  |*|*|*|*|*|*|*|*|*|*|*|*|\t    The Last Book Has Been Successfully Deleted.    \t|*|*|*|*|*|*|*|*|*|*|*|*|\n\n\n");

        printf("\n\n\t\t\t  |*|*|*|*|*|*|*|*|*|*|*|*|\t\t Total Number Of Available Books: %d    \t\t|*|*|*|*|*|*|*|*|*|*|*|*|\n\n\n", (*library).bookCount);
    }
}

void delete_any_book(struct Library *library)
{
    char deleteBook[50];

    printf("\t\t\t\tPlease enter the book name to delete: ");

    scanf(" %[^\n]s", deleteBook);

    int found = 0;

    for(int i = 0; i < (*library).bookCount; i++)
    {
        if(strcmp((*library).books[i].Title, deleteBook) == 0)
        {
            for(int j = i; j < (*library).bookCount - 1; j++)
            {
                (*library).books[j] = (*library).books[j + 1]; /* to fill out the previous blank place */
            }

            ((*library).bookCount)--;

            found = 1;

            printf("\n\n\n\t\t\t  |*|*|*|*|*|*|*|*|*|*|*|*|\t\tThe Book Has Been Deleted Successfully!  \t|*|*|*|*|*|*|*|*|*|*|*|*|\n\n\n");

            printf("\n\n\t\t\t  |*|*|*|*|*|*|*|*|*|*|*|*|\t\t   Total Number Of Available Books: %d \t\t|*|*|*|*|*|*|*|*|*|*|*|*|\n\n\n", (*library).bookCount);
        }
    }

    if(!found)
    {
        printf("\n\n\n\t\t\t  \t\t\t\t ~~ The Book '%s' Is Not Available For Deletion. ~~ \n\n\n", deleteBook);
    }
}
