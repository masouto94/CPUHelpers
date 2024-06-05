// C++ code
//
#define BLUEPIN 9
#define REDPIN 10
#define GREENPIN 5
#define POTE A1
#include "colors.h"
#include "secretCode.h"

bool checkTime(unsigned long &base,unsigned long counter,int threshold){
  unsigned long diff = counter - base ;
  if(diff >= threshold){
    base  = counter;
    return true;
  }
  return false;
} 
void setColour(int poteInput){
  //El pote llega hasta 1023
  int maxValue = 1023;
  if(poteInput < (maxValue /2)){
    RGBColor color = ColorFactory::Red();
    analogWrite(REDPIN, color.red);
    analogWrite(GREENPIN, color.green);
    analogWrite(BLUEPIN, color.blue);
    Serial.println(color.red);
    Serial.println( color.green);
    Serial.println(  color.blue);
  }
  else{
    RGBColor color = ColorFactory::Blue();
    analogWrite(REDPIN, color.red);
    analogWrite(GREENPIN, color.green);
    analogWrite(BLUEPIN, color.blue);
  }
}
  
void setup()
{
  pinMode(REDPIN, OUTPUT);
  pinMode(GREENPIN, OUTPUT);
  pinMode(BLUEPIN, OUTPUT);
  pinMode(POTE, INPUT);
  Serial.begin(9600);
  
}


unsigned long millisAnteriores = 0;
void loop()
{
    SecretCode codigo = SecretCode("red","green","blue","yellow");
    std::array<char*,4> inputUser = {"red","blue","black","pink"};
    for (int i=0; i<4; i++){
    printf("Posicion %d el usuario puso %s y el codigo es %s => %s\n",i+1,inputUser[i],codigo.code[i],codigo.comparar(inputUser)[i]);
    };
  int pote=analogRead(POTE);
  setColour(pote);
  Serial.println(pote);
  
  
}