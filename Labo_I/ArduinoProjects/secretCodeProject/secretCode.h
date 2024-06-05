#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <array>
class SecretCode{
    srand(time(NULL));

      public:
        char* one;
        char* two;
        char* three;
        char* four;
        std::array<char*,4> code;

        std::array<char*,4> comparar(std::array<char*,4> inputUsuario){
            std::array<char*,4> answer = {"NULL","NULL","NULL","NULL"};
            for(int i=0; i < 4; i++){
                if(inputUsuario[i] == code[i]){
                    answer[i] = "redPeg";
                    continue;
                }
                for(int code_index = 0; code_index < 4; code_index++){
                    if(inputUsuario[i] == code[code_index]){
                        answer[i] = "yellowPeg";
                        break;
                    }
                }
             }
            return answer;
          }
        SecretCode(){
            char* colours[7] = {"red","green","blue","yellow", "pink", "white","black"};
            one = colours[rand() % 7];
            two = colours[rand() % 7];
            three = colours[rand() % 7];
            four = colours[rand() % 7];
            code = {one,two,three,four};
          }
        SecretCode(char* color1, char* color2, char* color3, char* color4){
            one = color1;
            two = color2;
            three = color3;
            four = color4;
            code = {one,two,three,four};

          }
      };
