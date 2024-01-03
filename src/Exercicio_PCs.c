#include <ctype.h>
#include <iso646.h>
#include <locale.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_STRING 30

struct Dado
{
    char tipohd,
    modelo     [TAM_STRING],
    marca      [TAM_STRING],
    processador[TAM_STRING];
    int memoria, hd;
};

typedef enum
{
	SAIR,
    INSERCAO,
    REMOCAO,
    ALTERACAO,
    LISTAGEM,
    BUSCA
}
Opcoes;

typedef enum
{
	MARCA,
    TIPO_HD,
    HD,
    MEMORIA,
    MODELO,
    PROCESSADOR
}
Dados;

typedef struct Dado Computador;

typedef unsigned char byte;

Computador* inventario;

unsigned short numero;

void dados(byte i)
{
	getchar();

    printf(
        "\nComputador nº %hhu\n"
        "Marca....................: ", ( i + 1 )
    );
    gets(inventario[i].marca);

	printf("Modelo...................: ");
    gets(inventario[i].modelo);

	printf("Processador..............: ");
    gets(inventario[i].processador);

    printf("Armazenamento (em GB)....: ");
    scanf("%d", &inventario[i].hd);

	printf("Memória (em GB)..........: ");
    scanf("%d", &inventario[i].memoria);

	do {
		printf("\nTipo de HD...[s/c]? ");
        scanf(" %c", &inventario[i].tipohd);
	} while (
        inventario[i].tipohd != 's' and
        inventario[i].tipohd != 'c'
    );
}

void insercao(void)
{
    char resposta = '\0';

    printf("Olá, é a sua primeira vez com esta tela [s/n]? ");
    scanf(" %c", &resposta);

	if ( tolower(resposta) == 'n')
    {
		puts("\nInserindo novo computador...");

        numero++;
	    inventario = realloc(inventario, numero * sizeof(Computador));

        dados(numero - 1);
	}
    else
    {
		printf("Informe o nº de PC\'s a serem cadastrados: ");
        scanf("%hu", &numero);

        inventario = calloc(numero, sizeof(Computador));

		for ( byte i = 0; i < numero; i++ )
        {
            dados(i);
        }
	}

	puts("\nInserção realizada.");
}

void remocao(void)
{
	Computador* novo_inventario;
	bool was_found = false;
	byte id = 0;

	printf("Informe o ID do PC: ");
    scanf("%hhu", &id);

	id--;
	novo_inventario = calloc((numero - 1), sizeof(Computador));

	for ( byte i = 0, j = 0; i < numero; i++ )
	{
		if ( i != id )
        {
			strcpy(novo_inventario[j].marca,       inventario[i].marca);
			strcpy(novo_inventario[j].modelo,      inventario[i].modelo);
			strcpy(novo_inventario[j].processador, inventario[i].processador);
			novo_inventario[j].tipohd    		=  inventario[i].tipohd;
			novo_inventario[j].hd  			    =  inventario[i].hd;
			novo_inventario[j].memoria  		=  inventario[i].memoria;
			j++;
		}
        else
            was_found = true;
	}

    if ( was_found )
    {
		free(inventario);
		inventario = novo_inventario;
		numero --;

		puts("\nRemoção realizada.");
	}
    else
        puts("\nCadastro não encontrado!");
}

void alteracao(void) // Fazer a verificacao antes de alterar...
{
	Dados dado;
    byte index = 0;

	printf("\nInforme o ID do PC: ");
    scanf("%hhu", &index);

	index--;

    printf(
        "\nSelecione o tipo de dado:"
        "\n0 - Marca   | 1 - Tipo de HD | 2 - Capac. de Armazenamento;"
        "\n3 - Memória | 4 - Modelo     | 5 - Processador;"
        "\nOpção? "
    );
	scanf("%d", &dado);
	getchar();

	switch ( dado )
	{
		case MARCA:
			printf("Nova marca: ");
			gets(inventario[index].marca);
			break;
		case TIPO_HD:
			do {
				printf("\nTipo de HD...[s/c]? ");
				scanf(" %c", &inventario[index].tipohd);
			} while (
                inventario[index].tipohd != 's' and
                inventario[index].tipohd != 'c'
            );
			break;
		case HD:
			printf("Nova capac. de armazenamento: ");
			scanf("%d", &inventario[index].hd);
			break;
		case MEMORIA:
			printf("Novo tamanho de memória: ");
			scanf("%d", &inventario[index].memoria);
			break;
		case MODELO:
			printf("Novo Modelo: ");
			gets(inventario[index].modelo);
			break;
		case PROCESSADOR:
			printf("Novo Processador: ");
			gets(inventario[index].processador);
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
            inventario[i].marca,
            inventario[i].modelo,
            inventario[i].tipohd,
            inventario[i].hd,
            inventario[i].memoria,
            inventario[i].processador
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
			if ( strcmp(modelo, inventario[i].modelo) == 0 )
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
                    inventario[i].marca,
                    inventario[i].modelo,
                    inventario[i].tipohd,
                    inventario[i].hd,
                    inventario[i].memoria,
                    inventario[i].processador
                );
				was_found = true;
			}
		}

		if ( not was_found )
        {
            puts("\nCadastro não encontrado!");
        }

		printf("\nDeseja realizar novamente [s/n]? ");
		scanf(" %c", &resposta);
	} while ( tolower(resposta) == 's' );
}

int main(int argc, char const *argv[])
{
	setlocale(LC_ALL, "");

	Opcoes opcao;

    do {
	    printf (
            "\nEscolha uma das opções:\n"
            "\n1 - Insercão | 2 - Remoção | 3 - Alteração"
            "\n4 - Listagem | 5 - Busca   | 0 - Sair"
            "\nOpção? "
        );
		scanf("%d", &opcao);
		system("clear");
		getchar();

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
			case SAIR:
				puts("\nFIM.");
				break;
	    	default:
	    		puts("Opção inválida!");
		}
	} while ( opcao not_eq SAIR );

    free(inventario);

	return EXIT_SUCCESS;
}