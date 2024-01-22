#include "../../includes/view/EvaluationsView.h"

void showComputerForm(unsigned short int i)
{
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
        computer.ID = getComputerID();

        if ( ok(computer.ID) )
            puts("\nID já utilizado!");
        else
            break;
    }
}

void printComputer(const Computer* const computer)
{
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
        computer->ID,
        computer->mark,
        computer->model,
        computer->processor,
        computer->color,
        computer->screen,
        computer->memory,
        computer->storage,
        computer->type
    );
}

unsigned int getComputerID(void)
{
    unsigned int id = 0u;

    printf("ID do computador: ");
	scanf("%d", &id);

    return id;
}

const unsigned int getMainMenuChoice(void)
{
    unsigned int choice = 0u;

    printf(
        "\nEscolha uma das opções abaixo:"
        "\n1. Inserir de novos computadores;"
        "\n2. Exibir computadores;"
        "\n3. Buscar PC;"
        "\n4. Alterar dados;"
        "\n5. Remover cadastro;"
        "\n6. Escolher outro arquivo;"
        "\n0. Sair;"
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
        "Escolha o dado que deseja alterar:"
        "\n1. Tipo;"
        "\n2. Tamanho da Tela;"
        "\n3. Marca;"
        "\n4. Modelo;"
        "\n5. Processador;"
        "\n6. Cor;"
        "\n7. Memória RAM (em GB);"
        "\n8. Capac. de Armazenamento (em GB);"
        "\nOpção\? "
    );
	scanf("%d", &choice);
	getchar();

    return choice;
}