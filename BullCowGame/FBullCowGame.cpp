#include "FBullCowGame.h"

FBullCowGame::FBullCowGame()
{
	Reset();
}


 
void FBullCowGame::Reset()
{
	constexpr int MAX_TRIES = 8;
	myCurrentTry = 1;
	myMaxTries = MAX_TRIES;
	return;
}


int FBullCowGame::getMaxTries() const
{
	return myMaxTries;
}

int FBullCowGame::getCurrentTry() const 
{
	return myCurrentTry;
}

bool FBullCowGame::isGameWon() const
{
	return false;
}

bool FBullCowGame::checkGuessValidity(std::string)
{
	return false;
}
