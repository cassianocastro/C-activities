#include "../../includes/controller/PcsController.h"

void start(void)
{
    unsigned int option = 0u;

    while ( true )
    {
	    option = getMainMenuChoice();

		system("clear");

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

	printf("Quantos computadores deseja cadastrar\? ");
    scanf("%hhu", &response);

	if ( response > 1 )
    {
        printf("Informe o nº de computadores a serem cadastrados: ");
    	scanf("%hu", &num);

	    inventary = (Computer*) calloc(num, sizeof(Computer));

    	for ( register byte i = 0; i < num; ++i )
        {
            showComputerForm(&inventary[i]);
        }
    }
    else
    {
		puts("\nInserindo novo computador...");

	    inventary = (Computer*) realloc(inventary, ++num * sizeof(Computer));

        showComputerForm(&inventary[num - 1]);
	}

	puts("\nInserção realizada.");
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
			printf("Marca: ");
			fgets(inventary[id].mark, MAX_SIZE_STR, stdin);
			break;
		case STORAGE_TYPE:
			do {
				printf(
                    "Tipo de Disco Rígido..."
					"\nDigite \"s\" para SSD ou \"c\" para convencional: "
                );
				scanf(" %c", &inventary[id].storageType);

                inventary[id].storageType = tolower(inventary[id].storageType);
			} while (
                inventary[id].storageType not_eq 's' and
                inventary[id].storageType not_eq 'c'
            );
			break;
		case STORAGE:
			printf("Capacidade de armazenamento: ");
			scanf("%d", &inventary[id].storage);
			break;
		case MEMORY:
			printf("Memória: ");
			scanf("%d", &inventary[id].memory);
			break;
		case MODEL:
			printf("Modelo: ");
			fgets(inventary[id].model, MAX_SIZE_STR, stdin);
			break;
		case PROCESSOR:
			printf("Processador: ");
			fgets(inventary[id].processor, MAX_SIZE_STR, stdin);
			break;
		default:
			puts("\nOpção inválida!");
	}

	puts("\nAlteração realizada.");
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

		puts("\nRemoção realizada.");
	}
    else
		puts("\nCadastro não encontrado!");
}

void searchComputer(void)
{
	char response = '\0', model[MAX_SIZE_STR];
	bool found = false;

	getchar();

    do {
    	printf("\nInforme o modelo do computador: ");
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
            puts("\nCadastro não encontrado!");
        }

        printf("\nDeseja realizar novamente [s/n]\? ");
		scanf(" %c", &response);

	} while ( tolower(response) == 's' );
}