#include "cell.h"

Cell::Cell()
{
	this->lastState = false;
    this->currentState = false;
}


bool Cell::getState()
{
    return this->lastState;
}

void Cell::setState(bool state)
{
	this->lastState = state;
	this->currentState = state;

}

//this must be called at leats one time per turn, but only when
//all nearby cells has called isAlive()
void Cell::setUpdated()
{
    this->lastState = this->currentState;
}


//this must check the 8 most nearby cells to set alive state of ifself
bool Cell::isAlive(int x, int y, Matrix *matrix)
{
    signed int i;
    signed int j;
	signed int xNeighbour;
    signed int yNeighbour;
    signed int aliveCellQuantity;


    aliveCellQuantity = 0;

    for (i = -1; i<2; i++) {
        for (j = -1; j<2; j++) {
			if ((j != 0) || (i != 0)) {
				xNeighbour = x + j;
				yNeighbour = y + i;
				//de esto se puede encargar el metodo get cell
				if ( xNeighbour >= 0 && xNeighbour < matrix->getN() ) {
						if ( yNeighbour >= 0 && yNeighbour < matrix->getM() ) {
							if ( matrix->getCell(xNeighbour, yNeighbour)->getState() ) {
								aliveCellQuantity++;
							}
						}
				}
	        }
    	}
    }

    if ( this->lastState && ((2 <= aliveCellQuantity) && (aliveCellQuantity <= 3 ))) {
        currentState = true;
    } else if ( !this->lastState && ( aliveCellQuantity == 3)) {
        currentState = true;
    } else {
        currentState = false;
    }
  
    //esto hay que revisarlo
	if ((matrix->getN() == x) && (matrix->getM() == y)) {
		for (i = -1; i<1; i++) {
			for (j = -1; j<1; j++) {
				xNeighbour = x - j;
				yNeighbour = y - i;
				matrix->updateCell(xNeighbour, yNeighbour);
			}
		}
	} else {
		matrix->updateCell(x -1, y -1);
	}
	return currentState;
}
