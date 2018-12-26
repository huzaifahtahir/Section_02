#include <iostream>
#include <string>
#include "FBullCowGame.h"

void printIntro();
void PlayGame();
std::string getGuess();
void printGuess(std::string guess);
bool askToPlayAgain();

FBullCowGame BCGame;	// Instantiate a new game

int main()
{
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


	int maxTries = BCGame.getMaxTries();

	// Loop for the number of turns asking for guesses
	for (int count = 0; count < maxTries; count++)
	{
		std::string guess = getGuess();
		printGuess(guess);
		std::cout << std::endl;
	}
}

void printIntro()
{
	constexpr int WORD_LENGTH = 5;
	std::cout << "Welcome to the Bulls and Cows, a fun word game.\n";
	std::cout << "Can you guess the " << WORD_LENGTH
		<< " letter isogram I'm thinking of?\n";
	return;

}

std::string getGuess()
{
	std::string guess;
	int myCurrentTry = BCGame.getCurrentTry();
	std::cout << "Try " << myCurrentTry << ". Enter your guess: ";
	getline(std::cin, guess);

	return guess;
}

void printGuess(std::string guess)
{
	//Print guess to user
	std::cout << "Your guess was: " << guess << std::endl;
}

bool askToPlayAgain()
{

	bool answer = false;
	std::string response = "";
	std::cout << "Do you want to play again? (Y/N) ";
	getline(std::cin, response);


	if (response[0] == 'y' || response[0] == 'Y')
		answer = true;
	if (response[0] != 'y' || response[0] == 'Y')
		answer = false;

	return answer;

}


