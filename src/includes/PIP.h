#include <ctype.h>
#include <iso646.h>
#include <locale.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char byte;

enum Meses
{
    JANEIRO = 1,
    FEVEREIRO,
    MARCO,
    ABRIL,
    MAIO,
    JUNHO,
    JULHO,
    AGOSTO,
    SETEMBRO,
    OUTUBRO,
    NOVEMBRO,
    DEZEMBRO
};

int geraPar(int limite)
{
    int n = rand() % limite;

    if ( n % 2 == 0 )
    {
        return n;
    }

    return (n + 1);
}

int geraImpar(int limite)
{
    int n = rand() % limite;

    if ( n % 2 != 0 )
    {
        return n;
    }

    return (n - 1);
}

int geraprimo(int limite)
{
    int num, x, cd;

    do {
        cd  = 0;
        num = rand() % limite;

        for ( x = 1; x <= num; x++ )
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
		case FEVEREIRO:
			if ( ano % 4 == 0 and ano % 100 != 0 or ano % 400 == 0 )
            {
				return dia > 0 and dia <= 29;
            }
			else if ( dia <= 28 and dia > 0 )
            {
                return true;
            }

			return false;
		case JANEIRO:
		case MARCO:
		case MAIO:
		case JULHO:
		case AGOSTO:
		case OUTUBRO:
		case DEZEMBRO:
			return dia >= 1 and dia <= 31;
		case ABRIL:
		case JUNHO:
		case SETEMBRO:
		case NOVEMBRO:
			return dia >= 1 and dia <= 30;
		default:
			return false;
	}
}

char* nameOfThis(byte month)
{
	switch ( month )
    {
		case JANEIRO:    return "Janeiro..";
		case FEVEREIRO:  return "Fevereiro";
		case MARCO:      return "Março....";
		case ABRIL:      return "Abril....";
		case MAIO:       return "Maio.....";
		case JUNHO:      return "Junho....";
		case JULHO:      return "Julho....";
		case AGOSTO:	 return "Agosto...";
		case SETEMBRO:	 return "Setembro.";
		case OUTUBRO:	 return "Outubro..";
		case NOVEMBRO:   return "Novembro.";
		case DEZEMBRO:   return "Dezembro.";
	}

	return NULL;
}