/*******************************************************************
Programa: TP 1 - Calculadora.

Objetivo: Realizar operaciones aritmeticas.
A partir de los operando ingresados por el usuario.

Autor: Agustin Roman Rodriguez.
Division: 1C
********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "Funciones.h"
int main()
{
    int opcion;
    double primerOperando;
    double segundoOperando;
    double resta;
    double suma;
    double multiplicacion;
    double primerFactorial;
    double segundoFactorial;
    double division;
    int banderaOperando;

    banderaOperando = 0;

    do
    {
        system("cls");
        if (banderaOperando==0)
        {
            printf("|1| Ingrese 1er operando.\n|2| Ingrese 2do operando. \n|3| Calcular operaciones.\n|4| Mostrar resultados.\n|5| Salir.\n");
        printf("Elija una opcion: ");
        scanf("%d", &opcion);
        } else
        {
            printf("|1| Ingrese 1er operando. El operando es: %2lf\n|2| Ingrese 2do operando. El operando es: %2lf\n|3| Calcular operaciones.\n|4| Mostrar resultados.\n|5| Salir.\n", primerOperando, segundoOperando);
        printf("Elija una opcion: ");
        scanf("%d", &opcion);
        }
        system("pause");
        switch(opcion)
        {
            case 1:
                system("cls");
                if (banderaOperando==0)
                {
                    printf("Ingrese un numero: ");
                    scanf("%lf", &primerOperando);

                } else
                {
                    printf("Ingrese un numero: ");
                    scanf("%lf", &primerOperando);
                    printf("El numero se modifico. \n");
                    fflush( stdin );
                }
                system("pause");
            break;
            case 2:
                system("cls");
                if (banderaOperando == 0)
                {
                    printf("Ingrese otro numero: ");
                    scanf("%lf", &segundoOperando);
                    banderaOperando = 1;
                } else
                {
                    printf("Ingrese un numero: ");
                    scanf("%lf", &segundoOperando);
                    printf("El numero se modifico. \n");
                    fflush( stdin );
                }
                system("pause");
            break;
            case 3:
                system("cls");
                resta = restarNumeros(primerOperando, segundoOperando);
                suma = sumarNumeros(primerOperando, segundoOperando);
                division = dividirNumeros(primerOperando, segundoOperando);
                multiplicacion = multiplicarNumeros(primerOperando, segundoOperando);

                if (primerOperando > 0)
                {
                    primerFactorial = calcularFactorial((int)primerOperando);
                }else
                {
                    printf("No se pudo calcular el factorial. (operando menor a cero)\n");
                }
                if (segundoOperando > 0)
                {
                    segundoFactorial = calcularFactorial((int)segundoOperando);
                }
                system("pause");
            break;
            case 4:
                system("cls");
                printf("|A| La resta de los numeros es: %lf\n", resta);
                printf("|B| La suma de los dos numeros es: %lf\n", suma);

                 if (division == 0)
                {
                    printf("No se pudo dividir por cero.\n");
                } else
                {
                    printf("|C| La division de los numeros es: %lf\n", division);
                }


                printf ("|D| La multiplicacion de ambos numeros es: %lf\n", multiplicacion);
                printf ("|E| El factorial del 1ero es: %lf y del 2do es: %lf\n", primerFactorial, segundoFactorial);
                system("pause");
            break;
            case 5:
                printf("ADIOS\n");
            break;

        }

    }while(opcion!=5);




    return 0;
}
