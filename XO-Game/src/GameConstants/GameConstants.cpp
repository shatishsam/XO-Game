#pragma once
#include <string>

class GameConstants
{
public:
	// player state
	static const enum playerState
	{
		Idle, In_Game
	};
	//game state
	static const enum gameState
	{
		Initialized, InProgress, Ended
	};
	

	//value for playerX moves
	static const int playerXMoveValue = 1;
	//value for playerO moves
	static const int playerYMovesValue = -1;


	/*** ErrorMessages ***/
	static std::string occupiedSquareErrorMessage = "Square Already Occupied Try Other Square"; //aready occupied

	static std::string invalidSquareErrorMessage="Invalid Square Provided Please Enter Correct Square"; // invalid index
};