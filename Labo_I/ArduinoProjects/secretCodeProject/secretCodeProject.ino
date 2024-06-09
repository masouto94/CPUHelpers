#include <LiquidCrystal_I2C.h>
#include "codigoSecreto.h"
#include "colors.h"
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
#define BUZZER 2

//NOTES
#define NOTE_A6  1760
#define NOTE_F6  1397
#define NOTE_C7  2093


int estadoActual = ESTADO_INICIO;

char* selectedColor = "";
int selectorIndex = 0;
int estadoBotonAdelAnterior =LOW;
int estadoBotonAtrasAnterior =LOW;
unsigned long  millisBOTONADEL = 0;
unsigned long  millisBOTONATRAS = 0;

LiquidCrystal_I2C pantalla(0x27, 16, 2);  //para el display PCF8574 (consultar si es este el que vamso a usar).

class RGBColor {
  // El objeto RGBColor tiene los valores de red green y blue.
public:
  int red;
  int green;
  int blue;
  char* name;
  RGBColor(){};
  RGBColor(int redValue, int greenValue, int blueValue, char* colorName)
    : red(redValue), green(greenValue), blue(blueValue), name(colorName) {}
};


class ColorFactory {
  //Funciones que retornan el color en rgb
public:
  static class RGBColor Yellow() {
    return RGBColor(255, 235, 59, "Yellow");
  }
  static class RGBColor White() {
    return RGBColor(250, 250, 250, "White");
  }
  static class RGBColor Orange() {
    return RGBColor(245, 127, 23, "Orange");
  }
  static class RGBColor Green() {
    return RGBColor(0, 255, 0, "Green");
  }
  static class RGBColor Blue() {
    return RGBColor(0, 0, 255, "Blue");
  }
  static class RGBColor Red() {
    return RGBColor(255, 0, 0, "Red");
  }
  static class RGBColor Violet() {
    return RGBColor(120, 40, 140, "Violet");
  }
};

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
};

//Crea la lista de colores del usuario
RGBColor userCode[4];
//Si estamos en estado inicio creamos el secretcode
#if estadoActual == ESTADO_INICIO
SecretCode machineCode ; 
#endif
               

void setEstado(int estado){
  estadoActual = estado;
}


//FIXME: No me anda acá pero si en CodeBlocks
char* normalizeColor(char* color){
  	int counter = 0;
    char normalized[8];
    for (size_t i = 0; color[i] != 0; i++){
    	counter++;
      	normalized[i] = color[i];
      if(counter == 8){
        char* normalizedColor = normalized;
        return normalizedColor;
      };
    };
    for(int i=counter; i <8; i++){
      normalized[i]=' ';
      };
    char* normalizedColor = normalized;
    return normalizedColor;
};

void setColor(RGBColor& color) {
  analogWrite(REDPIN, color.red);
  analogWrite(GREENPIN, color.green);
  analogWrite(BLUEPIN, color.blue);
  if(selectedColor != color.name){
  selectedColor = color.name;
    pantalla.print(selectedColor);
    //no puedo normalizar el color
    //Serial.println(normalizeColor(color.name));
    userCode[selectorIndex] = color;
    calculateCursor();
  }  
}

void renderColor(int poteInput) {
  if(estadoActual != ESTADO_SELECCION){
    return;
  }

  if (poteInput >= 4 && poteInput <= 171) {
    RGBColor color = ColorFactory::White();
    setColor(color);

  } else if (poteInput > 171 && poteInput <= 341) {
    RGBColor color = ColorFactory::Yellow();
    setColor(color);
  } else if (poteInput > 341 && poteInput <= 511) {
    RGBColor color = ColorFactory::Orange();
    setColor(color);
  } else if (poteInput > 511 && poteInput <= 681) {
    RGBColor color = ColorFactory::Red();
    setColor(color);
  } else if (poteInput > 681 && poteInput <= 851) {
    RGBColor color = ColorFactory::Blue();
    setColor(color);
  } else if (poteInput > 851 && poteInput <= 1021) {
    RGBColor color = ColorFactory::Green();
    setColor(color);
  } else if (poteInput > 1021 && poteInput <= 1023) {
    RGBColor color = ColorFactory::Violet();
    setColor(color);
  }
}
void calculateCursor() {
  switch (selectorIndex) {
    case 0:
      pantalla.setCursor(0, 0);
    selectedColor = "";
      break;
    case 1:
      pantalla.setCursor(8, 0);
    selectedColor = "";
      break;
    case 2: 
      pantalla.setCursor(0, 1);
    selectedColor = "";
      break;
    case 3:
      pantalla.setCursor(8, 1);
    selectedColor = "";
      break;
  }
}

void resetCursor(){
  pantalla.setCursor(0,0);
  selectorIndex = 0;
  selectedColor = "";
}


void renderSelection( char* mode) {
  if (mode == "adelante") {
    if (selectorIndex < 3) {
      selectorIndex++;
    }
  } else if (mode == "atras") {
    if (selectorIndex > 0) {
      selectorIndex--;
    }
  }
  calculateCursor();
}
void setup() {

  pantalla.init();       //inicia el display.
  pantalla.backlight();  //prende los leds del display.

  pinMode(REDPIN, OUTPUT);
  pinMode(GREENPIN, OUTPUT);
  pinMode(BLUEPIN, OUTPUT);
  pinMode(POTE, INPUT);
  pinMode(BOTONADEL, INPUT);
  pinMode(BOTONATRAS, INPUT);
  pinMode(BOTONCONF, INPUT);
  Serial.begin(9600);
}

//Seteado en 1 para probar
int intentosPendientes = 1;

void loop() {
  Serial.println(estadoActual);
  unsigned long millisActuales = millis();
  int pote = analogRead(POTE);
  
  int estadoBotonAdel = digitalRead(BOTONADEL);
  int estadoBotonAtras = digitalRead(BOTONATRAS);
  int estadoBotonConf = digitalRead(BOTONCONF);
  
  //Inicializo para evitar errores en el switch
  //Se ve que no se pueden inicializar variables dentro
  //de un switch. Pero sí se pueden modificar
  SecretCode userSecretCode;
  switch (estadoActual)
{
case ESTADO_INICIO:
    machineCode = SecretCode();
    
    setEstado(ESTADO_SELECCION);
    break;
case ESTADO_SELECCION:
    

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
    if (estadoBotonConf == HIGH && selectorIndex == 3)
    {
        setEstado(ESTADO_CONFIRMACION);
    }
    break;
case ESTADO_CONFIRMACION:
    // Poner acá la lógica del Juego y terminar con setEstado
    // correspondiente a reintentar o perder y hacer INTENTOS--

    // Esto lo puse para confirmar que generaba randoms y bien
    userSecretCode = SecretCode(userCode);
    for (int i = 0; i < 4; i++)
    {
        Serial.print(userSecretCode.code[i].name);
        Serial.print("=>");
        Serial.print(machineCode.code[i].name);
        Serial.println("\n");
    }
    delay(1000);

    // Este if deberia verificar la condicion de victoria
    // Le
    if (false) // if(victoria...)
    {
        setEstado(ESTADO_VICTORIA);
    }
    else
    {
        if (intentosPendientes > 0)
        {
            intentosPendientes--;
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
    resetCursor();
    delay(1000);
    setEstado(ESTADO_INICIO);
    break;
case ESTADO_DERROTA:
    pantalla.clear();
    pantalla.print("Perdiste");
    funeralMarch();
    pantalla.clear();
    resetCursor();
    delay(1000);

    setEstado(ESTADO_INICIO);
    break;
}

  
}
