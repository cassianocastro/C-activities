#ifndef EVALUATION_H

#define EVALUATION_H

#include <errno.h>
#include <inttypes.h>
#include <iso646.h>
#include <locale.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 50
#define TAM_PROCESS 20
#define TAM_COR 20

typedef enum
{
	SAIR,
	INSERCAO,
	LISTAGEM,
	BUSCA,
	ALTERACAO,
	REMOCAO,
	OUTRO_ARQUIVO
}
Opcoes;

typedef enum
{
	TIPO = 1,
	TAMANHO_TELA,
	MARCA,
	MODELO,
	PROCESSADOR,
	COR,
	RAM,
	ARMAZENAMENTO
}
Dados;

typedef struct
{
	int ID;
    int RAM;
    int HD;

    float tamanho_tela;

    char tipo;
	char marca[TAM];
	char modelo[TAM];
	char processador[TAM_PROCESS];
	char cor[TAM_COR];
}
Computer;

FILE* arquivo;

char nome_arquivo[TAM];

Computer computer;

/**
 *
 */
void insercao(void);

/**
 *
 */
void listagem(void);

/**
 *
 */
void alteracao(void);

/**
 *
 */
void remocao(void);

/**
 *
 */
void busca(void);

/**
 *
 */
bool ok(int*);

/**
 *
 */
void alterado(Computer*);

/**
 *
 */
void escolher(void);

#endif