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
	INSERCAO = 1,
	REMOCAO,
	ALTERACAO,
	LISTAGEM,
	BUSCA
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

    printf("\nComputador n� %hhu\n\nMarca........: ", (pos + 1));
	fgets(inventario[pos].marca, MAX_SIZE_STR, stdin);

	printf("Modelo.......: ");
	fgets(inventario[pos].modelo, MAX_SIZE_STR, stdin);

	printf("Processador..: ");
	fgets(inventario[pos].processador, MAX_SIZE_STR, stdin);

    do {
		printf(
            "\nTipo de Disco R�gido..."
			"\nDigite \"s\" para SSD ou \"c\" para convencional: "
        );
		scanf(" %c", &inventario[pos].tipohd);
	} while (
        inventario[pos].tipohd not_eq 's' and
        inventario[pos].tipohd not_eq 'c'
    );

    printf("\nCapacidade de Armazenamento (em GB): ");
	scanf("%d", &inventario[pos].hd);

	printf("Tamanho da Mem�ria (em GB).........: ");
	scanf("%d", &inventario[pos].memoria);
}

void insercao(void)
{
	char resposta = '\0';

	printf("Ol�, � a sua primeira vez com esta tela [s/n]? ");
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
		printf("Informe o n� de computadores a serem cadastrados: ");
    	scanf("%hu", &num);

	    inventario = calloc(num, sizeof(Computador));

        register Byte pos = 0;

    	for ( ; pos < num; pos++ )
        {
            preenchimento_dados(pos);
        }
	}

	puts("\nInser��o realizada.");
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
		puts("\nRemo��o realizada.");
	}
    else
		puts("\nCadastro N�O encontrado!");
}

void alteracao(void)
{
	Dados tipo;
    Byte index = 0;

	printf("\nInforme o ID do computador: ");
	scanf("%hhu", &index);

	index--;

	printf(
        "\nSelecione o tipo de dado:\n"
		"\n1. Marca   | 2. Tipo de HD | 3. Capac. de Armazenamento"
		"\n4. Mem�ria | 5. Modelo 	  | 6. Processador"
		"\nOp��o? "
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
                    "Tipo de Disco R�gido..."
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
			printf("Novo tamanho de mem�ria: ");
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
			puts("\nOp��o inv�lida!");
	}

	puts("\nAltera��o realizada.");
}

void listagem(void)
{
	register Byte pos = 0;

    for ( ; pos < num; pos++ )
    {
		printf(
            "\nComputador n� %hhu:\n"
			"Marca..............................: %s"
			"Modelo.............................: %s"
			"Tipo de HD.........................: %c\n"
			"Capac. de Armazenamento............: %d GB\n"
			"Mem�ria............................: %d GB\n"
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
                "\nComputador n� %hhu:\n"
                "Marca..............................: %s"
                "Modelo.............................: %s"
                "Tipo de HD.........................: %c\n"
                "Capac. de Armazenamento............: %d GB\n"
                "Mem�ria............................: %d GB\n"
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
            puts("\nCadastro N�O encontrado!");
        }

        printf("\nDeseja realizar novamente [s/n]? ");
		scanf(" %c", &resposta);

		resposta = tolower(resposta);
	} while ( resposta == 's' );
}

int main(void)
{
	setlocale(LC_ALL, "");

	Opcoes opcao;

    while ( true )
    {
	    printf(
            "\nEscolha uma das op��es abaixo:\n"
			"1. Inserc�o | 2. Remo��o | 3. Altera��o"
			"4. Listagem | 5. Busca   | Outra tecla: Sair"
			"\nOp��o? "
        );
		scanf("%d", &opcao);
		system("clear");

    	switch ( opcao )
        {
	    	case INSERCAO:
	    		insercao();
	    		break;
			case REMOCAO:
				remocao();
				break;
			case ALTERACAO:
				alteracao();
				break;
			case LISTAGEM:
				listagem();
				break;
	    	case BUSCA:
	    		busca();
	    		break;
	    	default:
	    		free(inventario);
				exit(EXIT_SUCCESS);
		}
	}

	return EXIT_SUCCESS;
}