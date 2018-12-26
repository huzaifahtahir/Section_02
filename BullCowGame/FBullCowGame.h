#pragma once
#include <iostream>
#include <string>

class FBullCowGame {
public:
	int getMaxTries() const;
	int getCurrentTry() const;
	bool isGameWon() const;


	void Reset();	//TODO make a more rich return value
	bool checkGuessValidity(std::string); //TODO make a more rich return value


private:
	int myCurrentTry = 1;
	int myMaxTries = 5;
	bool isIsogram(std::string);
};
