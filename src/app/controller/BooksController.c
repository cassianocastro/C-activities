#include "../../includes/controller/BooksController.h"

Book library[10];

void start(void)
{
    for ( register byte i = 0, size = 10; i < size; ++i )
	{
        library[i] = createBook();
    }

    unsigned int option = 0u;

	do {
		option = showMainMenu();

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
}

void addBook(void)
{
	bool found = false;

	for ( register byte i = 0, size = 10; i < size; ++i )
	{
		if ( library[i].release == 0 )
        {
            library[i] = showBooksForm();

            found = true;

            break;
		}
	}

	printf("%s.\n", not found ? "Lista cheia" : "Livro incluído");
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
	Book* book  = NULL;
	byte option = 0;

	do {
		option = showSearchMenu();

		system("clear");

		switch ( option )
		{
			case 1:
				book = findBookByTitle();
				break;
			case 2:
				book = findBookByAuthor();
				break;
			case 3:
				book = findBookByPublishingCiA();
				break;
            default:
				puts("Opção inválida!");
		}

        if ( book != NULL )
        {
            printBookInfo(1, book);
        }
		else
        {
            puts("Livro não encontrado.");
        }
	} while ( askUser() == 'n' );
}

Book* findBookByTitle(void)
{
    char str[TAMANHO];

    printf("Informe o título do livro: ");
    scanf(" %[^\n]s", str);

    for ( register byte i = 0, size = 10; i < size; ++i )
	{
        if ( strcmp(str, library[i].title) == 0 )
        {
            return &library[i];
        }
    }

    return NULL;
}

Book* findBookByAuthor(void)
{
    char str[TAMANHO];

    printf("Informe o nome do autor: ");
    scanf(" %[^\n]s", str);

    for ( register byte i = 0, size = 10; i < size; ++i )
	{
        if ( strcmp(str, library[i].author) == 0 )
        {
            return &library[i];
        }
    }

    return NULL;
}

Book* findBookByPublishingCiA(void)
{
    char str[TAMANHO];

    printf("Informe o nome da editora: ");
    scanf(" %[^\n]s", str);

    for ( register byte i = 0, size = 10; i < size; ++i )
	{
        if ( strcmp(str, library[i].publishing) == 0 )
        {
            return &library[i];
        }
    }

    return NULL;
}