#include <iso646.h>
#include <inttypes.h>
#include <locale.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./includes/PIP.h"

#define SIZE_employees 10
#define SIZE 50
#define MONTHS 12

typedef unsigned char byte;

typedef enum
{
    EXIT,
    CREATE,
    READ,
    DELETE,
    VALUES
}
Options;

typedef struct
{
	int day;
    int month;
    int year;
}
BirthDate;

struct employee
{
	char cpf[14];
	char name[SIZE];
	char address[SIZE];

	float wage[MONTHS];
    float sum;
	int code;

	BirthDate bd;
}
employees[SIZE_employees];

struct employee createEmployee(void)
{
    struct employee employee = {
        .name     = "",
        .address  = "",
        .cpf      = "",
        .bd.day   = 0,
        .bd.month = 0,
        .bd.year  = 0,
        .code     = 0,
        .sum      = 0.0f,
        .wage     = { 0.0f }
    };

    return employee;
}

struct employee showEmployeeForm(void)
{
    bool ok = false;
    struct employee employee;

    printf("Nome do funcionário: ");
    gets(employee.name);

    printf("CPF: ");
    gets(employee.cpf);

    do {
        puts("Data de nascimento...");

        printf("Dia: ");
        scanf("%d", &employee.bd.day);

        printf("Mês: ");
        scanf("%d", &employee.bd.month);

        printf("Ano: ");
        scanf("%d", &employee.bd.year);

        ok = isValid(
            employee.bd.day,
            employee.bd.month,
            employee.bd.year
        );

        if ( not ok )
        {
            puts("**Data Inválida!");
        }
    } while ( not ok );

    getchar();

    printf("Endereço: ");
    gets(employee.address);

    printf("Código (somente números): ");
    scanf("%d", &employee.code);

    getchar();

    for ( byte month = 0; month < MONTHS; month++ )
    {
        employee.wage[month] = 0.0f;
    }

    return employee;
}

void printEmployeeInfo(const struct employee* const employee)
{
    printf(
        "\n\nFuncionário nº %d:"
        "\nNome...................: %s"
        "\nCPF....................: %s"
        "\nData de Nascimento.....: %d/%.2d/%d"
        "\nEndereço...............: %s\n"
        "\nRenda Anual............: R$ %.2f\n",
        employee->code,
        employee->name,
        employee->cpf,
        employee->bd.day,
        employee->bd.month,
        employee->bd.year,
        employee->address,
        employee->sum
    );

    for ( register byte i = 0; i < MONTHS; ++i )
    {
        printf("\nSalário/%s......: R$ %.2f", nameOfThis(i + 1), employee->wage[i]);
    }
}

void addEmployee(void)
{
	bool found = false;

	for ( register byte i = 0; i < SIZE_employees; ++i )
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

    for ( register byte i = 0; i < SIZE_employees; ++i )
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
	unsigned int code = 0u;

	printf("Código do funcionário: ");
	scanf("%d", &code);

	bool found = false;

	for ( register byte i = 0; i < SIZE_employees; ++i )
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

void insertAllWages(int i)
{
    employees[i].sum = 0.0f;

    for ( byte month = 0; month < MONTHS; month++ )
	{
        printf("Salário/%s: R$ ", nameOfThis(month + 1));
        scanf("%f", &employees[i].wage[month]);

        employees[i].sum += employees[i].wage[month];
    }
}

void insertWage(int i)
{
    byte number   = 0;
    char response = '\0';

    do
	{
        printf("\nDigite o nº do mês na qual deseja inserir o salário.(Ex.: Abril = 4): ");
        scanf("%i", &number);

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

void wages(void)
{
	char response = '\0';
	bool wasFound = false;
	byte code     = 0;

    printf("\nCódigo do funcionário: ");
    scanf("%i", &code);

	for ( byte i = 0; i < SIZE_employees; i++ )
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

            wasFound = true;

            break;
		}
	}

	if ( not wasFound )
    {
        puts("Código inválido.");
    }
}

/**
 *
 */
int main(int argc, const char* argv[])
{
	setlocale(LC_ALL, "");

    unsigned int option = 0u;

    for ( register byte i = 0; i < SIZE_employees; ++i )
	{
        employees[i] = createEmployee();
    }

	do
	{
		printf(
            "\n\nEscolha uma opção:"
            "\n1. Inserção | 2. Exibir | 3. Remoção | 4. Valores | 0. Finalizar"
            "\nOpção\? "
        );
		scanf("%i", &option);
		getchar();

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

	return EXIT_SUCCESS;
}