STD=c99
CC=gcc
LD=gcc
CCFLAGS=-Wall -Wextra -w --ansi --pedantic -std=$(STD)


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



TARGET=bin/employees.exe
OBJS=bin/main.o bin/employeeModel.o bin/employeesController.o bin/employeesView.o bin/pip.o
LDFLAGS=-D=EMPLOYEES

all: $(OBJS)
	$(LD) $(LDFLAGS) $(OBJS) -o $(TARGET)

./bin/main.o: main.c src/includes/controller/EmployeesController.h
	$(CC) $(CCFLAGS) -c main.c -o bin/main.o

./bin/employeeModel.o: src/app/model/EmployeeModel.c src/includes/model/EmployeeModel.h
	$(CC) $(CCFLAGS) -c src/app/model/EmployeeModel.c -o bin/employeeModel.o

./bin/employeesController.o: src/app/controller/EmployeesController.c src/includes/controller/EmployeesController.h
	$(CC) $(CCFLAGS) -c src/app/controller/EmployeesController.c -o bin/employeesController.o

./bin/employeesView.o: src/app/view/EmployeesView.c src/includes/view/EmployeesView.h
	$(CC) $(CCFLAGS) -c src/app/view/EmployeesView.c -o bin/employeesView.o

./bin/pip.o: src/app/pip.c src/includes/pip.h
	$(CC) $(CCFLAGS) -c src/app/pip.c -o bin/pip.o



# TARGET=bin/evaluation.exe
# OBJS=bin/main.o bin/evaluation.o
# LDFLAGS=-D=EVALUATION

# all: $(OBJS)
# 	$(LD) $(LDFLAGS) $(OBJS) -o $(TARGET)

# ./bin/main.o: main.c src/includes/Evaluation.h
# 	$(CC) $(CCFLAGS) -c main.c -o bin/main.o

# ./bin/evaluation.o: src/app/Evaluation.c src/includes/Evaluation.h
# 	$(CC) $(CCFLAGS) -c src/app/Evaluation.c -o bin/evaluation.o



# TARGET=bin/frota.exe
# OBJS=bin/main.o bin/Frota.o
# LDFLAGS=-D=FROTA

# all: $(OBJS)
# 	$(LD) $(LDFLAGS) $(OBJS) -o $(TARGET)

# ./bin/main.o: main.c src/includes/Frota.h
# 	$(CC) $(CCFLAGS) -c main.c -o bin/main.o

# ./bin/Frota.o: src/app/Frota.c src/includes/Frota.h
# 	$(CC) $(CCFLAGS) -c src/app/Frota.c -o bin/Frota.o



# TARGET=bin/library.exe
# OBJS=bin/main.o bin/library.o
# LDFLAGS=-D=LIBRARY

# all: $(OBJS)
# 	$(LD) $(LDFLAGS) $(OBJS) -o $(TARGET)

# ./bin/main.o: main.c src/includes/Library.h
# 	$(CC) $(CCFLAGS) -c main.c -o bin/main.o

# ./bin/library.o: src/app/Library.c src/includes/Library.h
# 	$(CC) $(CCFLAGS) -c src/app/Library.c -o bin/library.o



# TARGET=bin/pcs.exe
# OBJS=bin/main.o bin/pcs.o
# LDFLAGS=-D=PC

# all: $(OBJS)
# 	$(LD) $(LDFLAGS) $(OBJS) -o $(TARGET)

# ./bin/main.o: main.c src/includes/pcs.h
# 	$(CC) $(CCFLAGS) -c main.c -o bin/main.o

# ./bin/pcs.o: src/app/pcs.c src/includes/pcs.h
# 	$(CC) $(CCFLAGS) -c src/app/pcs.c -o bin/pcs.o



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