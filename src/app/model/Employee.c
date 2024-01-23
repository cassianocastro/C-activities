#include "../../includes/model/Employee.h"

Employee createEmployee(void)
{
    Employee employee = {
        .name     = "",
        .address  = "",
        .cpf      = "",
        .bd.day   = 0,
        .bd.month = 0,
        .bd.year  = 0,
        .code     = 0,
        .sum      = 0.0f,
        .wage     = { 0.0f }
    };

    return employee;
}