#include <errno.h>
#include <inttypes.h>
#include <iso646.h>
#include <locale.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 50
#define TAM_PROCESS 20
#define TAM_COR 20

typedef enum
{
	SAIR,
	INSERCAO,
	LISTAGEM,
	BUSCA,
	ALTERACAO,
	REMOCAO,
	OUTRO_ARQUIVO
}
Opcoes;

typedef enum
{
	TIPO = 1,
	TAMANHO_TELA,
	MARCA,
	MODELO,
	PROCESSADOR,
	COR,
	RAM,
	ARMAZENAMENTO
}
Dados;

typedef struct
{
	int ID;
    int RAM;
    int HD;

    float tamanho_tela;

    char tipo;
	char marca[TAM];
	char modelo[TAM];
	char processador[TAM_PROCESS];
	char cor[TAM_COR];
}
Computador;

FILE* arquivo;
char nome_arquivo[TAM];
Computador PC;

bool okay(int* index_pointer)
{
	Computador PC_teste;

	fseek(arquivo, 0, SEEK_SET);

    while ( true )
    {
		fread(&PC_teste, sizeof(Computador), 1, arquivo);

        if ( feof(arquivo) ) break;

        if ( PC_teste.ID == (*index_pointer) ) return true;
	}

	return false;
}

void insercao(void)
{
	register uint8_t pos = 0;
    short numero_cadastros = 0;

	printf("Quantos cadastros voc� deseja fazer? ");
	scanf("%hu", &numero_cadastros);

	for ( pos = 0; pos < numero_cadastros; pos++ )
    {
		fseek(arquivo, 0, SEEK_END);

        getchar();

        printf(
            "\n\tComputador nº %hhu"
			"\nMarca..........................: ",
            (pos + 1)
        );
		fgets(PC.marca, sizeof(PC.marca), stdin);

		printf("Modelo.........................: ");
		fgets(PC.modelo, sizeof(PC.modelo), stdin);

		printf("Processador....................: ");
		fgets(PC.processador, sizeof(PC.processador), stdin);

		printf("Cor............................: ");
		fgets(PC.cor, sizeof(PC.cor), stdin);

		printf("Tamanho da Tela................: ");
		scanf("%f", &PC.tamanho_tela);

		printf("Mem�ria RAM (em GB)............: ");
		scanf("%d", &PC.RAM);

		printf("Capac. de Armazenamento (em GB): ");
		scanf("%d", &PC.HD);

		do {
			printf("Tipo [d/n].....................: ");
			scanf(" %c", &PC.tipo);
		} while ( PC.tipo not_eq 'd' and PC.tipo not_eq 'n' );

		while ( true )
        {
			printf("Informe o ID do computador: ");
			scanf("%d", &PC.ID);

			if ( okay(&PC.ID) )
				puts("\nID JÁ UTILIZADO!");
			else
				break;
		}

		fwrite(&PC, sizeof(Computador), 1, arquivo);
	}

	puts("\nCadastro(s) realizado(s).");
}

void remocao(void)
{
	int index = 0;

	printf("Informe o ID do computador: ");
	scanf("%d", &index);

	if ( not okay(&index) )
    {
		puts("\aID não encontrado.");

		return;
	}

	FILE* arquivo_temporario = fopen("temporario.xxx", "ab+");

	if ( arquivo_temporario not_eq NULL )
    {
		fseek(arquivo, 0, SEEK_SET);

		while ( true )
        {
			fread(&PC, sizeof(Computador), 1, arquivo);

            if ( feof(arquivo) ) break;

            if ( PC.ID not_eq index )
            {
				fwrite(&PC, sizeof(Computador), 1, arquivo_temporario);
            }
		}

		fclose(arquivo_temporario);
		fclose(arquivo);
		remove(nome_arquivo);
	}
    else
    {
		printf("\aErro nº %d: %s", errno, strerror(errno));

    	return;
	}

	arquivo = fopen(nome_arquivo, "ab+");
	arquivo_temporario = fopen("temporario.xxx", "rb");

	if ( arquivo not_eq NULL and arquivo_temporario not_eq NULL )
    {
		fseek(arquivo_temporario, 0, SEEK_SET);

		while ( true )
        {
			fread(&PC, sizeof(Computador), 1, arquivo_temporario);

			if ( feof(arquivo_temporario) ) break;

			fwrite(&PC, sizeof(Computador), 1, arquivo);
		}

		fclose(arquivo_temporario);
		remove("temporario.xxx");
		puts("Computador Removido.");
	}
    else
        printf("\aErro nº %d: %s", errno, strerror(errno));
}

void listagem(void)
{
	register uint8_t pos = 0;

	fseek(arquivo, 0, SEEK_SET);

	for ( ; not feof(arquivo); pos++)
    {
		fread(&PC, sizeof(Computador), 1, arquivo);

		if ( feof(arquivo) ) break;

		printf(
            "\n\tComputador ID nº %d:\n"
            "Marca..........................: %s"
            "Modelo.........................: %s"
            "Processador....................: %s"
            "Cor............................: %s"
            "Tamanho da Tela................: %.1f\"\n"
            "Mem�ria RAM....................: %d GB\n"
            "Capac. de Armazenamento........: %d GB\n"
            "Tipo...........................: %c\n\n",
            PC.ID,
            PC.marca,
            PC.modelo,
            PC.processador,
            PC.cor,
            PC.tamanho_tela,
            PC.RAM,
            PC.HD,
            PC.tipo
        );
	}

	( pos == 0 ) ? puts("\a\nEstoque VAZIO.") : system("pause");
}

void busca( void )
{
	int index = 0;
    bool was_found = false;

	printf("Informe o ID do computador: ");
	scanf("%d", &index);

	fseek(arquivo, 0, SEEK_SET);

	while ( true )
    {
		fread(&PC, sizeof(Computador), 1, arquivo);

		if ( feof(arquivo) ) break;

		if ( PC.ID != index ) continue;

		printf(
            "\n\tComputador ID nº %d:\n"
            "Marca..........................: %s"
            "Modelo.........................: %s"
            "Processador....................: %s"
            "Cor............................: %s"
            "Tamanho da Tela................: %.1f\"\n"
            "Mem�ria RAM....................: %d GB\n"
            "Capac. de Armazenamento........: %d GB\n"
            "Tipo...........................: %c\n\n",
            PC.ID,
            PC.marca,
            PC.modelo,
            PC.processador,
            PC.cor,
            PC.tamanho_tela,
            PC.RAM,
            PC.HD,
            PC.tipo
        );

		was_found = true;

		break;
	}

	if ( not was_found )
    {
        puts("\aComputador NÃO ENCONTRADO.");
    }
}

void alterado(Computador* PC)
{
	Dados dado;

	printf(
        "Escolha o dado que deseja alterar:\n"
        "1 - Tipo;\n"
        "2 - Tamanho da Tela;\n"
        "3 - Marca;\n"
        "4 - Modelo;\n"
        "5 - Processador;\n"
        "6 - Cor;\n"
        "7 - Memória RAM (em GB);\n"
        "8 - Capac. de Armazenamento (em GB);\n"
        "Opção?"
    );
	scanf("%d", &dado);
	getchar();

	switch ( dado )
    {
		case TIPO:
			do {
				printf("Novo Tipo [d/n]: ");
				scanf(" %c", &PC->tipo);
			} while ( PC->tipo not_eq 'd' and PC->tipo not_eq 'n' );
			break;
		case TAMANHO_TELA:
			printf("Novo Tamanho da Tela: ");
			scanf("%f", &PC->tamanho_tela);
			break;
		case MARCA:
			printf("Nova Marca: ");
			fgets(PC->marca, sizeof(PC->marca), stdin);
			break;
		case MODELO:
			printf("Novo Modelo: ");
			fgets(PC->modelo, sizeof(PC->modelo), stdin);
			break;
		case PROCESSADOR:
			printf("Novo Processador: ");
			fgets(PC->processador, sizeof(PC->processador), stdin);
			break;
		case COR:
			printf("Nova Cor: ");
			fgets(PC->cor, sizeof(PC->cor), stdin);
			break;
		case RAM:
			printf("Nova Memória RAM (em GB): ");
			scanf("%d", &PC->RAM);
			break;
		case ARMAZENAMENTO:
			printf("Nova Capac. de Armazenamento (em GB): ");
			scanf("%d", &PC->HD);
			break;
		default:
			puts("\aDígito inválido!");
	}
}

void alteracao(void)
{
	int index = 0;

    printf("Informe o ID do computador: ");
	scanf("%d", &index);

    if ( not okay(&index) )
    {
		puts("\aComputador NÃO ENCONTRADO.");

		return;
	}

	FILE* arquivo_temporario = fopen("temporario.xxx", "ab+");

	if ( arquivo_temporario != NULL )
    {
		fseek(arquivo, 0, SEEK_SET);

        while ( true )
        {
			fread(&PC, sizeof(Computador), 1, arquivo);

        	if ( feof(arquivo) ) break;

        	if ( PC.ID not_eq index )
            {
				fwrite(&PC, sizeof(Computador), 1, arquivo_temporario);
            }
			else
            {
				alterado(&PC);
				fwrite(&PC, sizeof(Computador), 1, arquivo_temporario);
			}
		}

		fclose(arquivo_temporario);
		fclose(arquivo);
		remove(nome_arquivo);
	}
    else
    {
		printf("Erro nº %d: %s", errno, strerror(errno));

    	return;
	}

	arquivo = fopen(nome_arquivo, "ab+");
	arquivo_temporario = fopen("temporario.xxx", "rb");

	if ( arquivo != NULL and arquivo_temporario != NULL )
    {
		fseek(arquivo_temporario, 0, SEEK_SET);

		while ( true )
        {
			fread(&PC, sizeof(Computador), 1, arquivo_temporario);

        	if ( feof(arquivo_temporario) ) break;

        	fwrite(&PC, sizeof(Computador), 1, arquivo);
		}

		fclose(arquivo_temporario);
		remove("temporario.xxx");
		puts("Alteração realizada.");
	}
}

void escolher(void)
{
	printf("\nInforme o nome do arquivo: ");
	gets(nome_arquivo);

	arquivo = fopen(nome_arquivo, "ab+");

	if ( arquivo == NULL )
    {
		printf("Erro nº %d: %s", errno, strerror(errno));

    	exit(EXIT_SUCCESS);
	}
}

int main(void)
{
	setlocale(LC_ALL, "");

    Opcoes opcao;

    escolher();

	Inicio_do_Programa:
		printf(
            "\nArquivo utilizado: %s\n\n"
            "Escolha uma das opções abaixo:\n"
            "1 - Inserir de novos computadores;\n"
            "2 - Exibir computadores;\n"
            "3 - Buscar PC;\n"
            "4 - Alterar dados;\n"
            "5 - Remover cadastro;\n"
            "6 - Escolher outro arquivo;\n"
            "0 - Sair;\n"
            "Opção? ",
            nome_arquivo
        );
		scanf("%d", &opcao);
		getchar();
		system("clear");

		switch ( opcao )
        {
			case SAIR:
				puts("Até mais...");
				break;
			case INSERCAO:
				insercao();
				break;
			case LISTAGEM:
				listagem();
				break;
			case BUSCA:
				busca();
				break;
			case ALTERACAO:
				alteracao();
				break;
			case REMOCAO:
				remocao();
				break;
			case OUTRO_ARQUIVO:
				fclose(arquivo);
				escolher();
				break;
			default:
				puts("\aDígito inválido!");
		}

	if ( opcao not_eq SAIR ) goto Inicio_do_Programa;

	return EXIT_SUCCESS;
}