STD=c99
CC=gcc
LD=gcc
CCFLAGS=-Wall -Wextra -w --ansi -pedantic -std=$(STD)

APP=../src/app
LIB=../src/includes

# TARGET=agenda.exe
# OBJS=main.o model.o controller.o view.o pip.o
# LDFLAGS=-D=AGENDA

# all: $(OBJS)
# 	$(LD) $(LDFLAGS) $(OBJS) -o $(TARGET)

# main.o: ../main.c $(LIB)/controller/AgendaController.h
# 	$(CC) $(CCFLAGS) -c ../main.c -o main.o

# model.o: $(APP)/model/Agenda.c $(LIB)/model/Agenda.h
# 	$(CC) $(CCFLAGS) -c $(APP)/model/Agenda.c -o model.o

# controller.o: $(APP)/controller/AgendaController.c $(LIB)/controller/AgendaController.h
# 	$(CC) $(CCFLAGS) -c $(APP)/controller/AgendaController.c -o controller.o

# view.o: $(APP)/view/AgendaView.c $(LIB)/view/AgendaView.h
# 	$(CC) $(CCFLAGS) -c $(APP)/view/AgendaView.c -o view.o

# pip.o: $(APP)/pip.c $(LIB)/pip.h
# 	$(CC) $(CCFLAGS) -c $(APP)/pip.c -o pip.o



# TARGET=computer.exe
# OBJS=main.o model.o controller.o view.o
# LDFLAGS=-D=COMPUTER

# all: $(OBJS)
# 	$(LD) $(LDFLAGS) $(OBJS) -o $(TARGET)

# main.o: ../main.c $(LIB)/controller/ComputersController.h
# 	$(CC) $(CCFLAGS) -c ../main.c -o main.o

# model.o: $(APP)/model/Computer.c $(LIB)/model/Computer.h
# 	$(CC) $(CCFLAGS) -c $(APP)/model/Computer.c -o model.o

# controller.o: $(APP)/controller/ComputersController.c $(LIB)/controller/ComputersController.h
# 	$(CC) $(CCFLAGS) -c $(APP)/controller/ComputersController.c -o controller.o

# view.o: $(APP)/view/ComputersView.c $(LIB)/view/ComputersView.h
# 	$(CC) $(CCFLAGS) -c $(APP)/view/ComputersView.c -o view.o



# TARGET=employees.exe
# OBJS=main.o model.o controller.o view.o pip.o
# LDFLAGS=-D=EMPLOYEES

# all: $(OBJS)
# 	$(LD) $(LDFLAGS) $(OBJS) -o $(TARGET)

# main.o: ../main.c $(LIB)/controller/EmployeesController.h
# 	$(CC) $(CCFLAGS) -c ../main.c -o main.o

# model.o: $(APP)/model/Employee.c $(LIB)/model/Employee.h
# 	$(CC) $(CCFLAGS) -c $(APP)/model/Employee.c -o model.o

# controller.o: $(APP)/controller/EmployeesController.c $(LIB)/controller/EmployeesController.h
# 	$(CC) $(CCFLAGS) -c $(APP)/controller/EmployeesController.c -o controller.o

# view.o: $(APP)/view/EmployeesView.c $(LIB)/view/EmployeesView.h
# 	$(CC) $(CCFLAGS) -c $(APP)/view/EmployeesView.c -o view.o

# pip.o: $(APP)/pip.c $(LIB)/pip.h
# 	$(CC) $(CCFLAGS) -c $(APP)/pip.c -o pip.o



# TARGET=evaluation.exe
# OBJS=main.o model.o controller.o view.o
# LDFLAGS=-D=EVALUATION

# all: $(OBJS)
# 	$(LD) $(LDFLAGS) $(OBJS) -o $(TARGET)

# main.o: ../main.c $(LIB)/controller/EvaluationsController.h
# 	$(CC) $(CCFLAGS) -c ../main.c -o main.o

# model.o: $(APP)/model/Evaluation.c $(LIB)/model/Evaluation.h
# 	$(CC) $(CCFLAGS) -c $(APP)/model/Evaluation.c -o model.o

# controller.o: $(APP)/controller/EvaluationsController.c $(LIB)/controller/EvaluationsController.h
# 	$(CC) $(CCFLAGS) -c $(APP)/controller/EvaluationsController.c -o controller.o

# view.o: $(APP)/view/EvaluationsView.c $(LIB)/view/EvaluationsView.h
# 	$(CC) $(CCFLAGS) -c $(APP)/view/EvaluationsView.c -o view.o



# TARGET=cars.exe
# OBJS=main.o model.o controller.o view.o
# LDFLAGS=-D=CARS

# all: $(OBJS)
# 	$(LD) $(LDFLAGS) $(OBJS) -o $(TARGET)

# main.o: ../main.c $(LIB)/controller/CarsController.h
# 	$(CC) $(CCFLAGS) -c ../main.c -o main.o

# model.o: $(APP)/model/Car.c $(LIB)/model/Car.h
# 	$(CC) $(CCFLAGS) -c $(APP)/model/Car.c -o model.o

# controller.o: $(APP)/controller/CarsController.c $(LIB)/controller/CarsController.h
# 	$(CC) $(CCFLAGS) -c $(APP)/controller/CarsController.c -o controller.o

# view.o: $(APP)/view/CarsView.c $(LIB)/view/CarsView.h
# 	$(CC) $(CCFLAGS) -c $(APP)/view/CarsView.c -o view.o


# TARGET=library.exe
# OBJS=main.o model.o controller.o view.o
# LDFLAGS=-D=LIBRARY

# all: $(OBJS)
# 	$(LD) $(LDFLAGS) $(OBJS) -o $(TARGET)

# main.o: ../main.c $(LIB)/controller/BooksController.h
# 	$(CC) $(CCFLAGS) -c ../main.c -o main.o

# model.o: $(APP)/model/Book.c $(LIB)/model/Book.h
# 	$(CC) $(CCFLAGS) -c $(APP)/model/Book.c -o model.o

# controller.o: $(APP)/controller/BooksController.c $(LIB)/controller/BooksController.h
# 	$(CC) $(CCFLAGS) -c $(APP)/controller/BooksController.c -o controller.o

# view.o: $(APP)/view/BooksView.c $(LIB)/view/BooksView.h
# 	$(CC) $(CCFLAGS) -c $(APP)/view/BooksView.c -o view.o



# TARGET=pcs.exe
# OBJS=main.o model.o controller.o view.o
# LDFLAGS=-D=PC

# all: $(OBJS)
# 	$(LD) $(LDFLAGS) $(OBJS) -o $(TARGET)

# main.o: ../main.c $(LIB)/controller/PcsController.h
# 	$(CC) $(CCFLAGS) -c ../main.c -o main.o

# model.o: $(APP)/model/Pc.c $(LIB)/model/Pc.h
# 	$(CC) $(CCFLAGS) -c $(APP)/model/Pc.c -o model.o

# controller.o: $(APP)/controller/PcsController.c $(LIB)/controller/PcsController.h
# 	$(CC) $(CCFLAGS) -c $(APP)/controller/PcsController.c -o controller.o

# view.o: $(APP)/view/PcsView.c $(LIB)/view/PcsView.h
# 	$(CC) $(CCFLAGS) -c $(APP)/view/PcsView.c -o view.o



# TARGET=task.exe
# OBJS=main.o task.o
# LDFLAGS=-D=TASK

# all: $(OBJS)
# 	$(LD) $(LDFLAGS) $(OBJS) -o $(TARGET)

# main.o: ../main.c $(LIB)/Task.h
# 	$(CC) $(CCFLAGS) -c ../main.c -o main.o

# task.o: $(APP)/Task.c $(LIB)/Task.h
# 	$(CC) $(CCFLAGS) -c $(APP)/Task.c -o task.o

#install:
#	@install x /usr/local/bin/x

clean:
	rm -rf *.o