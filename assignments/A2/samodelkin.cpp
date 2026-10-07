#include <iostream>
#include <random>

using namespace std;

//room data
const int KEY_ROOM = 3;
const int WEAPON_ROOM = 7;
const int EXIT_ROOM = 5;

//enum used to store the game state
//more effiecent than four constant shorts
enum Game_State {
	playing,
	player_won,
	player_lost,
	player_quit
};

//gets a boolean value in the form of a char from the user
bool prompt_user_bool() {
	//this variable is used to store the char from the user
	char answer;

	//prompts and stores answer
	cout << "Enter your answer (Y/N): " << endl;
	cin >> answer;

	//acts accordingly to the user's input
	switch(answer) {
		//if true return true
		case 'y':
		case 'Y':
			return true;
		break;

		//if false return false
		case 'n':
		case 'N':
			return false;
		break;

		//if something else is given, reprompt
		default:
			cout << "Either enter yes (y) or no (n)." << endl;
			cout << "Anything else is not permitted" << endl;
			return prompt_user_bool();
		break;
	}
}

//gets a random number between the bounds given
int generate_random_int(int min, int max) {
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> distrib(min, max);
	return distrib(gen);
}

//code for an empty room
void empty_room() {
	cout << "Nothing is in this room" << endl;
}

//code for a room with a key 
void key_room(bool* has_key) {
	//if the user has the key just tell them they already have it
	if (*has_key) {
		cout << "Nothing to be found. You recall this to be the room you found the key in." << endl;
		return;
	}
	//tells the user that there is something to pick up if they didn't pick it up already
	//also prompts them to decide on wether to pick it up
	cout << "You feel the presence of something in the room." << endl;
	cout << "Do you wish to pick up the item in the center of the room." << endl;
	bool answer = prompt_user_bool();

	//if the user want to pick it up, pick it up
	if (answer) {
		cout << "You picked up a key." << endl;
		*has_key = true;
		return;
	}

	//if they don't want to pick up the key don't
	cout << "You may regret that choice my friend." << endl;
	return;
	
}

//code for a room with a weapon
void weapon_room(bool *has_weapon) {
	//if they already have it the player just leaves
	if (*has_weapon) {
		cout << "Nothing to be found. You recall this to be the room you found the sword in." << endl;
		return;
	}
	//tells the user that there is something to pick up and prompts them to pick 
	//wether to pick it up or not
	cout << "Do you wish to pick up the item in the center of the room." << endl;
	bool answer = prompt_user_bool();

	//if they want to they pick it up
	if (answer) {
		cout << "You feel the presence of something in the room." << endl;
		cout << "You picked up a sword." << endl;
		*has_weapon = true;
		return;
	}
	
	//otherwise they leave it
	cout << "You may regret that choice my friend." << endl;
	return;
	
}

//code for a room with a enemy
void enemy_room(bool *has_weapon, int* health, Game_State* game_state) {
	//makes an enemy and tells the player
	int enemy_health = generate_random_int(20,35);
	cout << "You found an enemy with " << enemy_health
		 << " that wants to fight you!" << endl;

	//fight loop
	while ((enemy_health>0) && (*health>0)) {
		//takes health from player and tells them
		*health-=generate_random_int(5,10);
		cout << "The enemy damages you and you now have " << *health << "hp left" << endl;

		//attacks the enemy dealing damage based on whether they have a weapon
		if (*has_weapon) {
			enemy_health-=generate_random_int(10,15);
		}
		else {
			enemy_health-=generate_random_int(1,5);
		}
		cout << "You damage the enemy and it now has" << enemy_health << "hp left" << endl;
	}

	//the player died and the game is over
	if (*health <=0) {
		*game_state = player_lost;
		cout << "You have died :(" << endl;
		return;
	}
	
	//the player killed the enemy and moves onto another room
	else {
		cout << "You have slain the enemy." << endl;
	}
}

//room that has a health pot
void potion_room(int* health) {
	//tells the user that they found and consumed a health potion
	cout << "This room has a health potion which you consume" << endl;
	int health_boost = generate_random_int(5,15);
	cout << "The potion gave you " << health_boost << "hp" << endl;
	*health+=health_boost;
	cout << "You now have: " << *health << "hp" << endl;
}

//room that allows the user to escape if they have the key
void exit_room(bool* has_key, Game_State* game_state) {
	cout << "There appears to be a locked gate. It seems to be the exit of this labyrinth" << endl;

	//if the user has a key they leave and updates the game state accordingly
	if (*has_key) {
		cout << "You use your key and open the gate" << endl;
		*game_state = player_won;
		cout << "You've managed to escape! Congrats you win." << endl;
	}

	//makes the user keep searching for the key
	else {
		cout << "You don't have a key to unlock the door. Keep searching for the key" << endl;
	}
}

//chages the players room to be a valid room
void goto_new_room(int* current_room, int room_count) {
	*current_room = generate_random_int(1,room_count);
}

//acts based on the room the player is currently in
void enter_room(int* room_number, int* health, bool* has_key, bool* has_weapon, Game_State* game_state) {
	//gives the player stats
		cout << "Current room: " << *room_number << endl;
		cout << "HP: " << *room_number << endl;
		if (*has_key) {
			cout << "Key: Obtained" << endl;
		}
		else {
			cout << "Key: Not Obtained" << endl;
		}
		if (*has_weapon) {
			cout << "Weapon: Obtained" << endl;
		}
		else {
			cout << "Wepaon: Not Obtained" << endl;
		}
	//end player stats
	
	//calls the function associated with each room
	switch (*room_number) {
		case KEY_ROOM:
			key_room(has_key);
			return;
		break;
		case WEAPON_ROOM:
			weapon_room(has_weapon);
			return;
		break;
		case EXIT_ROOM:
			exit_room(has_key, game_state);
			return;
		break;
	}

	//if not a special room, pick a room mathematically
	switch (*room_number % 5) {
		case 0:
			empty_room();
		break;
		case 1:
			potion_room(health);
		break;
		default:
			enemy_room(has_weapon, health, game_state);
		break;
	}

}
