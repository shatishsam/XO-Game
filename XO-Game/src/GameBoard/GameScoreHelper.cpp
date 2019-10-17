#pragma once
#include <iostream>
#include <vector>
#include "../GameConstants/GameConstants.cpp"

class GameScoreHelper
{
private:
	//to calculate the no of moves played so we can check if the game is draw in O(1).
	int movesCount; 

	//store scores of each row, column, diagonal so we can find if someone wins in O(1)
	std::vector<int> rowScores;
	std::vector<int> columnScores;

	int leftDiagonalScore;
	int rightDiagonalScore;

public:
	GameScoreHelper()
	{
		this->movesCount = 0;
		this->leftDiagonalScore = 0;
		this->rightDiagonalScore = 0;

		//initialize all scores as 0.
		for (int i = 0; i < 3; i++)
		{
			rowScores.push_back(0);
			columnScores.push_back(0);
		}
	}


public:
	//update the scores of row,column and diagonals when a move is made
	void updateScoreWithMove(int i, int j, bool isPlayerX)
	{
		int scoreValue = (isPlayerX ? 1 : -1);
		
		rowScores[i] += scoreValue; columnScores[j] += scoreValue; //update rowscore and columnscore
		if (i == j) leftDiagonalScore += scoreValue; //update left diagonal score 
		if (i + j == 2) rightDiagonalScore += scoreValue; //update right diagonal score
		movesCount++; //update the no of moves played
	}

	//check if someone has won
	GameConstants::gameState getCurrentGameState()
	{
		//check the diagonals first as its easy to calculate
		if (leftDiagonalScore == 3 || rightDiagonalScore == 3) return GameConstants::gameState::playerXVictory;
		if (leftDiagonalScore == -3 || rightDiagonalScore == -3) return GameConstants::gameState::playerYVictory;

		//check the row and column now.
		for (int i = 0; i < 3; i++)
		{
			if (rowScores[i] == 3 || columnScores[i] == 3) return GameConstants::gameState::playerXVictory;
			if (rowScores[i] == -3 || columnScores[i] == -3) return GameConstants::gameState::playerYVictory;
		}
		//check if the game is draw. if move count is 9
		if (movesCount == 9) return GameConstants::gameState::gameDraw;

		//no one has won the game so return game in progress
		return GameConstants::gameState::gameInProgress;
	}

	//temp function to display the scores
	void displayScores()
	{
		std::cout << "displaying the board scores" << std::endl;
		for (int i = 0; i < 3; i++)
		{
			std::cout << i << " row score is" << rowScores[i] << std::endl;
			std::cout << i << " column score is" << columnScores[i] << std::endl;
		}
		std::cout << "left diagonal score is" << leftDiagonalScore << std::endl;
		std::cout << "right diagona score is" << rightDiagonalScore << std::endl;
	}
};