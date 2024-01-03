#include <conio.h>
#include <stdio.h>
#include <windows.h>

/**
 * Cores do DOS
 * Descrição: Procedimento para definição de Cores do DOS
 */
enum DOS_COLORS
{
    BLACK, BLUE, GREEN, CYAN, RED, MAGENTA, BROWN,
    LIGHT_GRAY, DARK_GRAY, LIGHT_BLUE, LIGHT_GREEN,
    LIGHT_CYAN, LIGHT_RED, LIGHT_MAGENTA, YELLOW, WHITE
};

/**
 * Cores das letras
 * Descrição: Procedimento para inserir cores de letras no programa
 */
void textcolor(enum DOS_COLORS iColor)
{
    HANDLE hl = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_SCREEN_BUFFER_INFO bufferInfo;

    BOOL b = GetConsoleScreenBufferInfo(hl, &bufferInfo);

    bufferInfo.wAttributes &= 0x00F0;

    SetConsoleTextAttribute(hl, bufferInfo.wAttributes |= iColor);
}

/**
 * Impressão de texto colorido
 */
int main(void)
{
    textcolor(BLUE);
    printf("\nAprovado");

    textcolor(RED);
    printf("\nReprovado");

    getch();

    return 0;
}