#include "../../includes/view/AgendaView.h"

const unsigned int showMainMenu(void)
{
    unsigned int option = 0u;

    printf(
        "\nChoose one of the options below:"
        "\n1. Add"
        "\n2. Show"
        "\n3. Update"
        "\n4. Delete"
        "\n5. Search"
        "\n0. Exit"
        "\nOption\? "
    );
    scanf("%1d", &option);

    return option;
}

const unsigned int showUpdateMenu(void)
{
    unsigned int option = 0u;

    printf(
        "\nSelect the data type:"
		"\n1. Name"
		"\n2. Sex"
		"\n3. Birthdate"
		"\n4. City"
		"\n5. Phone"
		"\nOption\? "
    );
	scanf("%1d", &option);
	getchar();

    return option;
}

void showContactForm(Contact* const contact)
{
    static int i = 0;

    printf("\nContact nº %hhu\n\n", ++i);
	getchar();

    getContactName(contact->name);

    getContactCity(contact->city);

    getContactPhone(contact->phone);

    contact->sex = getContactSex();

    contact->dn  = getContactBirthDate();

	contact->age = CURRENT_YEAR - contact->dn.year;
}

byte getContactID(void)
{
    byte id = 0u;

	printf("\nContact ID: ");
	scanf("%hhu", &id);

    return --id;
}

void getContactName(char* const str)
{
    printf("Name: ");
    scanf(" %50[A-Za-z]s", str);
}

void getContactPhone(char* const str)
{
    printf("Phone: ");
    scanf(" %16[0-9]s", str);
}

void getContactCity(char* const str)
{
    printf("City: ");
    scanf(" %20[A-Za-z]s", str);
}

char getContactSex(void)
{
    char sex = '\0';

    do {
        printf("Sex [m/f]: ");
        scanf(" %[^\n]c", &sex);

        sex = tolower(sex);
    } while ( sex not_eq 'f' and sex not_eq 'm' );

    return sex;
}

BirthDate getContactBirthDate(void)
{
    BirthDate date = { .day = 0, .month = 0, .year = 0 };

    puts("Birthdate...");

    begin:

    printf("Day: ");
    scanf("%hhu", &date.day);

    printf("Month: ");
    scanf("%hhu", &date.month);

    printf("Year: ");
    scanf("%hu", &date.year);

    if ( not isValid(date.day, date.month, date.year) )
    {
        puts("Invalid date!");

        goto begin;
    }

    return date;
}

void printContact(const Contact* const contact)
{
    printf(
        // "\n\tContact nº %hhu:"
        "\nName..........: %s"
        "\nAge...........: %hhu years old"
        "\nSex...........: %c"
        "\nCity..........: %s"
        "\nPhone.........: %s"
        "\nBirthdate.....: %hhu/%hhu/%hu",
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