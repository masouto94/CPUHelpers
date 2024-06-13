#include "colors.h"
#define CANT_COLORES 4
// RESULTS
#define CORRECTO 0
#define POSICION_INCORRECTA 1
#define INCORRECTO 2

#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C pantalla(0x27, 16, 2); // para el display PCF8574 (consultar si es este el que vamos a usar).

//Global vars
int selectorIndex = 0;
unsigned long blinkerMillisControl = 0;
unsigned long blinkerMillis;
String selectedColor = "";

String normalizeString(String color)
{
  int counter = 0;
  String normalized;
  for (size_t i = 0; color[i] != 0; i++)
  {
    counter++;
    normalized += color[i];
    if (counter == 8)
    {
      return normalized;
    };
  };
  for (int i = counter; i < 8; i++)
  {
    normalized += ' ';
  };
  return normalized;
};

void blinkScreen()
{
  switch (selectorIndex)
  {
  case 0:
    pantalla.setCursor(0, 0);
    break;
  case 1:
    pantalla.setCursor(8, 0);
    break;
  case 2:
    pantalla.setCursor(0, 1);
    break;
  case 3:
    pantalla.setCursor(8, 1);
    break;
  }
  pantalla.blink();
  if (blinkerMillis - blinkerMillisControl >= 50)
  {
    pantalla.noBlink();
    blinkerMillisControl = blinkerMillis;
  }
}

void calculateCursor()
{
  // IMPLEMENTAR CON MILLIS
  switch (selectorIndex)
  {
  case 0:
    pantalla.setCursor(0, 0);
    selectedColor = "";
    blinkScreen();
    break;
  case 1:
    pantalla.setCursor(8, 0);
    selectedColor = "";
    blinkScreen();
    break;
  case 2:
    pantalla.setCursor(0, 1);
    selectedColor = "";
    blinkScreen();
    break;
  case 3:
    pantalla.setCursor(8, 1);
    selectedColor = "";
    blinkScreen();
    break;
  }
}
void resetCursor()
{
  pantalla.setCursor(0, 0);
  selectorIndex = 0;
  selectedColor = "";
}
void renderSelection(String mode)
{
  if (mode == "adelante")
  {
    if (selectorIndex < 3)
    {
      selectorIndex++;
    }
  }
  else if (mode == "atras")
  {
    if (selectorIndex > 0)
    {
      selectorIndex--;
    }
  }
  calculateCursor();
}

class SecretCode
{
public:
  RGBColor code[4];
  SecretCode()
  {
    RGBColor colours[7] = {
        ColorFactory::Red(),
        ColorFactory::Green(),
        ColorFactory::Blue(),
        ColorFactory::Yellow(),
        ColorFactory::Orange(),
        ColorFactory::White(),
        ColorFactory::Violet()

    };

    for (int i = 0; i < 4; i++)
    {
      code[i] = colours[random(1, 17) % 7];
    }
  }
  SecretCode(RGBColor colorsArray[])
  {
    for (int i = 0; i < 4; i++)
    {
      code[i] = colorsArray[i];
    }
  }

  /*
        Compara los colores ingresados con los colores a adivinar y devuelve por parametro un array con el estado de cada uno.
        'resultado' tiene que tener espacio para CANT_COLORES elementos.
        */
  static void verificar_aciertos(RGBColor colores_a_adivinar[], RGBColor colores_ingresados[], int *resultado)
  {
    int flags[CANT_COLORES] = {INCORRECTO, INCORRECTO, INCORRECTO};

    // Primera recorrida para chequear los colores que estan en la posicion correcta
    for (int i = 0; i < CANT_COLORES; i++)
    {
      if (colores_ingresados[i].name == colores_a_adivinar[i].name)
      {
        resultado[i] = CORRECTO;
      }
      else
      {
        resultado[i] = INCORRECTO; // Cargo INCORRECTO por defecto para evitar valores basura
      }
    }

    // Segunda recorrida para chequear los colores que estan en una posicion incorrecta
    for (int cont_input = 0; cont_input < CANT_COLORES; cont_input++)
    {
      if (resultado[cont_input] != CORRECTO)
      {
        for (int cont_respuesta = 0; cont_respuesta < CANT_COLORES; cont_respuesta++)
        {
          if (flags[cont_respuesta] != POSICION_INCORRECTA && resultado[cont_input] != POSICION_INCORRECTA && resultado[cont_respuesta] != CORRECTO)
          {

            if (colores_a_adivinar[cont_respuesta].name == colores_ingresados[cont_input].name)
            {
              flags[cont_respuesta] = POSICION_INCORRECTA;
              resultado[cont_input] = POSICION_INCORRECTA;
              break;
            }
          }
        }
      }
    }
  }

  // Devuelve true si el jugador acertó todos los colores, y false en caso contrario
  static bool verificar_victoria(int resultado[])
  {
    for (int i = 0; i < CANT_COLORES; i++)
    {
      if (resultado[i] != CORRECTO)
      {
        return false;
      }
    }
    return true;
  }

  static void imprimir_resultado(int resultado[], RGBColor userInput[])
  {
    pantalla.clear();

    for (int i = 0; i < CANT_COLORES; i++)
    {
      selectorIndex = i;
      calculateCursor();
      String analysis = userInput[i].name;
      switch (resultado[i])
      {
      case CORRECTO:
        analysis.concat(" O");
        pantalla.print(normalizeString(analysis));
        break;
      case POSICION_INCORRECTA:
        analysis.concat(" X");
        pantalla.print(normalizeString(analysis));
        break;
      case INCORRECTO:
        analysis.concat(" -");
        pantalla.print(normalizeString(analysis));
        break;
      }
    }
    delay(3000);
    pantalla.clear();
    resetCursor();
  }

  void printCode()
  {
    Serial.print('[');
    Serial.print(this->code[0].name);
    Serial.print(", ");

    int i = 1;
    while (i < CANT_COLORES - 1)
    {
      Serial.print(this->code[i].name);
      Serial.print(", ");
      i++;
    }
    Serial.print(this->code[i].name);
    Serial.println(']');
  }

  void showCode()
  {
    for (int i = 0; i < CANT_COLORES; i++)
    {
      selectorIndex = i;
      calculateCursor();
      pantalla.print(normalizeString(this->code[i].name));
    }
  }
};
