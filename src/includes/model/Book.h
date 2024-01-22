#ifndef BOOK_MODEL_H

#define BOOK_MODEL_H

#define TAMANHO 50

typedef unsigned char byte;

/**
 *
 */
typedef struct
{
	char title[TAMANHO];
	char author[TAMANHO];
	char publishing[TAMANHO];
	char subject[TAMANHO];

	unsigned short release;
}
Book;

/**
 *
 */
Book createBook(void);

#endif