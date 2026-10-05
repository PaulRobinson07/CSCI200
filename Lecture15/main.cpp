#include <iostream>
#include <fstream>

using namespace std;

int main() {
    cout << "Hello World!" << endl;

	//declare ifstream object
	ifstream fin;
	fin.open("data.txt");
	ifstream saveFile("save.txt");
	ifstream preferencesFile;

	if(fin.fail()) {
		cerr << "Unable to open file" << endl;
		return -1;
	}
	char x;
	while(!fin.eof()) {
		x = (char)fin.get();
		cout << x;

	}
	fin.close();
    return 0;
}
