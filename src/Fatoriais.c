#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <iso646.h>
//OK
int recursive( int number ) {

    if (( number == 1 ) or ( number == 0 ))
        return 1;
    return number * recursive( number - 1 );
}

int iterative( int number ){
    int fatorial = 1;
    for ( ; number > 1; number--) {
        fatorial *= number;
    }
    return fatorial;
}

int main( void ){
    unsigned int number = 0, option = 0;

    printf("Insira um número para o qual deseja calcular seu fatorial: ");
    scanf ( "%i", &number );
    printf(
        "Selecione a forma de calcular:\n"
        "1. Iterativa | 2. Recursiva\n"
        "Opção? "
    );
    scanf ( "%i", &option );

    printf(
        "\nFatorial calculado: %d\n",
        ( option == 1 ) ? iterative( number ) : recursive( number )
    );
    return ( EXIT_SUCCESS );
}
