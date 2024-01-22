#include "../../includes/controller/EvaluationsController.h"

void start(void)
{
    unsigned int option = 0u;

    chooseFile();

	begin:
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
			case SEARCH:
				searchComputer();
				break;
			case UPDATE:
				updateComputer();
				break;
			case DELETE:
				deleteComputer();
				break;
			case CHOOSE_FILE:
				fclose(arquivo);
				chooseFile();
				break;
            case EXIT:
				puts("Até mais...");
				break;
			default:
				puts("\aDígito inválido!");
		}

	if ( option not_eq EXIT ) goto begin;
}

void addComputer(void)
{
    unsigned short int cadastros = 0;

	printf("Quantos cadastros você deseja fazer\? ");
	scanf("%hu", &cadastros);

	for ( register unsigned short int i = 0; i < cadastros; ++i )
    {
		fseek(arquivo, 0, SEEK_END);

        showComputerForm(i);

		fwrite(&computer, sizeof(Computer), 1, arquivo);
	}

	puts("\nCadastro(s) realizado(s).");
}

void showComputers(void)
{
	register uint8_t i = 0;

	fseek(arquivo, 0, SEEK_SET);

	for ( ; not feof(arquivo); ++i )
    {
		fread(&computer, sizeof(Computer), 1, arquivo);

		if ( feof(arquivo) ) break;

        printComputer(&computer);
	}

	( i == 0 ) ? puts("\a\nEstoque vazio.") : system("pause");
}

void updateComputer(void)
{
	unsigned int id = getComputerID();

    if ( not ok(id) )
    {
		puts("\aComputador não encontrado.");

		return;
	}

	FILE* tmp = fopen("temporario.xxx", "ab+");

	if ( tmp == NULL )
    {
        printf("Erro nº %d: %s", errno, strerror(errno));

    	return;
    }

    fseek(arquivo, 0, SEEK_SET);

    while ( true )
    {
        fread(&computer, sizeof(Computer), 1, arquivo);

        if ( feof(arquivo) ) break;

        if ( computer.ID == id )
        {
            alterado(&computer);
        }

        fwrite(&computer, sizeof(Computer), 1, tmp);
    }

    fclose(tmp);
    fclose(arquivo);

    remove(nome_arquivo);

	arquivo = fopen(nome_arquivo, "ab+");
	tmp     = fopen("temporario.xxx", "rb");

	if ( arquivo == NULL or tmp == NULL )
    {
        return;
    }

    fseek(tmp, 0, SEEK_SET);

    while ( true )
    {
        fread(&computer, sizeof(Computer), 1, tmp);

        if ( feof(tmp) ) break;

        fwrite(&computer, sizeof(Computer), 1, arquivo);
    }

    fclose(tmp);
    remove("temporario.xxx");

    puts("Alteração realizada.");
}

void deleteComputer(void)
{
	unsigned int id = getComputerID();

	if ( not ok(id) )
    {
		puts("\aID não encontrado.");

		return;
	}

	FILE* tmp = fopen("temporario.xxx", "ab+");

	if ( tmp == NULL )
    {
        printf("\aErro nº %d: %s", errno, strerror(errno));

    	return;
    }

    fseek(arquivo, 0, SEEK_SET);

    while ( true )
    {
        fread(&computer, sizeof(Computer), 1, arquivo);

        if ( feof(arquivo) ) break;

        if ( computer.ID not_eq id )
        {
            fwrite(&computer, sizeof(Computer), 1, tmp);
        }
    }

    fclose(tmp);
    fclose(arquivo);

    remove(nome_arquivo);

	arquivo = fopen(nome_arquivo, "ab+");
	tmp     = fopen("temporario.xxx", "rb");

	if ( arquivo == NULL or tmp == NULL )
    {
        printf("\aErro nº %d: %s", errno, strerror(errno));

        return;
    }

    fseek(tmp, 0, SEEK_SET);

    while ( true )
    {
        fread(&computer, sizeof(Computer), 1, tmp);

        if ( feof(tmp) ) break;

        fwrite(&computer, sizeof(Computer), 1, arquivo);
    }

    fclose(tmp);
    remove("temporario.xxx");

    puts("Computador Removido.");
}

void searchComputer(void)
{
	unsigned int id = getComputerID();

    bool found = false;

	fseek(arquivo, 0, SEEK_SET);

	while ( true )
    {
		fread(&computer, sizeof(Computer), 1, arquivo);

		if ( feof(arquivo) ) break;

		if ( computer.ID != id ) continue;

		printComputer(&computer);

		found = true;

		break;
	}

	if ( not found )
    {
        puts("\aComputador não encontrado.");
    }
}

bool ok(int id)
{
	Computer pc;

	fseek(arquivo, 0, SEEK_SET);

    while ( true )
    {
		fread(&pc, sizeof(Computer), 1, arquivo);

        if ( feof(arquivo) ) break;

        if ( pc.ID == id ) return true;
	}

	return false;
}

void alterado(Computer* pc)
{
	unsigned int data = getUpdateMenuChoice();

	switch ( data )
    {
		case TYPE:
			do {
				printf("Tipo [d/n]: ");
				scanf(" %c", &pc->type);
			} while ( pc->type not_eq 'd' and pc->type not_eq 'n' );
			break;
		case SCREEN:
			printf("Tamanho da Tela: ");
			scanf("%f", &pc->screen);
			break;
		case MARK:
			printf("Marca: ");
			fgets(pc->mark, sizeof(pc->mark), stdin);
			break;
		case MODEL:
			printf("Modelo: ");
			fgets(pc->model, sizeof(pc->model), stdin);
			break;
		case PROCESSOR:
			printf("Processador: ");
			fgets(pc->processor, sizeof(pc->processor), stdin);
			break;
		case COLOR:
			printf("Cor: ");
			fgets(pc->color, sizeof(pc->color), stdin);
			break;
		case MEMORY:
			printf("Memória RAM (em GB): ");
			scanf("%d", &pc->memory);
			break;
		case STORAGE:
			printf("Capac. de Armazenamento (em GB): ");
			scanf("%d", &pc->storage);
			break;
		default:
			puts("\aDígito inválido!");
	}
}

void chooseFile(void)
{
	printf("\nNome do arquivo: ");
	fgets(nome_arquivo, TAM, stdin);

	arquivo = fopen(nome_arquivo, "ab+");

	if ( arquivo == NULL )
    {
		printf("Erro nº %d: %s", errno, strerror(errno));

    	exit(EXIT_SUCCESS);
	}
}