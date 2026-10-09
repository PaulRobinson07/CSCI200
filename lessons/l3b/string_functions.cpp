#include "string_functions.h"

#include <iostream>

using namespace std;

size_t string_length(const string STR)  {
    size_t result = 0;
    result = STR.length();  // set result to the length of the string
    return result;
}

//gets the character at a given location from a string
char string_char_at(const string STR, const size_t IDX) {
    char result = '\0';
	//gets the character
	result = STR.at(IDX);
    return result;
}

//concatenates two strings
string string_append(const string LEFT, const string RIGHT)  {
    string result = LEFT;
	//uses the properties of string to simply add one string to another
	result+=RIGHT;
    return result;
}

//inserts one string into another
string string_insert(const string STR, const string TO_INSERT, const size_t IDX) {
    string result = STR;

	//inserts the string and returns the result
	result.insert(IDX, TO_INSERT); 
    return result;
}

//finds a character in a string
size_t string_find(const string STR, const char C)  {
    size_t result = 0;

	//finds the location of the first instance of char C, if not the returned value is nullstring
	result = STR.find_first_of(C);
    return result;
}

//gets a portion of a string
string string_substring(const string STR, const size_t IDX, const size_t LEN) {
	//makes a return string and adds every element from IDX to IDX+LEN
    string result;
	for (size_t i=IDX;i<IDX+LEN;i++) {
		result+=STR.at(i);
	}
    return result;
}

//replaces part of a string
string string_replace(const string STR, const string TEXT_TO_REPLACE, const string REPLACE_WITH) {
    string result = STR;

	//finds the location of the string we want to replace
	size_t pos = STR.find(TEXT_TO_REPLACE);
	
	//if it is in the string, replace it with another string
	if (pos!=string::npos) {
		result.replace(pos, TEXT_TO_REPLACE.length(), REPLACE_WITH);
	}
    return result;
}

//finds the first word and then prints out that word
string string_first_word(const string STR)  {
    string result = STR;

	//finds the first word end
	size_t pos = STR.find_first_of(" ");

	//if there is more than word, set the string to be the end of the first word
	if (pos!=string::npos) {
		result=STR.substr(0,pos);
	}
    return result;
}


//removes the first word from a string
string string_remove_first_word(const string STR)  {
    string result;

	//finds the first word end
	size_t pos = STR.find_first_of(" ");

	//if there is more than word, set the string to be the everything after end of the first word
	if (pos!=string::npos) {
		result=STR.substr(pos+1,STR.length());
	}
    return result;
}

//gets the second word of a string
string string_second_word(const string STR)  {
    string result;

	//finds the first word end
	size_t pos1 = STR.find(" ");

	//if there is more than word, continue
	if (pos1!=string::npos) {
		//find the second word end if there is one
		size_t pos2 = STR.find(" ", pos1+1);
		//if there is an end to the second word, write result as a substring from the first " " to the second " "
		if (pos2!=string::npos) {
			result=STR.substr(pos1+1,pos2-pos1-1);
		}

		//if there isn't an end just write the rest of the string to result
		else {
			result=STR.substr(pos1+1,STR.length()-pos1-1);
		}
	}
    return result;
}

//I didn't want to do another nested set of statements or refactor two into something for three
//so I just call the function to find nth :)
string string_third_word(const string STR)  {
    string result = STR;
	result = string_nth_word(STR,3);
    return result;
}

//finds the nth word in a string
string string_nth_word(const string STR, const int N)  {
    string result;
	//makes it so the code will run don't touch
	size_t pos = string::npos;

	//loops to find the correct start of the string
	for (int i=0; i<N-1; i++) {
		pos = STR.find(" ", pos+1);
		//if there isn't a valid start, quit the function because there isn't an Nth word
		if (pos==string::npos) {
			return result;
		}
	}

	//finds the location of the end of the string
	size_t pos2 = STR.find(" ", pos+1);
	//if the string has more text after the word just write the next word
	if (pos2==string::npos) {
		result = STR.substr(pos+1,STR.length()-pos-1);
	}
	//otherwise write everything after the start of the word
	else {
		result = STR.substr(pos+1,pos2-pos-1);
	}

    return result;
}

//tokenizes a string based on a char deliminator
vector<string> string_tokenize(const string STR, const char DELIMINATOR) {
	//variables need to run the code
    vector<string> result;
	string temp_string = STR;
	size_t pos = 0;

	//while there is still words loop through them
	while(pos!=string::npos) {
		//find the next break
		pos = temp_string.find(DELIMINATOR);

		//add the current word to the list
		result.push_back(temp_string.substr(0,pos));

		//if the position is not the string length, shorten the temp_string by the current word
		if (pos!=temp_string.length()) {
			temp_string = temp_string.substr(pos+1,temp_string.length());
		}
	}
    return result;
}

//subsitutes one character in a string for another
string string_substitute(const string STR, const char TARGET, const char REPLACEMENT)  {
    string result;

	//loops over every character in a string
	for(size_t i=0;i<STR.length();i++) {
		//if it is the target replace it
		if (STR.at(i)==TARGET) {
			result.push_back(REPLACEMENT);
		}
		//otherwise add the original character
		else {
			result.push_back(STR.at(i));
		}
	}
    return result;
}

//makes a string all lower case
string string_to_lower(const string STR) {
    string result;

	//loops over every character in a string
	for(size_t i=0;i<STR.length();i++) {
		//if it is uppercase make it lowercase
		if (STR.at(i)>= 65 && STR.at(i) <=90) {
			char c = STR.at(i)+32;
			result.push_back(c);
		}
		//otherwise add the original character
		else {
			result.push_back(STR.at(i));
		}
	}
    return result;
}

//makes a string all uppercase
string string_to_upper(const string STR) {
    string result;

	//loops over every character in a string
	for(size_t i=0;i<STR.length();i++) {
		//if it is lowercase make it uppercase 
		if (STR.at(i)>= 97 && STR.at(i) <= 122) {
			char c = STR.at(i)-32;
			result.push_back(c);
		}
		//otherwise add the original character
		else {
			result.push_back(STR.at(i));
		}
	}
    return result;
}

//compares two strings and says their differences though output
int string_compare(const string LHS, const string RHS) {
	//defaults to the strings being equal
    int result = 0;
	//compares them
	result = LHS.compare(RHS);

	//either the value of char does not match or all compared chars match but the string is shorter
	if (result>=1) {
		result=1;
	}
	//either the value of char does not match or all compared chars match but the string is longer 
	if(result<=-1) {
		result=-1;
	}
    return result;
}
