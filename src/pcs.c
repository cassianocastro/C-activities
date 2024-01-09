#include <ctype.h>
#include <iso646.h>
#include <inttypes.h>
#include <locale.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE_STR 30

typedef unsigned char Byte;

typedef struct
{
    char tipohd;
	char modelo[MAX_SIZE_STR];
	char marca[MAX_SIZE_STR];
	char processador[MAX_SIZE_STR];

    int memoria;
    int hd;
}
Computador;

typedef enum
{
	CREATE = 1,
	READ,
	UPDATE,
	DELETE,
	SEARCH
}
Opcoes;

typedef enum
{
	MARCA = 1,
	TIPO_HD,
	HD,
	MEMORIA,
	MODELO,
	PROCESSADOR
}
Dados;

unsigned short int num;

Computador* inventario;

void preenchimento_dados(Byte pos)
{
	getchar();

    printf("\nComputador nº %hhu\n\nMarca........: ", (pos + 1));
	fgets(inventario[pos].marca, MAX_SIZE_STR, stdin);

	printf("Modelo.......: ");
	fgets(inventario[pos].modelo, MAX_SIZE_STR, stdin);

	printf("Processador..: ");
	fgets(inventario[pos].processador, MAX_SIZE_STR, stdin);

    do {
		printf(
            "\nTipo de Disco Rígido..."
			"\nDigite \"s\" para SSD ou \"c\" para convencional: "
        );
		scanf(" %c", &inventario[pos].tipohd);
	} while (
        inventario[pos].tipohd not_eq 's' and
        inventario[pos].tipohd not_eq 'c'
    );

    printf("\nCapacidade de Armazenamento (em GB): ");
	scanf("%d", &inventario[pos].hd);

	printf("Tamanho da Memória (em GB).........: ");
	scanf("%d", &inventario[pos].memoria);
}

void insercao(void)
{
	char resposta = '\0';

	printf("Olá, é a sua primeira vez com esta tela [s/n]\? ");
    scanf(" %c", &resposta);

    resposta = tolower(resposta);

	if ( resposta == 'n' )
    {
		puts("\nInserindo novo computador...");
	    num++;
	    inventario = realloc(inventario, num * sizeof(Computador));
	    preenchimento_dados(num - 1);
	}
    else
    {
		printf("Informe o nº de computadores a serem cadastrados: ");
    	scanf("%hu", &num);

	    inventario = calloc(num, sizeof(Computador));

        register Byte pos = 0;

    	for ( ; pos < num; pos++ )
        {
            preenchimento_dados(pos);
        }
	}

	puts("\nInserção realizada.");
}

void remocao(void)
{
	Byte index = 0, pos = 0, pos2 = 0;
	Computador* new_inventario;
    bool was_found = false;

	printf("Informe o ID do computador: ");
	scanf("%hhu", &index);

	index--;
	new_inventario = calloc((num - 1), sizeof(Computador));

	for ( pos = 0; pos < num; pos++ )
    {
		if ( pos == index )
        {
			was_found = true;

			continue;
		}

		strcpy(new_inventario[pos2].marca,       inventario[pos].marca);
		strcpy(new_inventario[pos2].modelo,      inventario[pos].modelo);
		strcpy(new_inventario[pos2].processador, inventario[pos].processador);
		new_inventario[pos2].tipohd    		=    inventario[pos].tipohd;
		new_inventario[pos2].hd  			=    inventario[pos].hd;
		new_inventario[pos2].memoria  		=    inventario[pos].memoria;

        pos2++;
	}

	if ( was_found )
    {
		free(inventario);
		inventario = new_inventario;
		num --;
		puts("\nRemoção realizada.");
	}
    else
		puts("\nCadastro não encontrado!");
}

void alteracao(void)
{
	unsigned int tipo = 0u;
    Byte index = 0;

	printf("\nInforme o ID do computador: ");
	scanf("%hhu", &index);

	index--;

	printf(
        "\nSelecione o tipo de dado:\n"
		"\n1. Marca   | 2. Tipo de HD | 3. Capac. de Armazenamento"
		"\n4. Memória | 5. Modelo 	  | 6. Processador"
		"\nOpção\? "
    );
	scanf("%d", &tipo);
	getchar();

	switch ( tipo )
    {
		case MARCA:
			printf("Nova marca: ");
			fgets(inventario[index].marca, MAX_SIZE_STR, stdin);
			break;
		case TIPO_HD:
			do {
				printf(
                    "Tipo de Disco Rígido..."
					"\nDigite \"s\" para SSD ou \"c\" para convencional: "
                );
				scanf(" %c", &inventario[index].tipohd);

                inventario[index].tipohd = tolower(inventario[index].tipohd);
			} while (
                inventario[index].tipohd not_eq 's' and
                inventario[index].tipohd not_eq 'c'
            );
			break;
		case HD:
			printf("Nova capacidade de armazenamento: ");
			scanf("%d", &inventario[index].hd);
			break;
		case MEMORIA:
			printf("Novo tamanho de memória: ");
			scanf("%d", &inventario[index].memoria);
			break;
		case MODELO:
			printf("Novo Modelo: ");
			fgets(inventario[index].modelo, MAX_SIZE_STR, stdin);
			break;
		case PROCESSADOR:
			printf("Novo Processador: ");
			fgets(inventario[index].processador, MAX_SIZE_STR, stdin);
			break;
		default:
			puts("\nOpção inválida!");
	}

	puts("\nAlteração realizada.");
}

void listagem(void)
{
	register Byte pos = 0;

    for ( ; pos < num; pos++ )
    {
		printf(
            "\nComputador nº %hhu:\n"
			"Marca..............................: %s"
			"Modelo.............................: %s"
			"Tipo de HD.........................: %c\n"
			"Capac. de Armazenamento............: %d GB\n"
			"Memória............................: %d GB\n"
			"Processador........................: %s",
			(pos + 1),
			inventario[pos].marca,
			inventario[pos].modelo,
			inventario[pos].tipohd,
			inventario[pos].hd,
			inventario[pos].memoria,
			inventario[pos].processador
        );
	}
}

void busca(void)
{
	char resposta = '\0', modelo[MAX_SIZE_STR];
	bool was_found = false;
    register Byte pos = 0;

	getchar();

    do {
    	printf("\nInforme o modelo do computador: ");
	    fgets(modelo, MAX_SIZE_STR, stdin);

	    was_found = false;

	    for ( pos = 0; pos < num; pos++ )
        {
			if ( strcmp(modelo, inventario[pos].modelo) != 0 ) continue;

            printf(
                "\nComputador nº %hhu:\n"
                "Marca..............................: %s"
                "Modelo.............................: %s"
                "Tipo de HD.........................: %c\n"
                "Capac. de Armazenamento............: %d GB\n"
                "Memória............................: %d GB\n"
                "Processador........................: %s",
                (pos + 1),
                inventario[pos].marca,
                inventario[pos].modelo,
                inventario[pos].tipohd,
                inventario[pos].hd,
                inventario[pos].memoria,
                inventario[pos].processador
            );

			was_found = true;
		}

		if ( not was_found )
        {
            puts("\nCadastro não encontrado!");
        }

        printf("\nDeseja realizar novamente [s/n]\? ");
		scanf(" %c", &resposta);

		resposta = tolower(resposta);
	} while ( resposta == 's' );
}

const unsigned int getMainMenuChoice(void)
{
    unsigned int choice = 0u;

    printf(
        "\nEscolha uma das opções abaixo:"
        "\n1. Insercão | 2. Listagem | 3. Alteração"
        "\n4. Remoção  | 5. Busca    | 6. Sair"
        "\nOpção\? "
    );
    scanf("%d", &choice);

    return choice;
}

/**
 *
 */
int main(int argc, const char* argv[])
{
	setlocale(LC_ALL, "");

	unsigned int option = 0u;

    while ( true )
    {
	    option = getMainMenuChoice();

		system("clear");

    	switch ( option )
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
	    	default:
	    		free(inventario);
				exit(EXIT_SUCCESS);
		}
	}

	return EXIT_SUCCESS;
}