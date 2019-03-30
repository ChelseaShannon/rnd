
#include <iostream>
#include <string>
#include "FBullCowGame.h"

void PrintIntro();
void PlayGame();
std::string GetGuess();
bool AskToPlayAgain();

FBullCowGame BCGame; //instantiate a new game

// entry point for our game
int main()
{
	bool bPlayAgain = false;
	do {
		PrintIntro();
		PlayGame();
		bPlayAgain = AskToPlayAgain();
	}
	while (bPlayAgain);
	
	return 0;
}


void PrintIntro() {
	//Introduce the Game
	constexpr int WORD_LENGTH = 5;
	std::cout << "Welcome to the Bulls and Cows, a fun word game.\n";
	std::cout << "Can you guess the " << WORD_LENGTH << " letter word I'm thinking of?\n";
	return;
}

void PlayGame()
{
	// Loop for the number of turns asking for guesses
	
	int MaxTries = BCGame.GetMaxTries();
	std::cout << MaxTries << std::endl;
	constexpr int NUM_OF_TURNS = 5;
	for (int count = 1; count <= MaxTries; count++) {
		std::string Guess = GetGuess();
		std::cout << "Your guess was " << Guess << std::endl;
		std::cout << std::endl;
	}

	std::cout << std::endl;

}

std::string GetGuess()
{	
	int CurrentTry = BCGame.GetCurrentTry();
	std::string Guess = "";
	//Get a guess from the player
	std::cout << "Try " << CurrentTry << ". Enter your guess: ";
	std::getline(std::cin, Guess);
	return Guess;
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again? (y/n) ";
	std::string Response = "";
	std::getline(std::cin, Response);

	return (Response[0] == 'y') || (Response[0] == 'Y');
}
