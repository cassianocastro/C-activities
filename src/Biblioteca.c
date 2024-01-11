#include <ctype.h>
#include <iso646.h>
#include <locale.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANHO 50

typedef unsigned char byte;

typedef enum
{
    EXIT,
    CREATE,
    READ,
    DELETE,
    SEARCH
}
Options;

typedef struct
{
	char title[TAMANHO];
	char author[TAMANHO];
	char publishing[TAMANHO];
	char subject[TAMANHO];

	unsigned short release;
}
Book;

Book library[10];

Book createBook(void)
{
    Book book = {
        .title      = "",
        .author     = "",
        .subject    = "",
        .publishing = "",
        .release    = 0
    };

    return book;
}

void printBookInfo(int i, const Book* const book)
{
    printf(
        "\nLivro nº %d do acervo......:"
        "\nTítulo....................: %s"
        "\nAutor.....................: %s"
        "\nEditora...................: %s"
        "\nAssunto...................: %s"
        "\nAno de lançamento.........: %d"
        "\n----------\n",
        i,
        book->title,
        book->author,
        book->publishing,
        book->subject,
        book->release
    );
}

bool findByTitle(void)
{
    char str[TAMANHO];
    bool found = false;

    printf("Informe o título do livro: ");
    scanf("%[^\n]s", str);

    for ( register byte i = 0, size = 10; i < size; ++i )
	{
        if ( strcmp(str, library[i].title) == 0 )
        {
            printBookInfo(i + 1, &library[i]);

            found = true;
        }
    }

    return found;
}

bool findByAuthor(void)
{
    char str[TAMANHO];
    bool found = false;

    printf("Informe o nome do autor: ");
    scanf("%[^\n]s", str);

    for ( register byte i = 0, size = 10; i < size; ++i )
	{
        if ( strcmp(str, library[i].author) == 0 )
        {
            printBookInfo(i + 1, &library[i]);

            found = true;
        }
    }

    return found;
}

bool findByPublishingCiA(void)
{
    char str[TAMANHO];
    bool found = false;

    printf("Informe o nome da editora: ");
    scanf("%[^\n]s", str);

    for ( register byte i = 0, size = 10; i < size; ++i )
	{
        if ( strcmp(str, library[i].publishing) == 0 )
        {
            printBookInfo(i + 1, &library[i]);

            found = true;
        }
    }

    return found;
}

bool responseIsValid(char response)
{
    response = tolower(response);

    if ( response == 's' or response == 'n' )
    {
        return true;
    }

    return false;
}

char askUser(void)
{
    char response = '\0';

    printf("\nDeseja voltar ao menu principal[s/n]\? ");
    scanf(" %c", &response);

    while ( not responseIsValid(response) )
	{
        printf("\nResposta inválida. Digite novamente: ");
        scanf(" %c", &response);
    }

    return response;
}

void addBook(void)
{
	bool found = false;

	for ( register byte i = 0, size = 10; i < size; ++i )
	{
		if ( library[i].release == 0 )
        {
            printf("Nome do autor.......: ");
            scanf(" %[^\n]s", library[i].author);

            printf("Título do livro.....: ");
            scanf(" %[^\n]s", library[i].title);

            printf("Assunto.............: ");
            scanf(" %[^\n]s", library[i].subject);

            printf("Editora.............: ");
            scanf(" %[^\n]s", library[i].publishing);

            printf("Ano de lançamento...: ");
            scanf("%hd", &library[i].release);

            found = true;

            break;
		}
	}

	printf("%s\n", not found ? "Lista cheia." : "Livro incluído.");
}

void showBooks(void)
{
    byte count = 0, size = 10;

    for ( register byte i = 0; i < size; ++i )
	{
        if ( library[i].release != 0 )
        {
            printBookInfo(i + 1, &library[i]);
        }
        else
        {
            ++count;
        }
    }

    if ( count == size )
    {
        puts("Sem livros cadastrados.");
    }
}

void deleteBook(void)
{
	char str[TAMANHO];
	bool found = false;

	printf(
        "Informe o título do livro "
        "(se mais de um livro possuir o mesmo título, "
        "o primeiro a ser inserido será excluído): "
	);
	scanf("%[^\n]s", str);

	for ( register byte i = 0, size = 10; i < size; ++i )
	{
		if ( strcmp(str, library[i].title) == 0 )
        {
	        library[i] = createBook();

            found = true;

            break;
		}
	}

	printf("Livro %s.\n", not found ? "não encontrado" : "excluído");
}

void searchBook(void)
{
	byte opcao     = 0;
	bool was_found = false;
	char response  = '\0';

	do
	{
		printf(
            "\nSelecione o tipo de busca:\
            \n1 - Por título | 2 - Por Autor | 3 - Por Editora\
            \nOpção\? "
        );
		scanf("%hhd", &opcao);
		system("clear");
		getchar();

		switch ( opcao )
		{
			case 1:
				was_found = findByTitle();
				break;
			case 2:
				was_found = findByAuthor();
				break;
			case 3:
				was_found = findByPublishingCiA();
				break;
            default:
				puts("Opção inválida!");
		}

		if ( not was_found )
        {
            puts("Livro não encontrado.");
        }

        response = askUser();
	} while ( response == 'n' );
}

/**
 *
 */
int main(int argc, const char** argv)
{
	setlocale(LC_ALL, "");

    unsigned int option = 0u;

    for ( register byte i = 0, size = 10; i < size; ++i )
	{
        library[i] = createBook();
    }

	do {
		printf(
            "\nEscolha uma das opções:"
            "\n1. Inserir livro | 2. Exibir acervo"
            "\n3. Excluir livro | 4. Pesquisar"
            "\n0. Sair"
            "\nOpção\? "
        );
		scanf("%d", &option);
		getchar();

		system("clear");

		switch ( option )
		{
			case CREATE:
                addBook();
                break;
			case READ:
                showBooks();
                break;
			case DELETE:
                deleteBook();
                break;
			case SEARCH:
                searchBook();
                break;
			case EXIT:
                puts("Tchau...");
                break;
			default:
                puts("Opção inválida.");
		}
	} while ( option not_eq EXIT );

	return EXIT_SUCCESS;
}