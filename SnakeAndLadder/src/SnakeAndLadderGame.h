/*
 * SnakeAndLadderGame.h
 *
 *  Created on: 21 Sep 2020
 *      Author: krish
 */

#ifndef SNAKEANDLADDERGAME_H_
#define SNAKEANDLADDERGAME_H_
#include <iostream>
#include <map>
#include "player.h"
using namespace std;

/**
 *
 */
class SnakeAndLadderGame {
private:
	Player *list;
	map <int, int> traversals;
	int noOfPlayers;
public:
	SnakeAndLadderGame();
	SnakeAndLadderGame(int noOfPlayers);
	virtual ~SnakeAndLadderGame();
	Player play();
};

#endif /* SNAKEANDLADDERGAME_H_ */
