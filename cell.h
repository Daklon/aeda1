#ifndef CELL_H
#define CELL_H

#include "matrix.h"

class Matrix;

class Cell{

    private:
        bool lastState;
        bool currentState;
	int xPosition;
	int yPosition;
	//revisar puntero
	Matrix *parentMatrix;
        bool isAlive();
    public:
        Cell(int x, int y,Matrix *matrix);
        ~Cell();	
	bool getState();
	void setUpdated();
};
#endif
