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
				puts("\nExiting...");
				break;
	    	default:
	    		puts("\aInvalid option!");
		}
	} while ( option not_eq EXIT );

    free(contacts);
}

void addContact(void)
{
	byte response = 0u;

	printf("How many contacts do you want register\? ");
    scanf(" %hhu", &response);

	if ( response > 1 )
    {
		num = response;

	    contacts = (Contact*) calloc(num, sizeof(Contact));

		for ( register byte i = 0; i < num; ++i )
        {
            showContactForm(&contacts[i]);
        }
	}
    else if ( response == 1 )
    {
        puts("New contact...");

	    contacts = (Contact*) realloc(contacts, ++num * sizeof(Contact));

        showContactForm(&contacts[num - 1]);
	}
    else
    {
        return;
    }

	puts("\nAdded contact(s).");
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
			puts("\n\aInvalid option!");
	}

	puts("\nUpdated register.");
}

void deleteContact(void)
{
	byte index = getContactID();
    bool found = searchID(index);

    if ( not found )
    {
        puts("\aRegister not found!");

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
    	printf("\nEnter the number of the month of birth (Ex.: April = 4): ");
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
            puts("\n\aRegister not found!");
        }

        printf("\n\nDo again [y/n]\? ");
		scanf(" %c", &response);

	} while ( tolower(response) == 'y' );
}