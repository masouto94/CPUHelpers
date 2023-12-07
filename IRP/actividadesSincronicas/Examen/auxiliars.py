#ejercicio 1
def ecuacion_1(x):
    nom = (pow(x,2) - 25) * (x+2)
    den = (2*x - 10)
    return nom / den
# print(ecuacion_1(-2))
# print(ecuacion_1(-5))

#ejercicio 2
def ecuacion_2(x):
    return (-2 * x) + 10 >= 0

for i in range(-15,10):
    print(i, ecuacion_2(i)) 