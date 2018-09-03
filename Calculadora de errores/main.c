#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
/******COMENTARIOS*************************************************************************************
*
******************************************************************************************************/

/******DECLARACION*DE*FUNCIONES***********************************************************************/
float ingresarNumero (void);
int ingresarOpcion(void);
float valorMedioTresMedidas(float);
float dispersion(float,float);
float porcentajeDeDispersion(float,float,float);
float valorMedio_N_medidas(void);
float errorAbsoluto(int);
/*****************************************************************************************************/

/******FUNCION*PRINCIPAL******************************************************************************/
int main()
{
    //VARIABLES:
    int opcion;
    float medida;
    //ACUMULADORES:
    float maximo=INT_MIN, minimo=INT_MAX, sumaTresMedidas=0;
    //CONTADORES:
    int i;
    int numeroDeMedidas;

    //OPCIONES:
    printf("Las siguientes son las opciones para cada operacion: \n");
    printf("1) Porcentaje de dispersion. \n");
    printf("2) Valor medio de (n) cantidad de medidas.\n");
    printf("3) Error absoluto de la magnitud.\n");
    do
    {
        opcion=ingresarOpcion();

        switch(opcion)
        {
            case 1:                             //CASO 1: VALOR MEDIO Y DISPERSION
                printf("Estas claculando el porcentaje de dispercion\n");
                printf("\nPrimero deberas ingresar las 3 medidas realizadas.\n");

                for(i=1;i<4;i++)
                {
                    printf("Ingrese la medida: \n");
                    scanf(" %f", &medida);

                    sumaTresMedidas+=medida;    //SUMO LAS MEDIDAS INGRESADAS

                    if(medida>maximo)           //CALCULO EL MAXIMO
                        {
                            maximo=medida;
                        }
                    if(medida<minimo)           //CALCULO EL MINIMO
                        {
                            minimo=medida;
                        }
                }

                printf("maximo: %f\n", maximo);
                printf("minimo: %f\n", minimo);
                valorMedioTresMedidas(sumaTresMedidas);//llamada a la funcion valor medio
                dispersion(maximo,minimo);             //llamada a la funcion dispersion
                porcentajeDeDispersion(sumaTresMedidas,maximo,minimo);//llamada a la funcion porcentajededispersion
            break;
            case 2:
                printf("Estas calculando el valor medio de las (n) cantidad de medidas realizadas \n");

                valorMedio_N_medidas();
            break;
            case 3:
                printf("Estas calculando el error absoluto \n");

                printf("\nIngrese la cantidad de medidas que realizo:\n");
                scanf(" %d", &numeroDeMedidas);

                errorAbsoluto(numeroDeMedidas);
            break;
        }
        system("pause");

    }while(opcion<4);


    return 0;
}
/******************************************************************************************************/

/********DESARROLLO*DE*LAS*FUNCIONES*******************************************************************/

/**FUNCION*INGRESAR*OPCION***************************************************************************
*\brief Solicita un valor y lo devuelve.
*\param Ninguno.
*\return Devuelve El valor de la opcion. Luego la variable en main adquiere el valor de "opcion".
*****************************************************************************************************/

int ingresarOpcion(void)
{
    int opcion;

    printf("Ingrese una opcion: ");
    scanf(" %d", &opcion);

    return opcion;
}

/**FUNCION INGRESAR NUMERO***************************************************************************
*\brief Solicita un valor y lo devuelve.
*\param Ninguno.
*\return Devuelve El valor ingresado. Luego la variable en main adquiere el valor de "numero".
*****************************************************************************************************/
float ingresarNumero(void)
{
    float numero;

    printf("\n Ingrese un numero:");
    scanf(" %f", &numero);

    return numero;
}

/**FUNCION*VALOR*MEDIO*******************************************************************************
*\brief Solicita un tres medidas y devielve el valor medio.
*\param
*\return
*****************************************************************************************************/
float valorMedioTresMedidas(float sumaTresMedidas)
{
    float valorMedio;

    printf("\n El valor medio es: %f \n", valorMedio=sumaTresMedidas/3);

    return valorMedio;
}

/**FUNCION*DISPERSION*******************************************************************************
*\brief Solicita el maximo y el minimo de las medidas, hace la diferencia, y los devuelve
*\param maximo y minimo
*\return dispersion
*****************************************************************************************************/
float dispersion(float maximo,float minimo)
{
    float dispersion;
    dispersion = maximo - minimo;
    printf("El valor de la dispersion es: %f \n", dispersion );

    return dispersion;
}

/**FUNCION*PORCENTAJE*DE*DISPERSION*******************************************************************
*\brief Solicita la sumaTresMedias, maximo y el minimo de las medidas.Con esos datos calcula el
 porcentaje de dispersion
*\param sumaTresMedidas, maximo y minimo
*\return dispersion
*****************************************************************************************************/

float porcentajeDeDispersion(float sumaTresMedidas,float maximo,float minimo)
{
    float porcentajeDeDispersion,valorMedio,dispersion;

    valorMedio=sumaTresMedidas/3;
    dispersion= maximo - minimo;
    porcentajeDeDispersion = (dispersion/valorMedio)*100;

    printf("El porcentaje de dispersion es: %f\n", porcentajeDeDispersion);

    if (porcentajeDeDispersion<2)
    {
        printf("\nLa cantidad de medidas totales a realizar es: 3\n");
    }
    else if(porcentajeDeDispersion>2 && porcentajeDeDispersion<8)
    {
        printf("\nLa cantidad de medidas totales a realizar es: 6\n");
    }
    else if(porcentajeDeDispersion>8 && porcentajeDeDispersion<15)
    {
        printf("\nLa cantidad de medidas totales a realizar es: 15\n");
    }
    else
    {
        printf("\nLa cantidad de medidas totales a realizar es: al menos 50\n");
    }

    return porcentajeDeDispersion;
}

/**FUNCION*VALOR*MEDIO*N*MEDIDAS*******************************************************************
*\brief Solicita la cantidad de medidas a realizar, las acumula, y
*\param numero de medidas
*\return valor medio de las n medidas
*****************************************************************************************************/

float valorMedio_N_medidas(void)
{
    int respuesta=1;
    int numeroDeMedidas=0;
    float medida,valorMedio,acumulador;

    while(respuesta !=0 )
    {
        numeroDeMedidas++;

        printf("Ingrese una medida:\n");
        scanf(" %f", &medida);

        acumulador += medida;

        printf("Quiere seguir ingresando medidas? (si=1/no=0)");
        scanf(" %d", &respuesta);
    }

    printf("\n El valor medio de las n medidas es: %f \n", valorMedio=acumulador/numeroDeMedidas);

    return valorMedio;
}

/**FUNCION*ERROR*ABSOLUTO****************************************************************************
*\brief Solicita la cantidad de medidas a realizar y te da a conocer cual sera la operacion a
*       realizar segun esta cantidad.
*\param numeroDeMedidas
*\return errorAbsoluto
*****************************************************************************************************/

float errorAbsoluto(int numeroDeMedidas)
{
    float maximo=INT_MIN, minimo=INT_MAX;
    int respuesta = 1;
    float errorAbsoluto, dispersion, sensibilidad, medida, acumulador=0;

    if(numeroDeMedidas==3)
    {
        printf("El error absoluto sera el valor de la sensibilidad del aparato utilizado para realizar la medida\n");
    }
    else if(numeroDeMedidas>3 && numeroDeMedidas<16)
    {
        printf("Ingrese el valor de sensibilidad del aparato:\n");
        scanf(" %f", &sensibilidad);

        while(respuesta !=0 )
        {
            numeroDeMedidas++;

            printf("Ingrese una medida:\n");
            scanf(" %f", &medida);

            acumulador += medida;

            if(medida>maximo)       //CALCULO EL MAXIMO
            {
                maximo=medida;
            }
            if(medida<minimo)       //CALCULO EL MINIMO
            {
                minimo=medida;
            }

            printf("Quiere seguir ingresando medidas? (si=1/no=0)\n");
            scanf(" %d", &respuesta);
        }

        dispersion = maximo - minimo;

        if((dispersion/4)>sensibilidad)
        {
            errorAbsoluto=(dispersion/4);
        }
        if((dispersion/4)<sensibilidad)
        {
            errorAbsoluto=sensibilidad;
        }

        printf("\nSensibilidad del aparato = %f\n", maximo);
        printf("\nMedida maxima = %f\n", maximo);
        printf("\nMedida minima = %f\n", minimo);
        printf("\nEl valor de la dispersion = %f\n",dispersion);
        printf("\nEl error absoluto es: %f\n", errorAbsoluto);

    }

    return errorAbsoluto;
}
/******************************************************************************************************/







