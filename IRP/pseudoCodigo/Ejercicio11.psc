Proceso Ej11
    Definir num1 Como Real;
    Definir num2 Como Real;
    Definir num3 Como Real;
	Definir mayor Como Real;
    Escribir "Ingrese 3 numeros distintos:";
    Leer num1, num2, num3;
    Si (num1 > num2 & num1 > num3) Entonces
		mayor  <- num1;
	Sino 
		Si (num2 > num1 & num2 > num3) Entonces
            mayor <- num2;
		Sino
            mayor <- num3;
		FinSi
	FinSi 
	Escribir "El numeros mayor es ",mayor;
FinProceso