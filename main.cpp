#include <iostream>
#include <chrono>
#include <thread>

#include "main.h"

using namespace std;

int main()
{
    int n;
    int m;
	int j;
	int i;
    char c;

    cout << "THE GAME OF LIFE\n\n";
    cout << "To start please, introduce the width of the board:";
    cin >> n;
    cout << "\nNow introduce the height of the board:";
    cin >> m;

    board = new Matrix(n,m);

	cout << "\nFinally, press y if you want the cell to be alive, else just press enter";

	for (i=0; i<m; i++) {
		for (j=0; j<n; j++) {
			cout << "\nMust the cell in the coordinates x=" << j << " y="	<<	i << " be alive? press Y to set alive, enter to set dead"; 	
			cin >> c;
			if (c == 'y') {
				board->getCell(j,i)->setState(true);
			}
		}
	}


    while (true){

	/*
       c = getchar(); 
	if (c == 's'){
	    break;
	}
	*/
	std::this_thread::sleep_for(std::chrono::milliseconds(600)); 
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	board->step();
    }

}
