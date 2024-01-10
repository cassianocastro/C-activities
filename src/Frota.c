#include <iso646.h>
#include <locale.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_STRING 20
#define TAMANHO_FROTA 10

typedef unsigned char byte;

typedef enum
{
    SAIR,
    INSERIR,
    EXCLUIR,
    EXIBIR
}
Opcoes;

struct carro
{
	char modelo[TAM_STRING];
	char marca[TAM_STRING];
	char placa[TAM_STRING];
	char cor[TAM_STRING];

	unsigned short ano;
}
frota[TAMANHO_FROTA];

void inicializar(void)
{
	for ( byte i = 0; i < TAMANHO_FROTA; i++ )
	{
        strcpy(frota[i].modelo, "");
        strcpy(frota[i].marca, "");
        strcpy(frota[i].placa, "");
        strcpy(frota[i].cor, "");

        frota[i].ano = 0;
    }
}

void exibir(void)
{
    for ( byte i = 0; i < TAMANHO_FROTA; i++ )
	{
        if ( frota[i].ano != 0 )
        {
            printf(
                "\nDados do carro\n"
                "\nModelo...............: %s"
                "\nMarca................: %s"
                "\nPlaca................: %s"
                "\nCor..................: %s"
                "\nAno de fabricação....: %d\n",
                frota[i].modelo,
                frota[i].marca,
                frota[i].placa,
                frota[i].cor,
                frota[i].ano
            );
        }
    }
}

void excluir(void)
{
    char placa_informada[TAM_STRING];

    printf("Informe a placa do veículo: ");
    gets(placa_informada);

    for ( byte i = 0; i < TAMANHO_FROTA; i++ )
	{
        if ( strcmp(placa_informada, frota[i].placa) == 0 )
        {
            strcpy(frota[i].modelo, "");
            strcpy(frota[i].marca, "");
            strcpy(frota[i].placa, "");
            strcpy(frota[i].cor, "");

            frota[i].ano = 0;

            puts("\nCarro excluído.");

            break;
        }
    }
}

void inserir(void)
{
    for ( byte i = 0; i < TAMANHO_FROTA; i++ )
	{
        if ( frota[i].ano == 0 )
        {
            printf("Marca..............: ");
            gets(frota[i].marca);

            printf("Modelo.............: ");
            gets(frota[i].modelo);

            printf("Cor................: ");
            gets(frota[i].cor);

            printf("Placa..............: ");
            gets(frota[i].placa);

            printf("Ano de fabricação..: ");
            scanf("%hu", &frota[i].ano);

            puts("\nCarro incluído.");

            break;
        }
    }
}

/**
 *
 */
int main(int argc, const char* argv[])
{
    setlocale(LC_ALL, "");

	unsigned int opcao = 0;

    inicializar();

    do {
		printf(
            "\nEscolha uma das opções:"
            "\n1. Inserir carro  | 2. Excluir carro"
            "\n3. Exibir modelos | 0. Finalizar"
            "\nOpção\? "
        );
		scanf("%d", &opcao);
		system("clear");
		getchar();

		switch ( opcao )
		{
			case INSERIR:
                inserir();
				break;
			case EXIBIR:
				exibir();
				break;
			case EXCLUIR:
				excluir();
				break;
			case SAIR:
				puts("\nFIM.");
				break;
			default:
				puts("Opção inválida!");
		}
	} while ( opcao not_eq SAIR );

	return EXIT_SUCCESS;
}