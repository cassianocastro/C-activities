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

void dados(byte i)
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

void insercao(void)
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
            dados(i);
        }
	}
    else
    {
		puts("\nInserindo novo computador...");

	    inventary = (Computer*) realloc(inventary, ++numero * sizeof(Computer));

        dados(numero - 1);
	}

	puts("\nInserção realizada.");
}

void remocao(void)
{
	Computer* novo_inventario;
	bool was_found = false;
	byte id = 0;

	printf("Informe o ID do PC: ");
    scanf("%hhu", &id);

	id--;
	novo_inventario = (Computer*) calloc((numero - 1), sizeof(Computer));

	for ( byte i = 0, j = 0; i < numero; i++ )
	{
		if ( i != id )
        {
			strcpy(novo_inventario[j].mark,      inventary[i].mark);
			strcpy(novo_inventario[j].model,     inventary[i].model);
			strcpy(novo_inventario[j].processor, inventary[i].processor);
			novo_inventario[j].storageType = inventary[i].storageType;
			novo_inventario[j].storage     = inventary[i].storage;
			novo_inventario[j].memory      = inventary[i].memory;
			j++;
		}
        else
            was_found = true;
	}

    if ( was_found )
    {
		free(inventary);
		inventary = novo_inventario;
		numero --;

		puts("\nRemoção realizada.");
	}
    else
        puts("\nCadastro não encontrado!");
}

/**
 * Fazer a verificacao antes de alterar...
 */
void alteracao(void)
{
	unsigned int dado = 0u;
    byte index = 0;

	printf("\nInforme o ID do PC: ");
    scanf("%hhu", &index);

	index--;

    printf(
        "\nSelecione o tipo de dado:"
        "\n0 - Marca   | 1 - Tipo de HD | 2 - Capac. de Armazenamento;"
        "\n3 - Memória | 4 - Modelo     | 5 - Processador;"
        "\nOpção\? "
    );
	scanf("%d", &dado);
	getchar();

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

	puts("\nAlteração realizada com sucesso.");
}

void listagem(void)
{
    for ( byte i = 0; i < numero; i++ )
	{
        printf(
            "\nComputador nº %hhu:"
            "\nMarca..............................: %s"
            "\nModelo.............................: %s"
            "\nTipo de HD.........................: %c"
            "\nCapac. de Armazenamento............: %d GB"
            "\nMemória............................: %d GB"
            "\nProcessador........................: %s"
            "\n------------",
            ( i + 1 ),
            inventary[i].mark,
            inventary[i].model,
            inventary[i].storageType,
            inventary[i].storage,
            inventary[i].memory,
            inventary[i].processor
        );
	}
}

void busca(void)
{
	char resposta = '\0', modelo[TAM_STRING];
    bool was_found = false;

    do
	{
    	printf("\nInforme o modelo do computador: ");
        gets(modelo);

	    was_found = false;

		for ( byte i = 0; i < numero; i++ )
		{
			if ( strcmp(modelo, inventary[i].model) == 0 )
            {
                printf(
			        "\nComputador nº %hhu:"
                    "\nMarca..............................: %s"
                    "\nModelo.............................: %s"
                    "\nTipo de HD.........................: %c"
                    "\nCapac. de Armazenamento............: %d GB"
                    "\nMemória............................: %d GB"
                    "\nProcessador........................: %s"
                    "\n------------",
                    ( i + 1 ),
                    inventary[i].mark,
                    inventary[i].model,
                    inventary[i].storageType,
                    inventary[i].storage,
                    inventary[i].memory,
                    inventary[i].processor
                );

				was_found = true;
			}
		}

		if ( not was_found )
        {
            puts("\nCadastro não encontrado!");
        }

		printf("\nDeseja realizar novamente [s/n]\? ");
		scanf(" %c", &resposta);
	} while ( tolower(resposta) == 's' );
}

/**
 *
 */
int main(int argc, const char* argv[])
{
	setlocale(LC_ALL, "");

	unsigned int opcao = 0u;

    do {
	    printf (
            "\nEscolha uma das opções:\n"
            "\n1 - Insercão | 2 - Listagem | 3 - Alteração"
            "\n4 - Remoção | 5 - Busca   | 0 - Sair"
            "\nOpção\? "
        );
		scanf("%d", &opcao);
		system("clear");
		getchar();

    	switch ( opcao )
		{
	    	case CREATE:
	    		insercao();
	    		break;
			case READ:
				listagem();
				break;
			case UPDATE:
				alteracao();
				break;
			case DELETE:
				remocao();
				break;
	    	case SEARCH:
	    		busca();
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