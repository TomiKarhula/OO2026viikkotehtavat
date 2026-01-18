#include "Game.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

Game::Game(int maxNumber)
{
    this->maxNumber = maxNumber;
    numOfGuesses = 0;

    srand(time(nullptr));
    randomNumber = rand() % maxNumber + 1;

    cout << "GAME CONSTRUCTOR: object initialized with "
         << maxNumber << " as a maximum value" << endl;
}

Game::~Game()
{
    cout << "GAME DESTRUCTOR: object cleared from stack memory" << endl;
}

void Game::play()
{
    cout << "GAME PLAY: game started" << endl;

    do {
        cout << "Give your guess between 1-" << maxNumber << endl;
        cin >> playerGuess;
        numOfGuesses++;

        if (playerGuess < randomNumber) {
            cout << "Your guess is too small" << endl;
        }
        else if (playerGuess > randomNumber) {
            cout << "Your guess is too big" << endl;
        }
        else {
            cout << "Your guess is right = " << randomNumber << endl;
        }

    } while (playerGuess != randomNumber);

    printGameResult();
}

void Game::printGameResult()
{
    cout << "You guessed the right answer = "
         << randomNumber
         << " with "
         << numOfGuesses
         << " guesses" << endl;
}
