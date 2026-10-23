#include "StreamUtility.h"

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

//gets the input from user
istream* StreamUtility::selectInput() {
	cout << "Do you want to read from the standard input (s) or a file (f)?" << endl;
	char c;
	cin >> c;

	//acts based on input also modular
	switch(c) {
		//they want to give a file
		case 'f':
		case 'F': {
			//asks for file
			cout << "What is the file path?" << endl;
			string path;
			cin >> path;
			//gets the file if valid if not fails
			ifstream*  fileStream = new ifstream(path);
			if (!fileStream->is_open()) {
				delete fileStream;
				return nullptr;
			}
			return fileStream;
			break;
		}

		//gets standard input
		case 's':
		case 'S': {
			return &std::cin;
		break;
		}

		//edge case if no valid option is picked
		default:
			return nullptr;
		break;
	}
}


//gets the output stream from user
ostream* StreamUtility::selectOutput() {
	//gets their selection
	cout << "Do you want to read from the standard ouput(o) or a file (f)?" << endl;
	char c;
	cin >> c;

	//acts based on selection
	switch(c) {
		//gets their given path
		case 'f':
		case 'F': {
			cout << "What is the file path?" << endl;
			string path;
			cin >> path;
			ofstream*  fileStream = new ofstream(path);

			//checks if path is valid and acts accordingly
			if (!fileStream->is_open()) {
				delete fileStream;
				return nullptr;
			}
			return fileStream;
			break;
		}
		
		//sets the output to be the terminal
		case 's':
		case 'o':
		case 'O':
		case 'S': {
			return &cout;
			break;
		}
		
		//user error edgecase
		default:
			return nullptr;
		break;
	}

}
