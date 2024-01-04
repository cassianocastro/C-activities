# C-activities

## Description

Exercises in C.

## How to compile

### Single file:

`gcc ./src/file.c -o ./bin/output.exe`

### Multiple files:

```sh
cd ./bin

gcc -c ../src/file1.c
gcc -c ../src/file2.c
gcc -c ../src/file3.c

gcc ./file{1,2,3}.o -o output.exe
```