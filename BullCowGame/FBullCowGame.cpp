#include "FBullCowGame.h"

FBullCowGame::FBullCowGame()
{
	Reset();
}


 
void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 4;
	const FString HIDDEN_WORD = "ant";
	
	myMaxTries = MAX_TRIES;
	myHiddenWord = HIDDEN_WORD;
	myCurrentTry = 1;
	return;

}


int32 FBullCowGame::getMaxTries() const { return myMaxTries; }
int32 FBullCowGame::getCurrentTry() const {	return myCurrentTry; }
int32 FBullCowGame::getHiddenWordLength() const { return myHiddenWord.length(); }

bool FBullCowGame::isGameWon() const
{
	return false;
}

bool FBullCowGame::checkGuessValidity(FString) const
{
	return false;
}


//Receives a VALID guess, increments turn, and returns count
FBullCowCount FBullCowGame::SubmitGuess(FString Guess)
{
	// increment the turn number
	myCurrentTry++;

	// setup a return variable
	FBullCowCount BullCowCount;

	// loop through all letters in the guess
	int32 HiddenWordLength = myHiddenWord.length();
	for (int32 MyHWChar = 0; MyHWChar < HiddenWordLength; MyHWChar++) {
		// compare letters against the hidden word
		for (int32 GChar = 0; GChar < HiddenWordLength; GChar++) {
			// if they match then
			if (Guess[GChar] == myHiddenWord[MyHWChar]) {
				if (MyHWChar == GChar) {
					// increment bulls if they're in the same place
					BullCowCount.bulls++;
				}
				// increment cows if not
				else
					BullCowCount.cows++;	// increment cows
			}
		}
	}
	return BullCowCount;
}
