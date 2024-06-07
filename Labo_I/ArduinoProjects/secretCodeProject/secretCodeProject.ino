#include <LiquidCrystal_I2C.h>
//#include "secretCode.h"
#define BLUEPIN 9
#define REDPIN 10
#define GREENPIN 5
#define POTE A1
#define BOTON1 3
#define BOTON2 7

char* selectedColor = "";
int selectorIndex = 0;

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
    return RGBColor(255, 235, 59, "Yellow ");
  }
  static class RGBColor White() {
    return RGBColor(250, 250, 250, " White ");
  }
  static class RGBColor Orange() {
    return RGBColor(245, 127, 23, "Orange ");
  }
  static class RGBColor Green() {
    return RGBColor(0, 255, 0, " Green ");
  }
  static class RGBColor Blue() {
    return RGBColor(0, 0, 255, " Blue  ");
  }
  static class RGBColor Red() {
    return RGBColor(255, 0, 0, " Red  ");
  }
  static class RGBColor Violet() {
    return RGBColor(120, 40, 140, "Violet ");
  }
};

void setColor(RGBColor& color) {
  analogWrite(REDPIN, color.red);
  analogWrite(GREENPIN, color.green);
  analogWrite(BLUEPIN, color.blue);
  if(selectedColor != color.name){
  selectedColor = color.name;
    pantalla.print(selectedColor);
    calculateCursor();
  }
  
  
  
  
}

void renderColor(int poteInput) {

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
  pinMode(BOTON1, INPUT);
  pinMode(BOTON2, INPUT);
  Serial.begin(9600);
}

void loop() {
  int pote = analogRead(POTE);
  renderColor(pote);
  int estadoboton1 = digitalRead(BOTON1);
  int estadoboton2 = digitalRead(BOTON2);

  if (estadoboton1 == HIGH) {
    renderSelection("adelante");
  }

  if (estadoboton2 == HIGH) {
    renderSelection( "atras");
  }

  pantalla.cursor();
  delay(200);
  //pantalla.write('A');
}
