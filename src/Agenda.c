#include <ctype.h>
#include <iso646.h>
#include <inttypes.h>
#include <locale.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./includes/Validacao.h"

typedef unsigned char byte;

typedef struct
{
	byte dia, mes;
	unsigned short int ano;
}
Data_nascimento;

typedef struct
{
	Data_nascimento dn;
	byte idade;
    char nome[51], cidade[21], telefone[17], sexo;
}
Pessoa;

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
	NOME = 1,
	SEXO,
	DATA,
	CIDADE,
	FONE
}
Dados;

const unsigned short int ANO_ATUAL = 2021;
Pessoa* agenda;
unsigned short int num;

/**
 *
 */
int main(int argc, const char* argv[])
{
	setlocale(LC_ALL, "");

    Opcoes opcao;

    do {
	    printf (
            "\nEscolha uma das opções abaixo:"
            "\n1 - Insercão;"
            "\n2 - Remoção;"
            "\n3 - Alteração;"
            "\n4 - Listagem;"
            "\n5 - Busca;"
            "\n6 - Sair;"
            "\nOpção\? "
        );
		scanf("%d", &opcao);

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
				puts("\nFIM...");
				break;
	    	default:
	    		puts("\aOpção inválida!");
		}
	} while ( opcao not_eq SAIR );

    free(agenda);

    return EXIT_SUCCESS;
}

void dados(byte pos)
{
	bool is_okay;

	getchar();

    printf("\nContato nº %hhu\n\nNome......: ", (pos + 1));
	fgets(agenda[pos].nome, 50, stdin);

    printf("Cidade....: ");
	fgets(agenda[pos].cidade, 20, stdin);

    printf("Telefone..: ");
	fgets(agenda[pos].telefone, 16, stdin);

    do
    {
		printf("Sexo [M/F]\? ");
		scanf(" %c", &agenda[pos].sexo);

		agenda[pos].sexo = tolower(agenda[pos].sexo);
	} while (
        agenda[pos].sexo not_eq 'f' and
        agenda[pos].sexo not_eq 'm'
    );

	while ( true )
    {
		printf("Data de nascimento...\nDia: ");
    	scanf("%hhu", &agenda[pos].dn.dia);

        printf("Mês: ");
    	scanf("%hhu", &agenda[pos].dn.mes);

        printf("Ano: ");
    	scanf("%hu",  &agenda[pos].dn.ano);

    	is_okay = validadata(
            agenda[pos].dn.dia,
			agenda[pos].dn.mes,
			agenda[pos].dn.ano
        );

		if ( not is_okay )
			puts("Data inválida!!");
		else
			break;
	}

	agenda[pos].idade = (uint8_t) ANO_ATUAL - agenda[pos].dn.ano;
}

void insercao(void)
{
	char resposta;
    register byte pos = 0;

	printf("Olá, é a sua primeira vez com esta tela [s/n]\? ");
    scanf(" %c", &resposta);

    resposta = tolower(resposta);

	if ( resposta == 'n' )
    {
		puts("Inserindo novo contato...");
	    num++;
	    agenda = realloc(agenda, num * sizeof(Pessoa));
	    dados(num - 1);
	}
    else
    {
		printf("Informe o nº de pessoas a serem cadastradas: ");
    	scanf("%hu", &num);
	    agenda = calloc(num, sizeof(Pessoa));

		for ( pos = 0; pos < num; pos++ ) dados(pos);
	}

	puts("\nInserção realizada.");
}

void listagem(void)
{
	register byte pos = 0;

    for ( ; pos < num; pos++ )
    {
		printf(
            "\n\tContato nº %hhu:"
			"\nNome..............: %s"
			"Idade...............: %hhu anos"
			"\nSexo..............: %c"
			"\nCidade............: %s"
			"Telefone............: %s"
			"Data de Nascimento..: %hhu/%hhu/%hu",
			(pos + 1),
			agenda[pos].nome,
			agenda[pos].idade,
			agenda[pos].sexo,
			agenda[pos].cidade,
			agenda[pos].telefone,
			agenda[pos].dn.dia,
			agenda[pos].dn.mes,
			agenda[pos].dn.ano
        );
	}
}

void alteracao(void)
{
	Dados tipo;
    byte index = 0;
    bool is_okay = false;

	printf("\nInforme o ID do contato: ");
	scanf("%hhu", &index);

    index--;

	printf(
        "\nSelecione o tipo de dado:"
		"\n1 - Nome;"
		"\n2 - Sexo;"
		"\n3 - Data de Nascimento;"
		"\n4 - Cidade;"
		"\n5 - Telefone;"
		"\nOpção\? "
    );
	scanf("%d", &tipo);
	getchar();

	switch ( tipo )
    {
		case NOME:
			printf("Novo nome: ");
			fgets(agenda[index].nome, 50, stdin);
			break;
		case SEXO:
			do {
				printf("Novo sexo [M/F]: ");
				scanf(" %c", &agenda[index].sexo);

				agenda[index].sexo = tolower(agenda[index].sexo);
			} while (
                agenda[index].sexo not_eq 'f' and
                agenda[index].sexo not_eq 'm'
            );
			break;
		case DATA:
			while ( true )
            {
				printf("Nova data de nascimento...\nDia: ");
				scanf("%hhu", &agenda[index].dn.dia);

                printf("Mês: ");
				scanf("%hhu", &agenda[index].dn.mes);

                printf("Ano: ");
				scanf("%hu", &agenda[index].dn.ano);

				is_okay = validadata(
                    agenda[index].dn.dia,
					agenda[index].dn.mes,
					agenda[index].dn.ano
                );

				if ( not is_okay )
                    puts("Data inválida!");
				else
                    break;
			}
			break;
		case CIDADE:
			printf("Nova cidade: ");
			fgets(agenda[index].cidade, 20, stdin);
			break;
		case FONE:
			printf("Novo telefone: ");
			fgets(agenda[index].telefone, 16, stdin);
			break;
		default:
			puts("\n\aOpção inválida!");
	}

	puts("\nAlteração realizada.");
}

void remocao(void)
{
	byte index = 0, pos = 0, pos2 = 0;
    bool was_found = false;
	Pessoa* new_agenda;

	printf("Informe o ID do contato: ");
	scanf("%hhu", &index);

    index--;
	new_agenda = calloc((num - 1), sizeof(Pessoa));

	for ( pos = 0; pos < num; pos++ )
    {
		if ( pos not_eq index )
        {
			strcpy(new_agenda[pos2].nome,     agenda[pos].nome);
			strcpy(new_agenda[pos2].cidade,   agenda[pos].cidade);
			strcpy(new_agenda[pos2].telefone, agenda[pos].telefone);
			new_agenda[pos2].sexo    	=      agenda[pos].sexo;
			new_agenda[pos2].dn.dia  	=      agenda[pos].dn.dia;
			new_agenda[pos2].dn.mes  	=      agenda[pos].dn.mes;
			new_agenda[pos2].dn.ano  	=      agenda[pos].dn.ano;
			new_agenda[pos2].idade   	=      agenda[pos].idade;
			pos2++;
		}
        else
            was_found = true;
	}

	if ( was_found )
    {
		free(agenda);
		agenda = new_agenda;
		num --;
		puts("\nRemoção realizada.");
	}
    else
		puts("\aCadastro não encontrado!!");
}

void busca(void)
{
	char resposta = '\0';
    bool was_found = false;
    byte mes = 0, pos = 0;

    do {
    	printf("\nDigite o nº do mês de nascimento (Ex.: Abril = 4): ");
	    scanf("%hu", &mes);

        was_found = false;

	    for ( pos = 0; pos < num; pos++ )
        {
			if ( mes != agenda[pos].dn.mes ) continue;

			printf(
                "\n\tContato nº %hhu:"
                "\nNome..............: %s"
                "Idade...............: %hhu anos"
                "\nSexo..............: %c"
                "\nCidade............: %s"
                "Telefone............: %s"
                "Data de Nascimento..: %hhu/%hhu/%hu",
                (pos + 1),
                agenda[pos].nome,
                agenda[pos].idade,
                agenda[pos].sexo,
                agenda[pos].cidade,
                agenda[pos].telefone,
                agenda[pos].dn.dia,
                agenda[pos].dn.mes,
                agenda[pos].dn.ano
            );

			was_found = true;
		}

		if ( not was_found )
        {
            puts("\n\aCadastro não encontrado!!");
        }

        printf("\n\nDeseja realizar novamente [S/n]\? ");
		scanf(" %c", &resposta);

		resposta = tolower(resposta);
	} while ( resposta == 's' );
}