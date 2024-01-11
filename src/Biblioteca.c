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

struct livro
{
	char titulo[TAMANHO];
	char autor[TAMANHO];
	char editora[TAMANHO];
	char assunto[TAMANHO];

	unsigned short ano;
}
biblioteca[10];

void init(void)
{
    struct livro book = {
        .titulo  = "",
        .autor   = "",
        .assunto = "",
        .editora = "",
        .ano     = 0
    };

	for ( byte i = 0, size = 10; i < size; i++ )
	{
        biblioteca[i] = book;
    }
}

void getData(int i)
{
    printf(
        "\nLivro nº %d do acervo......:"
        "\nTítulo....................: %s"
        "\nAutor.....................: %s"
        "\nEditora...................: %s"
        "\nAssunto...................: %s"
        "\nAno de lançamento.........: %d"
        "\n----------\n",
        ( i + 1 ),
        biblioteca[i].titulo,
        biblioteca[i].autor,
        biblioteca[i].editora,
        biblioteca[i].assunto,
        biblioteca[i].ano
    );
}

void read(void)
{
    byte count = 0;
    byte size  = 10;

    for ( byte i = 0; i < size; i++ )
	{
        ( biblioteca[i].ano != 0 ) ? getData(i) : count++;
    }

    if ( count == size )
    {
        puts("Sem livros cadastrados.");
    }
}

bool findByTitle(void)
{
    char word[TAMANHO];
    bool wasFound = false;

    printf("Informe o título do livro: ");
    gets(word);

    for ( byte i = 0, size = 10; i < size; i++ )
	{
        if ( strcmp(word, biblioteca[i].titulo) == 0 )
        {
            getData(i);

            wasFound = true;
        }
    }

    return wasFound;
}

bool findByAuthor(void)
{
    char word[TAMANHO];
    bool wasFound = false;

    printf("Informe o nome do autor: ");
    gets(word);

    for ( byte i = 0, size = 10; i < size; i++ )
	{
        if ( strcmp(word, biblioteca[i].autor) == 0 )
        {
            getData(i);

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
        if ( strcmp(word, biblioteca[i].editora) == 0 )
        {
            getData(i);

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
		if ( strcmp(title, biblioteca[i].titulo) == 0 )
        {
			strcpy(biblioteca[i].titulo, "");
	        strcpy(biblioteca[i].autor, "");
	        strcpy(biblioteca[i].editora, "");
	        strcpy(biblioteca[i].assunto, "");
	        biblioteca[i].ano = 0;

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
		if ( biblioteca[i].ano == 0 )
        {
            printf("Nome do autor.......: ");
            gets(biblioteca[i].autor);

            printf("Título do livro.....: ");
            gets(biblioteca[i].titulo);

            printf("Assunto.............: ");
            gets(biblioteca[i].assunto);

            printf("Editora.............: ");
            gets(biblioteca[i].editora);

            printf("Ano de lançamento...: ");
            scanf("%hd", &biblioteca[i].ano);

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

    init();

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