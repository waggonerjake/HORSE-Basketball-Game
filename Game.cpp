// 
// Honor Pledge:
// //
// // I pledge that I have neither given nor 
// // received any help on this assignment.
// //
// // jwaggon

#include <iostream>
#include "Player.h"
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <iomanip>

int main()
{
	//Srand so it picks a different random number
	srand(time(NULL));
	//Condition for the while loop
	bool keepGoing = true;
	//Create the players
	Player * player1 = new Player();
	Player * player2 = new Player();
	//Start the while loop
	while(keepGoing)
	{
		
		//Player 1's turn to shoot the ball
		player1->Shoot();
		if(player1->getPlayerBucket() == false)
		{
			//Checking if they missed
			std::cout<<"Player 1: Missed Shot!"<<std::endl;
		}	
		if(player1->getPlayerBucket() == true)
		{
			//Checking if they made it
			std::cout<<"Player 1: Hit Shot!"<<std::endl;
		}
		//Player 2's turn to shoot the ball
		player2->Shoot();
		if(player2->getPlayerBucket() == false)
		{
			//Checking to see if they missed
			std::cout<<"Player 2: Missed Shot!"<<std::endl;
		}
		if(player2->getPlayerBucket() == true)
		{
			//Checking to see if they made it
			std::cout<<"Player 2: Hit Shot!"<<std::endl;
		}

		//If player 1 made it and player2 missed, give player 2 the next letter.
		if(player1->getPlayerBucket() == true && player2->getPlayerBucket() == false)
		{
			std::cout<<std::setw(25)<<"Player 2: Added an "<<player2->ReceiveLetter()<<std::endl;
		}
		//IF player 1 missed and player 2 made it, give player 1 the next letter.
		else if(player1->getPlayerBucket() == false && player2->getPlayerBucket() == true)
		{
			std::cout<<std::setw(25)<<"Player1: Added an "<<player1->ReceiveLetter()<<std::endl;
		}
		//To end the loop, check if player 1's string is equal to HORSE, if so end.
		if(player1->getCounter()>=5)
		{
			char reply[3];			
			std::cout<<"Player 2 Wins! ";
			std::cout<<player2->getScore()<<" :: ";
			std::cout<<"Player 1 Loses! ";
			std::cout<<player1->getScore()<<std::endl;
			std::cout<<"Would you like to play again? (Y|N)";
			std::cin>>reply;
			if(strcmp(reply,"Y")==0)
			{
				delete player1;
				delete player2;
				Player * player1 = new Player();
				Player * player2 = new Player();
				keepGoing = true;	
			}
			else if(strcmp(reply,"N")==0)
			{
				keepGoing = false;
				delete player1;
				delete player2;
			}
			else
			{
				std::cout<<"No correct answer detected, aborting process"<<std::endl;
				keepGoing = false;
				delete player1;
				delete player2;
			}

		}
		//To end the loop, check if player 2's string is equal to HORSE, if so end.
		else if(player2->getCounter()>=5)
		{
			char reply[3];
			std::cout<<"Player 1 Wins! ";
			std::cout<<player1->getScore()<<" :: ";
			std::cout<<"Player 2 Loses! ";
			std::cout<<player2->getScore()<<std::endl;
			std::cout<<"Would you like to play again? (Y|N)";
			std::cin>>reply;
			if(strcmp(reply,"Y")==0)
			{
				delete player1;
				delete player2;
				Player * player1 = new Player();
				Player * player2 = new Player();
				keepGoing = true;	
			}
			else if(strcmp(reply,"N")==0)
			{
				delete player1;
				delete player2;
				keepGoing = false;
			}
			else
			{
				std::cout<<"No correct answer detected, aborting process"<<std::endl;
				keepGoing = false;
				delete player1;
				delete player2;
			}
		}
	}
	return 0;
}
