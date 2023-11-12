Proceso Ej9
	Definir horas_trab Como Entero;
	Definir horas_extra Como Entero;
	Definir salario_sem Como Entero;
	Escribir "Ingrese la cantidad de horas trabajadas en la semana:";
	Leer horas_trab;
	Si (horas_trab > 40) Entonces
		horas_extra <- horas_trab - 40;
		salario_sem <- horas_extra * 20 + 40 * 16;
	Sino
		salario_sem <- horas_trab * 16;
	FinSi
	Escribir "El salario semanal es $", salario_sem;
FinProceso