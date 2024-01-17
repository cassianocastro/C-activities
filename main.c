#include <locale.h>
#include <stdlib.h>

#ifdef EVALUATION

#include "./src/includes/Evaluation.h"

#elif defined AGENDA

#include "./src/includes/Agenda.h"

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