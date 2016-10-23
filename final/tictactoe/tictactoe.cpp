/*
 * Tic Tac Toe Class Implementation
 *
 * tictactoe.cpp
 *
 * Brooke Cantwell
 *
 * 8 May 2016
 *
 * Functions and methods for the Tic Tac Toe class.
 */

#include <iostream>
#include <iomanip>
#include "tictactoe.h"
#include <ctime>
#include <cstdlib>

int TicTacToe::numGamesPlayed = 1;

//GLOBAL FUNCTIONS

//output function, displays the board and the current player
//and player handle

ostream& operator<< (ostream&out, TicTacToe game) {

	out << endl << " +---+---+---+" << endl;

	for (int r = 0; r < game.ROW; r++) {

		for (int c = 0; c < game.COL; c++) {
			out << " | ";
			out << game.board[r][c].getMarker( );
		}

		out << " | " << endl;
		out << " +---+---+---+" << endl;
	}

	out << endl;

	return(out);
}

istream& operator>> (istream&in, TicTacToe&game) {
	int r, c;
	char dummyChar;

	do {
		cout << "Player #" << game.currentPlayer + 1 << " (" << game.players[game.currentPlayer].getHandle( ) << ')' << endl;
		cout << "Input desired cell in the form ROWxCOL: ";
		in >> r >> dummyChar >> c;
		c--;
		r--;
	} while (!game.setCell(r,c));


	return(in);
}	

//CONSTRUCTORS

//default constructor
TicTacToe::TicTacToe( ) {
	currentPlayer = 0;
}

TicTacToe::TicTacToe(string f1, char m1, string l1, string f2, char m2, string l2) {
	players[0].setName(f1, m1, l1);
	players[1].setName(f2, m2, l2);

}

//MUTATOR METHODS

//setCell, checks that board cell is valid
bool TicTacToe::setCell(int r, int c) {
	bool restat = true;

	if (board[r][c].takenCell( )) {
		cout << "That cell is taken!" << endl;
		restat = false;
	}

	else {	
		if (r <= ROW && c <= COL)
			playCell(r, c);
		else
			restat = false;
	}

	return(restat);
}

//playCell, alter cell values
void TicTacToe::playCell(int r, int c) {
	char mark = players[currentPlayer].getMarker( );

	board[r][c].setMarker(mark);

	//check for winner
	checkBoard( );
}

//inputPlayer, input player information
void TicTacToe::inputPlayers( ) {
	for (int i = 0; i < DEFAULT_NUM_PLAYERS; i++) {
		cin >> players[i];
	}
}

//inputDate, input date information
void TicTacToe::inputDate( ) {
	cin >> gameDay;
}

//randomize markers for each player
void TicTacToe::randomMarker( ) {
	int rNum;
	//create temporary array of player objects
	Player tempPlayers[DEFAULT_NUM_PLAYERS] = players;

	srand (time (0) );

	rNum = rand( ) % 2 + 0;

	switch(rNum) {
		//if the first player in the array is
		//assigned x (order doesn't change)
		case 0:
			players[0].setMarker('X');
			players[1].setMarker('O');
			//x goes first
			currentPlayer = 0;
			break;
		//if the second player in the array is assigned x 
		//(switch players so x always goes first and is the 
		//1st player in the array)
		case 1:
			//switch players around
			players[0] = tempPlayers[1];
			players[1] = tempPlayers[0];
			//assign markers
			players[0].setMarker('X');
			players[1].setMarker('O');
			currentPlayer = 0;
			break;
		default:
			cout << "ERROR" << endl;
	}

	cout << "Player #1: " << players[0].getHandle( ) << endl;
	cout << "Player #2: " << players[1].getHandle( ) << endl;
}

//change players
void TicTacToe::changePlayer( ) {
	if (currentPlayer == 0)
		currentPlayer = 1;
	else
		currentPlayer = 0;
}

//checkBoard - sums up rows/columns/diagonals and checks for a winner
bool TicTacToe::checkBoard( ) {
	int numSums = 4;
	bool win;
	int count = 0;	

	//call all functions to sum up diagonals, rows
	//and columns and break out of the loop if one
	//of the functions returns true
	while (!win && count < numSums) {
		win = checkRightDiagonal( );
		if (win)
			break;
		win = checkLeftDiagonal( );
		if (win)
			break;
		win = checkRows( );
		if (win)
			break;
		win = checkCols( );
		if (win)
			break;
		count++;
	}
	
	return(win);

}

//PRIVATE METHODS used by checkBoard( )

//function that contains the switch statement/logic used
//in every function called by checkBoard( ), if a winner
//is found the winner data members is assigned, the
//gamesWon value for that player is incremented, and
//the winner and their handle is displayed
bool TicTacToe::checkSumValue(int sum) {
	bool win;

	switch(sum) {
		case 9:
			win = true;
			winner = 0;
			cout << "Player #1, " << players[0].getHandle( ) << " won!" << endl;
			players[0].gamesWon++;
			break;
		case -9:
			win = true;
			winner = 1;
			cout << "Player #2, " << players[1].getHandle( ) << " won!" << endl;
			players[1].gamesWon++;
			break;
		default:
			win = false;
	}

	return(win);
}

bool TicTacToe::checkRightDiagonal( ) {
	bool win;
	int sum = 0;
	
	for (int r = 0, c = 0; r < ROW; r++, c++)
		sum += board[r][c].getiMarker( );

	win = checkSumValue(sum);

	return(win);
}


bool TicTacToe::checkLeftDiagonal( ) {
	bool win;
	int sum = 0;

	for (int r = 0, c = COL - 1; c >= 0; r++, c--)	
		sum += board[r][c].getiMarker( );

	win = checkSumValue(sum);

	return(win);
}

bool TicTacToe::checkRows( ) {
	bool win;
	int sum;	

	for  (int r = 0; r < ROW && !win; r++) {
		sum = 0;
		for (int c = 0; c < COL; c++)
			sum += board[r][c].getiMarker( );
		win = checkSumValue(sum);
	}

	return(win);
}

bool TicTacToe::checkCols( ) {
	bool win;
	int sum;

	for (int c = 0; c < COL && !win; c++) {
		sum = 0;
		for (int r = 0; r < ROW; r++)
			sum += board[r][c].getiMarker( );
		win = checkSumValue(sum);
	}

	return(win);
}



//use the setMarker method to clear the board and reset
//iMarker values to 0
void TicTacToe::clearBoard( ) {
	for (int r = 0; r < ROW; r++) {
		for (int c = 0; c < COL; c++) {
			board[r][c].setMarker(' ');
		}
	}
}

void TicTacToe::displayStatistics( ) {

	cout << "Number of Games Played: " << numGamesPlayed << endl << endl;

	for (int i = 0; i < DEFAULT_NUM_PLAYERS; i++) {
		cout << "Statistics for " << players[i].getHandle( ) << endl;
		cout << "Games Won: " << players[i].gamesWon << endl;
		cout << std::fixed << setprecision(2) << "Percentage of Games Won: " << (players[i].gamesWon / (float)numGamesPlayed ) * 100 << '%' << endl;
}
}
