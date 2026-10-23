#ifndef INPUTPROCESSOR_H
#define INPUTPROCESSOR_H

#include <vector>
#include <string>
#include <istream> 
#include <iostream>

using namespace std;

//handles the input grabbing and editing
class InputProcessor {
public:  
	vector<string> words;
	vector<string> getAllWords();
	void readFromStream(istream &ptr);
	void sanitizeWords(const string &punctuation);
};

#endif
