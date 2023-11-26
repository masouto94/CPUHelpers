import math
#Problema 1 de la guia

'''
Se aplica sobre un cuerpo una F = 500 N en un angulo a. Se desplaza 20 M. Calcular Tf para los valores de a = [0,45,60,90,120,180] 
'''

F = 500
deltaX = 20
conjunto_a = { a: math.radians(a) for a in [0,45,60,90,120,180,270]}

#Siendo Tf = F * delta X * cos alfa
def calculo_trabajo(F, delta, alfa):
    return F*delta* round(math.cos(alfa),2)

print(conjunto_a)
for key,angulo in conjunto_a.items():
    print(f"Para el angulo {key} el trabajo es {calculo_trabajo(F,deltaX,angulo)} J")