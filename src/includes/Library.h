#ifndef LIBRARY_H

#define LIBRARY_H

#include <ctype.h>
#include <iso646.h>
#include <locale.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANHO 50

typedef unsigned char byte;

typedef enum
{
    EXIT,
    CREATE,
    READ,
    DELETE,
    SEARCH
}
Options;

typedef struct
{
	char title[TAMANHO];
	char author[TAMANHO];
	char publishing[TAMANHO];
	char subject[TAMANHO];

	unsigned short release;
}
Book;

extern Book library[];

/**
 *
 */
void addBook(void);

/**
 *
 */
void showBooks(void);

/**
 *
 */
void deleteBook(void);

/**
 *
 */
void searchBook(void);

/**
 *
 */
Book* findBookByTitle(void);

/**
 *
 */
Book* findBookByAuthor(void);

/**
 *
 */
Book* findBookByPublishingCiA(void);

/**
 *
 */
Book createBook(void);

/**
 *
 */
void printBookInfo(int, const Book* const);

/**
 *
 */
bool responseIsValid(char);

/**
 *
 */
char askUser(void);

/**
 *
 */
Book showBooksForm(void);

/**
 *
 */
const unsigned int showSearchMenu(void);

/**
 *
 */
const unsigned int showMainMenu(void);

/**
 *
 */
void start(void);

#endif