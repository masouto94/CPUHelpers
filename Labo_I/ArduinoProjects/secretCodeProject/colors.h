class RGBColor{

    public:
        int red;
        int green;
        int blue;

        RGBColor();
        RGBColor(int redValue, int greenValue, int blueValue)
        : red(redValue), green(greenValue),blue(blueValue)
        {}
    };

class ColorFactory{
  //Funciones que retornan el color en rgb
  public:
  static RGBColor Yellow(){
    return RGBColor(255, 235, 59);
  }
   static RGBColor White(){
    return RGBColor(250, 250, 250);
  }
   static RGBColor Orange(){
    return RGBColor(245, 127, 23);
  }
   static RGBColor Green(){
    return RGBColor(0, 77, 64);
  }
  static RGBColor Blue(){
    return RGBColor(74, 20, 140);
  }
  static RGBColor Red(){
    return RGBColor(183, 28, 28);
   }
};
