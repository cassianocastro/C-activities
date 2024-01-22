#include "../../includes/model/Book.h"

Book createBook(void)
{
    Book book = {
        .title      = "",
        .author     = "",
        .subject    = "",
        .publishing = "",
        .release    = 0
    };

    return book;
}