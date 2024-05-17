// C++ code
//
#define REDLED 10
#define YLWLED 8
#define GREENLED 7
#define BUZZERINPUT 5

void swap(int item){
	if(digitalRead(item) == HIGH){
      digitalWrite(item, LOW);
      return;
 }
 digitalWrite(item, HIGH);
 return;  
}

class Beep{
  public:
  	int led;
    
  	Beep(int ledVal){
      led = ledVal;
    }
  Beep(){};

    void titilar(){
      swap(led);
      beepIfLit();
      delay(500);
    }
  void beepIfLit(int note=440, int duration=500){
    if (digitalRead(led) == HIGH){
      Serial.print(led);
      tone(led,note,duration);
      delay(duration);
      noTone(led);
    }
  }
};

class TrafficLight{


  public:
  Beep red;
  Beep yellow;
  Beep green;

  TrafficLight(Beep &redBeep ,Beep &yellowBeep,Beep &greenBeep)
  : red(redBeep), yellow(yellowBeep), green(greenBeep)
  {} 
  void check(){
  	Serial.print("OK");
  }
  void initSequence(){  	
    digitalWrite(yellow.led, LOW);
    
    digitalWrite(red.led, HIGH);
    red.beepIfLit(493,2000);
    digitalWrite(red.led, LOW);
    
    digitalWrite(yellow.led, HIGH);
    yellow.beepIfLit(440,1000);
    digitalWrite(yellow.led, LOW);

    digitalWrite(green.led, HIGH);
    green.beepIfLit(523,2000);
    digitalWrite(green.led, LOW);
  }
    
};
void setup()
{
  pinMode(REDLED, OUTPUT);
  pinMode(YLWLED, OUTPUT);
  pinMode(GREENLED, OUTPUT);
  pinMode(INPUTPIN, INPUT);
  Serial.begin(9600);
}



void loop()
{
  int signal = digitalRead(INPUTPIN);
  
  Beep red = Beep(REDLED);
  Beep yellow = Beep(YLWLED);
  Beep green = Beep(GREENLED);

  
  TrafficLight semaforo = TrafficLight(red,yellow,green);
  
  if(signal == LOW){
    yellow.titilar();

    
  }
  else if(signal == HIGH){
    semaforo.initSequence();
  }
  signal = digitalRead(INPUTPIN);
}