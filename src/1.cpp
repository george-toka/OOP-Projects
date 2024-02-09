#include <iostream>
#include <cstring>
using namespace std;


// ========== Structs ==========

// Exercise 1
struct Player 
{
	char token[50];
	unsigned short int cash;
	unsigned short int status;
	bool get_out_of_jail;
	char property[10];
	unsigned short int property_val;
};

struct Move 
{
	char name[20];
	char type[20];
	unsigned short int effect;
};


// ========== Functions ==========

// Exercise 2 | player_info()
void player_info(Player player){
	
	if (player.status == 0) {
		
		cout << "This player uses the "  << player.token << ", has $" << player.cash << " and is free" << endl;
	} else {
		
		cout << "This player uses the "  << player.token << ", has $" << player.cash << " and is in jail" << endl;
	}
}

// Exercise 3.1 | next_move()
void next_move(Player *players[3], int player, Move move){
	
	char prop[10];
	char name[10];

	if (strcmp(move.type,"action") == 0) {
		
		if ((strcmp(move.name,"start") == 0)){
			
			players[player]->cash+= move.effect;
			cout << "The player using the "  << players[player]->token << " moved on " << move.name << endl;
		} else {
			
			if (players[player]->get_out_of_jail == false) {
			
				players[player]->status = move.effect;
				players[player]->get_out_of_jail = false;			
			}
			
			cout << "The player using the "  << players[player]->token << " moved on the " << move.name << endl;
		}
	} else {
		
		int temp;
		//Find the player holding the property == move.name
		for (int i=0;i<3;i++) {

			if (strcmp(players[i]->property,move.name)==0) {
				temp = i;
			}
		}
		
		if (strcmp(players[player]->property,move.name)==0) {
			
			cout << "The player using the "  << players[player]->token << " moved on the " << move.name << " lot"<< endl;
		}else{
		
			players[temp]->cash += move.effect;
			players[player]->cash -= move.effect;
			
			cout << "The player using the "  << players[player]->token << " moved on the " << move.name << " lot"<< endl;	
		}
	}	
}

// Exercise 3.2 | find_winner()
int find_winner(Player *players[3]){

		int winner;
		float net;
		float  max=0;
		
		for (int i=0;i<3;i++) {
			
			net = players[i]->cash + players[i]->property_val*0.55;
			
			if (net > max) {
				
				max = net;
				winner = i;
			}
		}

		cout << "The player using the "  << players[winner]->token << " wins having a total net worth  of $" << max << endl;
}

int main() {
	
	Player playerOne = {"shoe", 500, 1, false, "brown", 100};
	Player playerTwo = {"top hat", 500, 1, false, "red", 380};
	Player playerThree = {"iron",500, 1, true, "green", 230};
	
	Move firstMove = {"start", "action", 200};
	Move secondMove = {"go_to_jail", "action", 1};
	Move thirdMove = {"green", "lot", 150};
	
	Player *players[3] = {&playerOne, &playerTwo, &playerThree};
	
	player_info(playerOne);
 	
	next_move(players, 0, firstMove);
 	
	next_move(players, 0, thirdMove);
	
	next_move(players, 1, secondMove);
	
	find_winner(players);
};
