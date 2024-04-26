#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <chrono>
#include <thread>
//Ejercicio 2
//
//Escribir un programa que simule un juego de dados con apuestas. El programa debe pedir al usuario que ingrese una cantidad de dinero para apostar y luego tirar dos dados de 6 caras.
//
//Si la suma de los dados es 6, 7 o 8 el jugador gana y duplica su apuesta.
//
//Si la suma es 2 o 12, el jugador pierde toda su apuesta. En cualquier caso, el juego pierde la mitad de su apuesta.
//
//El jugador puede elegir apostar nuevamente introduciendo el carácter ‘S’ o retirarse con sus ganancias introduciendo cualquier otro carácter.
//
//Ejemplo:
//
//“¿Cuánto dinero quiere apostar? “
//
//100
//
//“Dados:  4 y 3 los dados suman 7“
//
//“¡Usted ganó!! duplica su apuesta“
//
//“Su poso acumulado es de $200, ¿Quiere apostar nuevamente? (S/N)
//
//S
//
//“Dados:  3 y 2 los dados suman 5“
//
//“¡Usted perdió!! pierde la mitad de su apuesta“
//
//“Su poso acumulado es de $100, ¿Quiere apostar nuevamente? (S/N)”
//
//S
//
//“Dados:  6 y 3 los dados suman 9“
//
//“¡Usted perdió!! pierde la mitad de su apuesta“
//
//“Su poso acumulado es de $50, ¿Quiere apostar nuevamente? (S/N)”
//
//N
//
//“Tome sus $50. Vuelva pronto!!”
//
//
//#include <stdio.h>
//
//#include <stdlib.h>
//
//#include <time.h>
//
//int main() {
//
//    int dado1,dado2;
//
//srand(time(NULL)); // inicializar el generador de números aleatorios
//
//dado1 = (rand() % 6) + 1; // generar un número aleatorio entre 1 y 6
//
//dado2 = (rand() % 6) + 1; // generar un número aleatorio entre 1 y 6

int rollDice(){
    return (rand() % 6) + 1;
}

int executeRound(int bet, int firstDice, int secondDice){
    printf("Tirando dados...\n");
    std::this_thread::sleep_for(std::chrono::seconds(2));
    int result = firstDice + secondDice;
    printf("Los dados salieron:\n Dado 1: %d\n Dado 2: %d\n", firstDice, secondDice);
    printf("El resultado es %d\n", result);
    if(result == 6 || result == 7 || result == 8){
    bet *= 2;
    printf("GANASTE! Tu pozo es %d\n", bet);
    }
    else if (result == 12 || result ==2){
    bet = 0;
    printf("PERDISTE TODO! El pozo quedó en %d\n", bet);
    }
    else{
        bet /= 2;
        printf("PERDISTE! Tu pozo se dividio a la mitad %d\n", bet);
    }
    return bet;
}

int Ejercicio_2(){
    int dice_1, dice_2;
    int startingBet;
    char continueBet='S';
    printf("Ingrese el dinero a apostar\n");
    std::cin >> startingBet;
    srand(time(NULL));
    while(continueBet == 'S' || continueBet == 's'){
        dice_1 = rollDice();
        dice_2 = rollDice();
        startingBet = executeRound(startingBet, dice_1,dice_2);
        if(startingBet == 0){
            break;
        }
        printf("Desea seguir jugando? [S/s]\n");
        std::cin >> continueBet;
    }
    if(startingBet > 0){
    printf("Te llevaste $%d", startingBet);
    }
    else {
    printf("GAME OVER!");
    }


    return 0;
}
