#ifndef CELL_H
#define CELL_H

#include "matrix.h"

class Matrix;

class Cell{

    private:
        bool lastState;
        bool currentState;
    public:
        Cell();
        ~Cell();	
    void isAlive(int x, int y,Matrix *matrix);
	bool getState();
	void setState(bool state);
	void setUpdated();
};
#endif
