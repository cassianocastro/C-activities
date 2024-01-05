#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <iso646.h>
#include <locale.h>
//OK
typedef enum {
    EXIT, CREATE, DELETE, SHOW
} Options;

typedef struct {
    int value;
    struct element* pointerToNext;
} element;

//Definicao do descritor. Ponteiros que armazezam o inicio e o final da fila
typedef struct {
    struct element* pointerToBeginQueue;
    struct element* pointerToEndQueue;
} descritor;

element* createElement( void ){
    int value = 0;
    printf ("Informe um valor para o novo elemento da fila: ");
    scanf  ("%d", &value);

    element* newElement     = malloc( sizeof(element) );
    newElement->value       = value;
    newElement->pointerToNext = NULL;

    return newElement;
}

bool isEmpty(descritor* desc){
    if ( desc->pointerToBeginQueue == NULL )
        return true;

    return false;
}

void enQueue(descritor* desc, element* newElement){
    if ( isEmpty(desc) ) {
        desc->pointerToBeginQueue = newElement;
        desc->pointerToEndQueue   = newElement;
    }
    else {
        element* lastElement       = desc->pointerToEndQueue;
        lastElement->pointerToNext = newElement;
        desc->pointerToEndQueue    = newElement;
    }
}

void deQueue(descritor* desc){
    if ( not isEmpty(desc) ) {
        element* helper           = desc->pointerToBeginQueue;
        desc->pointerToBeginQueue = helper->pointerToNext;

     //Se o elemento era unico na fila, atualiza o final da fila tamb�m para NULL:
        if ( desc->pointerToBeginQueue == NULL )
            desc->pointerToEndQueue = NULL;

        helper->pointerToNext = NULL;
        printf("Valor do elemento excluído: %d \n", helper->value);
        free(helper);
    } else
        puts("A fila está vazia!");
}

void showQueue(descritor* desc){
    element* firstElement = desc->pointerToBeginQueue;

    if ( firstElement != NULL ){
        element* element = firstElement;
        do {
            printf(" %d ", element->value);
            element = element->pointerToNext;
        } while ( element != NULL );
    }else
        puts("Fila Vazia.");
}

void createMenu( void ){
    printf (
        "\n Operações sobre Filas \n"
        "Selecione a opção desejada: \n"
        "1. Incluir | 2. Excluir | 3. Exibir | 0. Sair\n"
        "Opção: "
    );
}

int main( void ){
    setlocale(LC_ALL, "portuguese-brazilian");
    Options option;

    element* newElement       = NULL;
    descritor* desc           = (descritor*) malloc ( sizeof(descritor) );
    desc->pointerToBeginQueue = NULL;
    desc->pointerToEndQueue   = NULL;

    while ( true ) {
        createMenu();
        scanf ( "%d", &option );
        system("clear");
        switch( option ) {
            case EXIT:
                exit( EXIT_SUCCESS );
                break;
            case CREATE:
                newElement = createElement();
                enQueue(desc, newElement);
                break;
            case DELETE:
                deQueue(desc);
                break;
            case SHOW:
                showQueue(desc);
                break;
            default:
                puts("Opção inválida!");
        }
    }
}
