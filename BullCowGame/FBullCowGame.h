#pragma once
#include <iostream>
#include <string>

class FBullCowGame {
public:
	FBullCowGame();	// Constructor

	int getMaxTries() const;
	int getCurrentTry() const;
	bool isGameWon() const;


	void Reset();	//TODO make a more rich return value
	bool checkGuessValidity(std::string); //TODO make a more rich return value


private:
	//See Constructor for init
	int myCurrentTry;
	int myMaxTries;
	bool isIsogram(std::string);
};
