#include <stdio.h>
#include <stdlib.h>

double restarNumeros(double primerNumero, double segundoNumero)
{
    double resta;
    resta = primerNumero - segundoNumero;
    return resta;
}

double sumarNumeros(double primerNumero, double segundoNumero)
{
    double suma;
    suma = primerNumero + segundoNumero;
    return suma;
}

double dividirNumeros(double primerNumero, double segundoNumero)
{
    double division;
    if (primerNumero==0||segundoNumero==0)
    {
        division = 0;
    } else
    {
        division = primerNumero / segundoNumero;
    }
    return division;
}

double multiplicarNumeros(double primerNumero, double segundoNumero)
{
    double multiplicacion;
    multiplicacion = primerNumero * segundoNumero;
    return multiplicacion;
}

int calcularFactorial(int numero)
{
    int factorial;

    if(numero == 0)
    {
        factorial = 1;
    } else if(numero>0)
    {
        factorial = numero * calcularFactorial(numero - 1);
    }
    else
    {
        factorial = 0;

    }

    return factorial;

}


