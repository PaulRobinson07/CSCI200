#include <fstream>
#include <ostream>
#include <iostream>
using namespace std;

int main() {
	//objects for file management
    ifstream file_input("secretMessage.txt");
	ofstream file_output("decoded.txt");
	
	//checks if the file input can be read and tells user if not
    if(file_input.fail() ) {
      cerr << "Could not open data.txt" << endl;
      return -1;
    }

	//checks if the file ouput can be written and tells user if not
	if(file_output.fail()) {
		cerr << "Could not write to decoded.txt" << endl;
		return -2;
	}

	char c;
	//while there are still characters to read from the input, write the output file
	while(!file_input.eof()) {
		//gets the next character
		file_input.get(c);

		//acts based on the character ascii code
		switch(c) {
			//if the character is a new line (13) make a new line in the output file
			case('\n'):
				file_output << endl;
			break;
			//if the code is a tilda (148) write a space
			case('~'):
				file_output << " ";
			break;
			//otherwise edit the keycode to be plus one
			default:
				c+=1;
				file_output << c;
			break;
		}
	}

	//closes the files
    file_input.close();
	file_output.close();

    return 0;
}
