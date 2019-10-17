#pragma once
#include <string>

class GameConstants
{
public:
	// player state
	const enum playerState
	{
		Idle, In_Game
	};

	//game state
	const enum gameState
	{
		gameInProgress, playerXVictory, playerYVictory, gameDraw
	};

	//value for playerX moves
	static const int playerXMoveValue = 1;
	//value for playerO moves
	static const int playerYMovesValue = -1;


	/*** ErrorMessages ***/
	static constexpr const char* occupiedSquareErrorMessage = "Square Already Occupied Try Other Square"; //aready occupied

	static constexpr const char* invalidSquareErrorMessage="Invalid Square Provided Please Enter Correct Square"; // invalid index
};