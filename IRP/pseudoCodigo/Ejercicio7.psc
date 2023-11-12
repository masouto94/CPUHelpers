Proceso Ej7
    Definir calif1 Como Entero;
    Definir calif2 Como Entero;
    Definir calif3 Como Entero;
    Definir promedio Como Real;
    Escribir "Ingrese las 3 calificaciones:";
    Leer calif1, calif2, calif3;
    promedio <- (calif1 + calif2 + calif3)/3;
    Si (promedio >= 70) Entonces
        Escribir "Estudiante aprobado";
    Sino
        Escribir "Estudiante reprobado";
    FinSi
FinProceso
