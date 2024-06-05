#include <stdio.h>
#include "Ejercicio_1.h"
#include "Ejercicio_2.h"
#include "Ejercicio_3.h"
void lolaRGBColor(RGBColor &color) {
    printf("Entre");
    printf("Se seteo red con :%d\n", color.red);
    printf("Se seteo green con :%d\n", color.green);
    printf("Se seteo blue con :%d\n", color.blue);
    return;
    }
int main(){
    lolaRGBColor(RGBColor::Red());
    Ejercicio_2();
    return 0;
}
