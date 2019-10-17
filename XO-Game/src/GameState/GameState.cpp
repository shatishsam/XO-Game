#pragma once
#include <iostream>
#include "../GamePlayer/GamePlayer.cpp"
#include "../GameConstants/GameConstants.cpp"
#include "../GameBoard/GameBoard.cpp"
using std::cout; using std::endl; using std::cin;

class GameState
{
private:
	GamePlayer* playerX=NULL;
	GamePlayer* playerY=NULL;
	GameBoard* gameBoard = NULL;
	GameConstants::gameState gameState;
	
public:
	GameState()
	{
		this->playerX = new GamePlayer("Sam", "sam@123", 1234);
		this->playerY = new GamePlayer("fam", "fam@123", 4321);
		gameBoard = new GameBoard();
		this->gameState = GameConstants::gameState::gameInProgress; //game state
	}

	void startGame()
	{
		cout <<"welcome" << playerX->getName() << " and " << playerY->getName() << endl;
		//change the player state of the players
		playerX->setPlayerState(GameConstants::playerState::In_Game);
		playerY->setPlayerState(GameConstants::playerState::In_Game);

		int i, j; //temp variables to get the index from the user
		while (gameState == GameConstants::gameState::gameInProgress)
		{
			//display the board to the user
			cout << "Current Board is" << endl;
			gameBoard->displayBoard();
			
			//get the move user wants to make
			cout << "Player1 Please enter your move in indexes" << endl;
			cin >> i >> j;
			while (gameBoard->tryMakeMove(i, j, true)); //try until both users makes a valid move

			//get the move user wants to make
			cout << "Player1 Please enter your move in indexes" << endl;
			cin >> i >> j;
			while (gameBoard->tryMakeMove(i, j, false));

			//update the new gamestate
			this->gameState = this->gameBoard->getCurrentGameState();
		}

		cout << "game has ended the result is" << this->gameState << endl;
	}
};