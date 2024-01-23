#include "../../includes/view/ComputersView.h"

Computer showComputerForm(byte i)
{
    Computer computer;

    printf("\nComputador nº %hhu\n", (i + 1));
	getchar();

    printf("Marca....................: ");
    gets(computer.mark);

	printf("Modelo...................: ");
    gets(computer.model);

	printf("Processador..............: ");
    gets(computer.processor);

	printf("Memória (em GB)..........: ");
    scanf("%d", &computer.memory);

    printf("Armazenamento (em GB)....: ");
    scanf("%d", &computer.storage);

	do {
		printf("Tipo de HD...[s/c]\? ");
        scanf(" %c", &computer.storageType);
	} while (
        computer.storageType != 's' and
        computer.storageType != 'c'
    );

    return computer;
}

void printComputerInfo(const byte i, const Computer* const computer)
{
    printf(
        "\nComputador nº %hhu:"
        "\nMarca......................: %s"
        "\nModelo.....................: %s"
        "\nTipo de HD.................: %c"
        "\nCapac. de Armazenamento....: %d GB"
        "\nMemória....................: %d GB"
        "\nProcessador................: %s"
        "\n------------",
        i,
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
        "\nEscolha uma das opções:\n"
        "\n1. Insercão | 2. Listagem | 3. Alteração"
        "\n4. Remoção  | 5. Busca    | 0. Sair"
        "\nOpção\? "
    );
    scanf("%d", &choice);
    getchar();

    return choice;
}

const unsigned int getUpdateMenuChoice(void)
{
    unsigned int choice = 0u;

    printf(
        "\nSelecione o tipo de dado:"
        "\n0 - Marca   | 1 - Tipo de HD | 2 - Capac. de Armazenamento;"
        "\n3 - Memória | 4 - Modelo     | 5 - Processador;"
        "\nOpção\? "
    );
	scanf("%d", &choice);
	getchar();

    return choice;
}

const byte getComputerID(void)
{
    byte id = 0;

	printf("\nInforme o ID do PC: ");
    scanf("%hhu", &id);

	return --id;
}