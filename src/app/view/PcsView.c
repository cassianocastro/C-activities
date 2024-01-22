#include "../../includes/view/PcsView.h"

const byte getComputerID(void)
{
    byte index = 0;

	printf("ID do computador: ");
	scanf("%hhu", &index);

	return --index;
}

void showComputerForm(byte i)
{
    printf("\nComputador nº %hhu\n\n", (i + 1));
	getchar();

    printf("Marca........: ");
	fgets(inventary[i].mark, MAX_SIZE_STR, stdin);

	printf("Modelo.......: ");
	fgets(inventary[i].model, MAX_SIZE_STR, stdin);

	printf("Processador..: ");
	fgets(inventary[i].processor, MAX_SIZE_STR, stdin);

    do {
		printf(
            "\nTipo de Disco Rígido..."
			"\nDigite \"s\" para SSD ou \"c\" para convencional: "
        );
		scanf(" %c", &inventary[i].storageType);
	} while (
        inventary[i].storageType not_eq 's' and
        inventary[i].storageType not_eq 'c'
    );

    printf("\nCapacidade de Armazenamento (em GB): ");
	scanf("%d", &inventary[i].storage);

	printf("Tamanho da Memória (em GB).........: ");
	scanf("%d", &inventary[i].memory);
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