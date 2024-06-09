#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "colors.h"
#define CANT_COLORES 4
#define MAX_INTENTOS 3
#define DEBUG // Para que se impriman por pantalla los resultados, y para poder ingresar valores por consola

//std::srand(std::time(NULL));

typedef enum {
  AMARILLO,
  BLANCO,
  NARANJA,
  VERDE,
  AZUL,
  ROJO,
  VIOLETA
} colores_t;


typedef enum {
  CORRECTO,
  POSICION_INCORRECTA,
  INCORRECTO
} resultado_t;


void mostrar_colores(RGBColor colores[]) {
    putchar('[');
    for (size_t i = 0; i < CANT_COLORES; i++) {
        if(colores[i].name.compareTo("Yellow") == 0) {
            printf("Amarillo");
        } else if(colores[i].name.compareTo("White") == 0) {
            printf("Blanco");
        } else if(colores[i].name.compareTo("Orange") == 0) {
            printf("Naranja");
        } else if(colores[i].name.compareTo("Green") == 0) {
            printf("Verde");
        } else if(colores[i].name.compareTo("Blue") == 0) {
            printf("Azul");
        } else if(colores[i].name.compareTo("Red") == 0) {
            printf("Rojo");
        } else if(colores[i].name.compareTo("Violet") == 0) {
            printf("Violeta");
        } else {
            printf("ERROR");
        }
        printf("%s", i != CANT_COLORES - 1 ? ", " : "]");
    }
}

void mostrar_resultado(resultado_t resultado[]) {
  for (size_t i = 0; i < CANT_COLORES; i++) {
    /*
    Serial.print("Resultado para el color ");
    Serial.print(i);
    Serial.print(": ");
    */
    switch (resultado[i]) {
      case CORRECTO:
        printf("O");
        break;
      case POSICION_INCORRECTA:
        printf("X");
        break;
      case INCORRECTO:
        printf("-");
        break;
    }
  }
}



class SecretCode{

      public:
        RGBColor code[4];
        SecretCode(){
            RGBColor colours[7] = {
                ColorFactory::Red(),
                ColorFactory::Green(),
                ColorFactory::Blue(),
                ColorFactory::Yellow(),
                ColorFactory::Orange(),
                ColorFactory::White(),
                ColorFactory::Violet()

                };

            for(int i=0; i<4;i++){
            code[i] = colours[rand() % 7];
            }
          }
        SecretCode(RGBColor colorsArray[]){
            for(int i=0; i<4;i++){
                code[i] = colorsArray[i];
            }
          }

        /*
        Compara los colores ingresados con los colores a adivinar y devuelve por parametro un array con el estado de cada uno.
        'resultado' tiene que tener espacio para CANT_COLORES elementos.
        */
        static void verificar_aciertos(RGBColor colores_a_adivinar[], RGBColor colores_ingresados[], resultado_t *resultado) {
          resultado_t flags[CANT_COLORES] = {INCORRECTO, INCORRECTO, INCORRECTO};
          
          // Primera recorrida para chequear los colores que estan en la posicion correcta
          for(size_t i = 0; i < CANT_COLORES; i++) {
            if(colores_ingresados[i].name == colores_a_adivinar[i].name) {
              resultado[i] = CORRECTO;
            } else {
              resultado[i] = INCORRECTO; // Cargo INCORRECTO por defecto para evitar valores basura
            }
          }

          // Segunda recorrida para chequear los colores que estan en una posicion incorrecta
          for (size_t cont_input = 0; cont_input < CANT_COLORES; cont_input++) {
            if(resultado[cont_input] != CORRECTO) {
              for (size_t cont_respuesta = 0; cont_respuesta < CANT_COLORES; cont_respuesta++) {
                if (flags[cont_respuesta] != POSICION_INCORRECTA &&
                        resultado[cont_input] != POSICION_INCORRECTA &&
                        resultado[cont_respuesta] != CORRECTO) {

                  if(colores_a_adivinar[cont_respuesta].name == colores_ingresados[cont_input].name) {
                    flags[cont_respuesta] = POSICION_INCORRECTA;
                    resultado[cont_input] = POSICION_INCORRECTA;
                    break;
                  }
                }
              }
            }
          }
        }
    };

// Devuelve true si el jugador acertó todos los colores, y false en caso contrario
bool verificar_victoria(resultado_t resultado[]) {
  for (size_t i = 0; i < CANT_COLORES; i++) {
    if (resultado[i] != CORRECTO) {
      return false;
    }
  }
  return true;
}

// TODO: Adaptar a Arduino (digitalRead, pasar cosas a loop y setup, etc)
void comenzar_juego() {
    // Se elige un patron de colores aleatorio
    srand(time(NULL));

    //RGBColor cpuSecretCode[4] = {ColorFactory::Red(), ColorFactory::Blue(), ColorFactory::Orange(), ColorFactory::Violet()};
    /*
    colores_t color1 = (colores_t) rand() % CANT_COLORES;
    colores_t color2 = (colores_t) rand() % CANT_COLORES;
    colores_t color3 = (colores_t) rand() % CANT_COLORES;
*/

    //RGBColor userSecretCode[4] = {ColorFactory::Red(), ColorFactory::Blue(), ColorFactory::Orange(), ColorFactory::Violet()};
    RGBColor userSecretCode[4];

    SecretCode juegoMaquina = SecretCode();
    SecretCode juegoJugador = SecretCode(userSecretCode);

#ifdef DEBUG
    printf("La respuesta es: ");
    mostrar_colores(juegoMaquina.code);
    putchar('\n');
#endif

    // Se le pide al usuario que ingrese una combinacion de colores
    size_t turno = 1;
    bool victoria = false;
    while(turno <= MAX_INTENTOS && victoria == false) {
        printf("Turno %zd\n", turno);
        //colores_t intento[CANT_COLORES];

        // TODO Leer combinacion de colores
#ifdef DEBUG
        printf("0 - AMARILLO\n1 - BLANCO\n2 - NARANJA\n3 - VERDE\n4 - AZUL\n5 - ROJO\n6 - VIOLETA\n");
        for (size_t i = 0; i < CANT_COLORES; i++) {
            int opcion;
            scanf(" %d", &opcion);
            if(opcion == AMARILLO) {
                userSecretCode[i] = ColorFactory::Yellow();
            } else if(opcion == BLANCO) {
                userSecretCode[i] = ColorFactory::White();
            } else if(opcion == NARANJA) {
                userSecretCode[i] = ColorFactory::Orange();
            } else if(opcion == VERDE) {
                userSecretCode[i] = ColorFactory::Green();
            } else if(opcion == AZUL) {
                userSecretCode[i] = ColorFactory::Blue();
            } else if(opcion == ROJO) {
                userSecretCode[i] = ColorFactory::Red();
            } else if(opcion == VIOLETA) {
                userSecretCode[i] = ColorFactory::Violet();
            }
        }
        printf("Elegiste: \n");
        mostrar_colores(userSecretCode);
        putchar('\n');
#endif
        // analogRead(.....);


        // Se compara esa combinacion con los colores a adivinar
        resultado_t resultado[CANT_COLORES];
        SecretCode::verificar_aciertos(juegoMaquina.code, userSecretCode, resultado);

#ifdef DEBUG
        mostrar_resultado(resultado);
        putchar('\n');
        putchar('\n');
#endif
        if(verificar_victoria(resultado) == true)
            victoria = true;

        turno++;
    }

    if(victoria == true)
        printf("Ganaste!\n");
    else {
        printf("Perdiste :(\nLa respuesta era: ");
        mostrar_colores(juegoMaquina.code);
        putchar('\n');
    }
}