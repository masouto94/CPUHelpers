#include <stdio.h>

int main(){
    int a = 12;
    int b = 44;

    int result = a+b;
    printf("Result %d\n", result);
    // Si mandas dos int a dividir se van a hacer enteros
    int divisor=3;
    int dividendo=10;
    printf("bad result %d\n", dividendo/divisor);
    //Hay o que guardarlo como float o castearlo
    float divisor_1=3;
    int dividendo_1=10;
    float result_1 = dividendo_1/divisor_1;
    printf("good result %f\n", result_1);
    printf("Alt good result %f\n", dividendo/(float) 3);

    //++a y a++ es diferente
    //a++ suma a la variable ++a es += para la variable a la que se asigna
    return 0;
}
