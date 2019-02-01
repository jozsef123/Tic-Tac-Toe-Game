#include "TicTacToe.h"

TicTacToe::TicTacToe()
{
	int x = 1;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
		{
			board[i][j] = to_string(x);
			x++;
		}
	player1 = 0;
	player2 = 0;
}

TicTacToe::~TicTacToe()
{
	int x = 1;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
		{
			board[i][j] = to_string(x);
			x++;
		}
	player1 = 0;
	player2 = 0;
}

void TicTacToe::printBoard()
{
	int x = 0;
	cout << "Player 1 <X>  -  Player 2 <O>" << endl;
	cout << "           |     |       " << endl;
	for (int i = 0; i < 3; i++)
	{
		if (i > 0 && i < 3)
			cout << "    -----------------------" << endl;
		cout << "\t";
		for (int j = 0; j < 3; j++)
		{
			cout << board[i][j];
			if((x+1)%3 != 0)
			cout << "  |  ";
			x++;
		}
		cout << endl;
	}
	cout << "           |     |       " << endl;
}

void TicTacToe::setPlayer1(int p1)
{
	while(cin.fail() || p1 < 1 || p1 > 9)
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Re-enter move: ";
		cin >> p1;
	}
	player1 = p1;
	if (!validMove(player1))
	{
		cout << "Invalid Move, re-enter move: ";
		cin >> p1;
		setPlayer1(p1);
	}
}

int TicTacToe::getPlayer1() const
{
	return player1;
}

void TicTacToe::setPlayer2(int p2)
{
	while(cin.fail() || p2 < 1 || p2 > 9)
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Re-enter move: ";
		cin >> p2;
	}
	player2 = p2;
	if (!validMove(player2))
	{
		cout << "Invalid Move, re-enter move: ";
		cin >> p2;
		setPlayer2(p2);
	}
}

int TicTacToe::getPlayer2() const
{
	return player2;
}

bool TicTacToe::validMove(int playerMove)
{
	int count = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			count++;
			if (count == playerMove)
			{
				if (board[i][j] == "X" || board[i][j] == "O")
					return false;
				else
				{
					if (playerMove == player1)
					{
						board[i][j] = "X";
						return true;
					}
					else
					{
						board[i][j] = "O";
						return true;
					}
				}
				
			}
		}
	}
}

bool TicTacToe::checkWinner() const
{
	//X's
	//Horizontal
	if (board[0][0] == "X" && board[0][1] == "X" && board[0][2] == "X")
	{
		return true;
	}
	if (board[1][0] == "X" && board[1][1] == "X" && board[1][2] == "X")
	{
		return true;
	}
	if (board[2][0] == "X" && board[2][1] == "X" && board[2][2] == "X")
	{
		return true;
	}
	//Vertical
	if (board[0][0] == "X" && board[1][0] == "X" && board[2][0] == "X")
	{
		return true;
	}
	if (board[0][1] == "X" && board[1][1] == "X" && board[2][1] == "X")
	{
		return true;
	}
	if (board[0][2] == "X" && board[1][2] == "X" && board[2][2] == "X")
	{
		return true;
	}
	//Crosses
	if (board[0][0] == "X" && board[1][1] == "X" && board[2][2] == "X")
	{
		return true;
	}
	if (board[0][2] == "X" && board[1][1] == "X" && board[2][0] == "X")
	{
		return true;
	}

	//O's
	//Horizontal
	if (board[0][0] == "O" && board[0][1] == "O" && board[0][2] == "O")
	{
		return true;
	}
	if (board[1][0] == "O" && board[1][1] == "O" && board[1][2] == "O")
	{
		return true;
	}
	if (board[2][0] == "O" && board[2][1] == "O" && board[2][2] == "O")
	{
		return true;
	}
	//Vertical
	if (board[0][0] == "O" && board[1][0] == "O" && board[2][0] == "O")
	{
		return true;
	}
	if (board[0][1] == "O" && board[1][1] == "O" && board[2][1] == "O")
	{
		return true;
	}
	if (board[0][2] == "O" && board[1][2] == "O" && board[2][2] == "O")
	{
		return true;
	}
	//Crosses
	if (board[0][0] == "O" && board[1][1] == "O" && board[2][2] == "O")
	{
		return true;
	}
	if (board[0][2] == "O" && board[1][1] == "O" && board[2][0] == "O")
	{
		return true;
	}

	return false;
}

bool TicTacToe::gameOver() const
{
	if (board[0][0] != "1" &&
		board[0][1] != "2" &&
		board[0][2] != "3" &&
		board[1][0] != "4" &&
		board[1][1] != "5" &&
		board[1][2] != "6" &&
		board[2][0] != "7" &&
		board[2][1] != "8" &&
		board[2][2] != "9")
		return true;
	else return false;
}

void TicTacToe::resetBoard()
{
	int x = 1;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
		{
			board[i][j] = to_string(x);
			x++;
		}
}