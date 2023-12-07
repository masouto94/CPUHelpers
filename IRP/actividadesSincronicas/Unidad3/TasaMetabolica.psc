Proceso TasaMetabolica
    Definir peso, altura, edad, tasa_metabolica como Real;
    Definir sexo Como Caracter;
    Escribir "Ingrese el peso en kilogramos: ";
    Leer peso;
    Escribir "Ingrese la altura en metros: ";
    Leer altura;
    Escribir "Ingrese la edad en a�os:";
    Leer edad;
    Escribir "Ingrese el sexo (F -> Femenino /M -> Masculino):";
    Leer sexo;
	Si (peso > 0 Y altura > 0 Y edad>0) Entonces
		Si sexo="F" Entonces
			tasa_metabolica <- 10*peso + 6.25*altura - 5*edad - 161;
		SiNo
			Si sexo="M" Entonces
				tasa_metabolica <- 10*peso + 6.25*altura - 5*edad + 5;
			Sino
				Escribir "Se har� una estimaci�n sin tener en cuenta el sexo.";
				tasa_metabolica <- 10*peso + 6.25*altura - 5*edad - 78;
			FinSi
		FinSi
		Escribir "La tasa metab�lica basal de esta persona es de aproximadamente", tasa_metabolica, " calor�as/dia.";
	Sino
		Escribir "Por favor, ingrese un peso, una altura y una edad v�lidos.";
	FinSi
	
FinProceso