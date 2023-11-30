Proceso coef_roz_dinamico
	Definir contador, v_cinco_m, e_cinetica Como Real;
	Definir masa, fuerza, fuerza_n, theta Como Real;
	Definir fx, trabajo_fx, fr_aux, mu_dinamico Como Real;
	Definir e_cinetica_acumulatoria Como Real;
	Definir delta_x Como Entero;
	delta_x <- 5;
	contador <-1;
	masa <- 20;
	fuerza <- 120;
	theta <- 37;
	Escribir 'Ingrese la velocidad a los 5m en m/s';
	Leer v_cinco_m;
	Si v_cinco_m== 0
		Entonces
		Escribir 'No se puede resolver';
	SiNo
	fx <- fuerza * COS(theta* PI/180);
	fuerza_n <- 0 - (masa * 10) + fuerza * SEN(theta* PI/180);
	trabajo_fx <- fx * delta_x * COS(0 * PI/180);
	fr_aux <- fuerza_n * delta_x * COS(180 * PI/180);
	e_cinetica <- 0.5 * masa * v_cinco_m^2;
	mu_dinamico <- (e_cinetica - trabajo_fx) / fr_aux;
	Escribir 'El mu dinamico es ', (-1* mu_dinamico);
	Escribir "##############";
	
	Mientras contador <= 10 Hacer
	
		e_cinetica_acumulatoria <- e_cinetica * (contador / 5);
		Escribir 'La energia cinetica en el metro ', contador, ' es ', e_cinetica_acumulatoria;
		contador <- contador +1;
	FinMientras
FinSi
FinProceso
