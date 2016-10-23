/*
 * Driver for Tic Tac Toe Class
 * (Final Lab Assignment)
 *
 * driver.cpp
 *
 * Brooke Cantwell
 *
 * 5 May 2016
 *
 * Driver for the Tic Tac Toe
 * game...
 *
 */

#include <iostream>
#include <iomanip>
#include "date.h"
#include "name.h"
#include "player.h"
#include "tictactoe.h"

using namespace std;

main( ) {
	TicTacToe game;
	bool startGame;
	bool firstTime = true;
	char answer = 'Y';
	int moveCounter = 0;

	//function prototypes
	bool startMenu( );
	
	startGame = startMenu( );

	//if the user decides to play
	if (startGame) {

		//input for player information and date
		game.inputPlayers( );
		game.inputDate( );

		//play the game
		while (answer == 'Y' || answer == 'y') {
			if (firstTime == true) {
				game.randomMarker( );
				firstTime = false;
			}
			cout << game;
			cin >> game;
			moveCounter++;
			if (!game.checkBoard( ) && moveCounter < 9)
				game.changePlayer( );
			else {
				if (!game.checkBoard( ) && moveCounter == 9) {
					cout << "Tie!" << endl;
					moveCounter = 0;
					game.clearBoard( );
					firstTime = true;
					cout << "Enter Y to play again or any other character to quit: ";
					cin >> answer;
					if (answer == 'Y' || answer == 'y')
						game.numGamesPlayed++;
				}
				else {
					cout << game;
					game.clearBoard( );
					firstTime = true;
					moveCounter = 0;
					cout << "Enter Y to play again or any other character to quit: ";
					cin >> answer;
					if (answer == 'Y' || answer == 'y')
						game.numGamesPlayed++;	
				}
	
			}
	}
	//display statistics
	game.displayStatistics( );

	}

}

bool startMenu( ) {
	char play;	
	bool startGame;

	cout << "Welcome to Tic-Tac-Toe in C++ Version 2.0!" << endl;
	cout << "Would you like to play? (Y/N): ";
	cin >> play;

	switch(play) {
		case 'Y':
		case 'y':
			cout << "Good choice!" << endl;
			cout << "First, enter your player information." << endl;
			startGame = true;
			break;
		case 'N':
		case 'n':
			cout << "That's too bad!" << endl;
			startGame = false;
			break;
		default:
			//if the user doesn't answer Y/N
			cout << "Unrecognized answer!" << endl;
			do {
				cout << "Would you like to play? (Y/N): ";
				cin >> play;
			} while (play != 'Y' && play != 'y' && play != 'N' && play != 'n');
			if (play == 'Y' || play == 'y') {
				cout << "Good choice!" << endl;
				cout << "First, enter your player information." << endl;
				startGame = true;
			}
			else {
				cout << "That's too bad!" << endl;
				startGame = false;
			}
	}

	return(startGame);

}
