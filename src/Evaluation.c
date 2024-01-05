#include "./includes/Evaluation.h"

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

void insercao(void)
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
		fgets(PC.marca, sizeof(PC.marca), stdin);

		printf("Modelo.........................: ");
		fgets(PC.modelo, sizeof(PC.modelo), stdin);

		printf("Processador....................: ");
		fgets(PC.processador, sizeof(PC.processador), stdin);

		printf("Cor............................: ");
		fgets(PC.cor, sizeof(PC.cor), stdin);

		printf("Tamanho da Tela................: ");
		scanf("%f", &PC.tamanho_tela);

		printf("Memória RAM (em GB)............: ");
		scanf("%d", &PC.RAM);

		printf("Capac. de Armazenamento (em GB): ");
		scanf("%d", &PC.HD);

		do {
			printf("Tipo [d/n].....................: ");
			scanf(" %c", &PC.tipo);
		} while ( PC.tipo not_eq 'd' and PC.tipo not_eq 'n' );

		while ( true )
        {
			printf("ID do computador: ");
			scanf("%d", &PC.ID);

			if ( ok(&PC.ID) )
				puts("\nID já utilizado!");
			else
				break;
		}

		fwrite(&PC, sizeof(Computer), 1, arquivo);
	}

	puts("\nCadastro(s) realizado(s).");
}

void remocao(void)
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
			fread(&PC, sizeof(Computer), 1, arquivo);

            if ( feof(arquivo) ) break;

            if ( PC.ID not_eq index )
            {
				fwrite(&PC, sizeof(Computer), 1, arquivo_temporario);
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
			fread(&PC, sizeof(Computer), 1, arquivo_temporario);

			if ( feof(arquivo_temporario) ) break;

			fwrite(&PC, sizeof(Computer), 1, arquivo);
		}

		fclose(arquivo_temporario);
		remove("temporario.xxx");
		puts("Computador Removido.");
	}
    else
        printf("\aErro nº %d: %s", errno, strerror(errno));
}

void listagem(void)
{
	register uint8_t i = 0;

	fseek(arquivo, 0, SEEK_SET);

	for ( ; not feof(arquivo); ++i )
    {
		fread(&PC, sizeof(Computer), 1, arquivo);

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
            PC.ID,
            PC.marca,
            PC.modelo,
            PC.processador,
            PC.cor,
            PC.tamanho_tela,
            PC.RAM,
            PC.HD,
            PC.tipo
        );
	}

	( i == 0 ) ? puts("\a\nEstoque vazio.") : system("pause");
}

void busca(void)
{
	int index = 0;
    bool found = false;

	printf("ID do computador: ");
	scanf("%d", &index);

	fseek(arquivo, 0, SEEK_SET);

	while ( true )
    {
		fread(&PC, sizeof(Computer), 1, arquivo);

		if ( feof(arquivo) ) break;

		if ( PC.ID != index ) continue;

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
            PC.ID,
            PC.marca,
            PC.modelo,
            PC.processador,
            PC.cor,
            PC.tamanho_tela,
            PC.RAM,
            PC.HD,
            PC.tipo
        );

		found = true;

		break;
	}

	if ( not found )
    {
        puts("\aComputador não encontrado.");
    }
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
		case TIPO:
			do {
				printf("Novo Tipo [d/n]: ");
				scanf(" %c", &pc->tipo);
			} while ( pc->tipo not_eq 'd' and pc->tipo not_eq 'n' );
			break;
		case TAMANHO_TELA:
			printf("Novo Tamanho da Tela: ");
			scanf("%f", &pc->tamanho_tela);
			break;
		case MARCA:
			printf("Nova Marca: ");
			fgets(pc->marca, sizeof(pc->marca), stdin);
			break;
		case MODELO:
			printf("Novo Modelo: ");
			fgets(pc->modelo, sizeof(pc->modelo), stdin);
			break;
		case PROCESSADOR:
			printf("Novo Processador: ");
			fgets(pc->processador, sizeof(pc->processador), stdin);
			break;
		case COR:
			printf("Nova Cor: ");
			fgets(pc->cor, sizeof(pc->cor), stdin);
			break;
		case RAM:
			printf("Nova Memória RAM (em GB): ");
			scanf("%d", &pc->RAM);
			break;
		case ARMAZENAMENTO:
			printf("Nova Capac. de Armazenamento (em GB): ");
			scanf("%d", &pc->HD);
			break;
		default:
			puts("\aDígito inválido!");
	}
}

void alteracao(void)
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
			fread(&PC, sizeof(Computer), 1, arquivo);

        	if ( feof(arquivo) ) break;

        	if ( PC.ID not_eq index )
            {
				fwrite(&PC, sizeof(Computer), 1, arquivo_temporario);
            }
			else
            {
				alterado(&PC);
				fwrite(&PC, sizeof(Computer), 1, arquivo_temporario);
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
			fread(&PC, sizeof(Computer), 1, arquivo_temporario);

        	if ( feof(arquivo_temporario) ) break;

        	fwrite(&PC, sizeof(Computer), 1, arquivo);
		}

		fclose(arquivo_temporario);
		remove("temporario.xxx");
		puts("Alteração realizada.");
	}
}

void escolher(void)
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

int main(int argc, const char* argv[])
{
	setlocale(LC_ALL, "");

    unsigned int option = 0u;

    escolher();

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
			case SAIR:
				puts("Até mais...");
				break;
			case INSERCAO:
				insercao();
				break;
			case LISTAGEM:
				listagem();
				break;
			case BUSCA:
				busca();
				break;
			case ALTERACAO:
				alteracao();
				break;
			case REMOCAO:
				remocao();
				break;
			case OUTRO_ARQUIVO:
				fclose(arquivo);
				escolher();
				break;
			default:
				puts("\aDígito inválido!");
		}

	if ( option not_eq SAIR ) goto begin;

	return EXIT_SUCCESS;
}