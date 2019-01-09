/*	This is the console executable, that makes use of the BullCowClass.
This acts as the view in a MVC pattern, and is resposible for all
user interaction. For game logic, see the FBullCowGame class.
*/

#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;

void printIntro();
void PlayGame();
FText getGuess();
void printGuess(FText guess);
bool askToPlayAgain();


FBullCowGame BCGame;	// Instantiate a new game

int main()
{
	std::cout << BCGame.getCurrentTry();
	bool bPlayAgain = false;
	do
	{
		printIntro();
		PlayGame();
		bPlayAgain = askToPlayAgain();
	} while (bPlayAgain);
	return 0;
}


void PlayGame()
{

	BCGame.Reset();
	int32 maxTries = BCGame.getMaxTries();

	// Loop for the number of turns asking for guesses
	// TODO change from FOR to WHILE loops once we are validating tries
	for (int32 count = 0; count < maxTries; count++)
	{
		FText guess = getGuess(); // TODO make loop checking valid

		// submit valid guess to the game and receive counts
		FBullCowCount BullCowCount = BCGame.SubmitGuess(guess);
		// print number of bulls and cows
		std::cout << "Bulls = " << BullCowCount.bulls;
		std::cout << ". Cows = " << BullCowCount.cows << std::endl;
		std::cout << std::endl;
	}

	// TODO summarise game
}

void printIntro()
{
	
	std::cout << "Welcome to the Bulls and Cows, a fun word game.\n";
	std::cout << "Can you guess the " << BCGame.getHiddenWordLength()
		<< " letter isogram I'm thinking of?\n";
	return;

}

FText getGuess()
{
	FText guess;
	int32 myCurrentTry = BCGame.getCurrentTry();
	std::cout << "Try " << myCurrentTry << ". Enter your guess: ";
	getline(std::cin, guess);

	return guess;
}

void printGuess(FText guess)
{
	//Print guess to user
	std::cout << "Your guess was: " << guess << std::endl;
}

bool askToPlayAgain()
{

	bool answer = false;
	FText response = "";
	std::cout << "Do you want to play again? (Y/N) ";
	getline(std::cin, response);


	if (response[0] == 'y' || response[0] == 'Y')
		answer = true;
	if (response[0] != 'y' || response[0] == 'Y')
		answer = false;

	return answer;

}


