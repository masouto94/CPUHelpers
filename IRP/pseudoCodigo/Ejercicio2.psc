Proceso Ej2
	Definir sueldo_base Como  Real               ;
	Definir venta1 Como Real;
	Definir venta2 Como Real;
	Definir venta3 Como Real;
    Definir total_vta Como Real;
	Definir comision Como Real;
	Definir sueldo_tot Como Real;
	Escribir "Ingrese el monto del sueldo base y las 3 ventas realizadas:";
	Leer sueldo_base, venta1, venta2, venta3;
	total_vta <- venta1 + venta2 + venta3;
	comision <- total_vta * 0.10;
	sueldo_tot <- sueldo_base + comision;
	Escribir "El sueldo total es $", sueldo_tot, " y las comisiones son $", comision;
FinProceso