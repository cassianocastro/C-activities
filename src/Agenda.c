#include "./includes/Agenda.h"

/**
 *
 */
int main(int argc, const char* argv[])
{
	setlocale(LC_ALL, "");

    unsigned int option = 0u;

    do {
	    option = showMainMenu();

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

    free(contacts);

    return EXIT_SUCCESS;
}

void dados(byte i)
{
	bool ok = false;

    printf("\nContato nº %hhu\n\n", (i + 1));
	getchar();

    printf("Nome......: ");
	fgets(contacts[i].nome, 50, stdin);

    printf("Cidade....: ");
	fgets(contacts[i].cidade, 20, stdin);

    printf("Telefone..: ");
	fgets(contacts[i].telefone, 16, stdin);

    do
    {
		printf("Sexo [M/F]\? ");
		scanf(" %c", &contacts[i].sexo);

		contacts[i].sexo = tolower(contacts[i].sexo);
	} while (
        contacts[i].sexo not_eq 'f' and
        contacts[i].sexo not_eq 'm'
    );

	while ( true )
    {
        puts("Data de nascimento...");

		printf("Dia: ");
    	scanf("%hhu", &contacts[i].dn.dia);

        printf("Mês: ");
    	scanf("%hhu", &contacts[i].dn.mes);

        printf("Ano: ");
    	scanf("%hu",  &contacts[i].dn.ano);

    	ok = validadata(
            contacts[i].dn.dia,
			contacts[i].dn.mes,
			contacts[i].dn.ano
        );

		if ( not ok )
			puts("Data inválida!!");
		else
			break;
	}

	contacts[i].idade = (uint8_t) ANO_ATUAL - contacts[i].dn.ano;
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

	    contacts = (Contact*) calloc(num, sizeof(Contact));

		for ( register byte i = 0; i < num; ++i )
        {
            dados(i);
        }
	}
    else
    {
        puts("Inserindo novo contato...");

	    contacts = (Contact*) realloc(contacts, ++num * sizeof(Contact));

        dados(num - 1);
	}

	puts("\nInserção realizada.");
}

void showContacts(void)
{
    for ( register byte i = 0; i < num; ++i )
    {
        printContact(&contacts[i]);
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
			fgets(contacts[index].nome, 50, stdin);
			break;
		case SEXO:
			do {
				printf("Novo sexo [M/F]: ");
				scanf(" %c", &contacts[index].sexo);

				contacts[index].sexo = tolower(contacts[index].sexo);
			} while (
                contacts[index].sexo not_eq 'f' and
                contacts[index].sexo not_eq 'm'
            );
			break;
		case DATA:
			while ( true )
            {
				printf("Nova data de nascimento...\nDia: ");
				scanf("%hhu", &contacts[index].dn.dia);

                printf("Mês: ");
				scanf("%hhu", &contacts[index].dn.mes);

                printf("Ano: ");
				scanf("%hu", &contacts[index].dn.ano);

				is_okay = validadata(
                    contacts[index].dn.dia,
					contacts[index].dn.mes,
					contacts[index].dn.ano
                );

				if ( not is_okay )
                    puts("Data inválida!");
				else
                    break;
			}
			break;
		case CIDADE:
			printf("Nova cidade: ");
			fgets(contacts[index].cidade, 20, stdin);
			break;
		case FONE:
			printf("Novo telefone: ");
			fgets(contacts[index].telefone, 16, stdin);
			break;
		default:
			puts("\n\aOpção inválida!");
	}

	puts("\nAlteração realizada.");
}

void deleteContact(void)
{
	byte index = 0;
    bool found = false;

	printf("ID do contato: ");
	scanf("%hhu", &index);

	Contact* tmp = (Contact*) calloc((num - 1), sizeof(Contact));

    --index;

	for ( register byte i = 0, j = 0; i < num; ++i )
    {
		if ( i not_eq index )
        {
			strcpy(tmp[j].nome,     contacts[i].nome);
			strcpy(tmp[j].cidade,   contacts[i].cidade);
			strcpy(tmp[j].telefone, contacts[i].telefone);

			tmp[j].sexo   = contacts[i].sexo;
			tmp[j].dn.dia = contacts[i].dn.dia;
			tmp[j].dn.mes = contacts[i].dn.mes;
			tmp[j].dn.ano = contacts[i].dn.ano;
			tmp[j].idade  = contacts[i].idade;

            ++j;
		}
        else
            found = true;
	}

	if ( found )
    {
		free(contacts);
		contacts = tmp;
		num--;

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
			if ( mes != contacts[pos].dn.mes ) continue;

			printf(
                "\n\tContato nº %hhu:"
                "\nNome..............: %s"
                "Idade...............: %hhu anos"
                "\nSexo..............: %c"
                "\nCidade............: %s"
                "Telefone............: %s"
                "Data de Nascimento..: %hhu/%hhu/%hu",
                (pos + 1),
                contacts[pos].nome,
                contacts[pos].idade,
                contacts[pos].sexo,
                contacts[pos].cidade,
                contacts[pos].telefone,
                contacts[pos].dn.dia,
                contacts[pos].dn.mes,
                contacts[pos].dn.ano
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

void printContact(const Contact* const contact)
{
    printf(
        // "\n\tContato nº %hhu:"
        "\nNome..............: %s"
        "Idade...............: %hhu anos\n"
        "Sexo................: %c\n"
        "Cidade..............: %s"
        "Telefone............: %s"
        "Data de Nascimento..: %hhu/%hhu/%hu",
        // (i + 1),
        contact->nome,
        contact->idade,
        contact->sexo,
        contact->cidade,
        contact->telefone,
        contact->dn.dia,
        contact->dn.mes,
        contact->dn.ano
    );
}

const unsigned int showMainMenu(void)
{
    unsigned int option = 0u;

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

    return option;
}