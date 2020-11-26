#include "employee.h"

void hardcodeEmployee(sEmployee list[], int len)
{
  int i;
  int id[5]={100,101,102,103,104};
  char firstName[5][50]={"Rigoberto","Francisco","Mariano","Salma","Sarampion"};
  char lastName[5][50]={"Penales","Pappa","Salame","Rina","Jodido"};
  float salary[5]= {10000,50000,12000,13000,14000};
  int sector[5]= {1,2,1,3,2};;

  for(i=0; i<len; i++)
  {
      list[i].id = id[i];
      strcpy(list[i].firstName, firstName[i]);
      strcpy(list[i].lastName, lastName[i]);
      list[i].salary = salary[i];
      list[i].sector = sector[i];
      list[i].isEmpty = 0;
  }
}
int initEmployee(sEmployee list[], int len)
{
    int index;
    int i;

    for(i=0; i<len; i++)
    {
        list[i].isEmpty = 1;
        index = 0;
    }

    return index;
}

int searchSpace(sEmployee list[], int len)
{
    int index = 0;
    int i;

    for(i=0; i<len ;i++)
    {
        if(list[i].isEmpty == 1)
        {
            list[i].isEmpty = 0;
            index = 1;
        }
    }

    return index;
}

sEmployee chargeEmployee()
{
    sEmployee anEmployee;

    anEmployee.id = 100;
    printf("Enter first name: \n");
    fflush(stdin);
    scanf("%[^\n]", anEmployee.firstName);
    printf("Enter last name: \n");
    fflush(stdin);
    scanf("%[^\n]", anEmployee.lastName);
    printf("Enter salary: \n");
    scanf("%f", &anEmployee.salary);
    printf("Enter sector: \n");
    scanf("%d", &anEmployee.sector);

    return anEmployee;
}

int addEmployee(sEmployee list[], int len)
{
    int i;
    int auxSpace;
    int index;

    for(i=0;i<len;i++)
    {
        auxSpace = searchSpace(list, len);
        if(auxSpace == 1)
        {
            list[i] = chargeEmployee();
            index = 0;
        }else
        {
            index = -1;
        }
    }
    return index;
}

int findEmployeeById(sEmployee list[], int len, int idSearch)
{
    int i;
    int auxId = -1;

    for(i=0;i<len;i++)
    {
        if(list[i].id == idSearch && len <= 0)
        {
            auxId = i;
        }
    }

    return auxId;
}

int removeEmployee(sEmployee list[], int len, int id)
{
    int i;
    int index = -1;


    for(i=0;i<len;i++)
    {
        if(list[i].id==id)
        {
            list[i].isEmpty=1;
            index = 0;
        }
    }
    return index;
}

int sortEmployeeByLastName(sEmployee list[], int len, int order)
{
    int i, j;
    int aux;
    sEmployee auxEmployee;

    for(i=0;i<len;i++)
    {
        for(j=i+1;j<len;j++)
        {
            aux = strcmp(list[i].lastName, list[j].lastName);
            if(aux >= 1)
            {
                auxEmployee = list[i];
                list[i] = list[j];
                list[j] = auxEmployee;
            }
        }
    }

    for(i=0;i<len;i++)
    {
        for(j=i+1;j<len;j++)
        {
            if(order == 1)
            {
                if(list[i].sector > list[j].sector)
                {
                    auxEmployee = list[i];
                    list[i] = list[j];
                    list[j] = auxEmployee;
                }
            }else{
                if(list[i].sector < list[j].sector)
                {
                    auxEmployee = list[i];
                    list[i] = list[j];
                    list[j] = auxEmployee;
                }
            }
        }
    }

    return 0;
}

void showEmployee(sEmployee anEmployee)
{
    printf("\n%10d %10s %10s\t $%10.1f %10.d\n", anEmployee.id, anEmployee.firstName, anEmployee.lastName, anEmployee.salary, anEmployee.sector);
}

void printEmployees(sEmployee list[], int len)
{
    int i;
    for(i=0;i<len;i++)
    {
        if(list[i].isEmpty==0)
        {
            showEmployee(list[i]);
        }
    }
}

void modifyEmployee(sEmployee list[], int len)
{
    int i;
    int idFind;
    int aux;
    int answer;

    printf("Chose id: \n");
    scanf("%d", &idFind);
    aux = findEmployeeById(list, len, idFind);
    for(i=0; i<len;i++)
    {
        if(aux != -1 && list[i].id == idFind)
        {
            printf("|1| first name \n|2| last name \n|3| salary \n|4| sector \n|5| Salir\n");
            printf("What do you want to modify? \n");
            scanf("%d", &answer);
            switch(answer)
            {
            case 1:
                printf ("Entry the first name: \n");
                fflush(stdin);
                scanf ("%s",list[i].firstName);
            break;
            case 2:
                printf ("Ingrese el last name: \n");
                fflush(stdin);
                scanf ("%s",list[i].lastName);
            break;
            case 3:
                printf ("Ingrese el salario: \n");
                scanf ("%f", &list[i].salary);
            break;
            case 4:
                printf ("Ingrese el sector: \n");
                scanf ("%d", &list[i].sector);
            break;
            case 5:
                printf("Good bye. \n");
            break;
            default:
                printf("Invalid option. \n");
            break;
            }
        }else
        {
            printf("id not found. \n");
        }
    }
}

void showTotalSalaryAndAverage(sEmployee list[], int len)
{
    int i;
    int counter=0;
    float total=0;
    float promedy;

    for(i=0; i<len; i++)
    {
        if(list[i].isEmpty==0)
        {
            total+= list[i].salary;
            counter++;
        }

    }

    promedy = total/counter;
    if(total==0)
    {
        promedy=0;
    }
    if(counter>0)
    {
        printf("\n################################ TOTAL SALARY ###########\n");
        printf("\n                                  $%.1f\n", total);
        printf("\n############################### SALARY PROMEDY ##########\n");
        printf("\n                                  $%.1f\n", promedy);
    }
}

void showEmployeesWhoExceedTheAverageSalary(sEmployee list[], int len)
{
    int i;

    for(i=0; i<len; i++)
    {
        if(list[i].isEmpty==0)
        {
            if(list[i].salary>=50000)
            {
                showEmployee(list[i]);
            }
        }
    }
}
