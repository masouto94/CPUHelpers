#MRU
def calcular_velocidad(xf,tf,x0=0,t0=0):
    delta_x=xf-x0
    delta_t=tf-t0
    return delta_x/delta_t
#La casa de Alberto se encuentra a 900m en línea recta de la casa de Diana. 
#Caminando con velocidad constante, Alberto tarda 10 minutos en cubrir esa distancia, 
#mientras que Diana la recorre en 15 minutos. 
#Cierto día salen ambos a las 15:00 horas, cada uno desde su casa y dirigiéndose a la casa del otro.
velAlberto = calcular_velocidad(900,(10*60))
velDiana = calcular_velocidad(900,(15*60))
print(velAlberto, "M/S")
print(velDiana, "M/S")

#Comparten mismo sistema de referencia así que uno está en 0 y otro en -900 desde el punto de vista de alberto
ecAlberto = f"x1 =  {velAlberto} m/s *t"
ecDiana = f"x2 = 900 -  {velDiana} m/s *t"
print(ecAlberto)
print(ecDiana)
#Para que x1(t) = x2(t)
ecuEncuentro = f"{velAlberto} m/s *t = 900 - {velDiana} m/s *t"
print(ecuEncuentro)
res = 900/(velAlberto+velDiana) 
print(res/60)

checkAlberto=900- (1.5*res)
checkd = res
print(checkAlberto,checkd)
print(1.5*res)

print("#"*10)
#Problema 2
def kmh_a_ms(kmh):
    return (kmh)/3.6
#Manuel viaja en auto desde Buenos Aires hasta Mar del plata por la ruta 2 y 
# se mueve a velocidad constante de 85 km/h
vel_manuel = 85
vel_julieta = 75
#¿A cuantós km de Buenos Aires estará luego de 1:30 h?
dist= vel_manuel * 1.5
print(dist)
#En m/s
dist_ms_manuel = kmh_a_ms(vel_manuel)
dist_ms_julieta = kmh_a_ms(vel_manuel)
print(dist_ms_manuel)
#Encuentro
ecuacion = f"{vel_manuel} km/h *t = {vel_julieta}km/h *t + 30km"
print(ecuacion) #resultado 3
print(f'''
Resolucion:
{vel_manuel} km/h *t - {vel_julieta}km/h *t  = 30km
10 km/h * t = 30km
t = 30km / 10 km/h ---se eliminan los km
t = 3
''')
print(vel_manuel*3, vel_julieta*3+30)

print("#"*10)
#Problema 3
"""
Dos corredores Lautaro y Nicolás corren en sentidos opuestos acercándose, sobre una pista recta. 
Corren a velocidad constante. 
Lautaro corre a 4,5m/s y Nicolás a 3,5m/s.
Inicialmente, la distancia que los separa es 100m. 
"""
vel_lautaro = 4.5
vel_nicolas = 3.5
#¿Cuánto tiempo después de salir se encuentran ambos corredores?

ecuacionCorredores = f"{vel_lautaro} m/s * t = {vel_nicolas} m/s * t + 100m"
print(ecuacionCorredores)
solucion=f'''
4.5 m/s * t = -3.5 m/s * t + 100m
(4.5 m/s + 3.5 m/s) * t = 100m
8 m/s * t = 100 m
t = 100m / 8m/s
t = {100/8}
'''
print(solucion)
print(4.5 * 12.5)
print(100 - 3.5  * 12.5 )


print("#"*10)
#Problema 4
'''
Dos motociclistas corren en una ruta rectilínea de 40km de longitud. 
El primero recorre la ruta con una velocidad constante de 55km/h. 
El segundo parte 3,5 minutos después del primero, pero cruza la línea final al mismo tiempo. 
¿Con qué velocidad constante en km/h recorrió la ruta el segundo motociclista?
'''

moto1=kmh_a_ms(55)
tot_time = 40000/moto1
otro = tot_time - (3.5*60)
print(moto1,tot_time,otro)
print(40000/otro)
print(16.61*3.6)

#resolver por regla de 3...no pude de otra

