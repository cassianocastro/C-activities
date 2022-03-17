#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <iso646.h>
#include <stdbool.h>

typedef struct nodo
{
    char info;
    struct nodo* esquerda;
    struct nodo* direita;
} nodo;

nodo* createNodo(char info)
{
    nodo* novo     = malloc( sizeof(nodo) );
    novo->info     = info;
    novo->esquerda = NULL;
    novo->direita  = NULL;
    return novo;
}

//Inclusao de um nodo na Arvore
void insere_folha(nodo** arv, char info)
{
    if ( *arv == NULL ) {
        *arv = createNodo(info);
    } else {
        //se a informacao e menor que a informacao da arvore, insere a esquerda
        if ( info < (*arv)->info ) {
            puts("Inserindo à Esquerda...");
            insere_folha(&(*arv)->esquerda, info);
            //se a informacao e maior que a informacao da arvore, insere a direita
        } else if ( info > (*arv)->info ) {
            puts("Inserindo à Direita...");
            insere_folha(&(*arv)->direita, info);
        }
    }
}

//Caminhamento pre-ordem
void pre_ordem(nodo* arv)
{
    if ( arv != NULL ) {
        printf("%c \n", arv->info);
        if ( arv->esquerda != NULL ) {
            puts("Nodo Esquerdo.");
            pre_ordem(arv->esquerda);
        }
        if ( arv->direita != NULL ) {
            puts("Nodo Direito.");
            pre_ordem(arv->direita);
        }
    }
}

//Caminhamento em-ordem
void em_ordem(nodo* arv)
{
    if ( arv != NULL ) {
        if ( arv->esquerda != NULL ) {
            puts("Nodo Esquerdo.");
            em_ordem(arv->esquerda);
        }
        printf("%c \n", arv->info);
        if ( arv->direita != NULL ) {
            puts("Nodo Direito.");
            em_ordem(arv->direita);
        }
    }
}

//Caminhamento pos-ordem
void pos_ordem(nodo * arv)
{
    if ( arv != NULL ) {
        if ( arv->esquerda != NULL ) {
            puts("Nodo Esquerdo.");
            pos_ordem(arv->esquerda);
        }
        if ( arv->direita != NULL ) {
            puts("Nodo direito.");
            pos_ordem(arv->direita);
        }
        printf("%c\n", arv->info);
    }
}

void pesquisar_nodo(nodo* arv, char pesq)
{
    if ( arv != NULL ) {
        if ( arv->info == pesq ) {
            printf("Nodo encontrado: %c\n", arv->info);
        } else {
            if ( pesq > arv->info ) {
                puts("Pesquisando a direita...");
                pesquisar_nodo(arv->direita, pesq);
            } else {
                puts("Pesquisando a esquerda...");
                pesquisar_nodo(arv->esquerda, pesq);
            }
        }
    } else
        puts("Nodo não encontrado.");
}

void createMenu()
{
    printf(
        "Operações sobre Árvores\n"
        "Selecione a opção desejada:\n"
        "1. Incluir Folha\n"
        "2. Caminhar em Pré-Ordem\n"
        "3. Caminhar em Ordem\n"
        "4. Caminhar em Pós-Ordem\n"
        "5. Pesquisar nodos na Árvore\n"
        "0. Sair\n"
        "Opção? "
    );
}

int main(int argc, char const *argv[])
{
    setlocale(LC_ALL, "");

    int option = 0;
    char info  = '\0';
    nodo* arv  = NULL;

    while ( true )
	{
        createMenu();
        scanf( "%i", &option );
        system( "clear" );
        switch ( option )
		{
            case 1:
                info = '\0';
                while ( info != '@' )
				{
                    printf("Informe a letra a inserir na Árvore (ou @ para sair): ");
                    scanf( " %c", &info );
                    if ( info != '@' ) insere_folha(&arv, info);
                }
                break;
            case 2:
                pre_ordem(arv);
                break;
            case 3:
                em_ordem(arv);
                break;
            case 4:
                pos_ordem(arv);
                break;
            case 5:
                printf("Informe a letra a ser pesquisada na Árvore: ");
                scanf(" %c", &info);
                pesquisar_nodo(arv, info);
                break;
            case 0:
                exit( EXIT_SUCCESS );
                break;
            default:
                puts("Opção inválida!");
        }
    }
    return ( EXIT_SUCCESS );
}