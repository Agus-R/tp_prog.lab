#include <stdio.h>
#include <stdlib.h>
#include "employee.h"

#define TAM 5

int main()
{
    int option;
    int answer;
    int answer2;
    int idSearch;
    //int a;
    int r;
    sEmployee listEmployees[TAM];

    do
    {
        printf("|1| ALTAS.\n|2| MODIFICAR.\n|3| BAJAS.\n|4| INFORMAR.\n|5| SALIR.\n");
        printf("Chose an option: ");
        scanf("%d", &option);

        switch(option)
        {
            case 1:
                hardcodeEmployee(listEmployees, TAM);
                /*a = addEmployee(listEmployees, TAM);
                if(a == 0)
                {
                    printf("Congrats! you add a employee. \n");
                }else
                {
                    printf("ERROR. Try again.\n");
                }*/
            break;
            case 2:
                modifyEmployee(listEmployees, TAM);
            break;
            case 3:
                printf("Enter id for remove an employee: ");
                scanf("%5d", &idSearch);
                r = removeEmployee(listEmployees, TAM, idSearch);
                if(r == 0)
                {
                    printf("Employee delete.\n");
                }else
                {
                    printf("ERROR. Try again.\n");
                }
            break;
            case 4:
                printf("|1| List of employees ordered by last name and sector.  \n");
                printf("|2| Total and average wages, and how many are above the average wage. \n");
                printf("How do you want to report the data? \n");
                scanf("%d", &answer);
                if(answer == 1)
                {
                    printf("How do you want to order the sector? (1)-ascending (2)-descending \n");
                    scanf("%d", &answer2);
                    sortEmployeeByLastName(listEmployees, TAM, answer2);
                    printEmployees(listEmployees, TAM);
                }else if(answer == 2)
                {
                    showTotalSalaryAndAverage(listEmployees, TAM);
                    showEmployeesWhoExceedTheAverageSalary(listEmployees, TAM);
                }else
                {
                    printf("ERROR. Try again. \n");
                }
            break;
            case 5:
                printf("Thanks for using it, bye! \n");
            break;
        }
    }while(option!=5);

    return 0;
}

