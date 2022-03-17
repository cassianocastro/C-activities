#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <iso646.h>

typedef struct No
{
    int idade;
    struct No* prox;
} No;

No* createElement(int idade)
{

    No* novo = (No*) malloc( sizeof(No) );
    novo->idade = idade;
    novo->prox  = NULL;
    return novo;
}

No* setFirst(No* lista, No* novo)
{
    novo->prox = lista;
    return novo;
}

No* setLast(No* lista, No* novo)
{
    if ( lista != NULL ) {
        No* aux = lista;

		while (aux->prox != NULL)
		{
            aux = aux->prox;
        }
        aux->prox = novo;
        return lista;
    }
    return novo;
}

No* delElement(No* lista, int posicao)
{
    No* aux    = lista;
    No* remove = NULL;
    int cont   = 1;

    if (lista == NULL)
        return NULL;

    while ( aux->prox != NULL and cont < (posicao - 1) )
	{
        aux = aux->prox;
        cont++;
    }

    // Se eh a segunda posicao entao so deve atualizar o cont
    if ( posicao == 2 ) cont++;
	/*
		Testa se a remoção é o primeiro da lista.
		Neste caso, existem duas possibilidades: (a) ter mais de um na lista.
		Quando for mais de um, atualizar a lista para o novo primeiro ou
		(b) ser o unico na lista
	*/
    if ( cont == 1 ) {
        if ( aux->prox != NULL )
            lista = aux->prox; // atualiza o inicio.
        else
            lista = NULL;      // caso só exista na lista o proprio a ser removido
        free(aux);
    } else {
        remove = aux->prox;
        aux->prox = remove->prox;
        free(remove);
    }
    return lista;
}

void showList(No* lista)
{
    while ( lista != NULL )
	{
        printf("%.2d | ", lista->idade);
        lista = lista->prox;
    }
    printf("\n");
}

No* setIndex(No* lista, No* novo, int posicao)
{
    No* aux  = lista;
    int cont = 1;

    if ( lista == NULL )
        return novo;

    while ( aux->prox != NULL and cont < (posicao - 1) )
	{
        aux = aux->prox;
        cont++;
    }

    novo->prox = aux->prox;
    aux->prox  = novo;

    if ( posicao == 1 )
        return novo;
    return lista;
}

int main(int argc, char const *argv[])
{
    setlocale(LC_ALL, "");

	No* lista = NULL;
    No* n     = createElement(35);
    No* n2    = createElement(50);
    No* n3    = createElement(30);
    No* n4    = createElement(55);
    No* n5    = createElement(3);

    puts("\nInserindo na última posição da lista os elementos 35 e 50:");
    lista = setLast(lista, n);
    lista = setLast(lista, n2);
    showList(lista);

    puts("\nInserindo 30 como primeiro elemento da lista:");
    lista = setFirst(lista, n3);
    showList(lista);

    puts("\nInserindo 55 como ultimo elemento da lista:");
    lista = setLast(lista, n4);
    showList(lista);

    puts("\nInserindo elemento 3 na posicao 3:");
    lista = setIndex(lista, n5, 3);
    showList(lista);

    puts("\nRemovendo o elemento da posição 1 da lista:");
    lista = delElement(lista, 1);
    showList(lista);

    puts("\nRemovendo o elemento da posição 2 da lista:");
    lista = delElement(lista, 2);
    showList(lista);

    puts("\nRemovendo o elemento da posição 3 da lista:");
    lista = delElement(lista, 3);
    showList(lista);

    return ( EXIT_SUCCESS );
}