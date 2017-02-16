#ifndef CELL_H
#define CELL_H

#include "matrix.h"

class Matrix;

class Cell{

    private:
        bool lastState;
        bool currentState;
        void isAlive(int x, int y,Matrix *matrix);
    public:
        Cell();
        ~Cell();	
	bool getState();
	void setState(bool state);
	void setUpdated();
};
#endif
