Proceso Ej12
	Definir horas_trab Como Entero;
	Definir pago_hs Como Real;
	Definir tot_pago Como Real;
	Definir horas_extra Como Entero;
	Definir p_ext Como Real;
	Definir p_doble Como Real;
	Definir p_triple Como Real;
	Escribir "Ingrese la cantidad de Hs trabajadas: ";
	Leer horas_trab;
	Escribir "Ingrese la cantidad de pesos que se paga por cada Hs de trabajo:";
	Leer pago_hs;
	Si (horas_trab <= 40) Entonces
		tot_pago <- horas_trab * pago_hs;
	Sino
		horas_extra <- horas_trab - 40;
		Si (horas_extra <= 8) Entonces
			p_ext <- horas_extra * pago_hs * 2;
		Sino
			p_doble <- 8 * pago_hs * 2;
			p_triple <- (horas_extra - 8) * pago_hs * 3;
			p_ext <- p_doble + p_triple;
		FinSi
		tot_pago <- 40 * pago_hs + p_ext;
	FinSi
	Escribir "El total a pagar es $", tot_pago;
FinProceso