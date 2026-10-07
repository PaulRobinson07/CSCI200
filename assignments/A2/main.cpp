/* CSCI 200: Fix Loop and Function Errors
 *
 * Author: (Paul Robinson)
 * 
 * Description: Lesson A2 seeks to teach students how to use header files with pointers
 * 
 * Copyright 2026 Dr. Jeffrey Paone
 * 
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use,
 * copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following
 * conditions:
 * 
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 *
 */
#include <iostream>
#include "samodelkin.h"

using namespace std;

//constants (most that are needed are in the other file, this just saves pointer parameters)
const int EXPLORABLE_ROOMS = 10;

//chageable variables
int health = 100;
bool has_key = false;
bool has_weapon = false;
int current_room;
int rooms_explored;
Game_State game_state = playing;

int main() {
	//game loop
	while (game_state==0) {
		//room logic
		goto_new_room(&current_room, EXPLORABLE_ROOMS);
		enter_room(&current_room, 
				&health, 
				&has_key, 
				&has_weapon, 
				&game_state);

		//prompts and acts based on whether the user wishes to keep exploring the dungeon
		cout << "Do you wish to keep exploring?" << endl;
		if (!prompt_user_bool()) {
			game_state = player_quit;
		}

		//increments the number of explored rooms
		rooms_explored++;
	}

	//tells the user how many rooms they explored
	cout << "You explored " << rooms_explored << " rooms" << endl;
	
	//uplifts the player after playing the game
	if (game_state==player_lost) {
			cout << "Try again!" << endl;
	}
	if (game_state==player_won) {
			cout << "Congrats on beating the game" << endl;
	}
	cout << "Have a nice day" << endl;
    return 0;
}
