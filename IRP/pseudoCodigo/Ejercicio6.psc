Proceso Ej6
    Definir porc_int Como Real;
    Definir capital Como Real;                    ;
    Definir interes Como Real;
    Definir capital_final Como Real;                    ;
    Escribir "Ingrese el porcentaje de intereses como decimal y el capital invertido:";
    Leer porc_int, capital;
    interes <- capital * porc_int;
    Si (interes > 7000) Entonces
		capital_final <- capital + interes;
		Escribir "El capital final es $", capital_final;
	SiNo
		Escribir "Los intereses no superan los 7000 para la inversión";
    FinSi
FinProceso