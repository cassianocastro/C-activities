#include "../../includes/model/Agenda.h"

const unsigned short int CURRENT_YEAR = 2024u;

byte num = 0u;

Contact* contacts;

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