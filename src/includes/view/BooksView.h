#ifndef BOOKS_VIEW_H

#define BOOKS_VIEW_H

#include <iso646.h>
#include <stdbool.h>

#include "../model/Book.h"

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

#endif