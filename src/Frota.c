#include <iso646.h>
#include <locale.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRING_SIZE 20

typedef unsigned char byte;

typedef enum
{
    EXIT,
    CREATE,
    READ,
    DELETE
}
Opcoes;

typedef struct
{
	char model[STRING_SIZE];
	char mark[STRING_SIZE];
	char placa[STRING_SIZE];
	char color[STRING_SIZE];

	unsigned short release;
}
Car;

Car frota[10];

const unsigned int ARRAY_SIZE = 10u;

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

Car createCar(void)
{
    Car car = {
        .color   = "",
        .mark    = "",
        .model   = "",
        .placa   = "",
        .release = 0
    };

	return car;
}

void addCar(void)
{
    for ( register byte i = 0; i < ARRAY_SIZE; ++i )
	{
        if ( frota[i].release == 0 )
        {
            showCarForm(&frota[i]);

            puts("\nCarro incluído.");

            break;
        }
    }
}

void showCars(void)
{
    for ( register byte i = 0; i < ARRAY_SIZE; ++i )
	{
        if ( frota[i].release != 0 )
        {
            printCarInfo(&frota[i]);
        }
    }
}

void deleteCar(void)
{
    char placa[STRING_SIZE];

    printf("Informe a placa do veículo: ");
    scanf("%[^\n]s", placa);
    getchar();

    for ( register byte i = 0; i < ARRAY_SIZE; ++i )
	{
        if ( strcmp(placa, frota[i].placa) == 0 )
        {
            frota[i] = createCar();

            puts("\nCarro excluído.");

            break;
        }
    }
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

/**
 *
 */
int main(int argc, const char* argv[])
{
    setlocale(LC_ALL, "");

	unsigned int option = 0u;

    for ( register byte i = 0; i < ARRAY_SIZE; ++i )
	{
        frota[i] = createCar();
    }

    do {
		option = showMainMenu();

		system("clear");

		switch ( option )
		{
			case CREATE:
                addCar();
				break;
			case READ:
				showCars();
				break;
			case DELETE:
				deleteCar();
				break;
			case EXIT:
				puts("\nFIM.");
				break;
			default:
				puts("Opção inválida!");
		}
	} while ( option not_eq EXIT );

	return EXIT_SUCCESS;
}