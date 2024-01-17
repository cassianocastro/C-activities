all: computer.exe #agenda.exe evaluation.exe

evaluation.exe: bin/main.o bin/evaluation.o
	gcc -D=EVALUATION bin/main.o bin/evaluation.o -o bin/evaluation.exe

./bin/main.o: main.c src/includes/Evaluation.h
	gcc -c main.c -o bin/main.o

./bin/evaluation.o: src/app/Evaluation.c src/includes/Evaluation.h
	gcc -c src/app/Evaluation.c -o bin/evaluation.o

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

clean:
	rm -rf bin/*.o bin/evaluation.exe bin/agenda.exe