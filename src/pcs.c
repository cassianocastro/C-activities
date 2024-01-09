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
	    		free(inventario);
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
	    inventario = realloc(inventario, num * sizeof(Computador));
	    preenchimento_dados(num - 1);
	}
    else
    {
		printf("Informe o nº de computadores a serem cadastrados: ");
    	scanf("%hu", &num);

	    inventario = calloc(num, sizeof(Computador));

        register Byte pos = 0;

    	for ( ; pos < num; pos++ )
        {
            preenchimento_dados(pos);
        }
	}

	puts("\nInserção realizada.");
}

void showComputers(void)
{
    for ( register Byte i = 0; i < num; ++i )
    {
		printComputerInfo(i, &inventario[i]);
	}
}

void updateComputer(void)
{
	unsigned int tipo = 0u;
    Byte index = 0;

	printf("\nInforme o ID do computador: ");
	scanf("%hhu", &index);

	index--;

	printf(
        "\nSelecione o tipo de dado:\n"
		"\n1. Marca   | 2. Tipo de HD | 3. Capac. de Armazenamento"
		"\n4. Memória | 5. Modelo 	  | 6. Processador"
		"\nOpção\? "
    );
	scanf("%d", &tipo);
	getchar();

	switch ( tipo )
    {
		case MARK:
			printf("Nova marca: ");
			fgets(inventario[index].mark, MAX_SIZE_STR, stdin);
			break;
		case STORAGE_TYPE:
			do {
				printf(
                    "Tipo de Disco Rígido..."
					"\nDigite \"s\" para SSD ou \"c\" para convencional: "
                );
				scanf(" %c", &inventario[index].storageType);

                inventario[index].storageType = tolower(inventario[index].storageType);
			} while (
                inventario[index].storageType not_eq 's' and
                inventario[index].storageType not_eq 'c'
            );
			break;
		case STORAGE:
			printf("Nova capacidade de armazenamento: ");
			scanf("%d", &inventario[index].storage);
			break;
		case MEMORY:
			printf("Novo tamanho de memória: ");
			scanf("%d", &inventario[index].memory);
			break;
		case MODEL:
			printf("Novo Modelo: ");
			fgets(inventario[index].model, MAX_SIZE_STR, stdin);
			break;
		case PROCESSOR:
			printf("Novo Processador: ");
			fgets(inventario[index].processor, MAX_SIZE_STR, stdin);
			break;
		default:
			puts("\nOpção inválida!");
	}

	puts("\nAlteração realizada.");
}

void deleteComputer(void)
{
	Byte index = 0, pos = 0, pos2 = 0;
	Computador* new_inventario;
    bool was_found = false;

	printf("Informe o ID do computador: ");
	scanf("%hhu", &index);

	index--;
	new_inventario = calloc((num - 1), sizeof(Computador));

	for ( pos = 0; pos < num; pos++ )
    {
		if ( pos == index )
        {
			was_found = true;

			continue;
		}

		strcpy(new_inventario[pos2].mark,      inventario[pos].mark);
		strcpy(new_inventario[pos2].model,     inventario[pos].model);
		strcpy(new_inventario[pos2].processor, inventario[pos].processor);
		new_inventario[pos2].storageType = inventario[pos].storageType;
		new_inventario[pos2].storage     = inventario[pos].storage;
		new_inventario[pos2].memory      = inventario[pos].memory;

        pos2++;
	}

	if ( was_found )
    {
		free(inventario);
		inventario = new_inventario;
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
    register Byte pos = 0;

	getchar();

    do {
    	printf("\nInforme o modelo do computador: ");
	    fgets(modelo, MAX_SIZE_STR, stdin);

	    was_found = false;

	    for ( pos = 0; pos < num; pos++ )
        {
			if ( strcmp(modelo, inventario[pos].model) != 0 ) continue;

            printComputerInfo(pos, &inventario[pos]);

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

void preenchimento_dados(Byte pos)
{
	getchar();

    printf("\nComputador nº %hhu\n\nMarca........: ", (pos + 1));
	fgets(inventario[pos].mark, MAX_SIZE_STR, stdin);

	printf("Modelo.......: ");
	fgets(inventario[pos].model, MAX_SIZE_STR, stdin);

	printf("Processador..: ");
	fgets(inventario[pos].processor, MAX_SIZE_STR, stdin);

    do {
		printf(
            "\nTipo de Disco Rígido..."
			"\nDigite \"s\" para SSD ou \"c\" para convencional: "
        );
		scanf(" %c", &inventario[pos].storageType);
	} while (
        inventario[pos].storageType not_eq 's' and
        inventario[pos].storageType not_eq 'c'
    );

    printf("\nCapacidade de Armazenamento (em GB): ");
	scanf("%d", &inventario[pos].storage);

	printf("Tamanho da Memória (em GB).........: ");
	scanf("%d", &inventario[pos].memory);
}

void printComputerInfo(Byte i, const Computador* const computer)
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