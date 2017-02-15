#ifndef MATRIX_H
#define MATRIX_H


#include <vector>

#include "cell.h"


class Matrix {

    public:

	Matrix(int n, int m);
        ~Matrix();
        void step();
	Cell *getCell(int x, int y);
	int getN();
	int getM();
	void updateCell(int x, int y);
    private:
        int N;
        int M; 
	std::vector< std::vector<Cell *> > board;
};
#endif
