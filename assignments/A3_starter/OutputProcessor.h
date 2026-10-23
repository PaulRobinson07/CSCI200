#ifndef OUTPUTPROCESSOR_H
#define OUTPUTPROCESSOR_H



#include <vector>
#include <string>
#include <ostream> 
#include <iostream>

using namespace std;

//@brief input processort object
class OutputProcessor{
public:
	//variables needed for later
	vector<string> uniqueWords;
	vector<int> uniqueWordCount;
	vector<char> alphabet;
	vector<int> charCount;
	int total_chars = 0;
	int word_count;

	//constructor (duh)
	OutputProcessor() {
		//makes an alphabet
		int word_count = 0;
		for (char c = 'A'; c<='Z'; ++c) {
			alphabet.push_back(c);
			charCount.push_back(0);
		}
	}
	//makes data
	void analyzeWords(vector<string> words);
	//writes data
	void writeToStream(ostream &ptr);
};

#endif
