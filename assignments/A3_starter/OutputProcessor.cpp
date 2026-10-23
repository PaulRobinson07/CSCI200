#include <vector>
#include <string>
#include <iostream>
#include "OutputProcessor.h"
#include <iomanip>
using namespace std;

//gets the words
vector<string> getAllWords() {
	vector<string> returnVector;
	return returnVector;
}

//analyizes words for later analylitics
void OutputProcessor::analyzeWords(vector<string> words) {
	//loops over words
	for (int i=0;i<words.size();i++) {
		bool found = false;
		//finds if the word is unique
		for (int j=0; j<uniqueWords.size();j++) {
			//if not just increment the word count for it
			if(words.at(i)==uniqueWords.at(j)) {
				found = true;
				uniqueWordCount.at(j)++;
			}
		}
		//if the word isn't unique add a new word to the list
		if (!found) {
			uniqueWords.push_back(words.at(i));
			uniqueWordCount.push_back(1);
		}
		//adds all characters to character trackers
		for (int j=0;j<words.at(i).length();j++) {
			int index = words.at(i).at(j);
			if (index >='A' && index <= 'Z') {
				charCount.at(words.at(i).at(j)-'A')++;
				total_chars++;
			}
		}
	}
	//sets the word count
	word_count= words.size();
}

//writes out the data about the txt file
void OutputProcessor::writeToStream(ostream &ptr) {
	//variables needed for rendering later
	int longestWord = 0;
	int mode = uniqueWordCount.at(0);
	int least = mode;
	string most_common_word=uniqueWords.at(0);
	int mode_chars = charCount.at(1);
	int least_chars;
	char mode_common_char = alphabet.at(0);
	char least_common_char = mode_common_char;
	string least_common_word;

	//loops over all words
	for (int i=0;i<uniqueWords.size();i++) {
		//finds the longest word
		if(uniqueWords.at(i).length()>longestWord) {
			longestWord = uniqueWords.at(i).length();
		}
		//finds the mode of words
		if(uniqueWordCount.at(i)>mode) {
			mode = uniqueWordCount.at(i);
			most_common_word = uniqueWords.at(i);
		}
		//find the least common word
		if(uniqueWordCount.at(i)<least) {
			least= uniqueWordCount.at(i);
			least_common_word = uniqueWords.at(i);
		}
	}

	//tells the counts of words
	ptr << "Analyzed " << word_count<< " total words" << endl;
	ptr << "Counted " << uniqueWords.size() << " unique words" << endl;

	//prints the counts of each unique word and left aligns it
	for (int i=0;i<uniqueWords.size();i++) {
		ptr << uniqueWords.at(i);
		for (int j=0;j<longestWord-uniqueWords.at(i).length();j++) {
			ptr << " ";
		}
		ptr << " - " << uniqueWordCount.at(i) << endl;
	}

	//gives stats on frequency of words
	ptr << "Most common word: " << most_common_word << " " << mode << "(" << setprecision(3) 
		<< (static_cast<double>(100*mode)/word_count) << "%)" << endl;
	ptr << "Least common word: " << least_common_word << " " << least << "(" << setprecision(3)
		<< (static_cast<double>(100*least)/word_count) << "%)" << endl;

	//loops over all letters
	for (int i=0;i<alphabet.size();i++) {
		ptr << alphabet.at(i);
		//prints space for left align
		for (int j=0;j<longestWord-1;j++) {
			ptr << " ";
		}
		ptr << charCount.at(i) << endl;;

		//finds mode of chars
		if(charCount.at(i)>mode_chars) {
			mode_chars = charCount.at(i);
			mode_common_char = alphabet.at(i);
		}

		//finds least common char
		if(charCount.at(i)<least_chars && charCount.at(i)!=0) {
			least_chars= charCount.at(i);
			least_common_char= alphabet.at(i);
		}
	}

	//gives frequencies of chars
	ptr << "Most common character: " << mode_common_char<< " " << mode_chars << "(" << setprecision(3) 
		<< (static_cast<double>(100*mode_chars)/total_chars) << "%)" << endl;
	ptr << "Least common character: " << least_common_char<< " " << least_chars << "(" << setprecision(3)
		<< (static_cast<double>(100*least_chars)/total_chars) << "%)" << endl;
}

