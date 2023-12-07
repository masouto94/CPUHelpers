Proceso AlgoritmoMaravilloso
	Definir cont como Entero;
    Definir num, suma como Real;
    suma <- 0;
    num <- 0;
    cont <- 0;
    
    Mientras (num >= -10) Hacer
        Escribir("Ingresa un número no menor a -10: ");
        Leer num;
        Si (num >= -10) entonces
            suma <- suma + num*num;
            cont <- cont + 1;
        FinSi
    FinMientras
    
    Si (cont > 0) entonces    
        Escribir "Obtenemos: ", suma," con ",cont," valores.";
    Sino
        Escribir "No se ingresaron números validos.";
    FinSi
FinProceso
