#include "../../includes/view/PcsView.h"

const byte getComputerID(void)
{
    byte index = 0;

	printf("ID do computador: ");
	scanf("%hhu", &index);

	return --index;
}

void showComputerForm(Computer* const computer)
{
    static unsigned int i = 0u;

    printf("\nComputador nº %hhu\n\n", ++i);
	getchar();

    printf("Marca........: ");
	scanf(" %[^\n]s", computer->mark);

	printf("Modelo.......: ");
    scanf(" %[^\n]s", computer->model);

	printf("Processador..: ");
    scanf(" %[^\n]s", computer->processor);

    do {
		printf(
            "Tipo de Disco Rígido... "
            "Digite \"s\" para SSD ou \"c\" para convencional"
			"\nOpção\? "
        );
		scanf(" %c", &computer->storageType);
	} while (
        computer->storageType not_eq 's' and
        computer->storageType not_eq 'c'
    );

    printf("\nCapacidade de Armazenamento (em GB): ");
	scanf("%d", &computer->storage);

	printf("Tamanho da Memória (em GB).........: ");
	scanf("%d", &computer->memory);
}

void printComputerInfo(byte i, const Computer* const computer)
{
    printf(
        "\nComputador nº %hhu:\n"
        "\nMarca....................: %s"
        "\nModelo...................: %s"
        "\nTipo de HD...............: %c"
        "\nCapac. de Armazenamento..: %d GB"
        "\nMemória..................: %d GB"
        "\nProcessador..............: %s",
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