#include <locale.h>
#include <stdlib.h>

#ifdef AGENDA

#include "./src/includes/controller/AgendaController.h"

#elif defined BOOKS

#include "./src/includes/controller/BooksController.h"

#elif defined CARS

#include "./src/includes/controller/CarsController.h"

#elif defined COMPUTER

#include "./src/includes/controller/ComputerController.h"

#elif defined EMPLOYEES

#include "./src/includes/controller/EmployeesController.h"

#elif defined EVALUATION

#include "./src/includes/controller/EvaluationsController.h"

#elif defined PC

#include "./src/includes/controller/PcsController.h"

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