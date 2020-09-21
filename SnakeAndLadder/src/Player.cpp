/*
 * Player.cpp
 *
 *  Created on: 21 Sep 2020
 *      Author: krish
 */

#include "Player.h"

Player::Player() {
	// TODO Auto-generated constructor stub
//	this->c1 = 0;
	this->name = "None";
	this->score = 0;
}

Player::~Player() {
	// TODO Auto-generated destructor stub
}

int Player::addDieCase(int dieScore){
	this->score += dieScore;
	return this->score;
}

int Player::setSnakeOrLadderScore(int newScore){
	this->score = newScore;
	return this->score;
}

string Player::getName(){
	return this->name;
}

void Player::setValues(string name){
	this->name  = name;
}
