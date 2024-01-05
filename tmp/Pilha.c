#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <iso646.h>
#include <locale.h>

typedef enum
{
    EXIT, PUSH, POP, SHOWSTACK
} Options;

typedef struct
{
    int valor;
    struct element* anterior;
} element;

element* createElement( element* topo, int valor )
{
    element* novo  = malloc( sizeof(element) );
    novo->valor    = valor;
    novo->anterior = NULL;
    return novo;
}

// Inserir elementos na pilha
element* push( element* topo, int valor )
{
    element* aux = topo;
    topo = createElement(topo, valor);
    topo->anterior = aux;
    return topo;
}

bool isEmpty(element* topo)
{
    return topo == NULL;
}

element* pop( element* topo )
{
    if ( not isEmpty(topo) ) {
        element* aux = topo;
        topo = topo->anterior;
        free(aux);
    } else
        puts("A pilha está vazia!");
    return topo;
}

void showStack( element* topo )
{
    bool isFirst = true;

    while ( topo != NULL )
	{
        puts("  ---");

	    if ( isFirst ) {
            printf("  |%d| <---- Topo \n", topo->valor);
            isFirst = false;
        } else
            printf("  |%d|\n", topo->valor);

        if (topo->anterior == NULL)
            puts("  ---");

        topo = topo->anterior;
    }
}

void createMenu( void )
{
    printf(
        "Operações sobre Pilhas\n"
        "Selecione a opção desejada:\n"
        "1.Incluir | 2.Excluir | 3.Mostrar Pilha | 0.Sair\n"
        "Opção? "
    );
}

int main(int argc, char const *argv[])
{
	setlocale(LC_ALL, "");

	Options option;
    int valor = 0;
    element* topo     = NULL;
    element* excluido = NULL;

    while ( true )
	{
        createMenu();
        scanf ( "%d", &option );
        system( "clear" );
        switch( option )
		{
            case PUSH:
                printf("Informe um valor para o novo elemento da pilha: ");
                scanf ("%d", &valor);
                topo = push(topo, valor);
                break;
            case POP:
                topo = pop(topo);
                break;
            case SHOWSTACK:
                (not isEmpty( topo )) ? showStack(topo) : puts("Pilha Vazia.");
                break;
            case EXIT:
                exit( EXIT_SUCCESS );
                break;
            default:
                puts("Opção inválida.");
        }
    }
}