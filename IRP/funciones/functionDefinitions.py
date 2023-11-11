from sympy import Interval, Symbol, S, sqrt, solveset, Eq, Gt, Lt
from sympy.calculus.util import continuous_domain

def not_function(func, *args):
    def wrapper(args):
        try:
            return func(args)
        except Exception:
            return f"{args} no es funcion de {func.__name__}"
    wrapper.__name__ = func.__name__
    return wrapper

@not_function
def interseccion(func):
    x_0 = func(0)
    if x_0 not in S.Reals:
        return f"{func.__name__} no tiene interseccion"
    return (0, x_0)

def conjuntos(func, symbol):
    zero = solveset(Eq(func(symbol), 0), symbol, domain=S.Reals)
    positive = solveset(Gt(func(symbol), 0), symbol, domain=S.Reals)
    negative = solveset(Lt(func(symbol), 0), symbol, domain=S.Reals)
    return {'C0':zero, 'C+':positive, 'C-': negative}

@not_function        
def ejemplo_4(x):
    return (12*x+3)/(4*x-8)

@not_function        
def ejemplo_5_a(x):
    return 2/(6*x+2)

@not_function        
def ejemplo_5_b(x):
    return sqrt(x)    

@not_function        
def ejemplo_5_b(x):
    return sqrt(x)   

@not_function        
def ejemplo_5_c(x):
    return sqrt(10*x+6)   

@not_function        
def ejemplo_5_d(x):
    return 13/sqrt(2*x+8) 

@not_function        
def ejemplo_5_e(x):
    return 6/ (3 - (sqrt(x-2)))

@not_function        
def pregunta_5(x):
    return sqrt(-2*x+9)
