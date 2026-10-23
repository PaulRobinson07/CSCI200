#include <vector>
#include <string>
#include "InputProcessor.h"

using namespace std;

//returns all retrieved words
vector<string> InputProcessor::getAllWords() {
	return words;
}


//gets all words from a file
void InputProcessor::readFromStream(istream &ptr) {
	char c;
	string s;
	//loops through the file
	while(!ptr.eof()) {
		//make sure the character is valid
		if ((c>='A' && c<'Z') || (c>='a' && c<='z')) {
			s+=c;
		}
		
		//if not make a new word
		else{
			//only if there is a word to add
			if (!s.empty()) {
				words.push_back(s);
			}
			s="";
		}
	}
}

//cleans up words
void InputProcessor::sanitizeWords(const string &punctuation) {
	for (size_t i = 0; i < words.size(); ++i) {
        std::string cleaned = "";
       
		//loops over words
        for (size_t j = 0; j < words[i].length(); ++j) {
            char c = words[i][j];
            
            // Check if the character is in the punctuation string
            bool isPunct = false;
            for (size_t p = 0; p < punctuation.length(); ++p) {
                if (c == punctuation[p]) {
                    isPunct = true;
                    break;
                }
            }
            
            // If it's not punctuation, keep it and convert to uppercase
            if (!isPunct) {
                if (c >= 'a' && c <= 'z') {
                    c = c - 32; // Convert lowercase to uppercase using ASCII math
                }
                cleaned += c;
            }
        }
        
        // Update the word in the vector
        words[i] = cleaned;
    }
}
