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

void read(void)
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

bool findByTitle(void)
{
    char title[TAMANHO];
    bool found = false;

    printf("Informe o título do livro: ");
    gets(title);

    for ( byte i = 0, size = 10; i < size; i++ )
	{
        if ( strcmp(title, library[i].title) == 0 )
        {
            printBookInfo(i + 1, &library[i]);

            found = true;
        }
    }

    return found;
}

bool findByAuthor(void)
{
    char word[TAMANHO];
    bool wasFound = false;

    printf("Informe o nome do autor: ");
    gets(word);

    for ( byte i = 0, size = 10; i < size; i++ )
	{
        if ( strcmp(word, library[i].author) == 0 )
        {
            printBookInfo(i + 1, &library[i]);

            wasFound = true;
        }
    }

    return wasFound;
}

bool findByPublishingCiA(void)
{
    char word[TAMANHO];
    bool wasFound = false;

    printf("Informe o nome da editora: ");
    gets(word);

    for ( byte i = 0, size = 10; i < size; i++ )
	{
        if ( strcmp(word, library[i].publishing) == 0 )
        {
            printBookInfo(i + 1, &library[i]);

            wasFound = true;
        }
    }

    return wasFound;
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

void find(void)
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

void del(void)
{
	char title[TAMANHO];
	bool was_found = false;

	printf(
        "Informe o título do livro "
        "(se mais de um livro possuir o mesmo título, "
        "o primeiro a ser inserido será excluído): "
	);
	gets(title);

	for ( byte i = 0, size = 10; i < size; i++ )
	{
		if ( strcmp(title, library[i].title) == 0 )
        {
			strcpy(library[i].title, "");
	        strcpy(library[i].author, "");
	        strcpy(library[i].publishing, "");
	        strcpy(library[i].subject, "");
	        library[i].release = 0;

            was_found = true;

            break;
		}
	}

	printf("%s \n", ( not was_found ) ? "Livro não encontrado." : "Livro excluído.");
}

void create(void)
{
	bool was_found = false;

	for ( byte i = 0, size = 10; i < size; i++ )
	{
		if ( library[i].release == 0 )
        {
            printf("Nome do autor.......: ");
            gets(library[i].author);

            printf("Título do livro.....: ");
            gets(library[i].title);

            printf("Assunto.............: ");
            gets(library[i].subject);

            printf("Editora.............: ");
            gets(library[i].publishing);

            printf("Ano de lançamento...: ");
            scanf("%hd", &library[i].release);

            was_found = true;

            break;
		}
	}

	printf("%s \n", ( not was_found ) ? "Lista cheia." : "Livro incluído.");
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
                create();
                break;
			case READ:
                read();
                break;
			case DELETE:
                del();
                break;
			case SEARCH:
                find();
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