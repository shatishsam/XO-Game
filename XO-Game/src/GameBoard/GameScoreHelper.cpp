#pragma once
#include <vector>

class GameScoreHelper
{
private:
	//store scores of each row, column, diagonal so we can find if someone wins in O(1)
	std::vector<int> rowScores;
	std::vector<int> columnScores;

	int leftDiagonalScore;
	int rightDiagonalScore;

public:
	GameScoreHelper()
	{
		for (int i = 0; i < 3; i++)
		{
			rowScores.push_back(0);
			columnScores.push_back(0);
		}

		this->leftDiagonalScore = 0;
		this->rightDiagonalScore = 0;
	}

	void updateScoreWithMove(int i, int j, bool isPlayerX)
	{
		int scoreValue = (isPlayerX ? 1 : -1);
		
		rowScores[i]++; columnScores[j]++; //update rowscore and columnscore
		if (i == j) leftDiagonalScore++; //update left diagonal score 
		if (i + j == 2) rightDiagonalScore++; //update right diagonal score
	}
};