Proceso Ej13
	Definir sal_mensual Como Real;
	Definir antig Como Entero;
	Definir util Como Real;
	Escribir "Ingrese el salario mensual (en pesos):";
	Leer sal_mensual;
	Escribir "Ingrese la antigüedad (en años):";
	Leer antig;
	Si (antig < 1) Entonces
		util <- sal_mensual * 0.05;
	Sino
		Si (antig >= 1 & antig < 2) Entonces
			util <- sal_mensual * 0.07;
		Sino
			Si (antig >= 2 & antig < 5) Entonces
				util <- sal_mensual * 0.10;
			Sino
				Si (antig >= 5 & antig < 10) Entonces
					util <- sal_mensual * 0.15;
				Sino
					util <- sal_mensual * 0.20;
				FinSi
			FinSi
		FinSi
	FinSi
	Escribir "La utilidad que recibe el trabajador es $", util;
FinProceso