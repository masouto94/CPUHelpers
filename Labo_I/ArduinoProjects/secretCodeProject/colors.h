
class RGBColor{

    public:
        int red;
        int green;
        int blue;
        String name;
        RGBColor() {};
        RGBColor(int redValue, int greenValue, int blueValue, String colorName)
        : red(redValue), green(greenValue),blue(blueValue), name(colorName)
        {}
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
