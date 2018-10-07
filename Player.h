//
//// Honor Pledge:
//// //
//// // I pledge that I have neither given nor
//// // received any help on this assignment.
//// //
//// // jwaggon
//

#include <string>

class Player
{
	private:
		//Bool values to check if they made the shot or not
		bool playerBucket;
		//int to count letters and iteration
		int letterCounter;
	public:
		//String that holds the letters of horse
		char horse_key[6];
		//Character Arrays to hold letters of horse
		char * ptr_playerLetter;
		//Default constructor
		Player();
		//Shoot method
		void Shoot();
		//Deconstructor
		~Player();
		//RecieveLetter method to see if the player needs to recieve a letter
		char ReceiveLetter();
		//Getters and Setters for booleans
		bool getPlayerBucket();
		void setPlayerBucket(bool bucket);
		//Getter for counter
		int getCounter();
		//Getter for score
		std::string getScore(); 
};
