#include "../includes/view/AgendaView.h"

void showContactForm(byte i)
{
	bool ok = false;

    printf("\nContato nº %hhu\n\n", (i + 1));
	getchar();

    printf("Nome......: ");
	fgets(contacts[i].name, 50, stdin);

    printf("Cidade....: ");
	fgets(contacts[i].city, 20, stdin);

    printf("Telefone..: ");
	fgets(contacts[i].phone, 16, stdin);

    do
    {
		printf("Sexo [M/F]\? ");
		scanf(" %c", &contacts[i].sex);

		contacts[i].sex = tolower(contacts[i].sex);
	} while (
        contacts[i].sex not_eq 'f' and
        contacts[i].sex not_eq 'm'
    );

	while ( true )
    {
        puts("Data de nascimento...");

		printf("Dia: ");
    	scanf("%hhu", &contacts[i].dn.day);

        printf("Mês: ");
    	scanf("%hhu", &contacts[i].dn.month);

        printf("Ano: ");
    	scanf("%hu",  &contacts[i].dn.year);

    	ok = isValid(
            contacts[i].dn.day,
			contacts[i].dn.month,
			contacts[i].dn.year
        );

		if ( not ok )
			puts("Data inválida!!");
		else
			break;
	}

	contacts[i].age = (uint8_t) CURRENT_YEAR - contacts[i].dn.year;
}

void printContact(const Contact* const contact)
{
    printf(
        // "\n\tContato nº %hhu:"
        "\nNome..............: %s"
        "Idade...............: %hhu anos\n"
        "Sexo................: %c\n"
        "Cidade..............: %s"
        "Telefone............: %s"
        "Data de Nascimento..: %hhu/%hhu/%hu",
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
    scanf("%d", &option);

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
	scanf("%d", &option);
	getchar();

    return option;
}

byte getContactID(void)
{
    byte id = 0;

	printf("\nID do contato: ");
	scanf("%hhu", &id);

    return --id;
}