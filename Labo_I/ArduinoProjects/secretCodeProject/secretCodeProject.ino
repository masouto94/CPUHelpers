#include "codigoSecreto.h"
#include "music.h"
#define BLUEPIN 9
#define REDPIN 10
#define GREENPIN 5
#define POTE A1
#define BOTONADEL 4
#define BOTONATRAS 7
#define BOTONCONF 3
#define APRETADO HIGH
#define NOAPRETADO LOW
#define ESTADO_INICIO 0
#define ESTADO_SELECCION 1
#define ESTADO_CONFIRMACION 2
#define ESTADO_VICTORIA 3
#define ESTADO_DERROTA 4
#define MAX_INTENTOS 4


int estadoActual = ESTADO_INICIO;
int estadoBotonAdelAnterior = LOW;
int estadoBotonAtrasAnterior = LOW;
int estadoBotonConfAnterior = LOW;
unsigned long millisBOTONADEL = 0;
unsigned long millisBOTONATRAS = 0;
unsigned long millisBOTONCONF = 0;


// Crea la lista de colores del usuario
RGBColor userInput[CANT_COLORES];

void setEstado(int estado)
{
  estadoActual = estado;
}
void setColor(RGBColor &color)
{
  analogWrite(REDPIN, color.red);
  analogWrite(GREENPIN, color.green);
  analogWrite(BLUEPIN, color.blue);
  if (selectedColor != color.name)
  {
    selectedColor = color.name;
    userInput[selectorIndex] = color;
    pantalla.print(normalizeString(selectedColor));
    calculateCursor();
  }
}
void renderColor(int poteInput)
{
  if (estadoActual != ESTADO_SELECCION)
  {
    return;
  }
  if (poteInput >= 4 && poteInput <= 171)
  {
    RGBColor color = ColorFactory::White();
    setColor(color);
  }
  else if (poteInput > 171 && poteInput <= 341)
  {
    RGBColor color = ColorFactory::Yellow();
    setColor(color);
  }
  else if (poteInput > 341 && poteInput <= 511)
  {
    RGBColor color = ColorFactory::Orange();
    setColor(color);
  }
  else if (poteInput > 511 && poteInput <= 681)
  {
    RGBColor color = ColorFactory::Red();
    setColor(color);
  }
  else if (poteInput > 681 && poteInput <= 851)
  {
    RGBColor color = ColorFactory::Blue();
    setColor(color);
  }
  else if (poteInput > 851 && poteInput <= 1021)
  {
    RGBColor color = ColorFactory::Green();
    setColor(color);
  }
  else if (poteInput > 1021 && poteInput <= 1023)
  {
    RGBColor color = ColorFactory::Violet();
    setColor(color);
  }
}


bool allColorsSelected(RGBColor colorList[])
{
  for (int i = 0; i < CANT_COLORES; i++)
  {
    if (colorList[i].name == "")
    {
      return false;
    }
  }
  return true;
}
void setup()
{
  pantalla.init();      // inicia el display.
  pantalla.backlight(); // prende los leds del display.
  pinMode(REDPIN, OUTPUT);
  pinMode(GREENPIN, OUTPUT);
  pinMode(BLUEPIN, OUTPUT);
  pinMode(POTE, INPUT);
  pinMode(BOTONADEL, INPUT);
  pinMode(BOTONATRAS, INPUT);
  pinMode(BOTONCONF, INPUT);
  randomSeed(analogRead(A0));
  Serial.begin(9600);
}

//declaramos variables de secretCode
SecretCode machineCode;
SecretCode userSecretCode;
unsigned int intento = 1;
unsigned long timeout = 0;
int resultado[4];
bool victoria = false;
void loop()
{
  unsigned long millisActuales = millis();
  blinkerMillis = millis();
  int pote = analogRead(POTE);
  int estadoBotonAdel = digitalRead(BOTONADEL);
  int estadoBotonAtras = digitalRead(BOTONATRAS);
  int estadoBotonConf = digitalRead(BOTONCONF);
  bool ready = false;
  // Inicializo para evitar errores en el switch
  // Se ve que no se pueden inicializar variables dentro
  // de un switch. Pero sí se pueden modificar
  switch (estadoActual)
  {
  case ESTADO_INICIO:
    machineCode = SecretCode();
    machineCode.printCode();
    setEstado(ESTADO_SELECCION);
    break;
  case ESTADO_SELECCION:
    if ((millisActuales - timeout) >= 60000)
    {
      setEstado(ESTADO_DERROTA);
    }
    else
    {
      renderColor(pote);
      if ((estadoBotonAdel == APRETADO) && (estadoBotonAdelAnterior == NOAPRETADO)) // BOTONADEL
      {
        if ((millisActuales - millisBOTONADEL) >= 10)
        {
          renderSelection("adelante");
          estadoBotonAdelAnterior = estadoBotonAdel;
        }
      }
      else
      {
        estadoBotonAdelAnterior = estadoBotonAdel;
        millisBOTONADEL = millisActuales;
      }
      if ((estadoBotonAtras == NOAPRETADO) && (estadoBotonAtrasAnterior == APRETADO)) // BOTONATRAS
      {
        if ((millisActuales - millisBOTONATRAS) >= 10)
        {
          renderSelection("atras");
          estadoBotonAtrasAnterior = estadoBotonAtras;
        }
      }
      else
      {
        estadoBotonAtrasAnterior = estadoBotonAtras;
        millisBOTONATRAS = millisActuales;
      }
      if ((estadoBotonConf == APRETADO) && (estadoBotonConfAnterior == NOAPRETADO) && allColorsSelected(userInput)) // BOTONADEL
      {
        if ((millisActuales - millisBOTONCONF) >= 10)
        {
          setEstado(ESTADO_CONFIRMACION);
          estadoBotonConfAnterior = estadoBotonConf;
        }
      }
      else
      {
        estadoBotonConfAnterior = estadoBotonConf;
        millisBOTONCONF = millisActuales;
      }
    }
    break;
  case ESTADO_CONFIRMACION:
    userSecretCode = SecretCode(userInput);
    SecretCode::verificar_aciertos(machineCode.code, userSecretCode.code, resultado);
    SecretCode::imprimir_resultado(resultado, userInput);
    victoria = SecretCode::verificar_victoria(resultado);
    if (victoria)
    {
      setEstado(ESTADO_VICTORIA);
    }
    else
    {
      if (intento <= MAX_INTENTOS)
      {
        pantalla.clear();
        pantalla.print("Te quedan: ");
        pantalla.print(String(MAX_INTENTOS - intento));
        pantalla.setCursor(0, 1);
        pantalla.print("intentos");
        intento++;
        while (!ready)
        {
          int confirm = digitalRead(BOTONCONF);
          if (confirm == HIGH)
          {
            pantalla.clear();
            resetCursor();
            ready = true;
            userInput[3].name = "";
            break;
          }
        }
        setEstado(ESTADO_SELECCION);
      }
      else
      {
        setEstado(ESTADO_DERROTA);
      }
    }
    break;
  case ESTADO_VICTORIA:
    pantalla.clear();
    pantalla.print("GANASTE");
    finalFantasy();
    pantalla.clear();
    machineCode.showCode();
    while (!ready)
    {
      int confirm = digitalRead(BOTONCONF);
      if (confirm == HIGH)
      {
        pantalla.clear();
        resetCursor();
        ready = true;
        userInput[3].name = "";
        break;
      }
    }
    intento = 1;
    resetCursor();
    setEstado(ESTADO_INICIO);
    timeout = millis();
    break;
  case ESTADO_DERROTA:
    pantalla.clear();
    pantalla.print("Perdiste");
    funeralMarch();
    pantalla.clear();
    machineCode.showCode();
    while (!ready)
    {
      int confirm = digitalRead(BOTONCONF);
      if (confirm == HIGH)
      {
        pantalla.clear();
        resetCursor();
        ready = true;
        userInput[3].name = "";
        break;
      }
    }
    intento = 1;
    setEstado(ESTADO_INICIO);
    timeout = millis();
    break;
  }
}
