/*******************************************************************
Programa: TP 1 - Calculadora.

Objetivo: Realizar operaciones aritmeticas.
A partir de los operando ingresados por el usuario.

Autor: Agustin Roman Rodriguez.
Division: 1C
********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "FuncionesAritmeticas.h"
int main()
{
	// Declaracion.
    int opcion;
    double primerOperando;
    double segundoOperando;
    int operandoPrimerFactorial;
    int operandoSegundoFactorial;
    double resta;
    double suma;
    double multiplicacion;
    double primerFactorial;
    double segundoFactorial;
    double division;
    int banderaGlobal;

    //Inicializacion.
    banderaGlobal = 0;

    //Desarrollo.
    do
    {
        if (banderaGlobal==0)
        {
            printf("|1| Ingrese 1er operando.\n|2| Ingrese 2do operando. \n|3| Calcular operaciones.\n|4| Mostrar resultados.\n|5| Salir.\n");
        printf("Elija una opcion: ");
        scanf("%d", &opcion);
        } else
        {
            printf("|1| Ingrese 1er operando. El operando es: %lf\n|2| Ingrese 2do operando. El operando es: %lf\n|3| Calcular operaciones.\n|4| Mostrar resultados.\n|5| Salir.\n", primerOperando, segundoOperando);
        printf("Elija una opcion: ");
        scanf("%d", &opcion);
        }


        switch(opcion)
        {
            case 1:
                if (banderaGlobal==0)
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

            break;
            case 2:
                if (banderaGlobal == 0)
                {
                    printf("Ingrese otro numero: ");
                    scanf("%lf", &segundoOperando);
                    banderaGlobal = 1;
                } else
                {
                    printf("Ingrese un numero: ");
                    scanf("%lf", &segundoOperando);
                    printf("El numero se modifico. \n");
                    fflush( stdin );
                }

            break;
            case 3:

                operandoPrimerFactorial = primerOperando;
                operandoSegundoFactorial = segundoOperando;

                resta = restarNumeros(primerOperando, segundoOperando);

                suma = sumarNumeros(primerOperando, segundoOperando);

                division = dividirNumeros(primerOperando, segundoOperando);

                multiplicacion = multiplicarNumeros(primerOperando, segundoOperando);

                primerFactorial = calcularFactorial(operandoPrimerFactorial);

                segundoFactorial = calcularFactorial(operandoSegundoFactorial);

            break;
            case 4:

                printf("|A| La resta de los numeros es: %lf\n", resta);


                printf("|B| La suma de los dos numeros es: %lf\n", suma);



                 if (division == 0)
                {
                    printf("No se pudo dividir por cero.\n");
                } else
                {
                    printf("|C|  La division de los numeros es: %lf\n", division);
                }


                printf ("|D|  La multiplicacion de ambos numeros es: %lf\n", multiplicacion);


                printf ("|E|  El factorial del 1ero es: %lf y del 2do es: %lf\n", primerFactorial, segundoFactorial);

                if (primerOperando || segundoOperando)
                {
                    printf("No se pudo calcular el factorial. (operando menor a cero)\n");
                }

            break;
            case 5:
                printf("ADIOS\n");
            break;

        }

    }while(opcion!=5);




    return 0;
}
