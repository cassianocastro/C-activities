#include "../../includes/view/BooksView.h"

Book showBooksForm(void)
{
    Book book = {};

    printf("Nome do autor.......: ");
    scanf(" %[^\n]s", book.author);

    printf("Título do livro.....: ");
    scanf(" %[^\n]s", book.title);

    printf("Assunto.............: ");
    scanf(" %[^\n]s", book.subject);

    printf("Editora.............: ");
    scanf(" %[^\n]s", book.publishing);

    printf("Ano de lançamento...: ");
    scanf("%hd", &book.release);

    return book;
}

void printBookInfo(int i, const Book* const book)
{
    printf(
        "\nLivro nº %d do acervo......:"
        "\nTítulo....................: %s"
        "\nAutor.....................: %s"
        "\nEditora...................: %s"
        "\nAssunto...................: %s"
        "\nAno de lançamento.........: %d"
        "\n----------\n",
        i,
        book->title,
        book->author,
        book->publishing,
        book->subject,
        book->release
    );
}

const unsigned int showSearchMenu(void)
{
    byte choice = 0u;

    printf(
        "\nSelecione o tipo de busca:"
        "\n1. Por título | 2. Por Autor | 3. Por Editora"
        "\nOpção\? "
    );
    scanf("%1hhd", &choice);
    getchar();

    return choice;
}

const unsigned int showMainMenu(void)
{
    unsigned int choice = 0u;

    printf(
        "\nEscolha uma das opções:"
        "\n1. Inserir livro | 2. Exibir acervo"
        "\n3. Excluir livro | 4. Pesquisar"
        "\n0. Sair"
        "\nOpção\? "
    );
    scanf("%1d", &choice);
    getchar();

    return choice;
}

bool responseIsValid(char response)
{
    response = tolower(response);

    return response == 's' or response == 'n';
}

char askUser(void)
{
    char response = '\0';

    printf("\nDeseja voltar ao menu principal[s/n]\? ");
    scanf(" %c", &response);

    while ( not responseIsValid(response) )
	{
        printf("\nResposta inválida. Digite novamente: ");
        scanf(" %c", &response);
    }

    return response;
}