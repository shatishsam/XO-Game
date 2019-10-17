#pragma once
#include <string>
#include "Person.cpp"
#include "../GameConstants/GameConstants.cpp"

class GamePlayer : public Person 
{
private:
	int gamePlayerId;
	GameConstants::playerState playerState;

public:
	GamePlayer(std::string Name, std::string emailId, int phoneNumber):Person(Name, emailId, phoneNumber)
	{
		this->gamePlayerId = rand();
		this->playerState = GameConstants::playerState::Idle;
	}

public:
	//get the current player state
	GameConstants::playerState getPlayerState() { return this->playerState; }

	//set the player state
	void setPlayerState(GameConstants::playerState newPlayerState) { this->playerState = newPlayerState; }
};
