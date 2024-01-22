#ifndef BOOKS_CONTROLLER_H

#define BOOKS_CONTROLLER_H

#include <ctype.h>
#include <iso646.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../model/Book.h"
#include "../view/BooksView.h"

/**
 *
 */
typedef enum
{
    EXIT,
    CREATE,
    READ,
    DELETE,
    SEARCH
}
Options;

extern Book library[];

/**
 *
 */
void start(void);

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

#endif