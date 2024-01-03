#include "./includes/Agenda.h"

/**
 *
 */
int main(int argc, const char* argv[])
{
	setlocale(LC_ALL, "");

    unsigned int option = 0u;

    do {
	    printf (
            "\nEscolha uma das opções abaixo:"
            "\n1. Insercão;"
            "\n2. Listagem;"
            "\n3. Alteração;"
            "\n4. Remoção;"
            "\n5. Busca;"
            "\n0. Sair;"
            "\nOpção\? "
        );
		scanf("%d", &option);

    	switch ( option )
        {
	    	case CREATE:
	    		addContact();
	    		break;
            case READ:
				showContacts();
				break;
            case UPDATE:
				updateContact();
				break;
			case DELETE:
				deleteContact();
				break;
	    	case SEARCH:
	    		searchContact();
	    		break;
			case EXIT:
				puts("\nFIM...");
				break;
	    	default:
	    		puts("\aOpção inválida!");
		}
	} while ( option not_eq EXIT );

    free(agenda);

    return EXIT_SUCCESS;
}

void dados(byte i)
{
	bool ok = false;

    printf("\nContato nº %hhu\n\n", (i + 1));
	getchar();

    printf("Nome......: ");
	fgets(agenda[i].nome, 50, stdin);

    printf("Cidade....: ");
	fgets(agenda[i].cidade, 20, stdin);

    printf("Telefone..: ");
	fgets(agenda[i].telefone, 16, stdin);

    do
    {
		printf("Sexo [M/F]\? ");
		scanf(" %c", &agenda[i].sexo);

		agenda[i].sexo = tolower(agenda[i].sexo);
	} while (
        agenda[i].sexo not_eq 'f' and
        agenda[i].sexo not_eq 'm'
    );

	while ( true )
    {
        puts("Data de nascimento...");

		printf("Dia: ");
    	scanf("%hhu", &agenda[i].dn.dia);

        printf("Mês: ");
    	scanf("%hhu", &agenda[i].dn.mes);

        printf("Ano: ");
    	scanf("%hu",  &agenda[i].dn.ano);

    	ok = validadata(
            agenda[i].dn.dia,
			agenda[i].dn.mes,
			agenda[i].dn.ano
        );

		if ( not ok )
			puts("Data inválida!!");
		else
			break;
	}

	agenda[i].idade = (uint8_t) ANO_ATUAL - agenda[i].dn.ano;
}

void addContact(void)
{
	char response = '\0';

	printf("Olá, é a sua primeira vez com esta tela[s/n]\? ");
    scanf(" %c", &response);

	if ( tolower(response) == 's' )
    {
		printf("Informe o nº de pessoas a serem cadastradas: ");
    	scanf("%hu", &num);

	    agenda = (Pessoa*) calloc(num, sizeof(Pessoa));

		for ( register byte i = 0; i < num; ++i )
        {
            dados(i);
        }
	}
    else
    {
        puts("Inserindo novo contato...");

	    agenda = (Pessoa*) realloc(agenda, ++num * sizeof(Pessoa));

        dados(num - 1);
	}

	puts("\nInserção realizada.");
}

void showContacts(void)
{
    for ( register byte i = 0; i < num; ++i )
    {
		printf(
            "\n\tContato nº %hhu:"
			"\nNome..............: %s"
			"Idade...............: %hhu anos"
			"\nSexo..............: %c"
			"\nCidade............: %s"
			"Telefone............: %s"
			"Data de Nascimento..: %hhu/%hhu/%hu",
			(i + 1),
			agenda[i].nome,
			agenda[i].idade,
			agenda[i].sexo,
			agenda[i].cidade,
			agenda[i].telefone,
			agenda[i].dn.dia,
			agenda[i].dn.mes,
			agenda[i].dn.ano
        );
	}
}

void updateContact(void)
{
	unsigned int tipo = 0u;
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

void deleteContact(void)
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

void searchContact(void)
{
	char resposta = '\0';
    bool was_found = false;
    byte mes = 0, pos = 0;

    do {
    	printf("\nDigite o nº do mês de nascimento (Ex.: Abril = 4): ");
	    scanf("%hhu", &mes);

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