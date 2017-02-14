#include "matrix.h"


using namespace std;

Matrix::Matrix(int n, int m)
{

    int i;
    int j;

    N = n;
    M = m;

    for (i=0; i <= n; i++) {
        for (j = 0; j <= m; j++) {

	    board[i][j] = new Cell (i, j, this);

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


Cell Matrix::getCell(int x, int y)
{

    if ( x >= 0 || x < N) {
        if ( y >= 0 || y < M) {
	    return board[x][y];
	}
    }

    return NULL;

}

void Matrix::updateCell(int x, int y)
{

    Cell cell;

    cell = this->getCell(x,y);

    if ( cell != NULL) {
        cell.setUpdated();
    }

}
