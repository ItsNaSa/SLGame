//============================================================================
// Name        : SnakeAndLadder.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "SnakeAndLadderGame.cpp"
using namespace std;

int main() {
	int noOfPlayers = 1;

	cout << "!!!Hello!!!" << endl; // prints !!!Hello World!!!
	cout<<"Welcome to my Snake and Ladder Game!!!"<<endl;
	while(noOfPlayers <= 1 || noOfPlayers > 4){
		if(noOfPlayers < 1 || noOfPlayers > 4){
			cout<<"Number of players should be 2 to 4!! Please enter properly!"<<endl;
		}
		cout<<"Enter total number of players please :: ";
		cin>>noOfPlayers;
	}
	SnakeAndLadderGame gameInstance1(noOfPlayers);
	Player winner = gameInstance1.play();
	cout<<"Winner of the match is "<<winner.getName()<<endl;
	cout<<"Thank you for playing!!"<<endl;
	return 0;
}
