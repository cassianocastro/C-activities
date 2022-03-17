#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
#include <iso646.h>

#define TAMANHO_FRASE 100

typedef unsigned int byte;

typedef enum
{
    SAIR,
    CRIPTOGRAFAR,
    DESCRIPTOGRAFAR
} Options;

void criptografar( char* frase )
{

    for ( byte i = 0, length = strlen( frase ); i < length; i++ )
	{
        if ( frase[i] >= 97 and frase[i] <= 122 ) {
            if ( frase[i] > 116 )
                frase[i] -= 26;
            frase[i] += 6;
        }
    }
}

void descriptografar( char* frase )
{
    for ( byte i = 0, length = strlen( frase ); i < length; i++ )
	{
        if ( frase[i] >= 97 and frase[i] <= 122 ) {
            frase[i] -= 6;
            if ( frase[i] < 97 )
                frase[i] += 26;
        }
    }
}

int main( void )
{
    Options opcao;
    char frase[TAMANHO_FRASE];
    do {
        printf(
            "1 - Criptografar | 2 - Descriptografar | 0 - Sair\
            \nOpção? "
        );
        scanf ( "%d", &opcao );
        getchar();
        switch ( opcao )
		{
            case CRIPTOGRAFAR:
                printf("Digite a frase: ");
                gets  ( frase );
                criptografar ( frase );
                printf("Texto criptografado: %s\n", frase);
                break;
            case DESCRIPTOGRAFAR:
                printf("Digite a frase: ");
                gets  ( frase );
                descriptografar ( frase );
                printf("Texto descriptografado: %s\n", frase);
                break;
            case SAIR:
                puts ("Saindo...");
                break;
            default:
                puts ("Opção Inválida!");
        }
    } while ( opcao not_eq SAIR );
    return ( EXIT_SUCCESS );
}