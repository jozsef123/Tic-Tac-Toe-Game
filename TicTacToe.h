#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <iostream>
#include <string>
#include <limits>

using namespace std;

class TicTacToe
{
public:
	TicTacToe();
	~TicTacToe();

	void printBoard();
	bool validMove(int);
	void setPlayer1(int);
	int getPlayer1() const;
	void setPlayer2(int);
	int getPlayer2() const;
	bool checkWinner() const;
	bool gameOver() const;
	void resetBoard();

private:
	int player1;
	int player2;
	string board[3][3];
};

#endif