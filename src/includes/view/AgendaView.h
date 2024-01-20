#ifndef AGENDA_VIEW_H

#define AGENDA_VIEW_H

#include "../model/AgendaModel.h"

/**
 *
 */
const unsigned int showMainMenu(void);

/**
 *
 */
const unsigned int showUpdateMenu(void);

/**
 *
 */
void showContactForm(byte);

/**
 *
 */
void printContact(const Contact* const);

/**
 *
 */
byte getContactID(void);

#endif