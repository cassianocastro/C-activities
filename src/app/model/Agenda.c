#include "../../includes/model/Agenda.h"

const unsigned short int CURRENT_YEAR = 2024;

Contact* contacts;

unsigned short int num;

bool searchID(const byte id)
{
    for ( register byte i = 0, j = 0; i < num; ++i )
    {
		if ( i == id )
        {
            return true;
		}
	}

    return false;
}