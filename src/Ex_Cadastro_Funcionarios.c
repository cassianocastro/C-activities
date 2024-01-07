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

	BirthDate birthDate;
}
employees[SIZE_employees];

void init(void)
{
    for ( byte i = 0; i < SIZE_employees; i++ )
	{
        strcpy(employees[i].name, "");
        strcpy(employees[i].address, "");
        strcpy(employees[i].cpf, "");

        employees[i].birthDate.day   = 0;
        employees[i].birthDate.month = 0;
        employees[i].birthDate.year  = 0;
        employees[i].code            = 0;
        employees[i].sum             = 0.0f;

        for ( byte month = 0; month < MONTHS; month++ )
		{
            employees[i].wage[month] = 0.0f;
        }
    }
}

void addEmployee(void)
{
	bool found = false, ok = false;

	for ( byte i = 0; i < SIZE_employees; i++ )
	{
		if ( employees[i].birthDate.day == 0 )
        {
			printf("Nome do funcionário: ");
			gets(employees[i].name);

        	printf("CPF: ");
			gets(employees[i].cpf);

        	do {
                puts("Data de nascimento...");

				printf("Dia: ");
				scanf("%d", &employees[i].birthDate.day);

                printf("Mês: ");
				scanf("%d", &employees[i].birthDate.month);

                printf("Ano: ");
				scanf("%d", &employees[i].birthDate.year);

				ok = isValid(
                    employees[i].birthDate.day,
                    employees[i].birthDate.month,
                    employees[i].birthDate.year
                );

				if ( not ok )
                {
                    puts("**Data Inválida!");
                }
			} while ( not ok );

			getchar();

			printf("Endereço: ");
			gets(employees[i].address);

			printf("Código (somente números): ");
			scanf("%d", &employees[i].code);

            getchar();

            found = true;

            break;
		}
	}

	if ( not found )
        puts("Lista cheia.");
    else
        puts("Funcionário incluído.");
}

void showEmployees(void)
{
    bool wasFound = false;

    for ( byte i = 0; i < SIZE_employees; i++ )
	{
        if ( employees[i].birthDate.day == 0 ) continue;

        printf(
            "\n\nFuncionário nº %d:"
            "\nNome...................: %s"
            "\nCPF....................: %s"
            "\nData de Nascimento.....: %d/%.2d/%d"
            "\nEndereço...............: %s\n"
            "\nRenda Anual............: R$ %.2f\n",
            employees[i].code,
            employees[i].name,
            employees[i].cpf,
            employees[i].birthDate.day,
            employees[i].birthDate.month,
            employees[i].birthDate.year,
            employees[i].address,
            employees[i].sum
        );

        for ( byte month = 0; month < MONTHS; month++ )
		{
            printf(
                "\nSalário/%s......: R$ %.2f",
                nameOfThis(month + 1),
                employees[i].wage[month]
            );
        }

        wasFound = true;
    }

    if ( not wasFound )
    {
        puts("Sem funcionários cadastrados!");
    }
}

void removeEmployee(void)
{
	int code = 0;
	bool wasFound = false;

	printf("Código do funcionário: ");
	scanf("%d", &code);

	for ( byte i = 0; i < SIZE_employees; i++ )
	{
		if ( code == employees[i].code )
        {
			strcpy(employees[i].name, "");
			strcpy(employees[i].address, "");
			strcpy(employees[i].cpf, "");

			employees[i].birthDate.day   = 0;
			employees[i].birthDate.month = 0;
			employees[i].birthDate.year  = 0;
			employees[i].code            = 0;
			employees[i].sum             = 0.0f;

			for ( byte month = 0; month < MONTHS; month++ )
			{
				employees[i].wage[month] = 0.0f;
			}

			wasFound = true;

			break;
		}
	}

	if ( not wasFound )
        puts("Funcionário não encontrado.");
    else
        puts("Funcionário excluído.");
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

    unsigned int option = 0;

    init();

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