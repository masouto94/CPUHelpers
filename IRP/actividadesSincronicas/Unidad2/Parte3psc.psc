Funcion valorPos <- resolvente (a, b, c)
	Definir valorPos como Real;
	Definir denominador como Real;
	Definir raiz_ como Real;
	denominador <- 2 * a;
	raiz_ <- RC(b*b - 4 * a * c);
    valorPos<- (-b - raiz_) / denominador ;
FinFuncion

Proceso carrera
	Definir alturaDaniela como Real;
	Definir alturaLeon como Real;
	Definir velocidadLeon como Real;
	Definir resDaniela como Real;
	Definir resLeon como Real;
	
	Leer alturaDaniela,alturaLeon,velocidadLeon;
	resDaniela <- resolvente(-5,0,alturaDaniela);
	resLeon<- resolvente(-5,velocidadLeon,alturaLeon);
	Si resDaniela == resLeon Entonces
		Escribir 'Llegan al mismo tiempo';
	Sino
		Si resDaniela > resLeon Entonces
			Escribir 'Daniela Llega primero';
		Sino
			Escribir 'Leon llega primero';
		FinSi
		
	FinSi
FinProceso
