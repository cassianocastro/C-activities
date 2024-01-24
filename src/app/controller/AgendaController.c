#include "../../includes/controller/AgendaController.h"

void start(void)
{
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
            showContactForm(&contacts[i]);
        }
	}
    else
    {
        puts("Inserindo novo contato...");

	    contacts = (Contact*) realloc(contacts, ++num * sizeof(Contact));

        showContactForm(&contacts[num - 1]);
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
    bool ok = false;
    byte id = getContactID();

    unsigned int tipo = showUpdateMenu();

	switch ( tipo )
    {
		case NAME:
            getContactName(contacts[id].name);
			break;
		case PHONE:
            getContactPhone(contacts[id].phone);
			break;
		case CITY:
            getContactCity(contacts[id].city);
			break;
		case SEX:
            contacts[id].sex = getContactSex();
			break;
		case BIRTHDATE:
            contacts[id].dn = getContactBirthDate();
			break;
		default:
			puts("\n\aOpção inválida!");
	}

	puts("\nAlteração realizada.");
}

void deleteContact(void)
{
	byte index = getContactID();
    bool found = searchID(index);

    if ( not found )
    {
        puts("\aCadastro não encontrado!");

        return;
    }

    Contact* tmp = (Contact*) calloc((num - 1), sizeof(Contact));

    for ( register byte i = 0u, j = 0u; i < num; ++i )
    {
        if ( i != index )
        {
            tmp[j++] = contacts[i];
        }
    }

    free(contacts);

    contacts = tmp;
    --num;

    puts("\nRemoção realizada.");
}

void searchContact(void)
{
	char response = '\0';
    bool found = false;
    byte month = 0;

    do {
    	printf("\nDigite o nº do mês de nascimento (Ex.: Abril = 4): ");
	    scanf("%hhu", &month);

        found = false;

	    for ( register byte i = 0; i < num; ++i )
        {
			if ( contacts[i].dn.month != month ) continue;

            printContact(&contacts[i]);

			found = true;
		}

		if ( not found )
        {
            puts("\n\aCadastro não encontrado!!");
        }

        printf("\n\nDeseja realizar novamente [S/n]\? ");
		scanf(" %c", &response);

	} while ( tolower(response) == 's' );
}