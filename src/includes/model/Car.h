#ifndef CAR_MODEL_H

#define CAR_MODEL_H

#define STRING_SIZE 20

typedef unsigned char byte;

/**
 *
 */
typedef struct
{
	char model[STRING_SIZE];
	char mark[STRING_SIZE];
	char placa[STRING_SIZE];
	char color[STRING_SIZE];

	unsigned short release;
}
Car;

/**
 *
 */
Car createCar(void);

#endif