#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <iso646.h>
#include <locale.h>
//OK
typedef struct No{
    int idade;
    struct No* proximo;
    struct No* anterior;
} No;

No* createElement(int age) {
    No* newElement;
    newElement = (No*) malloc( sizeof(No) );
    newElement->idade    = age;
    newElement->proximo  = NULL;
    newElement->anterior = NULL;

    printf("Novo elemento: %d\n", newElement->idade);
    return newElement;
}
//Funcao abaixo insere no inicio da lista
No* setFirst(No* list, No* novo) {
    if (list != NULL) {
        list->anterior = novo;
        novo->proximo  = list;
    }
    return novo;
}

No* getLastElement(No* list) {
    while (list->proximo != NULL) {
        list = list->proximo;
    }
    return list;
}

No* setLast(No* list, No* novo){
    if (list != NULL) {
        No* last = getLastElement(list);
        last->proximo  = novo;
        novo->anterior = last;
        return list;
    }
    return novo;
}

void showList(No* list){
    if (list != NULL){
        for (int i = 0; list != NULL; i++) {
            printf("\nIdade do elemento %d: %d", i, list->idade);
            list = list->proximo;
        }
    }else
        puts("Lista vazia.");
}

void showReversed(No* lista) {
    No* ultimo = getLastElement(lista);

    for (int i = 0; ultimo != NULL; i++) {
        printf("\nIdade do elemento %d: %d", i, ultimo->idade);
        ultimo = ultimo->anterior;
    }
}

No* removeElement(No* lista, int posicao) {
    if (lista != NULL) {
        No* auxiliar = lista;
        //exclusao lista
        if (posicao == 1) {
            lista = lista->proximo;
            //Se nao for o ultimo elemento da lista
            if (lista != NULL) {
                lista->anterior = NULL;
            }
        } else {
            for (int i = 1; auxiliar != NULL && i < posicao; i++) {
                auxiliar = auxiliar->proximo;
            }

            if (auxiliar == NULL) {
                printf("A lista nao tem %d elementos \n", posicao);
                return lista;
            }
            auxiliar
                ->anterior
                ->proximo = auxiliar->proximo;
            //exclusão do último não necessita atualizar a referencia de um elemento posterior
            if (auxiliar->proximo != NULL) {
                auxiliar
                    ->proximo
                    ->anterior = auxiliar->anterior;
            }
        }
        free( auxiliar );
    } else
        puts("A lista está vazia!");
    return lista;
}

No* add(No* list, No* novo, int posicao) {
    No* auxiliar = list;
    //Inclusão no inicio
    if (list == NULL || posicao == 1) {
        list = setFirst(list, novo);
    }
    else {
        for (int i = 1; auxiliar->proximo != NULL && i < posicao; i++) {
            auxiliar = auxiliar->proximo;
        }

        if (auxiliar->proximo != NULL) {
            //inclusão em outro ponto
            auxiliar
                ->anterior
                ->proximo  = novo;
            novo->proximo  = auxiliar;
            novo->anterior = auxiliar->anterior;
            auxiliar->anterior = novo;
        } else
            //Inclusão no último
            setLast(list, novo);
    }
    return list;
}

int main( void ){
    setlocale(LC_ALL, "portuguese-brazilian");
    // Criando referencia para a lista
    No* list = NULL;

    // criar um lista apontada por n com o primerio elemento
    No* n  = createElement(35);
    No* n2 = createElement(50);
    No* n3 = createElement(30);
    No* n4 = createElement(55);
    No* n5 = createElement(3);
    No* n6 = createElement(1);

    puts("Inserindo na última posição da lista os elementos 50, 30 e 55:");
    list = setLast(list, n2);
    list = setLast(list, n3);
    list = setLast(list, n4);
    showList(list);

    puts("\n\nInserindo 3 como primeiro elemento da lista:");
    list = setFirst(list, n5);
    showList(list);

    puts("\n\nRemovendo o elemento da posicao 4 da lista:");
    list = removeElement(list, 4);
    showList(list);

    puts("\n\nApresentando a lista em ordem inversa:");
    showReversed(list);

    puts("\n\nInserindo 1 na posicao 2 da lista:");
    list = add(list, n6, 2);
    showList(list);

    puts("\n\nApresentando a lista em ordem inversa:");
    showReversed(list);

    puts("\n\nRemovendo 30...");
    list = removeElement(list, 4);
    showList(list);

    puts("\n\nRemovendo 50...");
    list = removeElement(list, 3);
    showList(list);

    puts("\n\nRemovendo 1...");
    list = removeElement(list, 2);
    showList(list);

    puts("\n\nRemovendo 3...");
    list = removeElement(list, 1);
    showList(list);
}
