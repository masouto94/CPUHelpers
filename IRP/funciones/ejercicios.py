from functionDefinitions import *

x = Symbol('x')
print("Ejemplo 4")
print("#"*10)
print("Evaluando la func con los valores que pide la consigna")
print("f(0) = ",ejemplo_4(0))
print("f(1) = ",ejemplo_4(1))
print("f(-1) = ",ejemplo_4(-1))
print("f(3) = ",ejemplo_4(3))
print("f(2) = ",ejemplo_4(2))
print("#"*10)
#El dominio se saca obteniendo en que valores el denominador de la funcion no es 0 y no tiene 
# ninguna operacion prohibida. Ej la raiz cuadrada de un numero negativo
#Es decir que, en este caso, el denominador debe ser distinto de 2
dominio_ejemplo_4=continuous_domain(ejemplo_4(x),x,S.Reals)
print("el dominio es ", dominio_ejemplo_4)
print("16 esta dentro del dominio de la func?", 16 in dominio_ejemplo_4)
print("2 esta dentro del dominio de la func?",2 in dominio_ejemplo_4)

#La interseccion es el punto 0 y f(0). Es decir x=0 e y= f(0)
print("la interseccion es ", interseccion(ejemplo_4))
#Se puede probar con otros
print("la interseccion de 5_b es ", interseccion(ejemplo_5_b))
#Este da que no tiene interseccion porque no es un numero real ya que si f(0) queda en el denominador
# 6 / 3−√−2
# = 3−i√2
print("la interseccion de 5_e es ", interseccion(ejemplo_5_e))


print("Ejemplo 5")
print("#"*10)
#En este caso, para que 6x+2 sea 0, x debe ser -1/3
#Ya que 6 * (- 1/3)  + 2 = 0
#El return de estas funciones de dominio devuelve intervalos. A menos que diga Interval.open es cerrado []
dominio_ejemplo_5_a=continuous_domain(ejemplo_5_a(x),x,S.Reals)
print("dominio_ejemplo_5_a",dominio_ejemplo_5_a)
print(f"-1/3 esta dentro del dominio de la func?",-1/3 in dominio_ejemplo_5_a)

#Y asi sucesivamente
dominio_ejemplo_5_b=continuous_domain(ejemplo_5_b(x),x,S.Reals)
print("dominio_ejemplo_5_b",dominio_ejemplo_5_b)
print(f"-13 esta dentro del dominio de la func?",-13 in dominio_ejemplo_5_b)

dominio_ejemplo_5_c=continuous_domain(ejemplo_5_c(x),x,S.Reals)
print("dominio_ejemplo_5_c",dominio_ejemplo_5_c)
print(f"-7 esta dentro del dominio de la func?",-7 in dominio_ejemplo_5_c)

dominio_ejemplo_5_d=continuous_domain(ejemplo_5_d(x),x,S.Reals)
print("dominio_ejemplo_5_d",dominio_ejemplo_5_d)
print(f"-10 esta dentro del dominio de la func?",-13 in dominio_ejemplo_5_d)

dominio_ejemplo_5_e=continuous_domain(ejemplo_5_e(x),x,S.Reals)
print("dominio_ejemplo_5_e",dominio_ejemplo_5_e)
print(f"1 esta dentro del dominio de la func?",-13 in dominio_ejemplo_5_b)

print("Ejemplo 7")
print("#"*10)
#Con la funcion conjuntos, pasamos la ecuacion y el simbolo y nos devuelve un diccionario con
#los conjuntos cero, positivo y negativo
print(conjuntos(ejemplo_4, x))
#se puede probar con otros...
print(conjuntos(ejemplo_5_c, x))
print("#"*10)