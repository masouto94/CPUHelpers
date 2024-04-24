#include <stdio.h>
#include <iostream>
#include <map>
int main(){
    std::map<char, float> notasMap;
    std::map<char, float> coleccion[7];
    float notasA = 0.0;
    float notasB = 0.0;
    int totalAlumnos = 0;
    float inputNota;
    int divisorPromedio = 0;
    float maxProm = 0.0;
    int anoPromMax;
    char divPromMax;


    printf("========================\n");
    printf("Calculadora de promedios\n");
    printf("========================\n");
    for(int i = 0; i < 7; i++){
        printf("A%co %d\n",164,i+1);
        printf("Ingrese las notas de la division A\n");
        do{

            scanf("%f", &inputNota);
            if(inputNota > 0){
                notasA += inputNota;
                divisorPromedio++;
            }
        } while(inputNota > 0);
        notasMap['A'] = notasA / divisorPromedio;
        if(maxProm < notasMap['A']){
            maxProm = notasMap['A'];
            anoPromMax = i+1;
            divPromMax = 'A';
        }
        totalAlumnos += divisorPromedio;

        divisorPromedio=0;
        notasA = 0.0;

        printf("Ingrese las notas de la division B\n");
        do{

            scanf("%f", &inputNota);
            if(inputNota > 0){
                notasB += inputNota;
                divisorPromedio++;
            }
        } while(inputNota > 0);
        notasMap['B'] = notasB / divisorPromedio;
        if(maxProm < notasMap['B']){
            maxProm = notasMap['B'];
            anoPromMax = i+1;
            divPromMax = 'B';
        }
        coleccion[i] = notasMap;
        totalAlumnos += divisorPromedio;
        divisorPromedio=0;  notasB = 0.0;
        notasMap.clear();
    }
    printf("Se procesaron %d alumnos\n", totalAlumnos);
    printf("Notas por a%co\n", 164);
    for(int i=0; i < 7; i++){
        printf("A%co %d", 164,i+1);
        printf("A: %0.2f\n", coleccion[i]['A']);
        printf("B: %0.2f\n", coleccion[i]['B']);
    }
    printf("El mayor promedio es %0.2f del a%co %d division %c",maxProm,164,anoPromMax,divPromMax);



    return 0;
}
