#include <stdio.h>
#include <iostream>
//Ejercicio 1:
//
//Una tienda de ropa necesita un programa que le permita llevar un registro de ventas de cada día durante una semana. Para ello, el programa debe permitir registrar las ventas de los últimos
//7 días. Por cada día se debe ingresar una cantidad desconocida de productos vendidos y sus precios. Finaliza el proceso de ingreso al introducir un 0 (cero).
//
//Por cada venta se ingresa:
//
//Código del producto, un número entero, de 1 a 9999
//
//Cantidad vendida, un número entero, mayor a 0
//
//Precio unitario, un número real, mayor a 0
//
//Al finalizar cada día, el programa debe calcular la cantidad total de productos vendidos y el monto total de las ventas de ese día.
//
//Al finalizar los 7 días, el programa debe mostrar un resumen total que incluya: la cantidad total de productos vendidos, el monto total de las ventas, el día que se vendió más y el monto vendido ese día.

int Ejercicio_1(){
    int productCode=0;
    int amountSold=0;
    int dailyAmountSold=0;
    float dailySalesTotal=0;
    float salesTotal=0;
    int totalAmountSold=0;
    int maxDay;
    float maxAmountSold=0;
    float unitPrice=0;

    printf("========================\n");
    printf("Calculadora de Ventas\n");
    printf("========================\n");
    for(int i = 0; i < 7; i++){
        printf("Dia %d\n",i+1);
        while(true){
            printf("Ingrese el codigo del producto (0 para terminar dia)\n");
            std::cin >> productCode;
            if(productCode == 0){
                break;
            }
            if (productCode < 0 || productCode > 9999){
                printf("Codigo invalido. Debe estar entre 1 y 9999. Intente de nuevo\n");
                continue;
            }
            printf("Ingrese la cantidad vendida\n");
            std::cin >> amountSold;
            totalAmountSold += amountSold;
            dailyAmountSold += amountSold;
            printf("Ingrese el precio unitario\n");
            std::cin >> unitPrice;
            salesTotal += unitPrice * amountSold;
            dailySalesTotal += unitPrice * amountSold;

        }
        printf("Para el dia %d se vendieron %d productos por un monto de %0.2f\n", i+1, dailyAmountSold, dailySalesTotal);
        if(dailySalesTotal> maxAmountSold){
            maxAmountSold = dailySalesTotal;
            maxDay = i + 1;
        }
        dailySalesTotal= 0;
        dailyAmountSold=0;
    }
    printf("##############################################\n");
    printf("##############################################\n");
    printf("En total se vendieron %d productos por un total de %0.2f\n", totalAmountSold, salesTotal);
    printf("##############################################\n");
    printf("El dia que mas se vendio fue el dia %d con un monto de %0.2f", maxDay,maxAmountSold);




    return 0;
}
