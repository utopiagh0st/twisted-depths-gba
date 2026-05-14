#include "level.h"

Level::Level() :
    _state(State::Title)    //starts with title state
{
    _bounds[0] = -50;   //up
    _bounds[1] = 48;    //down
    _bounds[2] = -66;   //left
    _bounds[3] = 66;    //right
}