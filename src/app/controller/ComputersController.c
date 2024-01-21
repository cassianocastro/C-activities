#include "../../includes/controller/ComputerController.h"

Computer* inventary;

unsigned short numero;

void start(void)
{
    unsigned int option = 0u;

    do {
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
			case EXIT:
				puts("\nFIM.");
				break;
	    	default:
	    		puts("Opção inválida!");
		}
	} while ( option not_eq EXIT );

    free(inventary);
}

void addComputer(void)
{
    unsigned int response = 0u;

    printf("Quantos computadores deseja cadastrar\? ");
    scanf(" %d", &response);

	if ( response > 1 )
        addSeveralComputers();
    else
        addOneComputer();

	puts("\nInserção realizada.");
}

void showComputers(void)
{
    for ( register byte i = 0; i < numero; ++i )
	{
        printComputerInfo(i + 1, &inventary[i]);
	}
}

/**
 * Fazer a verificacao antes de alterar...
 */
void updateComputer(void)
{
    byte index = getComputerID();
    unsigned int dado = getUpdateMenuChoice();

	switch ( dado )
	{
		case MARK:
			printf("Nova marca: ");
			gets(inventary[index].mark);
			break;
		case STORAGE_TYPE:
			do {
				printf("\nTipo de HD...[s/c]\? ");
				scanf(" %c", &inventary[index].storageType);
			} while (
                inventary[index].storageType != 's' and
                inventary[index].storageType != 'c'
            );
			break;
		case STORAGE:
			printf("Nova capac. de armazenamento: ");
			scanf("%d", &inventary[index].storage);
			break;
		case MEMORY:
			printf("Novo tamanho de memória: ");
			scanf("%d", &inventary[index].memory);
			break;
		case MODEL:
			printf("Novo Modelo: ");
			gets(inventary[index].model);
			break;
		case PROCESSOR:
			printf("Novo Processador: ");
			gets(inventary[index].processor);
			break;
		default:
			puts("\nOpção inválida!");
	}

	puts("\nAlteração realizada.");
}

void deleteComputer(void)
{
	bool found = false;
	byte id    = getComputerID();

    Computer* tmp = (Computer*) calloc((numero - 1), sizeof(Computer));

	for ( register byte i = 0, j = 0; i < numero; ++i )
	{
		if ( i == id )
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
		numero--;

		puts("\nRemoção realizada.");
	}
    else
        puts("\nCadastro não encontrado!");
}

void searchComputer(void)
{
	char response = '\0', model[TAM_STRING];
    bool found = false;

    do {
    	printf("\nInforme o modelo do computador: ");
        gets(model);

	    found = false;

		for ( register byte i = 0; i < numero; ++i )
		{
			if ( strcmp(model, inventary[i].model) == 0 )
            {
                printComputerInfo(i + 1, &inventary[i]);

				found = true;
			}
		}

		if ( not found )
        {
            puts("\nCadastro não encontrado!");
        }

		printf("\nDeseja realizar novamente [s/n]\? ");
		scanf(" %c", &response);
	} while ( tolower(response) == 's' );
}

void addSeveralComputers(void)
{
    printf("Informe o nº de PC\'s a serem cadastrados: ");
    scanf("%hu", &numero);

    inventary = (Computer*) calloc(numero, sizeof(Computer));

    for ( register byte i = 0; i < numero; ++i )
    {
        inventary[i] = showComputerForm(i);
    }
}

void addOneComputer(void)
{
    puts("\nInserindo novo computador...");

    inventary = (Computer*) realloc(inventary, ++numero * sizeof(Computer));

    inventary[numero - 1] = showComputerForm(numero - 1);
}