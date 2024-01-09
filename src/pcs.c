#include "./includes/pcs.h"

/**
 *
 */
int main(int argc, const char* argv[])
{
	setlocale(LC_ALL, "");

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

	return EXIT_SUCCESS;
}

void addComputer(void)
{
	char resposta = '\0';

	printf("Olá, é a sua primeira vez com esta tela [s/n]\? ");
    scanf(" %c", &resposta);

    resposta = tolower(resposta);

	if ( resposta == 'n' )
    {
		puts("\nInserindo novo computador...");
	    num++;
	    inventary = (Computer*) realloc(inventary, num * sizeof(Computer));
	    preenchimento_dados(num - 1);
	}
    else
    {
		printf("Informe o nº de computadores a serem cadastrados: ");
    	scanf("%hu", &num);

	    inventary = (Computer*) calloc(num, sizeof(Computer));

    	for ( register byte i = 0; i < num; ++i )
        {
            preenchimento_dados(i);
        }
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
    byte index = getComputerID();

	unsigned int tipo = getUpdateMenuChoice();

	switch ( tipo )
    {
		case MARK:
			printf("Nova marca: ");
			fgets(inventary[index].mark, MAX_SIZE_STR, stdin);
			break;
		case STORAGE_TYPE:
			do {
				printf(
                    "Tipo de Disco Rígido..."
					"\nDigite \"s\" para SSD ou \"c\" para convencional: "
                );
				scanf(" %c", &inventary[index].storageType);

                inventary[index].storageType = tolower(inventary[index].storageType);
			} while (
                inventary[index].storageType not_eq 's' and
                inventary[index].storageType not_eq 'c'
            );
			break;
		case STORAGE:
			printf("Nova capacidade de armazenamento: ");
			scanf("%d", &inventary[index].storage);
			break;
		case MEMORY:
			printf("Novo tamanho de memória: ");
			scanf("%d", &inventary[index].memory);
			break;
		case MODEL:
			printf("Novo Modelo: ");
			fgets(inventary[index].model, MAX_SIZE_STR, stdin);
			break;
		case PROCESSOR:
			printf("Novo Processador: ");
			fgets(inventary[index].processor, MAX_SIZE_STR, stdin);
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

		strcpy(tmp[j].mark,      inventary[i].mark);
		strcpy(tmp[j].model,     inventary[i].model);
		strcpy(tmp[j].processor, inventary[i].processor);
		tmp[j].storageType = inventary[i].storageType;
		tmp[j].storage     = inventary[i].storage;
		tmp[j].memory      = inventary[i].memory;

        ++j;
	}

	if ( found )
    {
		free(inventary);
		inventary = tmp;
		num --;
		puts("\nRemoção realizada.");
	}
    else
		puts("\nCadastro não encontrado!");
}

void searchComputer(void)
{
	char resposta = '\0', modelo[MAX_SIZE_STR];
	bool was_found = false;
    register byte pos = 0;

	getchar();

    do {
    	printf("\nInforme o modelo do computador: ");
	    fgets(modelo, MAX_SIZE_STR, stdin);

	    was_found = false;

	    for ( pos = 0; pos < num; pos++ )
        {
			if ( strcmp(modelo, inventary[pos].model) != 0 ) continue;

            printComputerInfo(pos, &inventary[pos]);

			was_found = true;
		}

		if ( not was_found )
        {
            puts("\nCadastro não encontrado!");
        }

        printf("\nDeseja realizar novamente [s/n]\? ");
		scanf(" %c", &resposta);

		resposta = tolower(resposta);
	} while ( resposta == 's' );
}

const byte getComputerID(void)
{
    byte index = 0;

	printf("ID do computador: ");
	scanf("%hhu", &index);

	return --index;
}

void preenchimento_dados(byte pos)
{
	getchar();

    printf("\nComputador nº %hhu\n\nMarca........: ", (pos + 1));
	fgets(inventary[pos].mark, MAX_SIZE_STR, stdin);

	printf("Modelo.......: ");
	fgets(inventary[pos].model, MAX_SIZE_STR, stdin);

	printf("Processador..: ");
	fgets(inventary[pos].processor, MAX_SIZE_STR, stdin);

    do {
		printf(
            "\nTipo de Disco Rígido..."
			"\nDigite \"s\" para SSD ou \"c\" para convencional: "
        );
		scanf(" %c", &inventary[pos].storageType);
	} while (
        inventary[pos].storageType not_eq 's' and
        inventary[pos].storageType not_eq 'c'
    );

    printf("\nCapacidade de Armazenamento (em GB): ");
	scanf("%d", &inventary[pos].storage);

	printf("Tamanho da Memória (em GB).........: ");
	scanf("%d", &inventary[pos].memory);
}

void printComputerInfo(byte i, const Computer* const computer)
{
    printf(
        "\nComputador nº %hhu:\n"
        "Marca....................: %s"
        "Modelo...................: %s"
        "Tipo de HD...............: %c\n"
        "Capac. de Armazenamento..: %d GB\n"
        "Memória..................: %d GB\n"
        "Processador..............: %s",
        (i + 1),
        computer->mark,
        computer->model,
        computer->storageType,
        computer->storage,
        computer->memory,
        computer->processor
    );
}

const unsigned int getMainMenuChoice(void)
{
    unsigned int choice = 0u;

    printf(
        "\nEscolha uma das opções abaixo:"
        "\n1. Insercão | 2. Listagem | 3. Alteração"
        "\n4. Remoção  | 5. Busca    | 6. Sair"
        "\nOpção\? "
    );
    scanf("%d", &choice);

    return choice;
}

const unsigned int getUpdateMenuChoice(void)
{
    unsigned int choice = 0u;

    printf(
        "\nSelecione o tipo de dado:\n"
		"\n1. Marca   | 2. Tipo de HD | 3. Capac. de Armazenamento"
		"\n4. Memória | 5. Modelo 	  | 6. Processador"
		"\nOpção\? "
    );
    scanf("%d", &choice);
    getchar();

    return choice;
}