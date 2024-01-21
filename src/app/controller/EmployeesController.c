#include "../../includes/controller/EmployeesController.h"

Employee employees[ARRAY_SIZE];

void start(void)
{
    for ( register byte i = 0; i < ARRAY_SIZE; ++i )
	{
        employees[i] = createEmployee();
    }

    unsigned int option = 0u;

	do {
		option = getMainMenuChoice();

		system("clear");

		switch ( option )
		{
			case CREATE:
				addEmployee();
				break;
			case READ:
				showEmployees();
				break;
			case DELETE:
				removeEmployee();
				break;
            case VALUES:
				wages();
				break;
			case EXIT:
				puts("\nFIM...");
				break;
			default:
				puts("Opção inválida!");
		}
	} while ( option not_eq EXIT );
}

void addEmployee(void)
{
	bool found = false;

	for ( register byte i = 0; i < ARRAY_SIZE; ++i )
	{
		if ( employees[i].bd.day == 0 )
        {
            employees[i] = showEmployeeForm();

            found = true;

            break;
		}
	}

    puts(not found ? "Lista cheia." : "Funcionário incluído.");
}

void showEmployees(void)
{
    bool found = false;

    for ( register byte i = 0; i < ARRAY_SIZE; ++i )
	{
        if ( employees[i].bd.day == 0 ) continue;

        printEmployeeInfo(&employees[i]);

        found = true;
    }

    if ( not found )
    {
        puts("Sem funcionários cadastrados!");
    }
}

void removeEmployee(void)
{
	unsigned int code = getEmployeeCode();

	bool found = false;

	for ( register byte i = 0; i < ARRAY_SIZE; ++i )
	{
		if ( code == employees[i].code )
        {
			employees[i] = createEmployee();

			found = true;

			break;
		}
	}

    printf("Funcionário %s.", not found ? "não encontrado" : "excluído");
}

void wages(void)
{
	char response = '\0';
	bool found = false;
	byte code  = getEmployeeCode();

	for ( byte i = 0; i < ARRAY_SIZE; i++ )
	{
		if ( code == employees[i].code )
        {
            printf("\nDeseja realizar a inserção de todos os salários [s/n]\? ");
            scanf(" %c", &response);

            if ( verifyResponse(response) == 's')
                insertAllWages(i);
            else
                insertWage(i);

            puts("Inserção de valor(es) realizada.");

            found = true;

            break;
		}
	}

	if ( not found )
    {
        puts("Código inválido.");
    }
}

void insertWage(int i)
{
    byte number   = 0;
    char response = '\0';

    do {
        printf("\nDigite o nº do mês na qual deseja inserir o salário.(Ex.: Abril = 4): ");
        scanf("%hhi", &number);

        for ( byte month = 0; month < MONTHS; month++ )
		{
            if ( ( number - 1 ) == month )
            {
                employees[i].sum -= employees[i].wage[month];

                printf("Digite o valor: R$ ");
                scanf("%f", &employees[i].wage[month]);

                employees[i].sum += employees[i].wage[month];

                break;
            }
        }

        printf("\nDeseja inserir outro valor [s/n]\? ");
        scanf(" %c", &response);

    } while ( response == 's' );
}

void insertAllWages(int i)
{
    employees[i].sum = 0.0f;

    for ( byte month = 0; month < MONTHS; month++ )
	{
        printf("Salário/%s: R$ ", getMonthName(month + 1));
        scanf("%f", &employees[i].wage[month]);

        employees[i].sum += employees[i].wage[month];
    }
}