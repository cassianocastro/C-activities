all: evaluation.exe

evaluation.exe: ./src/Evaluation.c ./src/includes/Evaluation.h
	gcc ./src/Evaluation.c -o ./bin/evaluation.exe

clean:
	rm -rf ./bin/evaluation.exe