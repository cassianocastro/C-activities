all: task.exe

agenda.exe: bin/Agenda.o bin/Validation.o
	gcc -D=AGENDA bin/main.o bin/Agenda.o bin/Validation.o -o bin/agenda.exe

./bin/main.o: main.c src/includes/Agenda.h
	gcc -c main.c -o bin/main.o

./bin/Agenda.o: src/app/Agenda.c src/includes/Agenda.h
	gcc -c src/app/Agenda.c -o bin/Agenda.o

./bin/Validation.o: src/app/Validation.c src/includes/Validation.h
	gcc -c src/app/Validation.c -o bin/Validation.o


computer.exe: bin/main.o bin/Computer.o
	gcc -D=COMPUTER bin/main.o bin/Computer.o -o bin/computer.exe

./bin/main.o: main.c src/includes/Computer.h
	gcc -c main.c -o bin/main.o

./bin/Computer.o: src/app/Computer.c src/includes/Computer.h
	gcc -c src/app/Computer.c -o bin/Computer.o


employees.exe: bin/main.o bin/employees.o bin/pip.o
	gcc -D=EMPLOYEES bin/main.o bin/employees.o bin/pip.o -o bin/employees.exe

./bin/main.o: main.c src/includes/Employees.h
	gcc -c main.c -o bin/main.o

./bin/employees.o: src/app/Employees.c src/includes/Employees.h
	gcc -c src/app/Employees.c -o bin/employees.o

./bin/pip.o: src/app/pip.c src/includes/pip.h
	gcc -c src/app/pip.c -o bin/pip.o


evaluation.exe: bin/main.o bin/evaluation.o
	gcc -D=EVALUATION bin/main.o bin/evaluation.o -o bin/evaluation.exe

./bin/main.o: main.c src/includes/Evaluation.h
	gcc -c main.c -o bin/main.o

./bin/evaluation.o: src/app/Evaluation.c src/includes/Evaluation.h
	gcc -c src/app/Evaluation.c -o bin/evaluation.o


frota.exe: bin/main.o bin/Frota.o
	gcc -D=FROTA bin/main.o bin/Frota.o -o bin/frota.exe

./bin/main.o: main.c src/includes/Frota.h
	gcc -c main.c -o bin/main.o

./bin/Frota.o: src/app/Frota.c src/includes/Frota.h
	gcc -c src/app/Frota.c -o bin/Frota.o


library.exe: bin/main.o bin/Library.o
	gcc -D=LIBRARY bin/main.o bin/Library.o -o bin/library.exe

./bin/main.o: main.c src/includes/Library.h
	gcc -c main.c -o bin/main.o

./bin/Library.o: src/app/Library.c src/includes/Library.h
	gcc -c src/app/Library.c -o bin/Library.o


pcs.exe: bin/main.o bin/pcs.o
	gcc -D=PC bin/main.o bin/pcs.o -o bin/pcs.exe

./bin/main.o: main.c src/includes/pcs.h
	gcc -c main.c -o bin/main.o

./bin/pcs.o: src/app/pcs.c src/includes/pcs.h
	gcc -c src/app/pcs.c -o bin/pcs.o


task.exe: bin/main.o bin/task.o
	gcc -D=TASK bin/main.o bin/task.o -o bin/task.exe

./bin/main.o: main.c src/includes/Task.h
	gcc -c main.c -o bin/main.o

./bin/task.o: src/app/Task.c src/includes/Task.h
	gcc -c src/app/Task.c -o bin/task.o


clean:
	rm -rf bin/*.o bin/evaluation.exe bin/agenda.exe