#include "cell.h"

Cell::Cell(int x, int y, Matrix *matrix)
{
    //esto hay que revisarlo, los punteros
    parentMatrix = matrix;
    xPosition = x;
    yPosition = y;
    lastState = false;
    currentState = false;
}


bool Cell::getState()
{
    return lastState;
}


//this must be called at leats one time per turn, but only when
//all nearby cells has called isAlive()
void Cell::setUpdated()
{
    lastState = currentState;
}


//this must check the 8 most nearby cells to set alive state of ifself
bool Cell::isAlive()
{
    int i;
    int j;
    int xNeighbour;
    int yNeighbour;
    int aliveCellQuantity;

    aliveCellQuantity = 0;

    for (i = -1; i<2; i++) {
        for (j = -1; j<2; j++) {
	    xNeighbour = xPosition - j;
	    yNeighbour = yPosition - i;
	    //de esto se puede encargar el metodo get cell
	    if ( xNeighbour >= 0 || xNeighbour < parentMatrix.getN() ) {
                if ( yNeighbour >= 0 || yNeighbour < parentMatrix.getM() ) {
                    if ( parentMatrix.getCell(xNeighbour, yNeighbour).getstate() ) {
                        aliveCellQuantity =+ 1;
		    }
		}
	    }
	}
    }

    if ( lastState && (2 <= aliveCellQuantity <= 3 )) {
        currentState = true;
    } else if ( !lastState && ( aliveCellQuantity == 3)) {
        currentState = true;
    } else {
        currentState = false;
    }
  
    //esto hay que revisarlo
    parentMatrix.updateCell(xPosition -1, yPosition -1).setUpdated();
}
