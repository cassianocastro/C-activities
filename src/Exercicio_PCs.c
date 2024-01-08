#include <ctype.h>
#include <iso646.h>
#include <locale.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_STRING 30

typedef struct
{
    char storageType;
    char model[TAM_STRING];
    char mark[TAM_STRING];
    char processor[TAM_STRING];

    int memory;
    int storage;
}
Computer;

typedef enum
{
	EXIT,
    CREATE,
    READ,
    UPDATE,
    DELETE,
    SEARCH
}
Opcoes;

typedef enum
{
	MARK,
    STORAGE_TYPE,
    STORAGE,
    MEMORY,
    MODEL,
    PROCESSOR
}
Dados;

typedef unsigned char byte;

Computer* inventary;

unsigned short numero;

void showComputerForm(byte i)
{
    printf("\nComputador nº %hhu\n", (i + 1));
	getchar();

    printf("Marca....................: ");
    gets(inventary[i].mark);

	printf("Modelo...................: ");
    gets(inventary[i].model);

	printf("Processador..............: ");
    gets(inventary[i].processor);

    printf("Armazenamento (em GB)....: ");
    scanf("%d", &inventary[i].storage);

	printf("Memória (em GB)..........: ");
    scanf("%d", &inventary[i].memory);

	do {
		printf("\nTipo de HD...[s/c]\? ");
        scanf(" %c", &inventary[i].storageType);
	} while (
        inventary[i].storageType != 's' and
        inventary[i].storageType != 'c'
    );
}

void printComputerInfo(const byte i, const Computer* const computer)
{
    printf(
        "\nComputador nº %hhu:"
        "\nMarca......................: %s"
        "\nModelo.....................: %s"
        "\nTipo de HD.................: %c"
        "\nCapac. de Armazenamento....: %d GB"
        "\nMemória....................: %d GB"
        "\nProcessador................: %s"
        "\n------------",
        i,
        computer->mark,
        computer->model,
        computer->storageType,
        computer->storage,
        computer->memory,
        computer->processor
    );
}

const unsigned int getMainMenuChoice(void)
{
    unsigned int choice = 0u;

    printf(
        "\nEscolha uma das opções:\n"
        "\n1. Insercão | 2. Listagem | 3. Alteração"
        "\n4. Remoção  | 5. Busca    | 0. Sair"
        "\nOpção\? "
    );
    scanf("%d", &choice);
    getchar();

    return choice;
}

const unsigned int getUpdateMenuChoice(void)
{
    unsigned int choice = 0u;

    printf(
        "\nSelecione o tipo de dado:"
        "\n0 - Marca   | 1 - Tipo de HD | 2 - Capac. de Armazenamento;"
        "\n3 - Memória | 4 - Modelo     | 5 - Processador;"
        "\nOpção\? "
    );
	scanf("%d", &choice);
	getchar();

    return choice;
}

const byte getComputerID(void)
{
    byte id = 0;

	printf("\nInforme o ID do PC: ");
    scanf("%hhu", &id);

	return --id;
}

void addComputer(void)
{
    char response = '\0';

    printf("Olá, é a sua primeira vez com esta tela [s/n]\? ");
    scanf(" %c", &response);

	if ( tolower(response) == 's')
    {
		printf("Informe o nº de PC\'s a serem cadastrados: ");
        scanf("%hu", &numero);

        inventary = (Computer*) calloc(numero, sizeof(Computer));

		for ( register byte i = 0; i < numero; ++i )
        {
            showComputerForm(i);
        }
	}
    else
    {
		puts("\nInserindo novo computador...");

	    inventary = (Computer*) realloc(inventary, ++numero * sizeof(Computer));

        showComputerForm(numero - 1);
	}

	puts("\nInserção realizada.");
}

void showComputers(void)
{
    for ( register byte i = 0; i < numero; ++i )
	{
        printComputerInfo(i + 1, &inventary[i]);
	}
}

/**
 * Fazer a verificacao antes de alterar...
 */
void updateComputer(void)
{
    byte index = getComputerID();
    unsigned int dado = getUpdateMenuChoice();

	switch ( dado )
	{
		case MARK:
			printf("Nova marca: ");
			gets(inventary[index].mark);
			break;
		case STORAGE_TYPE:
			do {
				printf("\nTipo de HD...[s/c]\? ");
				scanf(" %c", &inventary[index].storageType);
			} while (
                inventary[index].storageType != 's' and
                inventary[index].storageType != 'c'
            );
			break;
		case STORAGE:
			printf("Nova capac. de armazenamento: ");
			scanf("%d", &inventary[index].storage);
			break;
		case MEMORY:
			printf("Novo tamanho de memória: ");
			scanf("%d", &inventary[index].memory);
			break;
		case MODEL:
			printf("Novo Modelo: ");
			gets(inventary[index].model);
			break;
		case PROCESSOR:
			printf("Novo Processador: ");
			gets(inventary[index].processor);
			break;
		default:
			puts("\nOpção inválida!");
	}

	puts("\nAlteração realizada.");
}

void deleteComputer(void)
{
	bool found = false;
	byte id    = getComputerID();

    Computer* tmp = (Computer*) calloc((numero - 1), sizeof(Computer));

	for ( register byte i = 0, j = 0; i < numero; ++i )
	{
		if ( i != id )
        {
            tmp[j] = inventary[i];

            ++j;
		}
        else
            found = true;
	}

    if ( found )
    {
		free(inventary);
		inventary = tmp;
		numero--;

		puts("\nRemoção realizada.");
	}
    else
        puts("\nCadastro não encontrado!");
}

void searchComputer(void)
{
	char response = '\0', model[TAM_STRING];
    bool found = false;

    do {
    	printf("\nInforme o modelo do computador: ");
        gets(model);

	    found = false;

		for ( register byte i = 0; i < numero; ++i )
		{
			if ( strcmp(model, inventary[i].model) == 0 )
            {
                printComputerInfo(i + 1, &inventary[i]);

				found = true;
			}
		}

		if ( not found )
        {
            puts("\nCadastro não encontrado!");
        }

		printf("\nDeseja realizar novamente [s/n]\? ");
		scanf(" %c", &response);
	} while ( tolower(response) == 's' );
}

/**
 *
 */
int main(int argc, const char* argv[])
{
	setlocale(LC_ALL, "");

	unsigned int opcao = 0u;

    do {
	    opcao = getMainMenuChoice();

		system("clear");

    	switch ( opcao )
		{
	    	case CREATE:
	    		addComputer();
	    		break;
			case READ:
				showComputers();
				break;
			case UPDATE:
				updateComputer();
				break;
			case DELETE:
				deleteComputer();
				break;
	    	case SEARCH:
	    		searchComputer();
	    		break;
			case EXIT:
				puts("\nFIM.");
				break;
	    	default:
	    		puts("Opção inválida!");
		}
	} while ( opcao not_eq EXIT );

    free(inventary);

	return EXIT_SUCCESS;
}