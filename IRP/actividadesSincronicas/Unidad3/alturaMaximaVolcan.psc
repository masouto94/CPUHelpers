Proceso alturaMaximaVolcan
    Definir altura_inicial, v_inicial, vy, angulo,t_hmax,h_max, gravedad como Real;
    altura_inicial <- 1000;
    v_inicial <- 60;
    gravedad <- 0-10;
    Escribir  "Ingrese el angulo de la piedra";
    Leer angulo;
    vy <- v_inicial * SEN(angulo* PI/180);
    t_hmax <-  (0-vy)/gravedad;
    h_max <- altura_inicial + vy * t_hmax + gravedad * 0.5 * t_hmax^2;
    Escribir "La altura maxima alcanzada para ese angulo de lanzamiento es ", h_max;
FinProceso
