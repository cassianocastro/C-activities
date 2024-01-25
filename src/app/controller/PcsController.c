#include "../../includes/controller/PcsController.h"

void start(void)
{
    unsigned int option = 0u;

    while ( true )
    {
	    option = getMainMenuChoice();

        clearScreen();

    	switch ( option )
        {
	    	case CREATE:
	    		addComputer();
	    		break;
			case READ:
				showComputers();
				break;
			case UPDATE:
				updateComputer();
				break;
			case DELETE:
				deleteComputer();
				break;
	    	case SEARCH:
	    		searchComputer();
	    		break;
	    	default:
	    		free(inventary);
				exit(EXIT_SUCCESS);
		}
	}
}

void addComputer(void)
{
	byte response = 0;

	printf("How many computers do you want register\? ");
    scanf("%hhu", &response);

	if ( response > 1 )
    {
        num = response;

	    inventary = (Computer*) calloc(num, sizeof(Computer));

    	for ( register byte i = 0; i < num; ++i )
        {
            showComputerForm(&inventary[i]);
        }
    }
    else if ( response == 1 )
    {
		puts("\nNew computer...");

	    inventary = (Computer*) realloc(inventary, ++num * sizeof(Computer));

        showComputerForm(&inventary[num - 1]);
	}
    else
    {
        return;
    }

	puts("\nAdded register.");
}

void showComputers(void)
{
    for ( register byte i = 0; i < num; ++i )
    {
		printComputerInfo(i, &inventary[i]);
	}
}

void updateComputer(void)
{
    byte id = getComputerID();

	unsigned int tipo = getUpdateMenuChoice();

	switch ( tipo )
    {
		case MARK:
            getComputerMark(inventary[id].mark);
			break;
		case MODEL:
            getComputerModel(inventary[id].model);
			break;
		case PROCESSOR:
            getComputerProcessor(inventary[id].processor);
			break;
		case STORAGE_TYPE:
            inventary[id].storageType = getComputerStorageType();
			break;
		case STORAGE:
            inventary[id].storage = getComputerStorage();
			break;
		case MEMORY:
            inventary[id].memory = getComputerMemory();
			break;
		default:
			puts("\nInvalid option!");
	}

	puts("\nUpdated register.");
}

void deleteComputer(void)
{
    bool found = false;
	byte index = getComputerID();

	Computer* tmp = (Computer*) calloc((num - 1), sizeof(Computer));

	for ( register byte i = 0, j = 0; i < num; ++i )
    {
		if ( i == index )
        {
			found = true;

			continue;
		}

        tmp[j] = inventary[i];

        ++j;
	}

	if ( found )
    {
		free(inventary);
		inventary = tmp;
		num--;

		puts("\nDeleted register.");
	}
    else
		puts("\nRegister not found!");
}

void searchComputer(void)
{
	char response = '\0', model[MAX_SIZE_STR];
	bool found = false;

	getchar();

    do {
    	printf("\nEnter the computer model: ");
	    fgets(model, MAX_SIZE_STR, stdin);

	    found = false;

	    for ( register byte i = 0; i < num; ++i )
        {
			if ( strcmp(model, inventary[i].model) != 0 ) continue;

            printComputerInfo(i, &inventary[i]);

			found = true;
		}

		if ( not found )
        {
            puts("\nRegister not found!");
        }

        printf("\nDo again [y/n]\? ");
		scanf(" %c", &response);

	} while ( tolower(response) == 'y' );
}