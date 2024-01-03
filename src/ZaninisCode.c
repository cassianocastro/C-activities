#include <iso646.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int main(int argc, char const *argv[])
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