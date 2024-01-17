all: evaluation.exe agenda.exe

evaluation.exe: bin/main.o bin/evaluation.o
	gcc bin/main.o bin/evaluation.o -o bin/evaluation.exe

./bin/main.o: main.c src/includes/Evaluation.h
	gcc -c main.c -o bin/main.o

./bin/evaluation.o: src/app/Evaluation.c src/includes/Evaluation.h
	gcc -c src/app/Evaluation.c -o bin/evaluation.o

agenda.exe: bin/Agenda.o bin/Validation.o
	gcc bin/Agenda.o bin/Validation.o -o bin/agenda.exe

./bin/Agenda.o: src/app/Agenda.c src/includes/Agenda.h
	gcc -c src/app/Agenda.c -o bin/Agenda.o

./bin/Validation.o: src/app/Validation.c src/includes/Validation.h
	gcc -c src/app/Validation.c -o bin/Validation.o

clean:
	rm -rf bin/*.o bin/evaluation.exe bin/agenda.exe