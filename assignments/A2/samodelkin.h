/*
 * I know we're supposed to use the keywords
 * define
 * ifdef
 * endif
 * but I just updated my laptop to macOS 27 and the compiler was bugging out
 */
#pragma once

//used to store current game state more effiecently than four constants
enum Game_State {
	playing,
	player_won,
	player_lost,
	player_quit
};
//gets a yes or no from user in the form of a char
bool prompt_user_bool();

//puts the user in a new room
void goto_new_room(int* current_room, int room_count);

//enters and acts in the room
void enter_room(int* room_number, int* health, bool* has_key, bool* has_weapon, Game_State* game_state);
