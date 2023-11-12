Proceso Ej5 
	Definir codigo_masc Como Caracter; 
	Definir codigo_fem Como Caracter; 
	Definir codigo_nb Como Caracter;
	Definir num_masc Como Entero; 
	Definir num_fem Como Entero; 
	Definir num_nb Como Entero;
	Definir total Como Entero;
	Definir porc_masc Como Real; 
	Definir porc_fem Como Real; 
	Definir porc_nb Como Real;
	codigo_masc <- "M";
	codigo_fem<- "F";
	codigo_nb <- "X";
	Escribir "Ingrese la cantidad masculinos, femenimos y no binarios:";
	Leer num_masc, num_fem, num_nb; 
	total <- num_masc + num_fem + num_nb; 
	porc_masc <- num_masc * 100 / total; 
	porc_fem <- num_fem * 100 / total;
	porc_nb <- num_nb * 100 / total; 
	Escribir "Los porcentajes son:";
	Escribir codigo_masc, " = " , porc_masc, "%";
	Escribir codigo_fem, " = " , porc_fem, "%";
	Escribir codigo_nb, " = " , porc_nb, "%";
FinProceso