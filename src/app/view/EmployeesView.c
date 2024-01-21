#include "../../includes/view/EmployeesView.h"

Employee showEmployeeForm(void)
{
    bool ok = false;
    Employee employee = createEmployee();

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

    return employee;
}

void printEmployeeInfo(const Employee* const employee)
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
        printf("\nSalário/%s......: R$ %.2f", getMonthName(i + 1), employee->wage[i]);
    }
}

const unsigned int getEmployeeCode(void)
{
    unsigned int code = 0u;

	printf("Código do funcionário: ");
	scanf("%d", &code);

    return code;
}

const unsigned int getMainMenuChoice(void)
{
    unsigned int choice = 0u;

    printf(
        "\n\nEscolha uma opção:"
        "\n1. Inserção | 2. Exibir | 3. Remoção | 4. Valores | 0. Finalizar"
        "\nOpção\? "
    );
    scanf("%i", &choice);
    getchar();

    return choice;
}