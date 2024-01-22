#include "../../includes/view/CarsView.h"

void showCarForm(Car* const car)
{
    printf("Marca..............: ");
    scanf("%[^\n]s", car->mark);
    getchar();

    printf("Modelo.............: ");
    scanf("%[^\n]s", car->model);
    getchar();

    printf("Cor................: ");
    scanf("%[^\n]s", car->color);
    getchar();

    printf("Placa..............: ");
    scanf("%[^\n]s", car->placa);
    getchar();

    printf("Ano de fabricação..: ");
    scanf("%hu", &car->release);
}

void printCarInfo(const Car* const car)
{
    printf(
        "\nDados do carro\n"
        "\nMarca................: %s"
        "\nModelo...............: %s"
        "\nPlaca................: %s"
        "\nCor..................: %s"
        "\nAno de fabricação....: %d\n",
        car->mark,
        car->model,
        car->placa,
        car->color,
        car->release
    );
}

const unsigned int showMainMenu(void)
{
    unsigned int choice = 0u;

    printf(
        "\nEscolha uma das opções:"
        "\n1. Inserir carro | 2. Exibir modelos"
        "\n3. Excluir carro | 0. Finalizar"
        "\nOpção\? "
    );
	scanf("%d", &choice);
	getchar();

    return choice;
}