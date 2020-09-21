/*
 * Player.h
 *
 *  Created on: 21 Sep 2020
 *      Author: krish
 */

#ifndef PLAYER_H_
#define PLAYER_H_
#include <iostream>
using namespace std;

//enum color{red, green, blue, yellow};

class Player {
private:
	string name;
	int score;
//	enum color c1;
public:
	Player();
	Player(string name, int color){
		this->name = name;
		this->score = 0;
//		this->c1 = color;
	}
	virtual ~Player();
	int addDieCase(int dieScore);
	int setSnakeOrLadderScore(int newScore);
	void setValues(string name);
	string getName();
};

#endif /* PLAYER_H_ */
