#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int id;
    char firstName[20];
    char lastName[20];
    float salary;
    int sector;
    int isEmpty;
}sEmployee;

int initEmployees(sEmployee[], int);
int searchSpace(sEmployee[], int);
sEmployee chargeEmployee();
int addEmployee(sEmployee[], int);
int findEmployeeById(sEmployee[], int, int);
int removeEmployee(sEmployee[], int, int);
int sortEmployeeByLastName(sEmployee[], int, int);
void showEmployee(sEmployee anEmployee);
void printEmployees(sEmployee[], int);
void modifyEmployee(sEmployee[], int);
void hardcodeEmployee(sEmployee[], int);
void showTotalSalaryAndAverage(sEmployee[], int);
void showEmployeesWhoExceedTheAverageSalary(sEmployee[], int);
