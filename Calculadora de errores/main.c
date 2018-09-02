#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
/******COMENTARIOS*************************************************************************************
*
******************************************************************************************************/

/******DECLARACION*DE*FUNCIONES***********************************************************************/
float ingresarNumero (void);
int ingresarOpcion(void);
float valorMedio(float);
float dispersion(float,float);
float porcentajeDeDispersion(float,float,float);
/*****************************************************************************************************/

/******FUNCION*PRINCIPAL******************************************************************************/
int main()
{
    //VARIABLES:
    float medida;
    int opcion;
    //ACUMULADORES:
    float maximo=INT_MIN, minimo=INT_MAX, sumaTresMedidas=0;
    //CONTADORES:
    int i;


    //OPCIONES:
    printf("Las siguientes son las opciones para cada operacion: \n");
    printf("1) Valor medio y dispersion \n");


    do
    {
        opcion=ingresarOpcion();

        switch(opcion)
        {
            case 1:                             //CASO 1: VALOR MEDIO Y DISPERSION
                printf("Estas claculando el valor medio y la dispercion de las primeras tres medidas:\n");
                printf("\nTambien calculamos el porcentaje de dispersion\n");

                for(i=1;i<4;i++)
                {
                    printf("Ingrese la medida: \n");
                    scanf(" %f", &medida);

                    sumaTresMedidas+=medida;//SUMO LAS MEDIDAS INGRESADAS

                    if(medida>maximo)       //CALCULO EL MAXIMO
                        {
                            maximo=medida;
                        }
                    if(medida<minimo)       //CALCULO EL MINIMO
                        {
                            minimo=medida;
                        }
                }

                printf("maximo: %f\n", maximo);
                printf("minimo: %f\n", minimo);
                valorMedio(sumaTresMedidas);
                dispersion(maximo,minimo);
                porcentajeDeDispersion(sumaTresMedidas,maximo,minimo);
            break;
        }
        system("pause");
        system("cls");
    }while(opcion<2);


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
float valorMedio(float sumaTresMedidas)
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


/******************************************************************************************************/







