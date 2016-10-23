/*
 * Cave Adventure Lab
 *
 * cave.cpp
 *
 * Brooke Cantwell
 *
 * 20 March 2016
 *
 * Cave adventure lab.
 *
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "level.h"
#include "animal.h"

using namespace std;

main( ) {
	//local variables
	string name;
	bool play;
	bool continuePlaying = true;
	Level level1("Evil Goblin", "golden sword", 1, "entering the mouth of the cave");
	Level level2("Evil Wombat", "golden shield", 2, "going deeper into the cave and turning off the water supply");
	Level level3("Hobogoblin Lord", "golden helmet", 3, "reaching the depths of the cave");
	const int numLevels = 3;

	Level levels[numLevels] = {level1, level2, level3};

	//function prototypes
	bool gameIntro(string&);
	bool playLevel(Level);
	void takeNap( );
	void playFinalLevel( );
	void sing12DaysofChristmas( );
	
	//use the static function setTrickLevel to determine which of the
	//three levels has a trick treasure
	Level::setTrickLevel( );

	play = gameIntro(name);	

	//if the user doesn't want to play, tell them they aren't very brave	
	if (!play)
		cout << "You aren't very brave after all!" << endl;
	//if the user wants to play, start level 1
	else {

		//use a for loop to go through levels 1-3 (as long as the player is still alive) by passing
		//the level to the playLevel function
		for (int i = 0; i < numLevels && continuePlaying == true; i++) {
			continuePlaying = playLevel(levels[i]);
		}

		//if the user is still alive after level 3, start the final level

		if (continuePlaying == true) 
			playFinalLevel( );	
	}

}

//gameIntro, outputs the introduction to the game and asks the user their
//name and if they want to play
bool gameIntro(string&name) {
	bool play;
	char answer;

	//display introduction
	cout << "Brave knight!!! What is your name? ";
	cin >> name;
	cout << "We are in need of your help, " << name << '!' << endl;
	cout << "Out village is being overrun by the goblins of the Northern Caves." << endl;
	cout << "We need you to defeat them!" << endl;
	cout << "Will you accept the challenge (Y/N)? ";
	cin >> answer;

	//switch on user answer
	switch(answer) {
		case 'Y':
		case 'y':
			play = true;
			break;
		case 'N':
		case 'n':
			play = false;
			break;
		default:
			cout << "We did not recognize your answer!";
			do {
				cout << "Will you accept the challenge (Y/N) ?";
				cin >> answer;
			} while (answer != 'Y' && answer != 'y' && answer != 'N' && answer != 'n');
			if (answer == 'Y' || answer == 'y')
				play = true;
			else
				play = false;
	}

	return(play);
}

void takeNap( ) {
	const int NUM_ANIMALS = 4;

	//create animal objects
	Animal cow("cow", "moo");
	Animal sheep("sheep", "baa");
	Animal pig("pig", "oink");
	Animal chicken("chicken", "cluck");

	static bool firstTime = true;
	int rNum;

	if (firstTime == true) {
		srand (time(0) );
		firstTime = false;
	}

	//generate random order
	rNum = rand( ) % 3 + 0;


	//create an array of pointers to animal objects, assign
	//an address location of each of the animals to a pointer
	//in the array depending on the random number
	
	Animal *ptrA[NUM_ANIMALS];

	switch(rNum) {
		case 0:
			ptrA[0] = &cow;
			ptrA[1] = &sheep;
			ptrA[2] = &pig;
			ptrA[3] = &chicken;
			break;
		case 1:
			ptrA[0] = &chicken;
			ptrA[1] = &pig;
			ptrA[2] = &sheep;
			ptrA[3] = &cow;
			break;
		case 2:
			ptrA[0] = &pig;
			ptrA[1] = &cow;
			ptrA[2] = &chicken;
			ptrA[3] = &sheep;
			break;
		case 3:
			ptrA[0] = &sheep;
			ptrA[1] = &chicken;
			ptrA[2] = &cow;
			ptrA[3] = &pig;
			break;
		case 4:
			cout << "Error with random number generator" << endl;
	}

	//create arrays of strings for the animal names and sounds	
	string names[NUM_ANIMALS];
	string sounds[NUM_ANIMALS];

	//populate the names and sounds array in the order provided by the switch statement
	for (int i = 0; i < NUM_ANIMALS; i++) {
		names[i] = (*ptrA[i]).getAnimal( );
		sounds[i] = (*ptrA[i]).getSound( );
	}

	cout << "You have picked up the treasure, now go rest before continuing the mission." << endl;

	//sing the verses for each animal and the sound it makes
	for (int i = 0; i < NUM_ANIMALS; i++) {
		cout << "Old MacDonald had a farm e-i-e-i-o, and on this farm he had a ";
		cout << names[i];
		cout << " e-i-e-i-o, with a ";
		cout << sounds[i] << '-' << sounds[i];
		cout << " here and a " << sounds[i] << '-' << sounds[i] << " there, ";
		cout << "here a " << sounds[i] << ", there a " << sounds[i];
		cout << " everywhere a " << sounds[i] << '-' << sounds[i];
		cout << ", Old MacDonald had a farm, e-i-e-i-o." << endl;
	}

}

//function to sing the 12 Days of Christmas
void sing12DaysofChristmas( ) {

	const int numDays = 12;
	string days[numDays] = {"first", "second", "third", "fourth", "fifth", "sixth", "seventh", "eighth", "ninth", "tenth", "eleventh", "twelfth"};
	string gifts[numDays] = {"a partridge in a pear tree", "two turtle doves", "three french hens", "four calling birds", "five golden rings", "six geese a-laying", "seven swans a-swimming", "eight maids a-milking", "nine ladies dancing", "ten lords a-leaping", "eleven pipers piping", "12 drummers drumming"};

	//for loop to control the day number
	for (int i = 0; i < numDays; i++) {
		cout << "On the " << days[i] << " day of Christmas my true love gave to me ";
		//nested for loop to control the number of gifts
		for (int j = i; j >= 0; j--) {
			//condtion statements to sing the last gift differently depending on the day number
			if (j != 0)
				cout << gifts[j] << ", ";
			else
			if (j == 0) {
				if (i == 0)
					cout << gifts[j] << ".";
				else
					cout << "and " << gifts[j] << ".";
			}
		}
		cout << endl;

	}

}

//playLevel function, plays the first three levels of the game with nested switch statements for each combination of possibilities
//with 3 choices for each level
bool playLevel(Level l) {
	string monster, treasure, adventure;
	int levelNumber;
	int trickLevel;
	int choice, choice2, choice3;
	bool trick;
	bool continuePlaying;
	//counter variables to display the number of options with the trick present
	int i = 1, c = 1;

	//function prototypes
	void sing12DaysofChristmas( );

	//set local variables to the data members of the specific level
	monster = l.getMonster( );
	treasure = l.getTreasure( );
	adventure = l.getAdventure( );
	levelNumber = l.getLevelNumber( );
	//call static member function getTrickLevel to get the level with the trick present for comparison
	trickLevel = Level::getTrickLevel( );
	if (levelNumber == trickLevel)
		trick = true;
	else
		trick = false;

	//output choices with the variables (set to the level's data members)
	cout << "You are now " << adventure << ", what would you like to do?" << endl;
	cout << "1) Attack the " << monster << endl;
	cout << "2) Pick up the " << treasure << endl;
	cout << "Enter your choice: ";
	cin >> choice;

	//nested switch statement - each level has a maximum of three possible choices (menu options displayed)
	//nested switch statements represent combinations of possibilities

	//use the user's choice to determine the next part of the game
	switch(choice) {
		case 1:
			//if the choose to attack the monster, tell them they have slayed it
			//and show the next choices
			cout << "You have slayed the " << monster << " and are still alive, what would you like to do?" << endl;
			cout << "1) Move on to the next adventure" << endl;
			cout << "2) Pick up the " << treasure << endl;
			cout << "Enter your choice: ";
			cin >> choice2;
			//if the user tries to go to the next level without picking up the treasure
			//tell them they've died
			switch(choice2) {
				case 1:
					cout << "You have tried to advance to the next level without picking up the treasure, you died!" << endl;
					continuePlaying = false;
					break;
				case 2:
					cout << "You have picked up the " << treasure << ". What would you like to do now?" << endl;
					//display different options for the first two levels and the last level
					if (levelNumber != 3)
						cout << i++ << ") Move on to the next level" << endl;
					else
						cout << i++ << ") Move on to the final mission" << endl;
			
					//if the current level is the trick level, display the trick treasure
					if (trick == true)
						cout << i++ << ") Pick up the silver tray of life" << endl;
					cout << "Enter your choice: ";
					//user input for the third choice of the level
					cin >> choice3;
					switch(choice3) {
						case 1:
							continuePlaying = true;
							break;
						case 2:
							cout << "You have been tricked into picking up a second treasure!" << endl;
							cout << "Now sing the 12 Days of Christmas!" << endl;
							sing12DaysofChristmas( );
							continuePlaying = true;
							break;
					}
			}
			break;
		case 2:
			//if the user chooses to pick up the treausre first instead of attacking
			//the monster, call the takeNap functions (sing Old MacDonald)
			takeNap( );
			cout << "Great! You are awake and rested, what would you like to do?" << endl;
			cout << c++ << ") Attack the " << monster << endl;
		
			if (levelNumber != 3)
				cout << c++ << ") Move on to the next adventure" << endl;
			else
				cout << c++ << ") Move on to the final mission" << endl;

			//if the current level is the trick level, display the trick treasure
			if (trick == true)
				cout << c++ << ") Pick up the silver tray of life" << endl;
			
			cout << "Enter your choice: ";
			//get user input for the second choice of the level
			cin >> choice2;
			switch(choice2) {
				case 1:
					cout << "You have slayed the " << monster << " and are still alive, what would you like to do?" << endl;
					if (levelNumber != 3)
						cout << "1) Move on to the next adventure" << endl;
					else		
						cout << "1) Move on to the final mission" << endl;
					cout << "Enter your choice: ";
					//get user input for the third choice of the level
					cin >> choice3;
					if (choice3 == 1)
						continuePlaying = true;
					
					break;
				case 2:
					cout << "You have tried to advance to the next level without killing the " << monster << ", you have died." << endl;
					break;
				case 3:
					cout << "They tricked you into picking up a second treasure, now sing the Twelve Days of Christmas!" << endl;
					//sing the 12 days of christmas
					sing12DaysofChristmas( );
			}
					continuePlaying = true;
			break;
		default:
			cout << "Please choose a valid menu option." << endl;
			continuePlaying = playLevel(l);						
	}

	return(continuePlaying);

}

void playFinalLevel( ) {
	char play;
	int numVillagers = 0;
	const int MAX_VILLAGERS = 30;
	int villagerNumber = 0;
	string specialWords[MAX_VILLAGERS];
	int rNum1, rNum2;
	int startingIndex, direction;

	cout << "Are you ready for the final mission (Y/N)?: ";
	cin >> play;	

	switch(play) {
		case 'Y':
		case 'y':
			//final level
			cout << "Enter a distinct special word for each Village Idiot, or enter 'quit' to quit." << endl;

			for (int i = 0; i < MAX_VILLAGERS; i++) {	
				cout << "Village Idiot #" << i + 1 << ", what is your special word? ";
				cin >> specialWords[i];
				//search the array for repeated words before continuing
				if (specialWords[i] == "quit")
					break;

				for (int j = 0; j < i; j++) {
					if (specialWords[i] == specialWords[j]) {
						cout << "You can't repeat any words! Please enter another special word: ";
						cin >> specialWords[i];
					}
				}
				numVillagers++;
			}

			//generate a random number for the direction (0 is forward and 1 is backwards)
			direction = rand( ) % 1 + 0;

			//generate a random number for the starting point
			startingIndex = rand( ) % numVillagers + 0;
		
			//switch on the direction variable
			switch(direction) {
				case 0:
					//start the poem at the starting index and go to the end
					for (int i = startingIndex; i <= numVillagers; i++) {
						if (specialWords[i] != "quit")
							cout << specialWords[i] << " ";
					}
					//finish the poem by starting from the beginning and going to the starting points
					for (int i = 0; i < startingIndex; i++) {
						if (specialWords[i] != "quit")
							cout << specialWords[i] << " ";
					}
					break;
				case 1:
					//start the poem and the starting index and go backwards to the beginning
					for (int i = startingIndex; i <= 0; i--) {
						if (specialWords[i] != "quit")
							cout << specialWords[i] << " ";
					}
					//finish the poem from the end to the starting point
					for (int i = numVillagers; i < startingIndex; i--) {
						if (specialWords[i] != "quit")
							cout << specialWords[i] << " ";
					}
			}
			cout << endl;
			break;

		case 'N':
		case 'n':
			cout << "That's too bad!" << endl;
			break;
		default:
			cout << "We did not recognize your answer!" << endl;
			playFinalLevel( );
	}
}
