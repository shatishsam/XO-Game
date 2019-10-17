#include <iostream>
#include "../GameState/GameState.cpp"
using namespace std;

int main()
{
	GameState* gameState = new GameState();
	cout << "starting the game" << endl;
	gameState->startGame();
}