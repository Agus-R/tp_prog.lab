#include <stdlib.h>
#include <stdio.h>
#include "Employee.h"
#include <string.h>

//CONTROLADORES
Employee* employee_new(void)
{
    Employee* pEmpleado;
    pEmpleado = (Employee*)malloc(sizeof(Employee));
    if(pEmpleado != NULL)
    {
        employee_setId(pEmpleado, 0);
        employee_setNombre(pEmpleado, "\0");
        employee_setHorasTrabajadas(pEmpleado, 0);
        employee_setSueldo(pEmpleado, 0);
    }

    return pEmpleado;
}

Employee* employee_newParametros(char* idStr, char* nombreStr, char* horasTrabajadasStr, char* sueldosStr)
{
    Employee* pEmpleado;
    int auxId;
    int auxHsTrabajadas;
    int auxSueldos;

    pEmpleado = employee_new();
    if(pEmpleado != NULL)
    {
        auxId = atoi(idStr);
        auxHsTrabajadas = atoi(horasTrabajadasStr);
        auxSueldos = atoi(sueldosStr);
        employee_setId(pEmpleado, auxId);
        employee_setNombre(pEmpleado, nombreStr);
        employee_setHorasTrabajadas(pEmpleado, auxHsTrabajadas);
        employee_setSueldo(pEmpleado, auxSueldos);
    }

    return pEmpleado;
}

//ID
int employee_setId(Employee* this,int id)
{
    int setId = 0;

    if (this != NULL && id > 0)
    {
        this->id = id;
        setId = 1;
    }

    return setId;
}

int employee_getId(Employee* this,int* id)
{
    int getId = 0;

    if(this != NULL && id != NULL)
    {
        *id = this->id;
        getId = 1;
    }

    return getId;
}

//NOMBRE
int employee_setNombre(Employee* this,char* nombre)
{
    int setNombre = 0;
    if(this != NULL )
    {
        strcpy(this->nombre, nombre);
        setNombre = 1;
    }

    return setNombre;
}

int employee_getNombre(Employee* this,char* nombre)
{
    int getNombre = 0;
    if(this != NULL && nombre != NULL)
    {
        nombre = this->nombre;
        getNombre = 1;
    }

    return getNombre;
}

//HORAS TRABAJADAS
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int setHs = 0;
    if(this != NULL && horasTrabajadas > 0)
    {
        this->horasTrabajadas = horasTrabajadas;
        setHs = 1;
    }

    return setHs;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int getHs = 0;
    if(this != NULL && horasTrabajadas != NULL)
    {
        *horasTrabajadas = this->horasTrabajadas;
        getHs = 1;
    }

    return getHs;
}

//SUELDO
int employee_setSueldo(Employee* this,int sueldo)
{
    int setSueldo = 0;
    if(this != NULL && sueldo > 0)
    {
        this->sueldo = sueldo;
        setSueldo = 1;
    }

    return setSueldo;
}

int employee_getSueldo(Employee* this,int* sueldo)
{
    int getSueldo = 0;
    if(this != NULL && sueldo != NULL)
    {
        *sueldo = this->sueldo;
        getSueldo = 1;
    }

    return getSueldo;
}

//COMPARAR
int employee_CompareByName(Employee* e1, Employee* e2)
{
    Employee* employee1 = (Employee*) e1;
    Employee* employee2 = (Employee*) e2;
    int retorno;
    char nameEmployee1[50];
    char nameEmployee2[50];

    employee_getNombre(employee1, nameEmployee1);
    employee_getNombre(employee2, nameEmployee2);

    if(employee1!=NULL && employee2!=NULL)
    {
        retorno = strcmp(nameEmployee1, nameEmployee2);
    }else{
        retorno = -1;
    }
    return retorno;
}

int employee_CompareById(Employee* e1, Employee* e2)
{
    Employee* employee1 = (Employee*) e1;
    Employee* employee2 = (Employee*) e2;
    int retorno;
    int idEmployee1;
    int idEmployee2;

    employee_getId(employee1, &idEmployee1);
    employee_getId(employee2, &idEmployee2);

    if(employee1!=NULL && employee2!=NULL)
    {
        if(idEmployee1 > idEmployee2)
        {
            retorno = 1;
        }else{
            if(idEmployee1 < idEmployee2)
            {
                retorno = -1;
            }else{
                retorno = 0;
            }
        }
    }
    return retorno;
}
