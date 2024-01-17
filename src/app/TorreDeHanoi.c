#include <stdio.h>
#include <stdlib.h>

/**
 * Move n discos do pino a para o pino b usando o pino c como intermediario
 */
void hanoi(int n, char x, char y, char z)
{
    if ( n == 1 )
        printf("mova disco %d de %c para %c\n", n, x, y);
    else
    {
        hanoi(n - 1, x, z, y); // H1

        printf("mova disco %d de %c para %c\n", n, x, y);

        hanoi(n - 1, z, y, x); // H2
    }
}

/**
 *
 */
int main(int argc, const char** argv)
{
    int numDiscos = 0;

    printf("Digite a quantidade de blocos a mover do pino A para o C: ");
    scanf("%d", &numDiscos);

    hanoi(numDiscos, 'A', 'B', 'C');

    return EXIT_SUCCESS;
}