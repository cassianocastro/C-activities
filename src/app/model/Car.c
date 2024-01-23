#include "../../includes/model/Car.h"

Car createCar(void)
{
    return (Car)
    {
        .color   = "",
        .mark    = "",
        .model   = "",
        .placa   = "",
        .release = 0
    };
}