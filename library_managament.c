#include <stdio.h>

void show_welcome();

void show_exit_message();

int authorization_screen();

void show_menu();

void enter_choice();

void add_book();

void show_all_books();

void search_books_by_name();

void search_books_by_author();

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

int main()
{
    printf("hello world");

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

void search_books_by_name()
{
}

void search_books_by_author()
{
}
