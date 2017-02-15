#include "matrix.h"


using namespace std;

Matrix::Matrix(int n, int m)
{

    int i;
    int j;


    N = n;
    M = m;

    board.resize(N);

    for (i=0; i<N; i++) {
        for (j=0; j<M; j++) {
		board[i].push_back(new Cell(i, j, this));
	}
    } 


}

void Matrix::step()
{

}


int Matrix::getN()
{

    return N;

}


int Matrix::getM()
{

    return M;

}


Cell* Matrix::getCell(int x, int y)
{

    if ( x >= 0 && x < N) {
        if ( y >= 0 && y < M) {
	    return board[x][y];
	}
    }

    return nullptr;

}

void Matrix::updateCell(int x, int y)
{

    Cell *cell;

    cell = this->getCell(x,y);

    if ( cell != nullptr) {
        cell->setUpdated();
    }

}
