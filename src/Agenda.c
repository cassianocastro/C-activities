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
	fgets(contacts[i].name, 50, stdin);

    printf("Cidade....: ");
	fgets(contacts[i].city, 20, stdin);

    printf("Telefone..: ");
	fgets(contacts[i].phone, 16, stdin);

    do
    {
		printf("Sexo [M/F]\? ");
		scanf(" %c", &contacts[i].sex);

		contacts[i].sex = tolower(contacts[i].sex);
	} while (
        contacts[i].sex not_eq 'f' and
        contacts[i].sex not_eq 'm'
    );

	while ( true )
    {
        puts("Data de nascimento...");

		printf("Dia: ");
    	scanf("%hhu", &contacts[i].dn.day);

        printf("Mês: ");
    	scanf("%hhu", &contacts[i].dn.month);

        printf("Ano: ");
    	scanf("%hu",  &contacts[i].dn.year);

    	ok = validadata(
            contacts[i].dn.day,
			contacts[i].dn.month,
			contacts[i].dn.year
        );

		if ( not ok )
			puts("Data inválida!!");
		else
			break;
	}

	contacts[i].age = (uint8_t) ANO_ATUAL - contacts[i].dn.year;
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
    bool ok = false;

	printf("\nID do contato: ");
	scanf("%hhu", &index);

    index--;

	printf(
        "\nSelecione o tipo de dado:"
		"\n1. Nome;"
		"\n2. Sexo;"
		"\n3. Data de Nascimento;"
		"\n4. Cidade;"
		"\n5. Telefone;"
		"\nOpção\? "
    );
	scanf("%d", &tipo);
	getchar();

	switch ( tipo )
    {
		case NAME:
			printf("Novo nome: ");
			fgets(contacts[index].name, 50, stdin);
			break;
		case SEX:
			do {
				printf("Novo sexo [M/F]: ");
				scanf(" %c", &contacts[index].sex);

				contacts[index].sex = tolower(contacts[index].sex);
			} while (
                contacts[index].sex not_eq 'f' and
                contacts[index].sex not_eq 'm'
            );
			break;
		case BIRTHDATE:
			while ( true )
            {
				printf("Nova data de nascimento...\nDia: ");
				scanf("%hhu", &contacts[index].dn.day);

                printf("Mês: ");
				scanf("%hhu", &contacts[index].dn.month);

                printf("Ano: ");
				scanf("%hu", &contacts[index].dn.year);

				ok = validadata(
                    contacts[index].dn.day,
					contacts[index].dn.month,
					contacts[index].dn.year
                );

				if ( not ok )
                    puts("Data inválida!");
				else
                    break;
			}
			break;
		case CITY:
			printf("Nova cidade: ");
			fgets(contacts[index].city, 20, stdin);
			break;
		case PHONE:
			printf("Novo telefone: ");
			fgets(contacts[index].phone, 16, stdin);
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
			strcpy(tmp[j].name,  contacts[i].name);
			strcpy(tmp[j].city,  contacts[i].city);
			strcpy(tmp[j].phone, contacts[i].phone);

			tmp[j].sex      = contacts[i].sex;
			tmp[j].dn.day   = contacts[i].dn.day;
			tmp[j].dn.month = contacts[i].dn.month;
			tmp[j].dn.year  = contacts[i].dn.year;
			tmp[j].age      = contacts[i].age;

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
			if ( mes != contacts[pos].dn.month ) continue;

			printf(
                "\n\tContato nº %hhu:"
                "\nNome..............: %s"
                "Idade...............: %hhu anos"
                "\nSexo..............: %c"
                "\nCidade............: %s"
                "Telefone............: %s"
                "Data de Nascimento..: %hhu/%hhu/%hu",
                (pos + 1),
                contacts[pos].name,
                contacts[pos].age,
                contacts[pos].sex,
                contacts[pos].city,
                contacts[pos].phone,
                contacts[pos].dn.day,
                contacts[pos].dn.month,
                contacts[pos].dn.year
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
        contact->name,
        contact->age,
        contact->sex,
        contact->city,
        contact->phone,
        contact->dn.day,
        contact->dn.month,
        contact->dn.year
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