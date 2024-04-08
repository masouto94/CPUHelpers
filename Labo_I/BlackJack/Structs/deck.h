#include <stdio.h>
using namespace std;
#include <string>
#include <iostream>
class Deck {
public:
    initializer_list<string> suits;

    Deck(initializer_list<string> suits){
        for (auto i = suits.begin(); i != suits.end(); i++) {
                cout << *i << endl;
            }
        //printf("%s", suits[2]);
        }
    void show(){
//        for (size_t i = 0; i < sizeof(suits); i++)
//            {
//             printf("%s",i);
//            }
    }

};
