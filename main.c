#include <locale.h>
#include <stdlib.h>

#ifdef AGENDA

#include "./src/includes/Agenda.h"

#elif defined COMPUTER

#include "./src/includes/Computer.h"

#elif defined EVALUATION

#include "./src/includes/Evaluation.h"

#elif defined FROTA

#include "./src/includes/Frota.h"

#elif defined LIBRARY

#include "./src/includes/Library.h"

#endif

/**
 *
 */
int main(int argc, const char** argv)
{
	setlocale(LC_ALL, "");

    start();

	return EXIT_SUCCESS;
}