#pragma once
#include <iostream>
#include <string>
#include <cstring>
#include "../GameConstants/GameConstants.cpp"
#include "../GameBoard/GameScoreHelper.cpp"
using std::cout; using std::endl;
class GameBoard
{
private:
	int gameID;
	int Board[3][3];
	GameScoreHelper* scoreHelper=NULL;

public:
	GameBoard()
	{
		this->gameID = rand();
		memset(this->Board, 0, sizeof(this->Board));
		scoreHelper = new GameScoreHelper();
	}

private:
	//check if valid index
	bool isValidIndex(int i, int j) { return (i >= 0 && i < 3) && (j >= 0 && j < 3); }
	//check if a square is empty
	bool isMovePossible(int i, int j) { return this->Board[i][j] == 0; }
	//throw error
	void throwError(std::string errorMessage) { std::cerr << errorMessage; }

public:
	//display the board
	void displayBoard()
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (Board[i][j] == 0) cout << "- ";
				else if (Board[i][j] == 1) cout << "X ";
				else cout << "O ";
			}
			cout << endl;
		}
	}

	//make the move if its a valid move and update the scorehelper clas
	bool tryMakeMove(int i, int j, bool isPlayerX)
	{
		//check for error conditions
		if (!isValidIndex(i, j)) { throwError(GameConstants::invalidSquareErrorMessage); return false; } //check if the indexes are valid
		if (!isMovePossible(i, j)) {throwError(GameConstants::occupiedSquareErrorMessage); return false; } //check if square is not occupied

		//the move is valid. based on the player set the value
		if (isPlayerX) this->Board[i][j] = GameConstants::playerXMoveValue;
		else this->Board[i][j] = GameConstants::playerYMovesValue;
		
		//update the score helper
		scoreHelper->updateScoreWithMove(i, j, isPlayerX);
		return true;
	}

	//get the updated game state after the move
	GameConstants::gameState getCurrentGameState() { return this->scoreHelper->getCurrentGameState(); }
};