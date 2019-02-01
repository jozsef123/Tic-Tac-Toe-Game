#include "TicTacToe.h"
#include <stdio.h>
#include <time.h>

int main()
{
	TicTacToe p;
	int p1Wins = 0;
	int p2Wins = 0;
	int input;
	bool done = false;
	int p1;
	int p2;
	bool gameOver = false;
		do 
		{
			while (!p.checkWinner())
			{
				
					if (!p.gameOver())
					{
						if (!p.checkWinner())
						{
							p.printBoard();
							cout << "X's Move: ";
							cin >> p1;
							p.setPlayer1(p1);
						}
						else
						{
							cout << "O's has WON!" << endl;
							p.printBoard();
							p2Wins++;
							gameOver = true;
						}
					}
					else
					{
						p.printBoard();
						cout << "The game has been restarted due to invalid board." << endl;
						p.resetBoard();
					}

					if (!p.gameOver())
					{
						if (!p.checkWinner())
						{
							p.printBoard();
							cout << "O's Move: ";
							cin >> p2;
							p.setPlayer2(p2);
						}
						else
						{
							cout << "X's has WON!" << endl;
							p.printBoard();
							p1Wins++;
							gameOver = true;
						}
					}
					else
					{
						p.printBoard();
						cout << "The game has been restarted due to invalid board." << endl;
						p.resetBoard();
					}
			}

			if (gameOver)
				p.resetBoard();
			cout << "Player 1 wins: " << p1Wins << endl;
			cout << "Player 2 wins: " << p2Wins << endl;
			cout << "Rematch: 1 for yes, other button press to exit: ";
			cin >> input;

			if (input == 1)
				done = false;
			else done = true;

		} while (done == false);

		cout << endl;
	if (p1Wins > p2Wins)
		cout << "Player 1 is the TicTacToe Champion!" << endl; 
	else if (p1Wins < p2Wins)
		cout << "Player 2 is the TicTacToe Champion!" << endl;
	else cout << "The match ended in a tie..." << endl;
	system("pause");
	return 0;
}