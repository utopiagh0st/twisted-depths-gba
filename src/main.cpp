//don't forget to execute the make command everytime u add a new asset
#include "bn_core.h" //core library!!
//classes
#include "game.h"

int main()
{
    bn::core::init(); //initialization comes after this line
    Game game;

    while(true) //game loop
    {   
        game.update();
        bn::core::update(); //this line always goes at the end
    }
}