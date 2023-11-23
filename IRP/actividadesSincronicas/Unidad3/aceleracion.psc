Proceso aceleracion
	Definir angulo_a, masa_en_kg,fuerza_en_newtons, roz_e,roz_d Como Real;
	Definir acel, f_normal, fre, frd,px Como Real;
	Escribir "Ingrese el angulo_a";
	Leer angulo_a;
	Escribir "Ingrese la masa_en_kg";
	Leer  masa_en_kg;
	Escribir "Ingrese la fuerza_en_newtons";
	Leer fuerza_en_newtons;
	Escribir "Ingrese el coef rozamiento estatico";
	Leer  roz_e;
	Escribir "Ingrese el coef rozamiento dinamico";
	Leer roz_d;
	px <- SEN(angulo_a * PI/180) * masa_en_kg * 10;
	f_normal <- COS(angulo_a * PI/180) * masa_en_kg * 10;
	fre <- f_normal * roz_e;
	Si fuerza_en_newtons <= fre
		Entonces
		Escribir "El objeto no se mueve";
	SiNo
		
		frd <- f_normal * roz_d;
		acel <- (fuerza_en_newtons - px - frd)/masa_en_kg;
		Escribir "La aceleracion es ", acel, " m/s2";
		
	FinSi
FinProceso
