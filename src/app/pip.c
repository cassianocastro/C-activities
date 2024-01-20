#include "../includes/pip.h"

int generateEvenNumber(const int limit)
{
    int n = rand() % limit;

    if ( n % 2 == 0 )
    {
        return n;
    }

    return (n + 1);
}

int generateOddNumber(const int limit)
{
    int n = rand() % limit;

    if ( n % 2 != 0 )
    {
        return n;
    }

    return (n - 1);
}

int generatePrimeNumber(const int limit)
{
    int num = 0, cd = 0;

    do {
        cd  = 0;
        num = rand() % limit;

        for ( int x = 1; x <= num; ++x )
        {
            if ( num % x == 0 ) cd++;

            if ( cd > 2 ) break;
        }
    } while ( cd != 2 );

    return num;
}

char verifyResponse(char response)
{
    response = tolower(response);

	while ( response != 's' and response != 'n' )
    {
		printf("\nOpção inválida. Digite novamente: ");
		scanf(" %c", &response);
	}

	return response;
}

bool isValid(int dia, int mes, int ano)
{
	switch ( mes )
    {
		case FEBRUARY:
			if ( ano % 4 == 0 and ano % 100 != 0 or ano % 400 == 0 )
            {
				return dia > 0 and dia <= 29;
            }
			else if ( dia <= 28 and dia > 0 )
            {
                return true;
            }

			return false;
		case JANUARY:
		case MARCH:
		case MAY:
		case JULY:
		case AUGUST:
		case OCTOBER:
		case DECEMBER:
			return dia >= 1 and dia <= 31;
		case APRIL:
		case JUNE:
		case SEPTEMBER:
		case NOVEMBER:
			return dia >= 1 and dia <= 30;
		default:
			return false;
	}
}

const char* getMonthName(byte month)
{
	switch ( month )
    {
		case JANUARY   : return "Janeiro..";
		case FEBRUARY  : return "Fevereiro";
		case MARCH     : return "Março....";
		case APRIL     : return "Abril....";
		case MAY       : return "Maio.....";
		case JUNE      : return "Junho....";
		case JULY      : return "Julho....";
		case AUGUST    : return "Agosto...";
		case SEPTEMBER : return "Setembro.";
		case OCTOBER   : return "Outubro..";
		case NOVEMBER  : return "Novembro.";
		case DECEMBER  : return "Dezembro.";
	}

	return NULL;
}