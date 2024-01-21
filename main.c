#include <locale.h>
#include <stdlib.h>

#ifdef AGENDA

#include "./src/includes/controller/AgendaController.h"

#elif defined COMPUTER

#include "./src/includes/controller/ComputerController.h"

#elif defined EVALUATION

#include "./src/includes/Evaluation.h"

#elif defined EMPLOYEES

#include "./src/includes/Employees.h"

#elif defined FROTA

#include "./src/includes/Frota.h"

#elif defined LIBRARY

#include "./src/includes/Library.h"

#elif defined PC

#include "./src/includes/pcs.h"

#elif defined TASK

#include "./src/includes/Task.h"

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