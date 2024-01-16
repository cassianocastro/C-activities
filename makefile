all: evaluation.exe

evaluation.exe: bin/main.o bin/evaluation.o
	gcc bin/main.o bin/evaluation.o -o bin/evaluation.exe

./bin/main.o: main.c src/includes/Evaluation.h
	gcc -c main.c -o bin/main.o

./bin/evaluation.o: src/app/Evaluation.c src/includes/Evaluation.h
	gcc -c src/app/Evaluation.c -o bin/evaluation.o

clean:
	rm -rf bin/*.o bin/evaluation.exe