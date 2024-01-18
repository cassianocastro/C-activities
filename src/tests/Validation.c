#include "./Validation.h"

bool validadata(uint8_t day, uint8_t month, uint16_t year)
{
    switch ( month )
    {
        case JANUARY:
        case MARCH:
        case MAY:
        case JULY:
        case AUGUST:
        case OCTOBER:
        case DECEMBER:
            return day <= 31 and day > 0;
        case FEBRUARY:
            if( ((year % 4 == 0) and (year % 100 not_eq 0)) or (year % 400 == 0) )
            {
                return day <= 29 and day > 0;
            }
            else if ( day <= 28 and day > 0 )
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
            return day <= 30 and day > 0;
        default:
            return false;
    }
}