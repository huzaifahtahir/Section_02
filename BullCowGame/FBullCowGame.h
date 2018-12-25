#pragma once
#include <iostream>
#include <string>

class FBullCowGame {
public:
	void Reset();	//TODO make a more rich return value
	int getMaxTries();
	int getCurrentTry();
	bool isGameWon();
	bool checkGuessValidity(std::string); //TODO make a more rich return value


private:
	int myCurrentTry;
	int myMaxTry;
	bool isIsogram(std::string);
};
