Proceso Ej4
    Definir calif1 Como Entero;
    Definir calif2 Como Entero;
    Definir calif3 Como Entero;
    Definir exam_f Como Entero;
    Definir trab_f Como Entero;
    Definir prom Como Real;
    Definir calif_final Como Real;
    Definir porc_par como Real;
    Definir porc_ef como Real;
    Definir porc_tf como Real;
	
    Escribir "Ingrese las 3 calificaciones parciales, la nota de examen final y del trabajo final:";
    Leer calif1, calif2, calif3, exam_f, trab_f;
    prom <- (calif1 + calif2 + calif3)/3;
    porc_par <- prom * 0.55;
    porc_ef <- exam_f * 0.30;
    porc_tf <- trab_f * 0.15;
    calif_final <- porc_par + porc_ef + porc_tf;
    Escribir "La calificacion final es ", calif_final;
FinProceso