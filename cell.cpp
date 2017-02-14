#include "cell.h"

Cell::Cell(int x, int y)
{
    xPosition = x;
    yPosition = y;
    lastState = false;
    currentState = false;
}


bool Cell::getState()
{
    return lastState;
}


//this must be called at leats one time per turn,, but only when
//all nearby cells has called isAlive()
void Cell::setUpdated()
{
    lastState = currentState;
}


//this must check the 8 most nearby cells to set alive state of ifself
bool Cell::isAlive()
{

}
