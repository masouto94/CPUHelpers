Proceso Ej3
	Definir total_comp Como Real;
	Definir desc Como Real;
	Definir pagar Como Real;
	Escribir "Ingrese el monto total de la compra:";
	Leer total_comp;
	desc <- total_comp * 0.15;
	pagar <- total_comp - desc;
	Escribir "Se debe pagar $", pagar;
FinProceso