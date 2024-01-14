#include "./includes/Criptographer.h"

#ifdef CRIPTOGRAPHER_V1

void criptografar(char* frase)
{
    for ( byte i = 0; i < strlen(frase); i++ )
    {
        if ( frase[i] >= 97 and frase[i] <= 122 )
        {
            if ( frase[i] > 116 )
            {
                frase[i] -= 26;
            }

            frase[i] += 6;
        }
    }
}

void descriptografar(char* frase)
{
    for ( byte i = 0; i < strlen(frase); i++ )
    {
        if ( frase[i] >= 97 and frase[i] <= 122 )
        {
            frase[i] -= 6;

            if ( frase[i] < 97 )
            {
                frase[i] += 26;
            }
        }
    }
}

/**
 *
 */
int main(int argc, const char* argv[])
{
    Options opcao;

    char frase[TAMANHO_FRASE];

    do {
        printf("1 - Criptografar | 2 - Descriptografar | 0 - Sair\nOpção\? ");
        scanf("%d", &opcao);
        getchar();

        switch ( opcao )
        {
            case CRIPTOGRAFAR:
                printf("Digite a frase: ");
                gets(frase);
                criptografar(frase);
                printf("Texto criptografado: %s\n", frase);
                break;
            case DESCRIPTOGRAFAR:
                printf("Digite a frase: ");
                gets(frase);
                descriptografar(frase);
                printf("Texto descriptografado: %s\n", frase);
                break;
            case SAIR:
                puts("Saindo...");
                break;
            default:
                puts("Opção Inválida!");
        }
    } while ( opcao not_eq SAIR );

    return EXIT_SUCCESS;
}

#elif CRIPTOGRAPHER_V2

void criptografar(char* frase)
{
    for ( byte i = 0, length = strlen(frase); i < length; i++ )
	{
        if ( frase[i] >= 97 and frase[i] <= 122 )
        {
            if ( frase[i] > 116 )
            {
                frase[i] -= 26;
            }

            frase[i] += 6;
        }
    }
}

void descriptografar(char* frase)
{
    for ( byte i = 0, length = strlen(frase); i < length; i++ )
	{
        if ( frase[i] >= 97 and frase[i] <= 122 )
        {
            frase[i] -= 6;

            if ( frase[i] < 97 )
            {
                frase[i] += 26;
            }
        }
    }
}

/**
 *
 */
int main(int argc, const char* argv[])
{
    Options opcao;

    char frase[TAMANHO_FRASE];

    do {
        printf("1 - Criptografar | 2 - Descriptografar | 0 - Sair\nOpção\? ");
        scanf("%d", &opcao);
        getchar();

        switch ( opcao )
		{
            case CRIPTOGRAFAR:
                printf("Digite a frase: ");
                gets(frase);
                criptografar(frase);
                printf("Texto criptografado: %s\n", frase);
                break;
            case DESCRIPTOGRAFAR:
                printf("Digite a frase: ");
                gets(frase);
                descriptografar(frase);
                printf("Texto descriptografado: %s\n", frase);
                break;
            case SAIR:
                puts("Saindo...");
                break;
            default:
                puts("Opção Inválida!");
        }
    } while ( opcao not_eq SAIR );

    return EXIT_SUCCESS;
}

#elif CRIPTOGRAPHER_ZANINI

void cripto(char* texto)
{
	short int tamanho = strlen(texto), i;

	for ( i = 0; i < tamanho; i++ )
    {
		if ( texto[i] >= 97 and texto[i] <= 116 )
        {
		    if ( texto[i] > 122 )
            {
                texto[i] -= 26;
            }

	    	texto[i] += 6;
	   	}
	}
}

void decripto(char* texto)
{
  	short int tamanho = strlen(texto), i;

	for ( i = 0; i < tamanho; i++ )
    {
	    if ( texto[i] >= 97 and texto[i] <= 122 )
        {
            texto[i] -= 6;

            if ( texto[i] < 97 )
            {
                texto[i] += 26;
            }
		}
	}
}

/**
 *
 */
int main(int argc, const char* argv[])
{
    setlocale(LC_ALL, "");

    char opcao = '0', frase[50];

    while ( opcao not_eq '3' )
    {
        printf("1 - Criptografar\n2 - Descriptografar\n3 - Sair\nOpção\? ");
        scanf(" %c", &opcao);

        switch ( opcao )
        {
            case '1':
                printf("Digite a frase: ");
                gets(frase);

                cripto(frase);

                printf("Texto criptografado: %s\n", frase);
                break;
            case '2':
                printf("Digite a frase: ");
                gets(frase);

                decripto(frase);

                printf("Texto criptografado: %s\n", frase);
                break;
            case '3':
                puts("Saindo...");
                break;
            default:
                puts("Opcao Inválida!");
        }
    }

    return EXIT_SUCCESS;
}

#endif