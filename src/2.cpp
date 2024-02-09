#include <iostream>
#include <string.h>
#include <string>
using namespace std;

// Exercise 1 & 2
class Player {

	public:
		string token; //Player Name
		string property_name;
		
		//seter for cash
		void setCash(unsigned int cash);
		unsigned int getCash(void);
		
		//seter for property_val
		void setPropVal(unsigned int prop_val);
		unsigned int getPropVal(void);
		void player_info();
		
		// constructor
		Player(string token, string prop_name,unsigned int cash,unsigned int prop_val);
		
		// destructor
		~Player();
		
	private:
		unsigned int cash;
		unsigned int property_val;
};

//Constructor
Player::Player(string tok, string prop_name,unsigned int money,unsigned int prop_val){

	cout <<"A new player is ready to play"<< endl;
	
	
	token = tok;
	property_name = prop_name;
	cash = money;
	property_val = prop_val;
}

//Deconstructor

Player::~Player(){

	cout << "Player using the " << token << " has stoped playing" << endl;
}


//Setters
void Player::setCash(unsigned int newCash){
	
	cash = newCash;
}

void Player::setPropVal(unsigned int prop_val){
	
	property_val = prop_val;
}

//Getters
unsigned int Player::getCash(void){

	return cash;
}

unsigned int Player::getPropVal(void){
	
	return property_val;
}


// Exercise 3.1 | player_info()
void Player::player_info(void){

	
	cout << "This player is using the "  << token << ", has $" << getCash() << " and owns the " << property_name << " lot" << endl;
}

// Exercize 3.2 | next_move()
void next_move(Player *players[], int player, string move){
			
	if (move == "start") {

		players[player]->setCash(players[player]->getCash() + 200);
		cout << "The player using the "  << players[player]->token << " moved on " << move << " and has $" << players[player]->getCash() << endl;
	} else {
		
		//Find the player holding the property == move
		int temp;
		
		for (int i=0;i<3;i++) {

			if (players[i]->property_name == move) {
				temp = i;
			}
		}
		

		if (players[player]->property_name == move) {
			
			cout << "The player using the "  << players[player]->token << " moved on " << move << " and has $" << players[player]->getCash() << endl;
		}else{
			
			if (move == "brown") {
				
				players[player]->setCash(players[player]->getCash() - 50);
				players[temp]->setCash(players[temp]->getCash() + 50);
			} else if(move == "green") {
				
				players[player]->setCash(players[player]->getCash() - 85);
				players[temp]->setCash(players[temp]->getCash() + 85);
			} else if(move == "red") {
				
				players[player]->setCash(players[player]->getCash() - 110);
				players[temp]->setCash(players[temp]->getCash() + 110);
			}
	
			cout << "The player using the "  << players[player]->token << " moved on " << move << " and has $" << players[player]->getCash() << endl;
		}
	}
}

//Exercise 3.3 | find_winner()
void find_winner(Player *players[]) {
	
	int winner;
	float net;
	float  max=0;
	float prop;
	for (int i=0;i<3;i++) {
		prop = players[i]->getPropVal();
		prop = prop*0.55;
		
		net = players[i]->getCash() + prop;
		if (net > max) {
			max = net;
			winner = i;
		}
	}

	cout << "The player using the "  << players[winner]->token << " wins having a total net worth  of $" << max << endl;
}

int main(){
	
	Player one = Player("Iron","brown",500,85);
	Player two = Player("Shoe", "red",500,125);
	Player three = Player("Battleship", "green",500,100);
	
	one.player_info();
	
	Player *players [] = {&one, &two, &three};
	
	next_move(players,0,"start");
	next_move(players,0,"red");
	
	find_winner(players);
}
