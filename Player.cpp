//:
//// Honor Pledge:
//// //
//// // I pledge that I have neither given nor
//// // received any help on this assignment.
//// //
//// // jwaggon
//

#include "Player.h"
#include <stdlib.h>
#include <cstring>
#include <stdio.h>
#include <iostream>

Player::Player()
{
	//Constructor setting the initial values
	//of their score to 6 null characters
	ptr_playerLetter = new char[6];
	//Setting the char horse_key
	//to value of HORSE
	strcpy(horse_key,"HORSE");
	//Set the letter iterator for 
	//their score value
	letterCounter = 0;
}

Player::~Player()
{
	//Deleting the strings to avoid
	//memory leaks
	delete[] ptr_playerLetter;
}

void Player::Shoot()
{	//Picks a random number between 1-51
	int FiftyFifty = rand()%51;
	//If the number is in between 1-26, player made the shot
	if(FiftyFifty >= 1 && FiftyFifty <= 26)
	{
		setPlayerBucket(true);		
	}
	else
	{
		//If it was between 26 and 51, player missed.
		setPlayerBucket(false);
	}
}

char Player::ReceiveLetter()
{
	//Setting the indentical index in the char array to the
	//indentical value of HORSE
	ptr_playerLetter[letterCounter] = horse_key[letterCounter];
	//Increment the letter counter so it can pick a new variable
	//next run
	letterCounter++;
	//Return the most recent letter that was added to the char array	
	return ptr_playerLetter[letterCounter - 1];
}
//Getter to see if the player made the shot or not
bool Player::getPlayerBucket()
{
	return playerBucket;
}
//Setter for setting the value if the player made the shot or not
void Player::setPlayerBucket(bool bucket)
{
	playerBucket = bucket;
}
//Getter for the letter counter to stop the program
int Player::getCounter()
{
	return letterCounter;
}
//Getter to return the players final score
std::string Player::getScore()
{
	std::string score(ptr_playerLetter);
	return score;
}

