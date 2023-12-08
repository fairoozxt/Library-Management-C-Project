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

int main()
{
    printf("hello world");

    return 0;
}

void show_welcome()
{
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

void add_book()
{
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
