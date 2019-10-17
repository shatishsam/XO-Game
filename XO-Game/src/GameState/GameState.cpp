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

private:
	//
	void displayGameResult()
	{
		switch (gameState)
		{
		
			case GameConstants::gameState::playerXVictory:
			{
				cout << playerX->getName() << " has won the game" << endl;
				break;
			}

			case GameConstants::gameState::playerYVictory:
			{
				cout << playerY->getName() << " has won the game" << endl;
				break;
			}

			case GameConstants::gameState::gameDraw:
			{
				cout << "Game Drawn" << endl;
				break;
			}
		}
	}

	//make the given player update the board
	void makePlayerMove(GamePlayer* gamePlayer)
	{
		//display the board to the user
		cout << "Current Board is" << endl;
		gameBoard->displayBoard();

		//get the move user wants to make
		int i, j;
		cout << gamePlayer->getName() << " Please enter your move in indexes" << endl;
		cin >> i >> j;
		if (!gameBoard->tryMakeMove(i, j, gamePlayer == playerX)) makePlayerMove(gamePlayer); //recursively call and make player move until he makes a valid move
		else this->gameState = this->gameBoard->getCurrentGameState(); //valid move so update the game state
	}

public:
	void startGame()
	{
		cout <<"welcome" << playerX->getName() << " and " << playerY->getName() << endl;
		//change the player state of the players
		playerX->setPlayerState(GameConstants::playerState::In_Game);
		playerY->setPlayerState(GameConstants::playerState::In_Game);

		while (true)
		{
			//playerX move and update the gamestate
			makePlayerMove(playerX);
			if (gameState != GameConstants::gameState::gameInProgress) break;

			//playerY move and update the gamestate
			makePlayerMove(playerY);
			if (gameState != GameConstants::gameState::gameInProgress) break;
		}
		//game has ended display the final result
		displayGameResult();
	}
};