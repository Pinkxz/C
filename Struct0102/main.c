#include <stdio.h>
#include <stdlib.h>

   typedef struct Books{
        char autor[50];
        char nome [10];
    }Book;

int main()
{
    Book book;

    strcpy(book.autor, "mateus");
    strcpy(book.nome, "revisando");

    printf("%s", book.autor);
    printf("\n%s", book.nome);


    return 0;
}
