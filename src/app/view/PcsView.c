#include "../../includes/view/PcsView.h"

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

void showComputerForm(Computer* const computer)
{
    static unsigned int i = 0u;

    printf("\nComputador nº %hhu\n\n", ++i);
	getchar();

    getComputerMark(computer->mark);

    getComputerModel(computer->model);

    getComputerProcessor(computer->processor);

    computer->storageType = getComputerStorageType();

    computer->storage     = getComputerStorage();

    computer->memory      = getComputerMemory();
}

const byte getComputerID(void)
{
    byte index = 0;

	printf("ID do computador: ");
	scanf("%hhu", &index);

	return --index;
}

void getComputerMark(char* const str)
{
    printf("Mark.....................................: ");
	scanf(" %[^\n]s", str);
}

void getComputerModel(char* const str)
{
    printf("Model....................................: ");
	scanf(" %[^\n]s", str);
}

void getComputerProcessor(char* const str)
{
    printf("Processor................................: ");
	scanf(" %[^\n]s", str);
}

unsigned int getComputerMemory(void)
{
    unsigned int memory = 0u;

    printf("Memória (em GB)..........................: ");
	scanf("%d", &memory);

    return memory;
}

unsigned int getComputerStorage(void)
{
    unsigned int storage = 0u;

    printf("Capacidade de armazenamento (em GB)......: ");
	scanf("%d", &storage);

    return storage;
}

char getComputerStorageType(void)
{
    char type = '\0';

    begin:

    printf(
        "Tipo de Disco Rígido... "
        "Digite \"s\" para SSD ou \"c\" para convencional"
        "\nOpção\? "
    );
    scanf(" %c", &type);

    type = tolower(type);

	if ( type not_eq 's' and type not_eq 'c' )
    {
        goto begin;
    }

    return type;
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