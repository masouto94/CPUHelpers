import numpy as np
import matplotlib.pyplot as plt
from scipy.integrate import odeint

class BacterialGrowthPlot():
	"""
	Clase para graficar el crecimiento bacteriano segun `eficiencia_division` 2 por default
	"""
	def __init__(self, eficiencia_division:float = 2) -> None:
		self.eficiencia_division = eficiencia_division
		self.poblacion_final = self.exponencial #FORMULA

	@property
	def eficiencia_division(self):
		return self._eficiencia_division

	@eficiencia_division.setter
	def eficiencia_division(self, eficiencia:float):
		if 1 >= eficiencia or eficiencia > 2:
			raise ValueError("La eficiencia tiene que ser mayor a 1 e igual o menor a 2")
		self._eficiencia_division = eficiencia
		return
	def exponencial(self, poblacion_inicial:int, tiempo:float) -> float:
		return poblacion_inicial*pow(self.eficiencia_division, tiempo)

	def graficar(self,tiempo: float, poblacion_t:int) -> None:#grafica
		fig, ax = plt.subplots()
		ax.plot(tiempo, poblacion_t, color='green')
		ax.set_ylabel('Poblacion bacterias(N)')
		ax.set_xlabel('Tiempo(t)')
		plt.yticks(rotation=45)
		plt.title('Poblacion bacterias(N) vs Tiempo(t)')
		return

	def carga_valor(self) -> float:
		print('NOTA: Ingrese el tiempo en horas')
		tiempo_transcurrido = float(input('Tiempo transcurrido: '))
		return tiempo_transcurrido

	def cargar_valores(self) -> tuple:
		poblacion_inicial = int(input('Ingrese poblacion inicial(Nro. entero): '))
		print('\n')
		print('NOTA: Ingrese el tiempo en horas')
		print('NOTA:si usa decimales, separarlos con "." NO con "," ')
		tiempo_transcurrido = float(input('Tiempo transcurrido: '))
		return poblacion_inicial, tiempo_transcurrido

	def dominio_imagen(self, tiempo_transcurrido:float, poblacion_inicial:int=100, NRO_PASOS:int = 50) -> tuple:
		tiempo = np.linspace(0, tiempo_transcurrido, NRO_PASOS) #Arma un tiempo de rango(0, tiempo_transcurrido) con objeto np array
		poblacion_t = np.apply_along_axis(lambda valor_t: self.poblacion_final(poblacion_inicial, valor_t), 0, tiempo) #Escala exponencial
		return tiempo, poblacion_t

	# #Esto no se usa en ningun lado
	# def funcion_poblacion_bacteriana(self):
	# 	poblacion_inicial, tiempo_transcurrido = self.cargar_valores()
	# 	poblacion_t = self.poblacion_final(poblacion_inicial, tiempo_transcurrido)
	# 	print(f'N(t={tiempo_transcurrido}) = {poblacion_inicial} * e^({tiempo_transcurrido})')
	# 	print(f'N(t={tiempo_transcurrido}) = {poblacion_t}')
	# 	print(f'Con una poblacion incial de {poblacion_inicial} bacterias, luego de {tiempo_transcurrido} unidades de tiempo tenemos {poblacion_t} bacterias')
	# 	return

	def graficar_crecimiento(self, tiempo_transcurrido:float , poblacion:int =100):
		tiempo ,poblacion_t = self.dominio_imagen(tiempo_transcurrido, poblacion)
		self.graficar(tiempo, poblacion_t)
		print(f'La poblacion en t=0 es {poblacion}')
		print(f'La poblacion en t={tiempo_transcurrido} es {poblacion_t[-1]}')
		plt.show()
		return
	
	def graficar_crecimiento_simple(self) -> None:
		tiempo_transcurrido = self.carga_valor()
		tiempo ,poblacion_t = self.dominio_imagen(tiempo_transcurrido)
		self.graficar(tiempo, poblacion_t)
		print(f'La poblacion en t=0 es {poblacion_t[0]}')
		print(f'La poblacion en t={tiempo_transcurrido} es {poblacion_t[-1]}')
		plt.show()
		return

	def graficar_crecimiento_con_poblacion(self) -> None:
		poblacion_inicial, tiempo_transcurrido = self.cargar_valores()
		tiempo ,poblacion_t = self.dominio_imagen(tiempo_transcurrido, poblacion_inicial)
		self.graficar(tiempo, poblacion_t)
		print(f'La poblacion en t=0 es {poblacion_t[0]}')
		print(f'La poblacion en t={tiempo_transcurrido} es {poblacion_t[-1]}')
		plt.show()
		return

class CellCyclePlot():
	def __init__(self,**kwargs) -> None:
		"""
		Clase para graficar crecimiento celular. Inicializa las siguientes variables en default:

		r = 0.1

		K = 1000

		N0 = 10

		t0 = 0

		tiempo_lag_max = 20

		tiempo_exp_max = 100

		tiempo_meseta_max = 200

		tiempo_dead_max = 250

		pasos = 100


		Se pueden modificar directamente: ej `self.N0 = 1234` setea ese valor para el objeto
		"""
    # CONFIGURACION
		self.r = 0.1  # Tasa de crecimiento intrínseco
		self.K = 1000  # Capacidad de carga del entorno
		self.N0 = 10  # Población inicial
		self.t0 = 0  # Tiempo inicial
		##TIEMPO POR FASES => lag - crecimiento exponencial - estancamiento/meseta - muerte
		self.tiempo_lag_max = 20
		self.tiempo_exp_max = 100
		self.tiempo_meseta_max = 200
		self.tiempo_dead_max = 250
		self.pasos = 100
		self.setear_atributos_custom(kwargs)
		

	def parametros(self):
		return list(self.__dict__.keys())
	
	def setear_atributos_custom(self,kwargs):
		allowed = set(self.__dict__.keys())
		kwargs_keys = set(kwargs.keys())
		if kwargs_keys.issubset(allowed):
			self.__dict__.update(kwargs)
			return
		raise KeyError(f"{kwargs_keys.difference(allowed)} no son claves permitidas. Solo se pueden setear {allowed}")

	
	# Definir la ecuación diferencial del crecimiento bacteriano logístico
	def crecimiento_bacteriano_logistico(self,N,t):
			dNdt = self.r * N * (1 - (N / self.K))
			return dNdt

	def graficar_crecimiento_celular(self):

		# Resolver la ecuación diferencial utilizando scipy *
		dominio_tiempo_lag = np.linspace(self.t0, self.tiempo_lag_max, self.pasos)
		dominio_tiempo_exp = np.linspace(self.tiempo_lag_max+1, self.tiempo_exp_max, self.pasos)
		dominio_tiempo_meseta = np.linspace(self.tiempo_exp_max+1, self.tiempo_meseta_max, self.pasos)
		dominio_tiempo_dead = np.linspace(self.tiempo_meseta_max+1, self.tiempo_dead_max, self.pasos)

		imagen_poblacion_exp = odeint(self.crecimiento_bacteriano_logistico, self.N0, dominio_tiempo_exp)#*
		imagen_poblacion_lag = np.full(dominio_tiempo_lag.shape[0], imagen_poblacion_exp[0])
		imagen_poblacion_meseta = np.full(dominio_tiempo_meseta.shape[0], imagen_poblacion_exp[-1])
		imagen_poblacion_dead = odeint(self.crecimiento_bacteriano_logistico, self.N0, dominio_tiempo_dead) #*

		dominio = np.concatenate((dominio_tiempo_lag, dominio_tiempo_exp, dominio_tiempo_meseta, dominio_tiempo_dead), axis=None)

		imagen = np.concatenate((imagen_poblacion_lag, imagen_poblacion_exp, imagen_poblacion_meseta, -imagen_poblacion_dead+975), axis=None)

		self.base_grafico(dominio, imagen)
		#Lineas adicionales
		plt.vlines(dominio_tiempo_lag[-1], color="red", ymin=5, ymax=self.K, linestyle='dashed')
		plt.vlines(dominio_tiempo_exp[-1], color="red", ymin=5, ymax=self.K, linestyle='dashed')
		plt.vlines(dominio_tiempo_meseta[-1], color="red", ymin=5, ymax=self.K, linestyle='dashed')
		plt.show()
		return

	def base_grafico(self, x,y):
		plt.plot(x, y, color='black')
		plt.ylabel('log(Nro.Celulas Viables)')
		plt.xlabel('Tiempo(t)')
		plt.yticks(rotation=45)
		plt.title('Curva de crecimiento bacteriano')
		plt.grid(True)


		plt.text(-10, 80,
						s = 'fase lag', size = 7, ha = 'left', va = 'top', alpha = 0.9,
						bbox = dict(boxstyle = 'round, pad = 0.4', ec = 'black', fc = 'white')
		)
		plt.text(45, 800,
						s = 'fase exp', size = 7, ha = 'left', va = 'top', alpha = 0.9,
						bbox = dict(boxstyle = 'round, pad = 0.4', ec = 'black', fc = 'white')
		)
		plt.text(150, 800,
						s = 'fase estancamiento', size = 7, ha = 'center', va = 'center', alpha = 0.9,
						bbox = dict(boxstyle = 'round, pad = 0.4', ec = 'black', fc = 'white')
		)
		plt.text(250, 400,
						s = 'fase muerte', size = 7, ha = 'right', va = 'bottom', alpha = 0.9,
						bbox = dict(boxstyle = 'round, pad = 0.4', ec = 'black', fc = 'white')
		)
		return