#include "./includes/Library.h"

/**
 *
 */
int main(int argc, const char** argv)
{
	setlocale(LC_ALL, "");

    start();

	return EXIT_SUCCESS;
}

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

bool responseIsValid(char response)
{
    response = tolower(response);

    return response == 's' or response == 'n';
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

Book showBooksForm(void)
{
    Book book = {};

    printf("Nome do autor.......: ");
    scanf(" %[^\n]s", book.author);

    printf("Título do livro.....: ");
    scanf(" %[^\n]s", book.title);

    printf("Assunto.............: ");
    scanf(" %[^\n]s", book.subject);

    printf("Editora.............: ");
    scanf(" %[^\n]s", book.publishing);

    printf("Ano de lançamento...: ");
    scanf("%hd", &book.release);

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

const unsigned int showSearchMenu(void)
{
    byte choice = 0u;

    printf(
        "\nSelecione o tipo de busca:"
        "\n1. Por título | 2. Por Autor | 3. Por Editora"
        "\nOpção\? "
    );
    scanf("%hhd", &choice);
    getchar();

    return choice;
}

const unsigned int showMainMenu(void)
{
    unsigned int choice = 0u;

    printf(
        "\nEscolha uma das opções:"
        "\n1. Inserir livro | 2. Exibir acervo"
        "\n3. Excluir livro | 4. Pesquisar"
        "\n0. Sair"
        "\nOpção\? "
    );
    scanf("%d", &choice);
    getchar();

    return choice;
}