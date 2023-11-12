Proceso Ej8
	Definir compra Como Real;
	Definir desc Como Real;
	Definir tot_pagar	Como Real;
	Escribir "Ingrese el valor de la compra:";
	Leer compra;
	Si (compra > 10000) Entonces
		desc <- compra * 0.20; 
	Sino 
		desc <- 0;
	FinSi 
	tot_pagar <- compra - desc;
	Escribir "El total a pagar es $", tot_pagar;
FinProceso