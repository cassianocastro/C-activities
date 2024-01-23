STD=c99
CC=gcc
LD=gcc
CCFLAGS=-Wall -Wextra -w --ansi -pedantic -std=$(STD)


# TARGET=bin/agenda.exe
# OBJS=bin/main.o bin/agendaModel.o bin/agendaController.o bin/agendaView.o bin/pip.o
# LDFLAGS=-D=AGENDA

# all: $(OBJS)
# 	$(LD) $(LDFLAGS) $(OBJS) -o $(TARGET)

# ./bin/main.o: main.c src/includes/controller/AgendaController.h
# 	$(CC) $(CCFLAGS) -c main.c -o bin/main.o

# ./bin/agendaModel.o: src/app/model/AgendaModel.c src/includes/model/AgendaModel.h
# 	$(CC) $(CCFLAGS) -c src/app/model/AgendaModel.c -o bin/agendaModel.o

# ./bin/agendaController.o: src/app/controller/AgendaController.c src/includes/controller/AgendaController.h
# 	$(CC) $(CCFLAGS) -c src/app/controller/AgendaController.c -o bin/agendaController.o

# ./bin/agendaView.o: src/app/view/AgendaView.c src/includes/view/AgendaView.h
# 	$(CC) $(CCFLAGS) -c src/app/view/AgendaView.c -o bin/agendaView.o

# ./bin/pip.o: src/app/pip.c src/includes/pip.h
# 	$(CC) $(CCFLAGS) -c src/app/pip.c -o bin/pip.o



# TARGET=bin/computer.exe
# OBJS=bin/main.o bin/computerModel.o bin/computerController.o bin/computerView.o
# LDFLAGS=-D=COMPUTER

# all: $(OBJS)
# 	$(LD) $(LDFLAGS) $(OBJS) -o $(TARGET)

# ./bin/main.o: main.c src/includes/controller/ComputerController.h
# 	$(CC) $(CCFLAGS) -c main.c -o bin/main.o

# ./bin/computerModel.o: src/app/model/ComputerModel.c src/includes/model/ComputerModel.h
# 	$(CC) $(CCFLAGS) -c src/app/model/ComputerModel.c -o bin/computerModel.o

# ./bin/computerController.o: src/app/controller/ComputersController.c src/includes/controller/ComputerController.h
# 	$(CC) $(CCFLAGS) -c src/app/controller/ComputersController.c -o bin/computerController.o

# ./bin/computerView.o: src/app/view/ComputersView.c src/includes/view/ComputerView.h
# 	$(CC) $(CCFLAGS) -c src/app/view/ComputersView.c -o bin/computerView.o



# TARGET=bin/employees.exe
# OBJS=bin/main.o bin/employeeModel.o bin/employeesController.o bin/employeesView.o bin/pip.o
# LDFLAGS=-D=EMPLOYEES

# all: $(OBJS)
# 	$(LD) $(LDFLAGS) $(OBJS) -o $(TARGET)

# ./bin/main.o: main.c src/includes/controller/EmployeesController.h
# 	$(CC) $(CCFLAGS) -c main.c -o bin/main.o

# ./bin/employeeModel.o: src/app/model/EmployeeModel.c src/includes/model/EmployeeModel.h
# 	$(CC) $(CCFLAGS) -c src/app/model/EmployeeModel.c -o bin/employeeModel.o

# ./bin/employeesController.o: src/app/controller/EmployeesController.c src/includes/controller/EmployeesController.h
# 	$(CC) $(CCFLAGS) -c src/app/controller/EmployeesController.c -o bin/employeesController.o

# ./bin/employeesView.o: src/app/view/EmployeesView.c src/includes/view/EmployeesView.h
# 	$(CC) $(CCFLAGS) -c src/app/view/EmployeesView.c -o bin/employeesView.o

# ./bin/pip.o: src/app/pip.c src/includes/pip.h
# 	$(CC) $(CCFLAGS) -c src/app/pip.c -o bin/pip.o



# TARGET=bin/evaluation.exe
# OBJS=bin/main.o bin/evaluationModel.o bin/evaluationController.o bin/evaluationView.o
# LDFLAGS=-D=EVALUATION

# all: $(OBJS)
# 	$(LD) $(LDFLAGS) $(OBJS) -o $(TARGET)

# ./bin/main.o: main.c src/includes/controller/EvaluationsController.h
# 	$(CC) $(CCFLAGS) -c main.c -o bin/main.o

# ./bin/evaluationModel.o: src/app/model/EvaluationModel.c src/includes/model/EvaluationModel.h
# 	$(CC) $(CCFLAGS) -c src/app/model/EvaluationModel.c -o bin/evaluationModel.o

# ./bin/evaluationController.o: src/app/controller/EvaluationsController.c src/includes/controller/EvaluationsController.h
# 	$(CC) $(CCFLAGS) -c src/app/controller/EvaluationsController.c -o bin/evaluationController.o

# ./bin/evaluationView.o: src/app/view/EvaluationsView.c src/includes/view/EvaluationsView.h
# 	$(CC) $(CCFLAGS) -c src/app/view/EvaluationsView.c -o bin/evaluationView.o



# TARGET=bin/cars.exe
# OBJS=bin/main.o bin/car.o bin/carsController.o bin/carsView.o
# LDFLAGS=-D=CARS

# all: $(OBJS)
# 	$(LD) $(LDFLAGS) $(OBJS) -o $(TARGET)

# ./bin/main.o: main.c src/includes/controller/CarsController.h
# 	$(CC) $(CCFLAGS) -c main.c -o bin/main.o

# ./bin/car.o: src/app/model/CarModel.c src/includes/model/CarModel.h
# 	$(CC) $(CCFLAGS) -c src/app/model/CarModel.c -o bin/car.o

# ./bin/carsController.o: src/app/controller/CarsController.c src/includes/controller/CarsController.h
# 	$(CC) $(CCFLAGS) -c src/app/controller/CarsController.c -o bin/carsController.o

# ./bin/carsView.o: src/app/view/CarsView.c src/includes/view/CarsView.h
# 	$(CC) $(CCFLAGS) -c src/app/view/CarsView.c -o bin/carsView.o


# TARGET=bin/library.exe
# OBJS=bin/main.o bin/book.o bin/booksController.o bin/booksView.o
# LDFLAGS=-D=LIBRARY

# all: $(OBJS)
# 	$(LD) $(LDFLAGS) $(OBJS) -o $(TARGET)

# ./bin/main.o: main.c src/includes/controller/BooksController.h
# 	$(CC) $(CCFLAGS) -c main.c -o bin/main.o

# ./bin/book.o: src/app/model/Book.c src/includes/model/Book.h
# 	$(CC) $(CCFLAGS) -c src/app/model/Book.c -o bin/book.o

# ./bin/booksController.o: src/app/controller/BooksController.c src/includes/controller/BooksController.h
# 	$(CC) $(CCFLAGS) -c src/app/controller/BooksController.c -o bin/booksController.o

# ./bin/booksView.o: src/app/view/BooksView.c src/includes/view/BooksView.h
# 	$(CC) $(CCFLAGS) -c src/app/view/BooksView.c -o bin/booksView.o



TARGET=bin/pcs.exe
OBJS=bin/main.o bin/pcs.o bin/pcsController.o bin/pcsView.o
LDFLAGS=-D=PC

all: $(OBJS)
	$(LD) $(LDFLAGS) $(OBJS) -o $(TARGET)

./bin/main.o: main.c src/includes/controller/PcsController.h
	$(CC) $(CCFLAGS) -c main.c -o bin/main.o

./bin/pcs.o: src/app/model/Pcs.c src/includes/model/Pcs.h
	$(CC) $(CCFLAGS) -c src/app/model/Pcs.c -o bin/pcs.o

./bin/pcsController.o: src/app/controller/PcsController.c src/includes/controller/PcsController.h
	$(CC) $(CCFLAGS) -c src/app/controller/PcsController.c -o bin/pcsController.o

./bin/pcsView.o: src/app/view/PcsView.c src/includes/view/PcsView.h
	$(CC) $(CCFLAGS) -c src/app/view/PcsView.c -o bin/pcsView.o



# TARGET=bin/task.exe
# OBJS=bin/main.o bin/task.o
# LDFLAGS=-D=TASK

# all: $(OBJS)
# 	$(LD) $(LDFLAGS) $(OBJS) -o $(TARGET)

# ./bin/main.o: main.c src/includes/Task.h
# 	$(CC) $(CCFLAGS) -c main.c -o bin/main.o

# ./bin/task.o: src/app/Task.c src/includes/Task.h
# 	$(CC) $(CCFLAGS) -c src/app/Task.c -o bin/task.o

#install:
#	@install x /usr/local/bin/x

clean:
	rm -rf bin/*.o