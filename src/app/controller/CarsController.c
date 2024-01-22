#include "../../includes/controller/CarsController.h"

Car frota[10];

const unsigned int ARRAY_SIZE = 10u;

void start(void)
{
    for ( register byte i = 0; i < ARRAY_SIZE; ++i )
	{
        frota[i] = createCar();
    }

    unsigned int option = 0u;

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
				puts("\nFim.");
				break;
			default:
				puts("Opção inválida!");
		}
	} while ( option not_eq EXIT );
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