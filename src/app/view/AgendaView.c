#include "../../includes/view/AgendaView.h"

void showContactForm(Contact* const contact)
{
    static int i = 0;

	bool ok = false;

    printf("\nContato nº %hhu\n\n", ++i);
	getchar();

    printf("Nome......: ");
    scanf(" %50[A-Za-z]s", contact->name);

    printf("Cidade....: ");
    scanf(" %20[A-Za-z]s", contact->city);

    printf("Telefone..: ");
    scanf(" %16[0-9]s", contact->phone);

    do {
		printf("Sexo [M/F]\? ");
		scanf(" %[^\n]c", &contact->sex);

		contact->sex = tolower(contact->sex);
	} while (
        contact->sex not_eq 'f' and
        contact->sex not_eq 'm'
    );

	while ( true )
    {
        puts("Data de nascimento...");

		printf("Dia: ");
    	scanf("%hhu", &contact->dn.day);

        printf("Mês: ");
    	scanf("%hhu", &contact->dn.month);

        printf("Ano: ");
    	scanf("%4hu", &contact->dn.year);

    	ok = isValid(
            contact->dn.day,
			contact->dn.month,
			contact->dn.year
        );

		if ( not ok )
			puts("Data inválida!!");
		else
			break;
	}

    // TODO: Replace int literal by CURRENT_YEAR constant
	contact->age = (uint8_t) 2024 - contact->dn.year;
}

void printContact(const Contact* const contact)
{
    printf(
        // "\n\tContato nº %hhu:"
        "\nNome................: %s"
        "\nIdade...............: %hhu anos"
        "\nSexo................: %c"
        "\nCidade..............: %s"
        "\nTelefone............: %s"
        "\nData de Nascimento..: %hhu/%hhu/%hu",
        // (i + 1),
        contact->name,
        contact->age,
        contact->sex,
        contact->city,
        contact->phone,
        contact->dn.day,
        contact->dn.month,
        contact->dn.year
    );
}

const unsigned int showMainMenu(void)
{
    unsigned int option = 0u;

    printf(
        "\nEscolha uma das opções abaixo:"
        "\n1. Insercão;"
        "\n2. Listagem;"
        "\n3. Alteração;"
        "\n4. Remoção;"
        "\n5. Busca;"
        "\n0. Sair;"
        "\nOpção\? "
    );
    scanf("%1d", &option);

    return option;
}

const unsigned int showUpdateMenu(void)
{
    unsigned int option = 0u;

    printf(
        "\nSelecione o tipo de dado:"
		"\n1. Nome;"
		"\n2. Sexo;"
		"\n3. Data de Nascimento;"
		"\n4. Cidade;"
		"\n5. Telefone;"
		"\nOpção\? "
    );
	scanf("%1d", &option);
	getchar();

    return option;
}

byte getContactID(void)
{
    byte id = 0u;

	printf("\nID do contato: ");
	scanf("%hhu", &id);

    return --id;
}

char getContactSex(void)
{
    char sex = '\0';

    do {
        printf("Novo sexo [M/F]: ");
        scanf(" %[^\n]c", &sex);

        sex = tolower(sex);
    } while ( sex not_eq 'f' and sex not_eq 'm' );

    return sex;
}

BirthDate getContactBirthDate(void)
{
    BirthDate date = { .day = 0, .month = 0, .year = 0 };

    puts("Nova data de nascimento...");

    begin:

    printf("Dia: ");
    scanf("%hhu", &date.day);

    printf("Mês: ");
    scanf("%hhu", &date.month);

    printf("Ano: ");
    scanf("%hu", &date.year);

    if ( not isValid(date.day, date.month, date.year) )
    {
        puts("Data inválida!");

        goto begin;
    }

    return date;
}

void getContactName(char* const str)
{
    printf("Novo nome: ");
    scanf(" %50[A-Za-z]s", str);
}

void getContactPhone(char* const str)
{
    printf("Novo telefone: ");
    scanf(" %16[0-9]s", str);
}

void getContactCity(char* const str)
{
    printf("Nova cidade: ");
    scanf(" %20[A-Za-z]s", str);
}