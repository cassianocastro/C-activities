#ifndef AGENDA_MODEL_H

#define AGENDA_MODEL_H

typedef unsigned char byte;

/**
 *
 */
typedef struct
{
	byte day;
    byte month;

    unsigned short int year;
}
BirthDate;

/**
 *
 */
typedef struct
{
	BirthDate dn;

    byte age;

    char name[51];
    char city[21];
    char phone[17];
    char sex;
}
Contact;

#endif