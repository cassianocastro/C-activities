#include "../includes/Validacao.h"

bool validadata(uint8_t dia, uint8_t mes, uint16_t ano)
{
    switch ( mes )
    {
        case JANUARY:
        case MARCH:
        case MAY:
        case JULY:
        case AUGUST:
        case OCTOBER:
        case DECEMBER:
            return dia <= 31 and dia > 0;
        case FEBRUARY:
            if( ((ano % 4 == 0) and (ano % 100 not_eq 0)) or (ano % 400 == 0) )
            {
                return dia <= 29 and dia > 0;
            }
            else if ( dia <= 28 and dia > 0 )
            {
                return true;
            }
            else
            {
                return false;
            }
        case APRIL:
        case JUNE:
        case SEPTEMBER:
        case NOVEMBER:
            return dia <= 30 and dia > 0;
        default:
            return false;
    }
}