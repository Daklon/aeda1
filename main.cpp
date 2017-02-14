#include <iostream>

#include <"main.h">
#include <"matrix.h">

using namespace std;

int main()
{
    int n;
    int m;
    char c;

    cout << "THE GAME OF LIFE\n\n";
    cout << "To start please, introduce the width of the board:";
    cin >> n;
    cout << "\nNow introduce the height of the board:";
    cin >> m;
    
    board = new Matrix(n,m);

    while (true){

        c=getch();
	if (c == 27){
	    break;
	}

	board.step();
    }

}
