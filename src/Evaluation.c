#include "./includes/Evaluation.h"

int main(int argc, const char* argv[])
{
	setlocale(LC_ALL, "");

    unsigned int option = 0u;

    chooseFile();

	begin:
		printf(
            "\nArquivo utilizado: %s\n"
            "\nEscolha uma das opções abaixo:"
            "\n1. Inserir de novos computadores;"
            "\n2. Exibir computadores;"
            "\n3. Buscar PC;"
            "\n4. Alterar dados;"
            "\n5. Remover cadastro;"
            "\n6. Escolher outro arquivo;"
            "\n0. Sair;"
            "\nOpção\? ",
            nome_arquivo
        );
		scanf("%d", &option);
		getchar();

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

	return EXIT_SUCCESS;
}

void addComputer(void)
{
    short cadastros = 0;

	printf("Quantos cadastros você deseja fazer\? ");
	scanf("%hu", &cadastros);

	for ( register uint8_t i = 0; i < cadastros; ++i )
    {
		fseek(arquivo, 0, SEEK_END);

        printf("\n\tComputador nº %hhu\n", (i + 1));
        getchar();

        printf("Marca..........................: ");
		fgets(computer.mark, sizeof(computer.mark), stdin);

		printf("Modelo.........................: ");
		fgets(computer.model, sizeof(computer.model), stdin);

		printf("Processador....................: ");
		fgets(computer.processor, sizeof(computer.processor), stdin);

		printf("Cor............................: ");
		fgets(computer.color, sizeof(computer.color), stdin);

		printf("Tamanho da Tela................: ");
		scanf("%f", &computer.screen);

		printf("Memória RAM (em GB)............: ");
		scanf("%d", &computer.memory);

		printf("Capac. de Armazenamento (em GB): ");
		scanf("%d", &computer.storage);

		do {
			printf("Tipo [d/n].....................: ");
			scanf(" %c", &computer.type);
		} while ( computer.type not_eq 'd' and computer.type not_eq 'n' );

		while ( true )
        {
			printf("ID do computador: ");
			scanf("%d", &computer.ID);

			if ( ok(&computer.ID) )
				puts("\nID já utilizado!");
			else
				break;
		}

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

		printf(
            "\n\tComputador ID nº %d:\n"
            "Marca..........................: %s"
            "Modelo.........................: %s"
            "Processador....................: %s"
            "Cor............................: %s"
            "Tamanho da Tela................: %.1f\"\n"
            "Memória RAM....................: %d GB\n"
            "Capac. de Armazenamento........: %d GB\n"
            "Tipo...........................: %c\n\n",
            computer.ID,
            computer.mark,
            computer.model,
            computer.processor,
            computer.color,
            computer.screen,
            computer.memory,
            computer.storage,
            computer.type
        );
	}

	( i == 0 ) ? puts("\a\nEstoque vazio.") : system("pause");
}

void updateComputer(void)
{
	int index = 0;

    printf("ID do computador: ");
	scanf("%d", &index);

    if ( not ok(&index) )
    {
		puts("\aComputador não encontrado.");

		return;
	}

	FILE* arquivo_temporario = fopen("temporario.xxx", "ab+");

	if ( arquivo_temporario != NULL )
    {
		fseek(arquivo, 0, SEEK_SET);

        while ( true )
        {
			fread(&computer, sizeof(Computer), 1, arquivo);

        	if ( feof(arquivo) ) break;

        	if ( computer.ID not_eq index )
            {
				fwrite(&computer, sizeof(Computer), 1, arquivo_temporario);
            }
			else
            {
				alterado(&computer);
				fwrite(&computer, sizeof(Computer), 1, arquivo_temporario);
			}
		}

		fclose(arquivo_temporario);
		fclose(arquivo);
		remove(nome_arquivo);
	}
    else
    {
		printf("Erro nº %d: %s", errno, strerror(errno));

    	return;
	}

	arquivo = fopen(nome_arquivo, "ab+");
	arquivo_temporario = fopen("temporario.xxx", "rb");

	if ( arquivo != NULL and arquivo_temporario != NULL )
    {
		fseek(arquivo_temporario, 0, SEEK_SET);

		while ( true )
        {
			fread(&computer, sizeof(Computer), 1, arquivo_temporario);

        	if ( feof(arquivo_temporario) ) break;

        	fwrite(&computer, sizeof(Computer), 1, arquivo);
		}

		fclose(arquivo_temporario);
		remove("temporario.xxx");
		puts("Alteração realizada.");
	}
}

void deleteComputer(void)
{
	int index = 0;

	printf("ID do computador: ");
	scanf("%d", &index);

	if ( not ok(&index) )
    {
		puts("\aID não encontrado.");

		return;
	}

	FILE* arquivo_temporario = fopen("temporario.xxx", "ab+");

	if ( arquivo_temporario not_eq NULL )
    {
		fseek(arquivo, 0, SEEK_SET);

		while ( true )
        {
			fread(&computer, sizeof(Computer), 1, arquivo);

            if ( feof(arquivo) ) break;

            if ( computer.ID not_eq index )
            {
				fwrite(&computer, sizeof(Computer), 1, arquivo_temporario);
            }
		}

		fclose(arquivo_temporario);
		fclose(arquivo);
		remove(nome_arquivo);
	}
    else
    {
		printf("\aErro nº %d: %s", errno, strerror(errno));

    	return;
	}

	arquivo = fopen(nome_arquivo, "ab+");
	arquivo_temporario = fopen("temporario.xxx", "rb");

	if ( arquivo not_eq NULL and arquivo_temporario not_eq NULL )
    {
		fseek(arquivo_temporario, 0, SEEK_SET);

		while ( true )
        {
			fread(&computer, sizeof(Computer), 1, arquivo_temporario);

			if ( feof(arquivo_temporario) ) break;

			fwrite(&computer, sizeof(Computer), 1, arquivo);
		}

		fclose(arquivo_temporario);
		remove("temporario.xxx");
		puts("Computador Removido.");
	}
    else
        printf("\aErro nº %d: %s", errno, strerror(errno));
}

void searchComputer(void)
{
	int index = 0;
    bool found = false;

	printf("ID do computador: ");
	scanf("%d", &index);

	fseek(arquivo, 0, SEEK_SET);

	while ( true )
    {
		fread(&computer, sizeof(Computer), 1, arquivo);

		if ( feof(arquivo) ) break;

		if ( computer.ID != index ) continue;

		printf(
            "\n\tComputador ID nº %d:\n"
            "Marca..........................: %s"
            "Modelo.........................: %s"
            "Processador....................: %s"
            "Cor............................: %s"
            "Tamanho da Tela................: %.1f\"\n"
            "Memória RAM....................: %d GB\n"
            "Capac. de Armazenamento........: %d GB\n"
            "Tipo...........................: %c\n\n",
            computer.ID,
            computer.mark,
            computer.model,
            computer.processor,
            computer.color,
            computer.screen,
            computer.memory,
            computer.storage,
            computer.type
        );

		found = true;

		break;
	}

	if ( not found )
    {
        puts("\aComputador não encontrado.");
    }
}

bool ok(int* id)
{
	Computer pc;

	fseek(arquivo, 0, SEEK_SET);

    while ( true )
    {
		fread(&pc, sizeof(Computer), 1, arquivo);

        if ( feof(arquivo) ) break;

        if ( pc.ID == (*id) ) return true;
	}

	return false;
}

void alterado(Computer* pc)
{
	unsigned int dado = 0u;

	printf(
        "Escolha o dado que deseja alterar:"
        "\n1. Tipo;"
        "\n2. Tamanho da Tela;"
        "\n3. Marca;"
        "\n4. Modelo;"
        "\n5. Processador;"
        "\n6. Cor;"
        "\n7. Memória RAM (em GB);"
        "\n8. Capac. de Armazenamento (em GB);"
        "\nOpção\?"
    );
	scanf("%d", &dado);
	getchar();

	switch ( dado )
    {
		case TYPE:
			do {
				printf("Novo Tipo [d/n]: ");
				scanf(" %c", &pc->type);
			} while ( pc->type not_eq 'd' and pc->type not_eq 'n' );
			break;
		case SCREEN:
			printf("Novo Tamanho da Tela: ");
			scanf("%f", &pc->screen);
			break;
		case MARK:
			printf("Nova Marca: ");
			fgets(pc->mark, sizeof(pc->mark), stdin);
			break;
		case MODEL:
			printf("Novo Modelo: ");
			fgets(pc->model, sizeof(pc->model), stdin);
			break;
		case PROCESSOR:
			printf("Novo Processador: ");
			fgets(pc->processor, sizeof(pc->processor), stdin);
			break;
		case COLOR:
			printf("Nova Cor: ");
			fgets(pc->color, sizeof(pc->color), stdin);
			break;
		case MEMORY:
			printf("Nova Memória RAM (em GB): ");
			scanf("%d", &pc->memory);
			break;
		case STORAGE:
			printf("Nova Capac. de Armazenamento (em GB): ");
			scanf("%d", &pc->storage);
			break;
		default:
			puts("\aDígito inválido!");
	}
}

void chooseFile(void)
{
	printf("\nNome do arquivo: ");
	fgets(nome_arquivo, sizeof(nome_arquivo), stdin);

	arquivo = fopen(nome_arquivo, "ab+");

	if ( arquivo == NULL )
    {
		printf("Erro nº %d: %s", errno, strerror(errno));

    	exit(EXIT_SUCCESS);
	}
}