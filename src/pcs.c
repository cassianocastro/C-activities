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
	register Byte pos = 0;

    for ( ; pos < num; pos++ )
    {
		printf(
            "\nComputador nº %hhu:\n"
			"Marca..............................: %s"
			"Modelo.............................: %s"
			"Tipo de HD.........................: %c\n"
			"Capac. de Armazenamento............: %d GB\n"
			"Memória............................: %d GB\n"
			"Processador........................: %s",
			(pos + 1),
			inventario[pos].marca,
			inventario[pos].modelo,
			inventario[pos].tipohd,
			inventario[pos].hd,
			inventario[pos].memoria,
			inventario[pos].processador
        );
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
			fgets(inventario[index].marca, MAX_SIZE_STR, stdin);
			break;
		case STORAGE_TYPE:
			do {
				printf(
                    "Tipo de Disco Rígido..."
					"\nDigite \"s\" para SSD ou \"c\" para convencional: "
                );
				scanf(" %c", &inventario[index].tipohd);

                inventario[index].tipohd = tolower(inventario[index].tipohd);
			} while (
                inventario[index].tipohd not_eq 's' and
                inventario[index].tipohd not_eq 'c'
            );
			break;
		case STORAGE:
			printf("Nova capacidade de armazenamento: ");
			scanf("%d", &inventario[index].hd);
			break;
		case MEMORY:
			printf("Novo tamanho de memória: ");
			scanf("%d", &inventario[index].memoria);
			break;
		case MODEL:
			printf("Novo Modelo: ");
			fgets(inventario[index].modelo, MAX_SIZE_STR, stdin);
			break;
		case PROCESSOR:
			printf("Novo Processador: ");
			fgets(inventario[index].processador, MAX_SIZE_STR, stdin);
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

		strcpy(new_inventario[pos2].marca,       inventario[pos].marca);
		strcpy(new_inventario[pos2].modelo,      inventario[pos].modelo);
		strcpy(new_inventario[pos2].processador, inventario[pos].processador);
		new_inventario[pos2].tipohd    		=    inventario[pos].tipohd;
		new_inventario[pos2].hd  			=    inventario[pos].hd;
		new_inventario[pos2].memoria  		=    inventario[pos].memoria;

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
			if ( strcmp(modelo, inventario[pos].modelo) != 0 ) continue;

            printf(
                "\nComputador nº %hhu:\n"
                "Marca..............................: %s"
                "Modelo.............................: %s"
                "Tipo de HD.........................: %c\n"
                "Capac. de Armazenamento............: %d GB\n"
                "Memória............................: %d GB\n"
                "Processador........................: %s",
                (pos + 1),
                inventario[pos].marca,
                inventario[pos].modelo,
                inventario[pos].tipohd,
                inventario[pos].hd,
                inventario[pos].memoria,
                inventario[pos].processador
            );

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
	fgets(inventario[pos].marca, MAX_SIZE_STR, stdin);

	printf("Modelo.......: ");
	fgets(inventario[pos].modelo, MAX_SIZE_STR, stdin);

	printf("Processador..: ");
	fgets(inventario[pos].processador, MAX_SIZE_STR, stdin);

    do {
		printf(
            "\nTipo de Disco Rígido..."
			"\nDigite \"s\" para SSD ou \"c\" para convencional: "
        );
		scanf(" %c", &inventario[pos].tipohd);
	} while (
        inventario[pos].tipohd not_eq 's' and
        inventario[pos].tipohd not_eq 'c'
    );

    printf("\nCapacidade de Armazenamento (em GB): ");
	scanf("%d", &inventario[pos].hd);

	printf("Tamanho da Memória (em GB).........: ");
	scanf("%d", &inventario[pos].memoria);
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