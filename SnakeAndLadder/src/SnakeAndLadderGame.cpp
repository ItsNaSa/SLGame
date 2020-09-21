/*
 * SnakeAndLadderGame.cpp
 *
 *  Created on: 21 Sep 2020
 *      Author: krish
 */

#include "SnakeAndLadderGame.h"
#include "Player.cpp"
#include <time.h>

SnakeAndLadderGame::SnakeAndLadderGame() {
	// TODO Auto-generated constructor stub
	this->noOfPlayers = 0;
}

SnakeAndLadderGame::~SnakeAndLadderGame() {
	// TODO Auto-generated destructor stub
}


SnakeAndLadderGame :: SnakeAndLadderGame(int noOfPlayers){
//	Initialize the snakes and ladders
	traversals.insert({1,38});
	traversals.insert({4,14});
	traversals.insert({8,30});
	traversals.insert({21,42});
	traversals.insert({32,10});
	traversals.insert({36,6});
	traversals.insert({48,26});
	traversals.insert({50,67});
	traversals.insert({63,18});
	traversals.insert({71,92});
	traversals.insert({80,99});
	traversals.insert({88,24});
	traversals.insert({95,56});
	traversals.insert({97,78});
	this->noOfPlayers = noOfPlayers;
	list = new Player[4];
	for(int i = 0; i < noOfPlayers; i++){
		string tempString;
		// int tempColour;
		cout<<"Enter the name of player "<<i+1<<" :: ";
		cin>>tempString;
		// cout<<"Enter the colour of player :: ";
		// cin>>tempColour;
		list[i].setValues(tempString);
	}
}

Player SnakeAndLadderGame :: play(){
	int turn = 0;
	int diceCast;
	char c;
	int currentPlayerScore = 0;
	srand(time(0));
	while(1){
		currentPlayerScore = 0;
		cout<<"\n\nChance of player "<<turn+1<<"("<<list[turn].getName()<<")"<<endl;
		// cout<<"Please press any character to throw the dice"<<endl;
		// cin>>c;
		diceCast = rand()%6 + 1; // range 1 to 6
		cout<<"\tDice casted value "<<diceCast<<"!"<<endl;
		currentPlayerScore = list[turn].addDieCase(diceCast);
		cout<<"\tNow you are at position "<<currentPlayerScore<<"!!"<<endl;
		map<int,int>:: iterator a = traversals.find(currentPlayerScore); //check if landed on snake or ladder
		if(a != traversals.end()){
			if(a->first > a->second){
				cout<<"\t\tOops!! You encountered a snake!!\tYou are now at position "<<a->second<<"!!"<<endl;
			}
			else{
				cout<<"\t\tYay!! You encountered a ladder!!\tYou are now at position "<<a->second<<"!!"<<endl;
			}
			currentPlayerScore = a->second;
			list[turn].setSnakeOrLadderScore(currentPlayerScore);
			cout<<"Now you are at position "<<currentPlayerScore<<"!!"<<endl;
		}
//		If the die casts 6, cast again
		while(diceCast == 6){
			cout<<"You threw 6!! Cast again!! ";
			// cout<<"Please press Enter to throw the dice";
			diceCast = 0;
			diceCast = rand()%6 + 1; // range 1 to 6
			cout<<"\t\t\tDice casted value "<<diceCast<<"!"<<endl;
			currentPlayerScore = list[turn].addDieCase(diceCast);
			if(currentPlayerScore >= 100){
				return list[turn];
			}
			cout<<"\t\t\tNow you are at position "<<currentPlayerScore<<"!!"<<endl;
			map<int,int>:: iterator ab = traversals.find(currentPlayerScore); //check if landed on snake or ladder
			if(ab != traversals.end()){
				if(ab->first > ab->second){
					cout<<"\t\tOops!! You encountered a snake!!\tYou are now at position "<<ab->second<<"!!"<<endl;
				}
				else{
					cout<<"\t\tYay!! You encountered a ladder!!\tYou are now at position "<<ab->second<<"!!"<<endl;
				}
				currentPlayerScore = ab->second;
				list[turn].setSnakeOrLadderScore(currentPlayerScore);
			}
			cout<<"Now you are at position "<<currentPlayerScore<<"!!"<<endl;
		}
		if(currentPlayerScore >= 100){
			return list[turn];
		}
		else{
			turn = (turn + 1) % noOfPlayers;
			continue;
		}

	}
}
