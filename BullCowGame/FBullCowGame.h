#pragma once
#include <iostream>
#include <string>

using FString = std::string;
using int32 = int;

// values initialized to zero
struct FBullCowCount 
{
	int32 bulls = 0;
	int32 cows = 0;
};

class FBullCowGame 
{
public:
	FBullCowGame();	// Constructor

	int32 getMaxTries() const;
	int32 getCurrentTry() const;
	int32 getHiddenWordLength() const;
	bool isGameWon() const;
	bool checkGuessValidity(FString) const ; //TODO make a more rich return value


	void Reset();	//TODO make a more rich return value
	// counts bulls and cows, and increases try number assuming valid guess
	FBullCowCount SubmitGuess(FString Guess);

private:
	//See Constructor for init
	int32 myCurrentTry;
	int32 myMaxTries;
	bool isIsogram(FString);
	FString myHiddenWord;
};
